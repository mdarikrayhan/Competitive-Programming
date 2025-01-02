#include <bits/stdc++.h>

using namespace std;

#define int long long 
typedef pair<int, int> pii;

const int MOD = 998244353;
const int N = 2e5 + 10;

int n;
pii a[N], b[N];
set<pii> se;
map<pii, pii> ma;

int get_dis(pii a, pii b)
{
	return abs(a.first - b.first) + abs(a.second - b.second);
}
void judge(int x, int y, int idx)
{
	if(!se.count({x, y})) 
	{
		if(get_dis({x, y}, a[idx]) < get_dis(ma[a[idx]], a[idx])) ma[a[idx]] = {x, y};
	}
	else if(get_dis(ma[{x, y}], a[idx]) < get_dis(ma[a[idx]], a[idx])) ma[a[idx]] = ma[{x, y}];
}
void solve()
{
	cin >> n;
	for(int i = 0; i < n; i ++) cin >> a[i].first >> a[i].second, b[i] = a[i], se.insert(a[i]), ma[a[i]] = {1e9, 1e9};
	
	sort(a, a + n);

	for(int i = 0; i < n; i ++)
	{
		judge(a[i].first - 1, a[i].second, i);
		judge(a[i].first, a[i].second - 1, i);
		judge(a[i].first - 1, a[i].second - 1, i);
		judge(a[i].first - 1, a[i].second + 1, i);
	}	
	
	for(int i = n - 1; i >= 0; i --)
	{
		judge(a[i].first, a[i].second + 1, i);
		judge(a[i].first + 1, a[i].second + 1, i);
		judge(a[i].first + 1, a[i].second, i);
		judge(a[i].first + 1, a[i].second - 1, i);
	}
	
	for(int i = 0; i < n; i ++) cout << ma[b[i]].first << " " << ma[b[i]].second << "\n";
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	solve();
	
	return 0;
}