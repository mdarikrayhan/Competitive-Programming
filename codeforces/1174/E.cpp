// LUOGU_RID: 158546607
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int mod=1e9+7;
int n;
int dp[1000005][21][3];
int qaq(int x,int y) {
    return (1<<x)*(y?3:1)%mod;
}
int main() {
    scanf("%d",&n);
    int hav3=log2(n/3)+1;
    int nhav3=log2(n);
    dp[1][nhav3][0]=1;
    if(hav3==nhav3) dp[1][nhav3-1][1]=1;
    rep(i,1,n-1) {
        rep(j,0,nhav3) {
            rep(k,0,1) {
                dp[i+1][j][k]=1ll*(1ll*dp[i+1][j][k]+dp[i][j][k]*(1ll*n/qaq(j,k)%mod-i+mod)%mod+mod)%mod;
                if(j>0) dp[i+1][j-1][k]=1ll*(1ll*dp[i+1][j-1][k]+dp[i][j][k]*(1ll*n/qaq(j-1,k)%mod-n/qaq(j,k)%mod)%mod+mod)%mod;
                if(k>0) dp[i+1][j][k-1]=1ll*(1ll*dp[i+1][j][k-1]+dp[i][j][k]*(1ll*n/qaq(j,k-1)%mod-n/qaq(j,k)%mod)%mod+mod)%mod;
            }
        }
    }
    printf("%d\n",dp[n][0][0]);
    return 0;
}