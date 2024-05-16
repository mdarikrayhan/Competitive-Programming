#include<bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rev(i,a,b) for(int i=a;i>=b;i--)
#define repp(i,a,b) for(int i=a;i<=b;i++)

void solve(){
        int n;
        cin>>n;
        vector<int>v(n);
        rep(i,0,n) cin>>v[i];
        sort(v.begin(),v.end());
        if(v[0]!=v[1]) cout<<"YES"<<endl;
        else{
            bool ans=false;
            rep(i,1,n){
                if(v[i]%v[0]!=0) ans=true;
            }
            if(ans) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
}
int main()
{
    FASTIO;
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
