// LUOGU_RID: 160400903
#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=2005,inf=1e9;
int T,n,a[N],dp[N][M],ans;
void chmin(int &x,int y){
    if(x>y) x=y;
}
void solve(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i) scanf("%d",&a[i]);
    for(int i=0;i<=n;++i) for(int j=0;j<M;++j) dp[i][j]=inf;
    dp[0][0]=0; ans=inf;
    for(int i=1;i<=n;++i) for(int j=0;j<M;++j){
        if(j+a[i]<M){
            if(dp[i-1][j]>a[i]) chmin(dp[i][j+a[i]],dp[i-1][j]-a[i]);
            else dp[i][j+a[i]]=0;
        }
        if(j>a[i]) chmin(dp[i][j-a[i]],dp[i-1][j]+a[i]);
        else chmin(dp[i][0],dp[i-1][j]+a[i]);
    }
    for(int i=0;i<M;++i) chmin(ans,i+dp[n][i]);
    printf("%d\n",ans);
}
int main(){
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}