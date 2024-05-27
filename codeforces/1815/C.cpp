// LUOGU_RID: 160394088
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1505;
int n , m , d[N];
vector<int>g[N] , vc[N];
int Solve()
{
	cin >> n >> m;
	memset(d , 0 , sizeof(int) * (n + 1));
	for(int i = 1 ; i <= n ; i++)
		g[i].clear() , vc[i].clear();
	for(int i = 1 ; i <= m ; i++)
	{
		int u , v; cin >> v >> u;
		g[u].push_back(v);
	}
	queue<int>q;
	q.push(d[1] = 1);
	while(!q.empty())
	{
		int u = q.front(); q.pop();
		for(int v : g[u])
			if(!d[v])d[v] = d[u] + 1 , q.push(v);
	}
	if(count(d + 1 , d + n + 1 , 0))
	{
		cout << "INFINITE\n";
		return 0;
	}
	for(int i = 1 ; i <= n ; i++)
		vc[d[i]].push_back(i);
	cout << "FINITE\n" << accumulate(d + 1 , d + n + 1 , 0) << "\n";
	int mx = *max_element(d + 1 , d + n + 1);
	for(int i = mx ; i >= 1 ; i--)
		for(int j = i ; j <= mx ; j++)
			for(int u : vc[j])cout << u << " ";
	cout << "\n";
	return 0;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0) , cout.tie(0);
	int T; cin >> T;
	while(T--)Solve();
	return 0;
}