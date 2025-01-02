#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define F first
#define S second
#define All(x) (x).begin(),(x).end()
#define len(x) (int)(x).size()
#define pb push_back
mt19937 rnd(time(0));

const int N = 1e5 + 7, H = 29, P = 1e9 + 7;
int hsh[N], rhsh[N], pwr[N], w[26];
int n, pal[N], mx[N];
pii seg[N << 2][2];
string s;

int get_hsh(int l, int r) {
	return (hsh[r] - 1LL * hsh[l] * pwr[r - l] % P + P) % P;
}

int get_rhsh(int l, int r) {
	return (rhsh[l] - 1LL * rhsh[r] * pwr[r - l] % P + P) % P;
}

void prepare() {
	for (int i = 0; i < n; i++) {
		int l = 0, r = min(i, n - i - 1) + 1;
		while (r - l > 1) {
			int mid = (l + r) >> 1;
			if (get_hsh(i - mid, i) == get_rhsh(i + 1, i + 1 + mid))
				l = mid;
			else
				r = mid;
		}
		pal[i] = l;
	}
	for (int i = 0; i < n; i++) {
		int l = 0, r = n - i + 1;
		while (r - l > 1) {
			int mid = (l + r) >> 1;
			if (get_hsh(i, i + mid) == get_rhsh(n - mid, n))
				l = mid;
			else
				r = mid;
		}
		mx[i] = l;
	}
}

void build(int id = 1, int st = 0, int en = n) {
	if (en - st == 1) {
		seg[id][0] = pii(pal[st], st);
		seg[id][1] = pii(mx[st], st);
		return;
	}
	int mid = (st + en) >> 1;
	build(id << 1, st, mid);
	build(id << 1 | 1, mid, en);
	seg[id][0] = max(seg[id << 1][0], seg[id << 1 | 1][0]);
	seg[id][1] = max(seg[id << 1][1], seg[id << 1 | 1][1]);
}

pii get(int l, int r, int id = 1, int st = 0, int en = n) {
	if (r <= st || l >= en)
		return pii(-1, -1);
	if (st >= l && en <= r)
		return seg[id][0];
	int mid = (st + en) >> 1;
	return max(get(l, r, id << 1, st, mid), get(l, r, id << 1 | 1, mid, en));
}

int find(int x, int id = 1, int st = 0, int en = n) {
	if (seg[id][1].F < x)
		return -1;
	if (en - st == 1)
		return st;
	int mid = (st + en) >> 1;
	if (seg[id << 1][1].F >= x)
		return find(x, id << 1, st, mid);
	return find(x, id << 1 | 1, mid, en);
}

pii solve(int l, int r) {
	int L = 0, R = n;
	while (R - L > 1) {
		int mid = (L + R) >> 1;
		if (2 * mid + 1 > r - l + 1 || r - mid < l + mid)
			R = mid;
		else {
			pii p = get(l + mid, r - mid + 1);
			if (p.F >= mid)
				L = mid;
			else
				R = mid;
		}
	}
	pii p = get(l + L, r - L + 1);
	return pii(L, p.S);
}

int32_t main() {
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> s;
	n = len(s);
	for (int i = pwr[0] = 1; i < N; i++)
		pwr[i] = 1LL * H * pwr[i - 1] % P;
	iota(w, w + 26, 1);
	for (int i = 0; i < 26; i++)
		swap(w[i], w[rnd() % (i + 1)]);
	for (int i = 0; i < n; i++) 
		hsh[i + 1] = (1LL * hsh[i] * H % P + w[s[i] - 'a']) % P;
	for (int i = n - 1; i >= 0; i--)
		rhsh[i] = (1LL * rhsh[i + 1] * H % P + w[s[i] - 'a']) % P;
	prepare();
	int ans = *max_element(pal, pal + n);
	vector<pii> res;
	for (int i = 0; i < n; i++)
		if (pal[i] == ans) {
			res.pb({i - pal[i], 2 * pal[i] + 1});
			break;
		}
	ans = 2 * ans + 1;
	build();
	for (int i = n - 1; i >= 0; i--) {
		int x = n - i;
		int l = find(x);
		if (l == -1 || i - l - x <= 0)
			continue;
		int l2 = l + x;
		pii p = solve(l2, i - 1);
	//	cout << x << ' ' << i + 1 << ' ' << l + 1 << ' ' << l2 + 1 << ' ' << i << ' ' << 2 * p.F + 1 << '\n';
		if (2 * p.F + 1 + 2 * x > ans) {
			res.clear();
			res.pb({l, x});
			res.pb({p.S - p.F, 2 * p.F + 1});
			res.pb({i, x});
			ans = 2 * p.F + 1 + 2 * x;
		}
	}
	//cout << ans << '\n';
	cout << len(res) << '\n';
	for (auto [a, b]: res)
		cout << a + 1 << ' ' << b << '\n';

	return 0;
}
