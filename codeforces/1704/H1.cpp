// LUOGU_RID: 160170910
//A tree without skin will surely die.
//A man without face is invincible.
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,j,k) for (int i=j;i<=k;++i)
#define per(i,j,k) for (int i=j;i>=k;--i)
int const N=5e3+10;
int n,mod,ans,fac[N],inv[N],pw[N][N];
inline int qpow(int a,int b){int r=1;while (b){if (b&1) r*=a,r%=mod;a*=a,a%=mod,b>>=1;}return r;}
inline int C(int n,int m){if (n<m || m<0) return 0;return fac[n]*inv[m]%mod*inv[n-m]%mod;}
inline void init(int n){
    fac[0]=1;
    rep(i,1,n) fac[i]=fac[i-1]*i%mod;
    inv[n]=qpow(fac[n],mod-2);
    per(i,n-1,0) inv[i]=inv[i+1]*(i+1)%mod;
    rep(i,0,n){
        pw[i][0]=1;
        rep(j,1,n) pw[i][j]=pw[i][j-1]*i%mod;
    }
}
void solve(){
    cin>>n>>mod;
    init(5000);
    rep(i,1,n/2) rep(j,0,n-2*i)
        ans+=pw[n-1][i]*pw[n-i-j][j]%mod*C(n,j)%mod*C(n-j,i)%mod*C(n-j-i-1,i-1)%mod*fac[n-j-i]%mod,ans%=mod;
    cout<<ans<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}