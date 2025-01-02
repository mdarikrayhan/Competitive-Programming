#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int n, q, ty, l, r, val, ans, ans1, block, bl, bl_l, bl_r, cnt[320][N + 5];
deque<int> dq[320];
int change(int x)
{
	return (x + ans - 1) % n + 1;
}
bool same(int l, int r)
{
	return l / block == r / block;
}
void update(int l, int r)
{
	// cout << l << ' ' << r << ' ' << block << "\n";
	if (same(l, r))
	{
		bl = l / block;
		l %= block, r %= block;
		dq[bl].insert(dq[bl].begin() + l, dq[bl][r]);
		dq[bl].erase(dq[bl].begin() + r + 1);
		return;
	}
	bl_l = l / block, bl_r = r / block;
	l %= block, r %= block;
	++cnt[bl_l][dq[bl_r][r]];
	dq[bl_l].insert(dq[bl_l].begin() + l, dq[bl_r][r]);
	for (int i = bl_l + 1; i <= bl_r; i++)
	{
		++cnt[i][*prev(dq[i - 1].end())];
		dq[i].insert(dq[i].begin(), *prev(dq[i - 1].end()));
		--cnt[i - 1][*prev(dq[i - 1].end())];
		dq[i - 1].pop_back();
	}
	--cnt[bl_r][dq[bl_r][r + 1]];
	dq[bl_r].erase(dq[bl_r].begin() + r + 1);
}
int query(int l, int r, int val)
{
	if (same(l, r))
	{
		ans1 = 0, bl = l / block;
		l %= block, r %= block;
		for (int i = l; i <= r; i++)
			ans1 += dq[bl][i] == val;
		return ans = ans1;
	}
	ans1 = 0, bl_l = l / block, bl_r = r / block;
	l %= block, r %= block;
	for (int i = l; i < dq[bl_l].size(); i++)
		ans1 += dq[bl_l][i] == val;
	for (int i = r; i >= 0; i--)
		ans1 += dq[bl_r][i] == val;
	for (int i = bl_l + 1; i < bl_r; i++)
		ans1 += cnt[i][val];
	return ans = ans1;
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	block = sqrt(n);
	for (int i = 0; i < n; i++)
	{
		cin >> val;
		dq[i / block].push_back(val);
		cnt[i / block][val]++;
	}
	cin >> q;
	while (q--)
	{
		cin >> ty >> l >> r;
		l = change(l);
		r = change(r);
		if (l > r)
			swap(l, r);
		// cout << l << ' ' << r << "\n";
		if (ty == 1)
			update(l - 1, r - 1);
		else
		{
			cin >> val;
			val = change(val);
			cout << query(l - 1, r - 1, val) << "\n";
		}
	}
	return 0;
}