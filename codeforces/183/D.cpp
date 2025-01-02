// LUOGU_RID: 159993549
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'
using namespace std;
const int N=3005,M=305;
int n,m,q[N][M];
double ans,f[N][M],g[N],dt[N];
double a[N][M];
signed main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    rep(i,1,n) rep(j,1,m) cin>>q[i][j];
    rep(i,1,n) rep(j,1,m) a[i][j]=q[i][j]/1000.0;
    rep(i,1,m) f[0][i]=1;
    rep(i,1,n) rep(j,1,m) f[i][j]=f[i-1][j]*(1-a[i][j]);
    rep(i,1,m) dt[i]=1-f[n][i];
    rep(i,1,n){
        int pos=0;
        rep(j,1,m) if(dt[j]>dt[pos]) pos=j;
        ans+=dt[pos];
        rep(j,0,n) g[j]=f[j][pos];
        f[0][pos]=0;
        rep(j,1,n) f[j][pos]=g[j-1]*a[j][pos]+f[j-1][pos]*(1-a[j][pos]);
        dt[pos]-=f[n][pos];
    }
    cout<<fixed<<setprecision(12)<<ans<<endl;
}