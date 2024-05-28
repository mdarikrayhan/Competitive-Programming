// LUOGU_RID: 159929735
#include <bits/stdc++.h>

typedef long long ll;

const int MAX = 1e5 + 5;

int n, k, x, y; ll ans;
bool tg[MAX << 3];
int sm[MAX << 3], s[MAX];
std::vector <int> v[MAX];

void pu(int x) { sm[x] = sm[x << 1] + sm[x << 1 | 1]; }
void pd(int l, int r, int x)
{
	if (!tg[x]) { return ; }
	tg[x] = false; tg[x << 1] ^= 1; tg[x << 1 | 1] ^= 1;
	int k = l + ((r - l) >> 1);
	sm[x << 1] = k - l + 1 - sm[x << 1];
	sm[x << 1 | 1] = r - k - sm[x << 1 | 1];
}

void mdf(int l, int r, int s, int t, int x)
{
	if (l >= s and r <= t) { tg[x] ^= 1; sm[x] = r - l + 1 - sm[x]; return ; }
	int k = l + ((r - l) >> 1); pd(l, r, x);
	if (s <= k) { mdf(l, k, s, t, x << 1); }
	if (t >  k) { mdf(k + 1, r, s, t, x << 1 | 1); }
	pu(x);
}

ll qry(int l, int r, int s, int t, int x)
{
	if (l >= s and r <= t) { return sm[x]; }
	int k = l + ((r - l) >> 1); pd(l, r, x); ll res = 0;
	if (s <= k) { res += qry(l, k, s, t, x << 1); }
	if (t >  k) { res += qry(k + 1, r, s, t, x << 1 | 1); }
	pu(x); return res;
}

int main()
{
	scanf("%d%d", &n, &k); ans = 1ll * n * (n - 1) * (n - 2) / 6ll;
	for (int i = 1; i <= n; ++i) { scanf("%d", &s[i]); }
	std::sort(s + 1, s + n + 1);
	for (int i = 1; i <= k; ++i)
	{
		scanf("%d%d", &x, &y);
		int l = std::lower_bound(s + 1, s + n + 1, x) - s,
		    r = std::upper_bound(s + 1, s + n + 1, y) - s - 1;
        if (l > r) { continue; }
		v[l].push_back(r); v[r + 1].push_back(l);
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j : v[i]) { if (i <= j) { mdf(1, n, i, j, 1); } else { mdf(1, n, j, i - 1, 1); } }
		ll x = i - 1;
		if (i > 1) { x -= qry(1, n, 1, i - 1, 1); }
		if (i < n) { x += qry(1, n, i + 1, n, 1); }
		ans -= x * (x - 1) / 2; 
	}
	printf("%lld", ans);
}