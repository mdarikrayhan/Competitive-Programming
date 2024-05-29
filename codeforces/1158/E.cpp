// Nothing is Given, Everything is Earned.
#include<bits/stdc++.h>
using namespace std;
#define Time() chrono::steady_clock::now().time_since_epoch().count()
mt19937 seed(Time());
int main()
{
int n; scanf("%d",&n);

auto ask=[&](auto d)
{
printf("?");
for(int x:d) printf(" %d",x);
printf("\n"); fflush(stdout);

vector<int> res(n);
for(int i=0;i<n;i++) scanf("%1d",&res[i]);
return res;
};

vector adj(n,vector(n,1)); vector ok(n,1);
while(count(ok.begin(),ok.end(),1))
{
vector<int> p;
for(int i=0;i<n;i++)
{
if(ok[i]) p.push_back(i);
}
shuffle(p.begin(),p.end(),seed);
p.resize(max<int>(1,p.size()/5));
vector<int> d(n);
for(int u:p) d[u]=1;
auto res=ask(d);
for(int u=0;u<n;u++)
{
for(int v=0;v<n;v++) if(d[u] && !res[v])
adj[u][v]=adj[v][u]=0;
}
vector<int> fa(n),dep(n,-1),val(n);
auto dfs=[&](auto self,int u) -> void
{
for(int v=0;v<n;v++) if(u!=v && adj[u][v])
{
if(!~dep[v])
{
fa[v]=u, dep[v]=dep[u]+1;
self(self,v), val[u] += val[v];
}
else if(dep[v]<dep[u]-1)
{
val[u]++;
if(v) val[fa[v]]--;
}
}
if(!val[u]) ok[u]=0;
};
dfs(dfs,dep[0]=0);
}
printf("!\n");
for(int i=0;i<n;i++)
for(int j=i+1;j<n;j++)
if(adj[i][j]) printf("%d %d\n",i+1,j+1);
fflush(stdout);
return 0;
}
