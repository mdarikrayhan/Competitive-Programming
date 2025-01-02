// LUOGU_RID: 160106116
#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int n, m;
int a[N], bl[N], f[N];
vector<int> v[N];
int find (int k) {return f[k] == k ? k : f[k] = find(f[k]);}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1, x; i <= n; i++)
	{
		cin >> x, bl[i] = x;
		f[x] = x;
	}
	int ans = n - 1;
	for(int i = 1; i <= n; i++)
	{
		if(find(bl[i]) == find(bl[i - 1])) ans--;
		v[bl[i]].push_back(i);
	}
	cout << ans << '\n';
	for(int i = 1; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		x = find(x); y = find(y);
		if(v[x].size() < v[y].size()) swap(x, y);
		for(int num : v[y])
		{
			if(find(bl[num + 1]) == x) ans--;
			if(find(bl[num - 1]) == x) ans--;
		}
		for(int num : v[y]) v[x].push_back(num);
		f[y] = x;
		cout << ans << '\n';
	}
	return 0;
}