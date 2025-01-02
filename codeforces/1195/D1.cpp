#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
const int N=1e5+10,mod=998244353;
int n,a[N],c[20];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        int x=a[i];
        int cnt=0;
        while(x){
            cnt++;
            x/=10;
        }
        c[cnt]++;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        vector<int> vec1;
        int x=a[i];
        while(x){
            vec1.push_back(x%10);
            x/=10;
        }
        reverse(vec1.begin(),vec1.end());
        auto vec=vec1;
        for(int j=1;j<=10;j++){
            if(c[j]){
                vec1=vec;
                vector<int> vec2;
                for(int k=1;k<=j;k++) vec2.push_back(0);
                int base=1;
                while(vec1.size() && vec2.size()){
                    vec2.pop_back();
                    base=base*10%mod;
                    int t=vec1.back()*base%mod;
                    vec1.pop_back();
                    base=base*10%mod;
                    t=t*c[j]%mod;
                    ans=(ans+t)%mod;
                }
                while(vec1.size()){
                    int t=vec1.back()*base%mod;
                    vec1.pop_back();
                    base=base*10%mod;
                    t=t*c[j]%mod;
                    ans=(ans+t)%mod;
                }
                vec1=vec;
                vec2.clear();
                for(int k=1;k<=j;k++) vec2.push_back(0);
                base=1;
                while(vec1.size() && vec2.size()){
                    int t=vec1.back()*base%mod;
                    vec1.pop_back();
                    base=base*10%mod;
                    t=t*c[j]%mod;
                    ans=(ans+t)%mod;
                    vec2.pop_back();
                    base=base*10%mod;
                }
                while(vec1.size()){
                    int t=vec1.back()*base%mod;
                    vec1.pop_back();
                    base=base*10%mod;
                    t=t*c[j]%mod;
                    ans=(ans+t)%mod;
                }
            }
        }
    }
    cout<<ans<<'\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T=1;
//    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
