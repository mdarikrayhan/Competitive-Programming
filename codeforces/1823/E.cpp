// LUOGU_RID: 160099250
#include<bits/stdc++.h>
using namespace std;
const int NN=2e5+4;
bool vis[NN];
int cnt;
vector<int>g[NN];
void dfs(int u)
{
	cnt++;
	vis[u]=true;
	for(int i=0;i<g[u].size();i++)
		if(!vis[g[u][i]])
			dfs(g[u][i]);
}
int main()
{
	int n,l,r,res=0;
	scanf("%d%d%d",&n,&l,&r);
	for(int i=1;i<=n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			cnt=0;
			dfs(i);
			if(cnt<l+r)
				res^=cnt/l;
		}
	printf(res?"Alice":"Bob");
	return 0;
}