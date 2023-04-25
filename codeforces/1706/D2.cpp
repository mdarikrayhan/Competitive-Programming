#include<bits/stdc++.h>
using namespace std;const int N=1e5+7;
int T_T,n,i,j,k,x,l,r,ans,a[N],f[N];
int main(){
for(scanf("%d",&T_T);T_T--;){
for(scanf("%d%d",&n,&k),ans=N,i=1;i<=n;++i)scanf("%d",a+i);
for(i=0;i<=a[1];++i)f[i]=-1;
for(i=1;i<=n;++i)for(x=a[i],l=1,r=0;l<=x;l=r+1)r=x/(x/l),f[l]=max(f[l],x/min(x/l,k));
for(i=1;i<=a[1];++i)f[i]=max(f[i-1],f[i]),ans=min(ans,f[i]-i);printf("%d\n",ans);
}
}