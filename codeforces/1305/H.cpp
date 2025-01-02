// learned from https://www.luogu.com.cn/article/j8bifm1x
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5, mod = 1e9 + 7, inf = 0x3f3f3f3f;

void gg() {
  cout << "-1 -1";
  exit(0);
}

int n, m, t, q;
struct Problem {
  int l, r;
} a[maxn];
int val[maxn];
struct Student {
  int p, s;
} b[maxn];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int s1[maxn], s2[maxn], S[maxn];
int c[maxn], d[maxn];

int num, mx, bmx;
bool check(int mid) {
  int kk = -1;
  for (int i = 1; i <= mid; i++) {
    if (d[i] != -1) {
      if (kk == -1) kk = d[i];
      if (d[i] != kk) return 0;
    }
  }
	
  int res = n;
  for (int i = 1; i <= mid; i++) res = min(res, (int)floor(1.0 * S[i] / i));
  if (kk > res) return 0;
  if (kk != -1) res = kk;
  int cursum = res * mid, lstmx = res;
  for (int i = mid + 1; i <= m; i++) {
    int curmx = min(t - cursum, min(lstmx, S[i] - cursum));
    if (curmx < d[i] || curmx < 0) return 0;
    if (d[i] != -1) {
			cursum += d[i];
			lstmx = d[i];
		} else {
			cursum += curmx;
			lstmx = curmx;
		}
  }
  if (cursum != t) return 0;
  mx = res;
  return 1;
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i].l >> a[i].r;
  cin >> q;
  for (int i = 1; i <= q; i++) {
		cin >> b[i].p >> b[i].s;
		c[b[i].p] = b[i].s;
		bmx = max(bmx, b[i].s);
	}

  sort(b + 1, b + 1 + q, [&](Student x, Student y) {
		return x.p < y.p;
	});
	
  for (int i = 2; i <= q; i++) {	
    if (b[i].p == b[i - 1].p && b[i].s != b[i - 1].s) gg();
	}
	
  cin >> t;
	sort(a + 1, a + 1 + n, [&](Problem x, Problem y) {
		return x.l < y.l;
	});

	int l = t, r = t;
	for (int i = 1; i <= n; i++) {	
		l -= a[i].l, r -= a[i].r, val[i] = a[i].l;
	}

	if (l < 0 || r > 0) gg();
	a[n + 1].l = inf;
	int cnt = 0;
	for (int i = 1; i <= n + 1; i++) {
		if (cnt) {
			int x = min(a[i].l - a[i - 1].l, l / cnt) + a[i - 1].l;
			while (!pq.empty()) {
				auto p = pq.top();
				if (p.first <= x) {
					l -= (p.first - a[i - 1].l), val[p.second] = p.first, cnt--;
					if (cnt) x = min(a[i].l - a[i - 1].l, l / cnt) + a[i - 1].l;
					pq.pop();
				} else break;
			}
			if (x == a[i].l) l -= (x - a[i - 1].l) * cnt;
			else { l -= (x - a[i - 1].l) * cnt;
				while (l--) val[pq.top().second] = x + 1, pq.pop();
				while (!pq.empty()) val[pq.top().second] = x, pq.pop();
				break;
			}
		}
		if (i == n + 1) break;
		pq.push(make_pair(a[i].r, i));
		cnt++;
	}
	for (int i = 1; i <= n; i++) {
		if (val[i] > m) gg();
	}
	
	for (int i = 1; i <= n; i++) {	
		s1[val[i]]++;
		s2[val[i]] += val[i];
	}

	for (int i = 1; i <= m; i++) {	
		s1[i] += s1[i - 1];
		s2[i] += s2[i - 1];
	}

	for (int i = 1; i <= m; i++) S[i] = s2[i] + (n - s1[i]) * i;
	for (int i = m; i >= 1; i--) c[i] = max(c[i], c[i + 1]);
	for (int i = m - 1; i >= 1; i--) S[i] = min(S[i], S[i + 1] - c[i + 1]);
	memset(d, -1, sizeof d);
	for (int i = 1; i <= q; i++) d[b[i].p] = b[i].s;
	
	l = 1, r = m;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (check(mid)) {
			l = mid + 1;
			num = mid;
		} else r = mid - 1;
	}
  if (num <= 0) gg();
	cout << num << ' ' << mx;
}