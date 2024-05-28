#include <bits/stdc++.h>
using namespace std;
int q, op, l, r, k, pre;
map<int, int> f, v;
int find(int x)
{
	int t;
	return f.count(x) ? (t = find(f[x]), v[x] ^= v[f[x]], f[x] = t) : x;
}
int main()
{
	ios::sync_with_stdio(0);
	for (cin >> q; q--;)
	{
		if (cin >> op >> l >> r, l ^= pre, r ^= pre, l > r && (swap(l, r), 1), op & 1)
		{
			cin >> k, k ^= pre;
			int fx = find(l - 1), fy = find(r);
			if (fx ^ fy)
				f[fx] = fy, v[fx] = k ^ v[l - 1] ^ v[r];
		}
		else
		{
			int fx = find(l - 1), fy = find(r);
			cout << (fx ^ fy ? (pre = 1, -1) : (pre = v[l - 1] ^ v[r])) << "\n";
		}
	}
}