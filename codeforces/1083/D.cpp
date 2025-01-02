// learned from https://www.luogu.com.cn/article/kez36jye
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 100005;
const int mod = 1000000007;
int n, a[maxn], mp[maxn];
int last[maxn], cnt[maxn], pre[maxn], nxt[maxn];
int fp[maxn], fs[maxn];
int stk[maxn], top;
ll sum[maxn << 2][4], lazy[maxn << 2][2];

ll s(ll x) {
	return x * (x + 1) / 2;
}

ll f(int l, int r) {
	return s(r) - s(l - 1);
}

#define lc (i << 1)
#define rc (i << 1 | 1)
void pushup(int i) {
  for (int j = 0; j < 4; j++) sum[i][j] = sum[lc][j] + sum[rc][j];
}

void pushlazy(int i, int l, int r, int z, int op) {
  sum[i][2] = sum[i][op ^ 1] * z;
  sum[i][op] = 1ll * (r - l + 1) * z;
  lazy[i][op] = z;
  if (op == 0) sum[i][3] = z * f(l, r);
}

void pushdown(int i, int l, int r) {
  int mid = (l + r) >> 1;
  if (lazy[i][0]) {
    pushlazy(lc, l, mid, lazy[i][0], 0);
    pushlazy(rc, mid + 1, r, lazy[i][0], 0);
    lazy[i][0] = 0;
  }
  if (lazy[i][1]) {
    pushlazy(lc, l, mid, lazy[i][1], 1);
    pushlazy(rc, mid + 1, r, lazy[i][1], 1);
    lazy[i][1] = 0;
  }
}

void update(int i, int l, int r, int x, int y, int z, int op) {
  if (x <= l && r <= y) {
    pushlazy(i, l, r, z, op);
    return;
  }
  pushdown(i, l, r);
  int mid = (l + r) >> 1;
  if (x <= mid) update(lc, l, mid, x, y, z, op);
  if (y > mid) update(rc, mid + 1, r, x, y, z, op);
  pushup(i);
}

ll query(int i, int l, int r, int x, int y, int z) {
  if (x > y) return 0;
  if (x <= l && r <= y) return sum[i][z];
  pushdown(i, l, r);
  int mid = (l + r) >> 1;
  ll res = 0;
  if (x <= mid) res += query(lc, l, mid, x, y, z);
  if (y > mid) res += query(rc, mid + 1, r, x, y, z);
  return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
  for (int i = 1; i <= n; i++) {
		cin >> a[i];
		mp[i] = a[i];
	}

  sort(mp + 1, mp + n + 1);
  int tot = unique(mp + 1, mp + n + 1) - mp - 1;
  for (int i = 1; i <= n; i++) {	
    a[i] = lower_bound(mp + 1, mp + tot + 1, a[i]) - mp;
		pre[i] = last[a[i]] + 1,
    last[a[i]] = i;
	}
	
  for (int i = 1; i <= tot; i++) last[i] = n + 1;
  for (int i = n; i; i--) {	
    nxt[i] = last[a[i]] - 1;
		last[a[i]] = i;
	}
	
  for (int i = n; i; i--) {
    while (top && pre[i] > pre[stk[top]]) top--;
    fp[i] = top ? stk[top] - 1 : n, stk[++top] = i;
  }
  top = 0;
  for (int i = n; i; i--) {
    while (top && nxt[i] < nxt[stk[top]]) top--;
    fs[i] = top ? stk[top] - 1 : n;
		stk[++top] = i;
  }
	
  ll res = 0;
  for (int i = n, j = n; i; i--) {
    update(1, 1, n, i, fp[i], pre[i], 0);
    update(1, 1, n, i, fs[i], nxt[i], 1);
    cnt[a[i]]++;
    while (cnt[a[i]] > 1) {
      cnt[a[j]]--;
			j--;
		}
    res += query(1, 1, n, i, j, 3) + i * query(1, 1, n, i, j, 1) - i * f(i, j) - query(1, 1, n, i, j, 2);
		res %= mod;
  }
	cout << (res + mod) % mod;
}