// LUOGU_RID: 158365757
//A tree without skin will surely die.
//A man without face is invincible.
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,j,k) for (int i=j;i<=k;++i)
#define per(i,j,k) for (int i=j;i>=k;--i)
int const N=105;
int const M=1e4+5;
int n,x,c[N],sm;
double C[N][N],dp[N][M];
void solve(){
    cin>>n>>x;
    rep(i,1,n) cin>>c[i],sm+=c[i];
    dp[0][0]=1;
    rep(i,1,n) per(k,i,1) rep(j,c[i],sm) dp[k][j]+=dp[k-1][j-c[i]];
    double ans=0;
    rep(i,0,n-1) rep(j,0,sm)
        ans+=min(1.0*(sm-j)/(n-i),(1.0*n/(n-i)-1)*x/2+x)*dp[i][j]/C[n][i];
    cout<<fixed<<setprecision(20)<<ans<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    rep(i,1,N-1){
        C[i][0]=C[i][i]=1;
        rep(j,1,i-1) C[i][j]=C[i-1][j]+C[i-1][j-1];
    }
    int t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}