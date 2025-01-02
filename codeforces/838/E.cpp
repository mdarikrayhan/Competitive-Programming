// LUOGU_RID: 99959700
#include<bits/stdc++.h>
using namespace std;
int n; int x[5010],y[5010];
double dp[5010][2510][2];
double get_dis(int a,int b)
{
return sqrt(1ll*(x[a]-x[b])*(x[a]-x[b])+1ll*(y[a]-y[b])*(y[a]-y[b]));
}
int main()
{
cin>>n;
for(int i=1; i<=n; ++i) cin>>x[i]>>y[i],x[i+n]=x[i],y[i+n]=y[i];
double ans=0;
for(int len=2; len<=n; ++len)
{
for(int i=1; i<=2*n-1-len+1; ++i)
{
int j=i+len-1;
dp[i][j-i][0]=max(dp[i+1][j-(i+1)][0]+get_dis(i,i+1),dp[i+1][j-(i+1)][1]+get_dis(i,j));
dp[i][j-i][1]=max(dp[i][j-1-i][0]+get_dis(i,j),dp[i][j-1-i][1]+get_dis(j,j-1));
if(len==n) ans=max(ans,max(dp[i][j-i][0],dp[i][j-i][1]));
}
}
printf("%.9f",ans);
return 0;
}