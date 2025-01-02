#include<bits/stdc++.h>
#define Alex ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define LD long double
#define int long long
using namespace std;
const int QAQ = 0;
const int base = 131;
const int mod = 998244353;
const double eps = 1e-10;
const int N = 2e6+10;
struct Edge{
	int v1,v2,v3,v4;
};
int n;
vector<int> G[200005];
vector<Edge> Ans;
inline int dfs(int u,int fa)
{
	int ch = 0;
	int Next = u;
	for(auto v : G[u])
	{
		if(v == fa) continue;
		int ans = dfs(v,u);
		if(ans < 0) continue;
		ch++;
		if(ch == 1) Next = ans;
		else if(ch == 2) Ans.push_back({fa,u,Next,ans}),Next = -1;
		else Ans.push_back({u,v,v,ans});
	}
	return Next;
}
signed main()
{
	Alex;
	int _;
	cin>>_;
	while(_--)
	{
		cin>>n;
		for(int i = 1;i <= n - 1;i++)
		{
			int u,v;
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		int rt = 1;
		for(int i = 1;i <= n;i++)
		{
			if(G[i].size() == 1)
			{
				rt = i;
				break;
			}
		}
		int to = dfs(rt,-1);
		cout<<Ans.size()<<'\n';
		for(Edge i : Ans)
		{
			cout<<i.v1<<' '<<i.v2<<' '<<to<<' '<<i.v3<<'\n';
			to = i.v4;
		}
		for(int i = 1;i <= n;i++) G[i].clear();
		Ans.clear();
    }
    return QAQ;
}  

