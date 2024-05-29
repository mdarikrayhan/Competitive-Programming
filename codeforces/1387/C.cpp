// LUOGU_RID: 157873575
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
// MagicDark
#include <bits/stdc++.h>
#define debug cerr << "\033[32m[" << __LINE__ << "]\033[0m "
#define SZ(x) ((int) x.size() - 1)
#define all(x) x.begin(), x.end()
#define ms(x, y) memset(x, y, sizeof x)
#define F(i, x, y) for (int i = (x); i <= (y); i++)
#define DF(i, x, y) for (int i = (x); i >= (y); i--)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
template <typename T> T& chkmax(T& x, T y) {return x = max(x, y);}
template <typename T> T& chkmin(T& x, T y) {return x = min(x, y);}
// template <typename T> T& read(T &x) {
// 	x = 0; int f = 1; char c = getchar();
// 	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
// 	for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
// 	return x *= f;
// }
const int N = 110, M = 55;
int sg, n, m, x[N], y[N], t[N][N], s[N];
vector <int> p[N];
pair <int, int> u[N];
string o[N];
struct ACAM {
	int son[N][2], tot, link[N];
	bool vis[N];
	int ins(int num, int f) {
		if (!son[num][f]) son[num][f] = ++tot;
		return son[num][f];
	}
	void build() {
		queue <int> q;
		F(i, 0, 1)
			if (son[0][i]) q.push(son[0][i]);
		while (q.size()) {
			int x = q.front(); q.pop();
			F(i, 0, 1)
				if (son[x][i]) {
					link[son[x][i]] = son[link[x]][i];
					q.push(son[x][i]);
				} else son[x][i] = son[link[x]][i];
		}
	}
} AC;
ull f[N][M][M], g[N][M][M];
bool visf[N][M][M], visg[N][M][M];
signed main() {
	cin.tie(0) -> sync_with_stdio(0); // don't use puts
	ms(f, 127), ms(g, 127);
	ull inf = f[0][0][0];
	// debug << inf << endl;
	cin >> sg >> n >> m;
	F(i, 1, n) {
		cin >> x[i] >> y[i];
		s[i] = s[i - 1] + y[i];
		F(j, 1, y[i]) {
			cin >> t[i][j];
			u[s[i - 1] + j] = make_pair(i, j);
			p[t[i][j]].push_back(s[i - 1] + j);
		}
	}
	F(i, 1, m) {
		int k;
		cin >> k;
		F(j, 1, k) {
			char c;
			cin >> c;
			o[i] += c;
		}
	}
	sort(o + 1, o + m + 1, [&] (const string& x, const string& y) {
		return x.size() < y.size();
	});
	F(i, 1, m) {
		string st = "";
		int num = 0;
		bool flag = false;
		for (char j: o[i]) {
			st += j;
			F(k, 1, i - 1) {
				if (o[k].size() > st.size()) break;
				if (st.substr(SZ(st) - SZ(o[k]), o[k].size()) == o[k]) {
					flag = true;
					break;
				}
			}
			if (flag) break;
			num = AC.ins(num, j - '0');
		}
		if (!flag) AC.vis[num] = true;//, debug << i << " " << num << endl;
	}
	AC.build();
	priority_queue <tuple <ll, int, int, int>, vector <tuple <ll, int, int, int>>, greater <tuple <ll, int, int, int>>> q;
	F(i, 1, n)
		F(j, 0, AC.tot) g[s[i - 1]][j][j] = 0, visg[s[i - 1]][j][j] = true;
	F(i, 0, AC.tot) {
		if (AC.vis[i]) continue;
		if (!AC.vis[AC.son[i][0]]) q.emplace(f[0][i][AC.son[i][0]] = 1, 0, i, AC.son[i][0]);
		if (!AC.vis[AC.son[i][1]]) q.emplace(f[1][i][AC.son[i][1]] = 1, 1, i, AC.son[i][1]);
	}
	while (q.size()) {
		auto [v, x, y, z] = q.top(); q.pop();
		if (x >= 0) {
			if (visf[x][y][z]) continue;
			visf[x][y][z] = true;
			// debug << x << " " << y << " " << z << " " << f[x][y][z] << endl;
			for (int i: p[x]) {
				if (u[i].second == ::y[u[i].first]) {
					// debug << " -> " << ::x[u[i].first] << endl;
					F(j, 0, AC.tot)
						if (visg[i - 1][j][y] && f[x][y][z] + g[i - 1][j][y] < f[::x[u[i].first]][j][z])
							q.emplace(f[::x[u[i].first]][j][z] = f[x][y][z] + g[i - 1][j][y], ::x[u[i].first], j, z);
				} else {
					F(j, 0, AC.tot)
						if (visg[i - 1][j][y] && f[x][y][z] + g[i - 1][j][y] < g[i][j][z]) {
							// debug << i << " " << j << " " << z << " " << x << " " << y << " " << z << endl;
							q.emplace(g[i][j][z] = f[x][y][z] + g[i - 1][j][y], - i, j, z);
						}
				}
			}
		} else {
			x *= -1;
			if (visg[x][y][z]) continue;
			visg[x][y][z] = true;
			assert(u[x].second != ::y[u[x].first]);
			int i = t[u[x].first][u[x].second + 1];
			if (u[x].second + 1 == ::y[u[x].first]) {
				F(j, 0, AC.tot)
					if (visf[i][z][j] && g[x][y][z] + f[i][z][j] < f[::x[u[x].first]][y][j]) {
						// if (::x[u[x].first] == 5) debug << x << " " << u[x].first << " " << u[x].second << " " << y << " " << z << " " << j << endl;
						q.emplace(f[::x[u[x].first]][y][j] = g[x][y][z] + f[i][z][j], ::x[u[x].first], y, j);
					}
			} else {
				F(j, 0, AC.tot)
					if (visf[i][z][j] && g[x][y][z] + f[i][z][j] < g[x + 1][y][j])
						q.emplace(g[x + 1][y][j] = g[x][y][z] + f[i][z][j], - (x + 1), y, j);
			}
		}
	}
	F(i, 2, sg - 1) {
		ull ans = inf;
		F(j, 0, AC.tot) {
			// if (i == 5) debug << j << " " << f[i][0][j] << endl;
			chkmin(ans, f[i][0][j]);
		}
		if (ans == inf) cout << "YES\n";
		else cout << "NO " << ans << '\n';
	}
	return 0;
}
/* why?
*/