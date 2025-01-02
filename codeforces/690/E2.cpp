#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 605
#define ll long long
int a[N][N],pre[1<<16][17],ans[17];
int T,n,m,k,i,j,h,x,Min;
ll sum,now,f[1<<16][17],val[17][17];
int main()
{
scanf("%d",&T);
while(T--){
scanf("%d%d%d",&n,&m,&k);
for(i=1;i<=n;i++)for(j=1;j<=m;j++)scanf("%d",&a[i][j]);
for(i=1;i<=k;i++)
for(j=1;j<=k;j++){
if(i==j)continue;sum=0;
for(h=1;h<=m;h++){
x=n/k*i;now=0;
now+=a[x][h]+a[x-1][h]+a[x-1][h-1]+a[x-1][h+1]+a[x][h-1]+a[x][h+1];
x=n/k*(j-1)+1;
now-=a[x][h]+a[x+1][h]+a[x+1][h-1]+a[x+1][h+1]+a[x][h-1]+a[x][h+1];
sum+=1ll*now*now;
}val[i][j]=sum;
}memset(f,120,sizeof(f));
for(i=1;i<=k;i++)f[1<<i-1][i]=0;
for(i=1;i<(1<<k);i++)
for(j=1;j<=k;j++){
if(!(i&(1<<j-1)))continue;
for(h=1;h<=k;h++){
if(i&(1<<h-1))continue;
int nxt=i+(1<<h-1);
if(f[i][j]+val[j][h]<f[nxt][h])
f[nxt][h]=f[i][j]+val[j][h],pre[nxt][h]=j;
}
}Min=1;
for(i=2;i<=k;i++)
if(f[(1<<k)-1][i]<f[(1<<k)-1][Min])Min=i;
for(i=k,j=(1<<k)-1;i;i--){
ans[Min]=i;j-=(1<<(Min-1));
Min=pre[j+(1<<(Min-1))][Min];
}for(i=1;i<=k;i++)printf("%d ",ans[i]);putchar(10);
}return 0;
}