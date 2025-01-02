#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define int long long
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	/*
	haave t1, t2, y1, t find t2

	ty1 + ty2 <= t1y1 + t2y2
	ty1 - t1y1 <= t2y2 - ty2
	(ty1 - t1y1) / (t2 - t) <= y2
	*/
	int t1, t2, x1, x2, t;
	cin >> t1 >> t2 >> x1 >> x2 >> t;
	if (t1 == t)
	{
		if (t2 == t)
		{
			cout << x1 << ' ' << x2;
			return 0;
		}
		cout << x1 << ' ' << 0;
		return 0;
	}
	else if (t2 == t)
	{
		cout << 0 << ' ' << x2;
		return 0;
	}
	int fans = 2e12, sans = 1, q = 0, w = 0;
	for (int y1 = 0; y1 <= x1; y1++)
	{
		int f = t * y1 - t1 * y1;
		int s = t2 - t;
		int y2 = (f + s - 1) / s;
		if (y2 > x2) continue;
		if ((t1 * y1 + t2 * y2) * sans < fans * (y1 + y2))
		{
			fans = t1 * y1 + t2 * y2;
			sans = y1 + y2;
			q = y1, w = y2;
		}
		else if ((t1 * y1 + t2 * y2) * sans == fans * (y1 + y2) && q + w < y1 + y2)
		{
			q = y1, w = y2;
		}
	}
	for (int y2 = 0; y2 <= x2; y2++)
	{
		int f = y2 * (t2 - t);
		int s = t - t1;
		int y1 = f / s;
		if (y1 > x1) continue;
		if ((t1 * y1 + t2 * y2) * sans < fans * (y1 + y2))
		{
			fans = t1 * y1 + t2 * y2;
			sans = y1 + y2;
			q = y1, w = y2;
		}
		else if ((t1 * y1 + t2 * y2) * sans == fans * (y1 + y2) && q + w < y1 + y2)
		{
			q = y1, w = y2;
		}
	}
	cout << q << ' ' << w;
	return 0;
}