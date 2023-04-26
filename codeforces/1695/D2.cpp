#include<cstdio>
#include<vector>
const int N=2e5+7;
std::vector<int> to[N];
bool vis[N];
int dfs(int i,int l)
{
if(to[i].size()>2)return i;
for(int v:to[i])if(v!=l)return dfs(v,i);
return i;
}
int main()
{
int T,n,u,v,ans;
scanf("%d",&T);
while(T--)
{
ans=0;
scanf("%d",&n);
for(int i=1;i<=n;++i)to[i].clear();
for(int i=1;i<n;++i)
scanf("%d%d",&u,&v),
to[u].push_back(v),
to[v].push_back(u);
for(int i=1;i<=n;++i)if(to[i].size()==1)vis[dfs(i,0)]=1,++ans;
for(int i=1;i<=n;++i)if(vis[i])vis[i]=0,--ans;
printf("%d\n",n==1?0:(ans?ans:1));
}
return 0;
}