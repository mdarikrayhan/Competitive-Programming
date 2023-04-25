#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=1005,inf=1e9;
int n,m;
int a[N],f[N][M];
vector<int> p[N],v[N];
void init()
{
for(int i=1;i<M;i++)
for(int j=1;j<M;j++)
if(i%j==0)p[i].push_back(j);
}
void dfs(int x,int fa)
{
for(auto i:p[a[x]])f[x][i]=0;
for(auto y:v[x])
{
if(y==fa)continue;
dfs(y,x);
for(auto i:p[a[x]])
{
int mn=inf;
for(auto j:p[a[y]])if(j*j%i==0)mn=min(mn,f[y][j]+(j%i!=0));
if(mn!=inf)f[x][i]+=mn;
else f[x][i]=inf;
}
}
}
void clear()
{
for(int i=1;i<=n;i++)v[i].clear();
for(int i=1;i<=n;i++)
for(int j=1;j<M;j++)f[i][j]=inf;
}
int main()
{
int cas,x,y;
init();
scanf("%d",&cas);
while(cas--)
{
scanf("%d %d",&n,&m);clear();
for(int i=1;i<=n;i++)scanf("%d",&a[i]);
for(int i=1;i<n;i++)scanf("%d %d",&x,&y),v[x].push_back(y),v[y].push_back(x);
dfs(1,0);
int ans=a[1];
for(auto i:p[a[1]])if(f[1][i]+1<=m)ans=max(ans,a[1]*i);
cout<<ans<<"\n";
}
return 0;
}