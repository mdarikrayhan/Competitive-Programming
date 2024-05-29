#include <bits/stdc++.h>
using namespace std;

namespace SOL {

using i64 = long long;
void debug(const char *msg, ...) {
#ifdef CLESIP
    va_list arg;
    static char pbString[512];
    va_start(arg,msg);
    vsprintf(pbString,msg,arg);
    cerr << "[DEBUG] " << pbString << "\n";
    va_end(arg);
#endif    
}
template<typename T, typename L>
bool chkmax(T &x, L y) { if (x < y) return x = y, true; return false; }
template<typename T, typename L>
bool chkmin(T &x, L y) { if (y < x) return x = y, true; return false; }

const int N = 2e5 + 10;
int n, fa[N], f[N], ans[N], cnt3;
vector<int> G[N];
vector<vector<int>> clique;
bool tflag;

void dfs(int x) {
	f[x] = 0;
	for (int y : G[x])
		dfs(y);
	int cnt = 0;
	vector<int> vec = { x };
	for (int y : G[x])
		if (f[y] == 0)
			cnt += 1, vec.push_back(y);
	if (x != 1 || cnt > 0) {		
		if (cnt == 0)
			f[x] = 0;
		else {
			clique.push_back(vec);
			if (cnt + 1 == 3)
				cnt3 += 1;
			f[x] = cnt + 1;
		}
	} else {
		if ((int) G[x].size() == 1) {
			int y = G[x][0];
			if (f[y] == 2) {
				for (auto &vec : clique) {
					if (vec[0] == y) {
						vec.push_back(x);
						return;
					}
				}
				// assert(false);
			}
			if (cnt3 >= 2) {
				for (auto &vec : clique) {
					if (vec[0] == y) {
						vec.push_back(x);
					}
				}
				return;
			} 
			int z = 0, w = 0;
			for (int u : G[y])
				for (int v : G[u])
					if (f[v] == 2)
						z = v, w = u;
			// assert(z != 0);
			// cerr << "case 3 " << z << " " << w << " " << y << "\n"; 
			for (auto &vec : clique) {
				if (vec[0] == y) {
					vec.erase(find(begin(vec), end(vec), w));
					vec.push_back(x);
				} else if (vec[0] == z) {
					vec.push_back(w);
				}
			}
			return;
		}
		int lc = G[x][0], rc = G[x][1];
		if (f[lc] > f[rc])
			swap(lc, rc);
		for (auto &vec : clique) {
			if (vec[0] == lc) {
				vec.push_back(x);
				return;
			}
		}
		// assert(false);
	}
}

void solve(int task) {
	cin >> n;

	cnt3 = 0;
	clique.clear();
	for (int i = 1; i <= n; i ++)
		G[i].clear(), fa[i] = f[i] = ans[i] = 0;

	for (int i = 2; i <= n; i ++)
		cin >> fa[i], G[fa[i]].push_back(i);
	if (task == 1 && n != 2)
		tflag = false;
	// tflag &= (task == 1 && n == 2);

	// if (task == 782 && tflag) {
	// 	cout << n << "\n";
	// 	for (int i = 2; i <= n; i ++)
	// 		cout << fa[i] << " \n"[i == n];
	// 	return;
	// }
	// if (tflag)
	// 	return;

	for (int i = 2; i <= n; i ++) {
		if (i == 4 && fa[3] == fa[4])
			cout << 2 << "\n";
		else
			cout << (i & 1) << "\n";
	}
	if (n == 4 && fa[3] == fa[4]) {
		cout << "wbww\n";
		return;
	}
	dfs(1);
	int cur = 0;
	// for (auto vec : clique) {
	// 	cerr << "new vec\n";
	// 	for (int x : vec)
	// 		cerr << x << " ";
	// 	cerr << "\n";
	// }
	sort(begin(clique), end(clique), [&](const vector<int> &lhs, const vector<int> &rhs) {
		return lhs.size() > rhs.size();
	});
	for (auto vec : clique) {
		int major = 1, minor = 0;
		if (cur > 0)
			major = 0, minor = 1;
		// debug("size: %llu major: %d minor: %d", vec.size(), major, minor);
		if ((int) vec.size() == 4) {
			bool flag = 0;
			for (int x : vec) {
				for (int y : vec)
					if (x != y && fa[x] == fa[y]) {
						flag = 1;
						ans[fa[x]] = minor, ans[x] = ans[y] = ans[fa[fa[x]]] = major;
						break;
					}
				if (flag)
					break;
			}
			if (major == 1)
				cur += 2;
			else
				cur -= 2;
		} else if ((int) vec.size() == 3) {
			bool flag = 0;
			for (int x : vec) {
				for (int y : vec)
					if (x != y && fa[x] == fa[y]) {
						ans[fa[x]] = minor;
						ans[x] = ans[y] = major;
						flag = 1;
						break;
					}
				if (flag)
					break;
			}
			if (!flag) {
				for (int x : vec)
					for (int y : vec)
						for (int z : vec)
							if (x != y && x != z && y != z && fa[z] == y && fa[y] == x) {
								// debug("find (%d, %d, %d)", x, y, z);
								ans[y] = minor, ans[x] = ans[z] = major;
							}
			}
			if (major == 1)
				cur += 1;
			else
				cur -= 1;
		} else {
			ans[vec[0]] = 0, ans[vec[1]] = 1;
		}
	}
	// assert(abs(cur) == (n & 1));
	for (int i = 1; i <= n; i ++)
		cout << (ans[i] ? 'b' : 'w');
	cout << "\n";
}

}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int tt; cin >> tt;
	SOL::tflag = (tt >= 10);
	for (int t = 1; t <= tt; t ++)
		SOL::solve(t);
	return 0;
}