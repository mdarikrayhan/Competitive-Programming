#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 200005
#define M 6000005
#define inf 1000000005
#define ll long long
using namespace std;
int n,f[N],cnt,Rt,nod;ll len[N],Ans;
int ID[M],vis[M],ls[M],rs[M];ll sum[M];
struct T
{
int x1,y1,y2,id,tp;
}a[N*2];
bool cmp(T a,T b)
{
return a.x1==b.x1?a.tp<b.tp:a.x1<b.x1;
}
int Get(int x)
{
return f[x]==x?x:f[x]=Get(f[x]);
}
void add(int&k,int l,int r,int u,int id,int v)
{
if(!k)k=++nod;
vis[k]=0;
if(l==r)
{
ID[k]=id;
sum[k]=v;
return;
}
int mid=l+(r-l)/2;
if(u<=mid)add(ls[k],l,mid,u,id,v);
else add(rs[k],mid+1,r,u,id,v);
sum[k]=sum[ls[k]]+sum[rs[k]];
ID[k]=max(ID[ls[k]],ID[rs[k]]);
}
void work(int k,int id)
{
if(!k||vis[k])return;
vis[k]=1;
if(ID[ls[k]]&&ID[rs[k]])
f[Get(ID[ls[k]])]=Get(ID[rs[k]]);
work(ls[k],id);
work(rs[k],id);
}
ll qry(int k,int l,int r,int u,int v,int id)
{
if((!k)||(!ID[k]))return 0;
if(u<=l&&r<=v)
{

f[Get(ID[k])]=id;
work(k,id);
return sum[k];
}
int mid=l+(r-l)/2;ll ans=0;
if(u<=mid)ans+=qry(ls[k],l,mid,u,v,id);
if(v>mid)ans+=qry(rs[k],mid+1,r,u,v,id);
return ans;
}
int main()
{
scanf("%d",&n);
for(int i=1;i<=n;i++)
{
int x1,y1,x2,y2;
scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
if(x1==x2)
{
a[++cnt]=(T){x1,y1,y2,i,2};
}
else 
{
len[i]=x2-x1+1;
a[++cnt]=(T){x1,y1,0,i,1};
a[++cnt]=(T){x2,y1,0,i,3};
}
}
for(int i=1;i<=n;i++)f[i]=i;
sort(a+1,a+cnt+1,cmp);
for(int i=1;i<=cnt;i++)
{
if(a[i].tp==2)len[a[i].id]=a[i].y2-a[i].y1+1-qry(Rt,-inf,inf,a[i].y1,a[i].y2,a[i].id);
else if(a[i].tp==1)add(Rt,-inf,inf,a[i].y1,a[i].id,1);
else add(Rt,-inf,inf,a[i].y1,0,0);
}
for(int i=1;i<=n;i++)
if(Get(i)!=i)len[Get(i)]+=len[i];

for(int i=1;i<=n;i++)
Ans=max(Ans,len[i]);
printf("%lld\n",Ans-1);
}