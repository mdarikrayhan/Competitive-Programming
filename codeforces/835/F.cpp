#include <bits/stdc++.h>
#define x first
#define y second
#define eps 1e-8
#define endl '\n'
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define IOS ios::sync_with_stdio(false);cin.tie(NULL);

using namespace std;
using PII = pair<int, int>;

const int N = 2e5 + 5, M = N << 1;
int e[M], w[M], ne[M], h[N], idx;
int in[N], d1[N], d2[N], p1[N], p2[N], up[N];
bool st[N];
int n, m, k;
vector<PII> ve;
PII a[M];
int T[M]; 
struct mat {
	int v[3][3];
	mat operator * (const mat &rhs) const {
		mat res;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				res.v[i][j] = -INF;
		for (int i = 0; i < 3; i++)
			for (int k = 0; k < 3; k++)
				for (int j = 0; j < 3; j++)
					res.v[i][j] = max(res.v[i][j], v[i][k] + rhs.v[k][j]);
		return res;
	}
};
struct node {
	int l, r;
	mat m;
} seg[M << 2];

void pushup(int p) {
	seg[p].m = seg[p << 1 | 1].m * seg[p << 1].m;
}

void build(int l, int r, int p = 1) {
	seg[p] = {l, r};
	if (l == r) {
		mat &m = seg[p].m;
		m.v[0][0] = m.v[1][1] = m.v[1][2] = m.v[2][2] = 0;
		m.v[0][1] = m.v[2][0] = m.v[2][1] = -INF;
		m.v[0][2] = a[l].x - T[l], m.v[1][0] = a[l].x + T[l];
		return;
	}
	int mid = l + r >> 1;
	build(l, mid, p << 1);
	build(mid + 1, r, p << 1 | 1);
	pushup(p);
}

mat query(int l, int r, int p = 1) {
	if (l <= seg[p].l && seg[p].r <= r)
		return seg[p].m;
	int mid = seg[p].l + seg[p].r >> 1;
	if (l <= mid && r > mid)
		return query(l, r, p << 1 | 1) * query(l, r, p << 1);
	if (l <= mid)
		return query(l, r, p << 1);
	else
		return query(l, r, p << 1 | 1);
}

void add(int a, int b, int c) {
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int p, int last) {
	if (!ve.empty() && p == ve[0].x)
		return;
	for (int i = h[p]; ~i; i = ne[i]) {
		int j = e[i];
		if (j != last && !st[j]) {
			ve.push_back({p, w[i]});
			dfs(j, p);
			return;
		}
	}
}

int dfs1(int p, int f) {
    d1[p] = d2[p] = -INF;
    for (int i = h[p]; ~i; i = ne[i]) {
        int j = e[i];
        if (j == f || !st[j])
            continue;
        int d0 = dfs1(j, p) + w[i];
        if (d0 >= d1[p]) {
            d2[p] = d1[p], p2[p] = p1[p];
            d1[p] = d0, p1[p] = j;
        } else if (d0 > d2[p])
            d2[p] = d0, p2[p] = j;
    }
    if (!p1[p] && !p2[p])
        return d1[p] = 0;
    return d1[p];
}

void dfs2(int p, int f) {
    for (int i = h[p]; ~i; i = ne[i]) {
        int j = e[i];
        if (j == f || !st[j])
            continue;
        if (p1[p] == j)
            up[j] = max(up[p], d2[p]) + w[i];
        else
            up[j] = max(up[p], d1[p]) + w[i];
        dfs2(j, p);
    }
}

void solve() {
	memset(h, -1, sizeof h);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);
		add(b, a, c);
		in[a]++, in[b]++;
	}
	queue<int> qu;
	for (int i = 1; i <= n; i++)
		if (in[i] == 1) {
			qu.push(i);
			st[i] = true;
		}
	while (!qu.empty()) {
		int p = qu.front();
		qu.pop();
		for (int i = h[p]; ~i; i = ne[i]) {
			int j = e[i];
			if (--in[j] == 1) {
				st[j] = true;
				qu.push(j);
			}
		}
	}
	for (int i = 1; i <= n; i++)
		if (!st[i]) {
			dfs(i, 0);
			break;
		}
	for (auto i : ve) {
		dfs1(i.x, 0);
		dfs2(i.x, 0);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans = max(ans, max(d1[i], up[i]));
	for (int i = 0; i < ve.size(); i++)
		ve[i].x = d1[ve[i].x];
	k = ve.size();
	for (int i = 1; i <= k; i++)
		a[i] = ve[i - 1];
	for (int i = k + 1; i <= k + k; i++)
		a[i] = a[i - k];
	for (int i = 1; i <= k + k; i++)
		T[i] = T[i - 1] + a[i - 1].y;
	build(1, k + k);
	int res = INF;
	for (int i = k; i < k + k; i++) {
		mat m = query(i - k + 1, i);
		res = min(res, m.v[1][2]);
	}
	cout << max(ans, res);
}

signed main(void) {
	IOS;
	int t = 1;
	//cin >> t;
	while (t--)
		solve();
	return 0;
}