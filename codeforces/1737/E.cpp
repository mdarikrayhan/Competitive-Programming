// LUOGU_RID: 160027912
#include<iostream>
#define int long long
using namespace std;
const int N=1e6+5,mod=1e9+7,inv=(mod+1)/2;
int t,n,f[N],dp[N],s[N];
signed main(){
    cin>>t;
    while(t--){
        cin>>n;
        f[0]=1;
        for(int i=1;i<=n;i++) f[i]=f[i-1]*inv%mod;
        s[n+1]=0;
        for(int i=n;i>=n/2+1;i--){
            dp[i]=1;
            s[i]=(s[i+1]*inv+dp[i])%mod;
        }
        for(int i=n/2;i;i--){
            dp[i]=(s[i+1]-s[i*2]*f[i-1]%mod+mod)*inv%mod;
            s[i]=(s[i+1]*inv+dp[i])%mod;
        }
        for(int i=1;i<=n;i++){
            cout<<dp[i]*f[(i+1)/2]%mod*((i==n)+1)%mod<<"\n";
        }
    }
    return 0;
}//