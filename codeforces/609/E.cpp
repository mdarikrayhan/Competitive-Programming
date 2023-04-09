#include<bits/stdc++.h>
using namespace std;
#define N 200001
#define LL long long
struct rua{LL u,v,w,id;}a[N];
LL n,m,mst,fa[N],f[N],sz[N],l[N];
bool cmp(rua x,rua y){return x.w<y.w;}
LL add(LL u,LL v,LL w)
{
LL mx=0;
while((fa[u]!=u||fa[v]!=v)&&u!=v)
if(fa[u]==u||(fa[v]!=v&&sz[v]<=sz[u]))
mx=max(mx,l[v]),v=fa[v];
else mx=max(mx,l[u]),u=fa[u];
if(u==v)return w-mx;
if(sz[u]<sz[v])swap(u,v);
sz[u]+=sz[v],fa[v]=u,l[v]=w;
return mst+=w,0;
}
int main()
{
scanf("%I64d%I64d",&n,&m);
for(int i=1;i<=m;i++)
scanf("%I64d%I64d%I64d",&a[i].u,&a[i].v,&a[i].w),sz[i]=1,fa[i]=a[i].id=i;
sort(a+1,a+m+1,cmp);
for(int i=1;i<=m;i++)
f[a[i].id]=add(a[i].u,a[i].v,a[i].w);
for(int i=1;i<=m;i++)
printf("%I64d\n",mst+f[i]);
}
