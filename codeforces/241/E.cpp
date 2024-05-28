// LUOGU_RID: 159449805
//洛谷 P5590
//https://www.luogu.com.cn/problem/P5590
#include<bits/stdc++.h>
#define P pair<int,int>
#define fi first
#define se second
#define LL long long
#define fr(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);
using namespace std;
const int N=5005;
int n,m,in[N],d[N],w[N];bool v[N],O[N],V[2][N];
vector<P>g[N];basic_string<int>G[N];queue<int>q;
P e[N];
inline bool spfa(int s)
{
	memset(d,0x3f,sizeof(d));d[s]=0;in[s]=v[s]=1;q.push(s);
	while(!q.empty())
	{
		int t=q.front();q.pop();v[t]=0;
		for(auto [to,w]:g[t]) if(d[to]>d[t]+w)
		{
			d[to]=d[t]+w;
			if(!v[to])
			{
				in[to]++;v[to]=1;q.push(to);
				if(in[to]==n+1) return 0;
			}
		}
	}return 1;
}
inline void tp(int s,bool *V)
{
	V[s]=1;q.push(s);
	while(!q.empty())
	{
		int t=q.front();q.pop();
		for(int i:G[t]) if(!V[i]) V[i]=1,q.push(i);
	}
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);cin>>n>>m;
	for(int i=1,u,v;i<=m;i++) cin>>u>>v,e[i]={u,v},G[u]+=v;tp(1,V[0]);
	if(!V[0][n]) return cout<<"No",0;
	for(int i=1;i<=n;i++) G[i].clear();
	for(int i=1;i<=m;i++) G[e[i].se]+=e[i].fi;tp(n,V[1]);
	for(int i=1;i<=n;i++) O[i]=V[0][i]&V[1][i];
	for(int i=1;i<=n;i++) if(O[i]) g[0].emplace_back(i,0);
	for(int i=1;i<=m;i++)
	{
		auto [u,v]=e[i];
		if(O[u]&&O[v]) g[u].push_back({v,2}),g[v].push_back({u,-1});
	}
	if(spfa(0))
	{
		cout<<"Yes\n";
		for(int i=1;i<=m;i++)
		{
			auto [u,v]=e[i];
			if(O[u]&&O[v]) cout<<d[v]-d[u]<<"\n";
			else cout<<"1\n";
		}
	}
	else cout<<"No";
	return 0;
}