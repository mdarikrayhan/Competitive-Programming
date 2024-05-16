#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef pair<int,int> pi;
const int mod=998244353;
#define int long long
const int M = 2e5 + 10;
int  power(int a, int b){
    if (b==0) return 1;
    int t =power(a,b/2);
    return (b%2?t*t%mod*a%mod:t*t%mod);
}
 void solve(){
     int n;cin>>n;
     vector<int>x(n),y(n);
     for(int i=0;i<n;i++){
        cin>>x[i]>>y[i];
     }
     if(n&1){cout<<"1"<<endl;return;}
     sort(x.begin(),x.end());
     sort(y.begin(),y.end());
     cout<<(x[n/2]-x[(n/2)-1]+1)*(y[n/2]-y[(n/2)-1]+1)<<endl;
 }
 signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T=1;
    cin>>T;
    while (T--) {
        solve();
    }
}