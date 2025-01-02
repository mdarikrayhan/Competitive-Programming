// LUOGU_RID: 160385651
#include<bits/stdc++.h>
#define fir first
#define sec second
#define all(x) begin(x),end(x)
using namespace std;
typedef long long ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair<int,int> pii;
template<typename type>
inline void chmin(type &x,const type &y)
{
	if(y<x)
		x=y;
}
template<typename type>
inline void chmax(type &x,const type &y)
{
	if(x<y)
		x=y;
}
constexpr int Max=5010;
int n;
vector<int>e[Max];
int d[Max],ans[Max];
void bfs(int S)
{
	memset(d,-1,sizeof(d));
	d[S]=0;
	queue<int>q;
	q.push(S);
	int i=0,s=0;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		++i,s+=d[u];
		chmax(ans[i],i*(n-1)-s*2);
		for(auto v:e[u])
			if(!~d[v])
				d[v]=d[u]+1,q.push(v);
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n;
	for(int i=1,u,v;i<n;++i)
		cin>>u>>v,e[u].push_back(v),e[v].push_back(u);
	for(int i=1;i<=n;++i)
		bfs(i);
	for(int i=0;i<=n;++i)
		cout<<ans[i]<<" \n"[i==n];
	return 0;
}