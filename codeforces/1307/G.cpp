#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define i128 __int128
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(x) (x).begin(), (x).end()
bool be;
constexpr int N = 55, M = 1e4 + 5;
constexpr int inf = 1e9;
int n, m, a[N], hed[N], pre[N], cnt = 1, s, t, d[N], incf[N];
bool inq[N];
vector<pll>v;
struct edge {
	int v, c, w, nxt;
}e[M];
inline void add(int u, int v, int c, int w)
{
	e[++cnt] = {v, c, w, hed[u]};
	hed[u] = cnt;
}
inline void link(int u, int v, int c, int w)
{
//	cerr << u << ' ' << v << ' ' << c << ',' << w << '\n';
	add(u, v, c, w), add(v, u, 0, -w);
}
bool SPFA()
{
	queue<int>q;
	memset(d, 63, sizeof(d));
	incf[s] = inf;
	d[s] = 0;
	q.emplace(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		inq[u] = 0;
		for (int i = hed[u]; i; i = e[i].nxt) {
			if (e[i].c == 0) continue;
			auto [v, c, w, _] = e[i];
			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				incf[v] = min(incf[u], c);
				pre[v] = i;
				if (!inq[v]) {
					inq[v] = 1;
					q.emplace(v);
				}
			}
		}
	}
	return d[t] != d[0];
}
void solve()
{
	int mxf = 0;
	ll mnc = 0;
	while (SPFA()) {
		int x = t;
		mxf += incf[t];
		mnc += (ll) d[t] * incf[t];
		v.emplace_back(mxf, mnc);
		while (x != s) {
			int i = pre[x];
			e[i].c -= incf[t];
			e[i ^ 1].c += incf[t];
			x = e[i ^ 1].v;
		}
	}
}
bool en;
int main()
{
	cerr << (&be - &en) / 1024.0 / 1024 << " MB\n--------------------------------" << endl;
#ifdef IAKIOI
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	s = 1, t = n;
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		link(u, v, 1, w);
	}
	solve();
	int q;
	cin >> q;
	while (q--) {
		int x;
		cin >> x;
		double ans = 1e18;
		for (auto [mxf, mnc] : v) {
			ans = min(ans, (double) (mnc + x) / mxf);
		}
		cout << fixed << setprecision(10) << ans << '\n';
	}
	return 0;
}
    	 	 		  	   		  	  	