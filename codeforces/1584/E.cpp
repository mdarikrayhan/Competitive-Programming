// LUOGU_RID: 160449696
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5 + 10 , INF = 1e9;
int n , a[N]; ll c[2][N] , b[N];
int top , stk[N] , nxt[4][N];
vector<int>vc[2][N];
int Solve()
{
	cin >> n;
	for(int i = 1 ; i <= n ; i++)
		cin >> a[i];
	for(int k : {0 , 1})
	{
		memset(c[k] , 0 , sizeof(ll) * (n + 3));
		for(int i = 1 ; i <= n ; i++)
			c[k][i] = c[k][i - 1] + ((i & 1) == k ? 1 : -1) * a[i];
		memcpy(b + 1 , c[k] , sizeof(ll) * (n + 1));
		sort(b + 1 , b + n + 2);
		int m = unique(b + 1 , b + n + 2) - b - 1;
		// for(int i = 0 ; i <= n ; i++)cerr << c[k][i] << " \n"[i == n];
		for(int i = 1 ; i <= m ; i++)vc[k][i].clear();
		for(int i = 0 ; i <= n ; i++)
		{
			c[k][i] = lower_bound(b + 1 , b + m + 1 , c[k][i]) - b;
			if((i & 1) == k)vc[k][c[k][i]].push_back(i);
		}
		for(int tt : {1 , 2})
		{
			int st = k << 1 | (tt - 1);
			memset(nxt[st] , 0 , sizeof(int) * (n + 3));
			for(int kk : {0 , 1})
			{
				stk[top = 1] = n + 2;
				for(int i = n + kk ; i >= tt ; i -= 2)
				{
					while(top && c[k][i] <= c[k][stk[top]])top--;
					stk[++top] = i;
					int l = 1 , r = top;
					while(l < r)
					{
						int mid = (l + r + 1) >> 1;
						if(c[k][stk[mid]] < c[k][i - tt])
							l = mid;
						else r = mid - 1;
					}
					nxt[st][i - tt] = stk[l];
				}
			}
		}
		// for(int i = 0 ; i <= n ; i++)cerr << c[k][i] << " \n"[i == n];
		// for(int i = 0 ; i <= n ; i++)cerr << nxt[k << 1][i] << " \n"[i == n];
		// for(int i = 0 ; i <= n ; i++)cerr << nxt[k << 1 | 1][i] << " \n"[i == n];
		// cerr << "\n";
	}
	ll ans = 0;
	auto qry = [&](vector<int>&vc , int be , int ed)
	{
		// cerr << "\tqry {";
		// for(int x : vc)cerr << x << ',';
		// cerr << "} [" << be << ',' << ed << ")\n";
		auto itl = lower_bound(vc.begin() , vc.end() , be);
		auto itr = lower_bound(vc.begin() , vc.end() , ed);
		return itr - itl;
	};
	for(int l = 1 ; l <= n ; l++)
	{
		int bit = l & 1 , rbit = bit ^ 1 , tmp = ans;
		int r = min(nxt[bit << 1][l - 1] , nxt[rbit << 1 | 1][l - 1]);
		ans += qry(vc[bit][c[bit][l - 1]] , l , r);
		ans += qry(vc[rbit][c[rbit][l - 1]] , l , r);
		// cerr << l << "," << r << ":" << ans - tmp << "\n";
	} 
	cout << ans << "\n";
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