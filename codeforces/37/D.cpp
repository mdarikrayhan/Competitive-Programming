// LUOGU_RID: 159146921
#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=1005,INF=1e18,M=1e9+7;
int T,n,m,x[N],y[N],s[N],jc[N],ny[N];
int dp[N][N],ans;
int qp(int x,int y){
    int res=1;
    while(y){
        if(y&1)res=res*x%M;
        x=x*x%M;
        y>>=1;
    }
    return res;
}
int zh(int n,int m){
    return jc[n]*ny[m]%M*ny[n-m]%M;
}
void sv(){
    cin>>m;
    for(int i=1;i<=m;i++)
        cin>>x[i],s[i]=s[i-1]+x[i];
    n=s[m],jc[0]=ny[0]=dp[0][0]=1;
    for(int i=1;i<=m;i++)cin>>y[i];
    for(int i=1;i<=n;i++)
        jc[i]=jc[i-1]*i%M,ny[i]=qp(jc[i],M-2);
    for(int i=1;i<=m;i++)
        for(int j=0;j<=s[i];j++)
            for(int k=0;k<=min(j,y[i]);k++)
                dp[i][j]=(dp[i][j]+dp[i-1][j-k]*zh(s[i]-j+k,k)%M)%M;
    ans=dp[m][n];
    for(int i=1;i<=m;i++)
        ans=ans*zh(n-s[i-1],x[i])%M;
    printf("%lld\n",ans);
    return;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cin>>T;
    T=1;
    while(T--)sv();
    return 0;
}