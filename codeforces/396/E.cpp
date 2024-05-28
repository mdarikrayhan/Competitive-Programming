#include<cstdio>
#define min(u,v) (u)<(v)?(u):(v)
int n,ans,l,x,j,i,f[1111111],flag,p[1111111]; 
long long c[1111111],k[1111111],y,q[1111111];
int main(){
for(i=2;i<=1000000;i++){if(!f[i])f[i]=i,p[++l]=i;for(j=1;p[j]<=f[i]&&p[j]*i<=1000000&&j<=l;j++)f[p[j]*i]=p[j];}
scanf("%d",&n);for(i=1;i<=n;i++)scanf("%d",&x),scanf("%I64d",c+x);scanf("%I64d",&y);for(i=1;i<=l;i++)k[p[i]]=y;
for(;;){flag=0;for(i=1;i<=l;i++)if(c[j=p[i]]){if(!k[j])continue;long long t=min(k[j],c[j]);k[j]-=t;c[j]-=t;flag=1;q[j]+=t-1;
for(j--;j>1;j/=f[j])c[f[j]]+=t;}else if(q[j])q[j]--;else if(k[j])k[j]--;if(!flag)break;}
for(i=1;i<=l;i++)ans+=c[p[i]]>0;printf("%d\n",ans);for(i=1;i<=l;i++)if(c[p[i]])printf("%d %I64d\n",p[i],c[p[i]]);}