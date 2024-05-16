// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int16_t solve()
{
	pair<int16_t,int16_t> mini = {-1,200}, maxi = {-1,-1};
	int n; cin >> n;
	for (int16_t i = 1; i <= n; ++i)
	{
		int16_t x; cin >> x;
		if (x < mini.second)
		{
			mini.first = i;
			mini.second = x;
		}
		if (x > maxi.second)
		{
			maxi.first = i;
			maxi.second = x;
		}
	}
	int16_t aa = max(maxi.first,mini.first), bb = n - min(maxi.first,mini.first) + 1, cc = mini.first + n - maxi.first + 1, dd = maxi.first + n - mini.first + 1;
	return min(min(aa,bb),min(cc,dd));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL), cout.tie(NULL);
	int t; cin >> t;
	while (t--)
		cout << solve() << '\n';
	return 0;
}
