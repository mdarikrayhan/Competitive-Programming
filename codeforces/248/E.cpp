// LUOGU_RID: 160445442
#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100005],b[100005];
double dp[100005][105],C[500105][6];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),dp[i][a[i]]=1,b[i]=a[i];
    scanf("%d",&m);
    for(int i=0;i<=500100;i++){
        C[i][0]=1;
        for(int j=1;j<=min(i,5);j++)C[i][j]=C[i-1][j-1]+C[i-1][j];
    }
    double ans=0;
    for(int i=1;i<=n;i++)if(!a[i])ans++;
    while(m--){
        int x,y,k;scanf("%d%d%d",&x,&y,&k);
        ans-=dp[x][0];
        for(int i=0;i<=a[x];i++){
            if(i<=b[x])dp[x][i]*=C[b[x]-i][k]/C[b[x]][k];else dp[x][i]=0;
            for(int j=1;j<=min(k,min(a[x],b[x])-i);j++)
                dp[x][i]+=dp[x][i+j]*C[i+j][j]*C[b[x]-i-j][k-j]/C[b[x]][k];
        }
        ans+=dp[x][0];
        printf("%.10lf\n",ans);
        b[x]-=k,b[y]+=k;
    }
    return 0;
}