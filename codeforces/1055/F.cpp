#include <bits/stdc++.h>
#define F for (j = 1; j <= n; ++j)
using namespace std;
enum
{
	N = 1000001
};
int i, j, bt, n, u, o, e, a[N], b[N], ch[N][2], siz[N];
long long w, sum, ans, k, s[N];
main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> k;
	a[1] = b[1] = 1;
	for (i = 2; i <= n; ++i)
		cin >> u >> w, s[i] = s[u] ^ w, a[i] = b[i] = 1;
	for (i = 61; ~i; --i)
	{
		sum = e = 0;
		F ch[j][0] = ch[j][1] = siz[j] = 0;
		F
		{
			int &p = a[j], &np = ch[p][s[j] >> i & 1];
			++siz[p = np ? np : np = ++e];
		}
		F sum += siz[ch[b[j]][s[j] >> i & 1]];
		sum < k ? (k -= sum, o = 1, ans += 1ll << i) : o = 0;
		F b[j] = ch[b[j]][(s[j] >> i & 1) ^ o];
	}
	cout << ans;
}