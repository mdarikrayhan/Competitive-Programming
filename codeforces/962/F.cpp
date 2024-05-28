// T810
#include<bits/stdc++.h>
template<typename t1, typename t2> bool chkmin(t1 &x, const t2 &y) {return x > y ? x = y, 1 : 0; }
template<typename t1, typename t2> bool chkmax(t1 &x, const t2 &y) {return x < y ? x = y, 1 : 0; }
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, bool> pib;
typedef pair<int, int> pii;
const int MAXN = 100000;
const int MAXM = 1000000;
int n, m, q; 
namespace VDCC {
	int dfn, dfl[MAXN + 3], low[MAXN + 3];
	stack<pii> st; int sttop;
	vector<int> ans, tmp;
	struct Edge {
		int u, v;
	} e[MAXN + 3]; int etot;
	vector<int> G[MAXN + 3];
	void add(int u, int v) {e[++etot] = {u, v}, G[u].push_back(etot), G[v].push_back(etot); }
	void dfs1(int x, int inedge) {
//		cout << x << " " << inedge << "\n";
		dfl[x] = low[x] = ++dfn, st.push({x, inedge});
		for (int r : G[x]) {
			int to = x != e[r].u ? e[r].u : e[r].v;
			if (!dfl[to]) {
				dfs1(to, r), chkmin(low[x], low[to]); 
			    if (dfl[x] <= low[to]) {
					pii y; int cntp = 0, cnte = 0; vector<int> tmp; tmp.clear();
					do {
						y = st.top(), st.pop();
						if (y.first > 0) ++cntp;
						++cnte, tmp.push_back(y.second);
//						cout << y.first << " " << y.second << "\n";
					} while (to != y.first);
					if (cntp + 1 == cnte) for (int i : tmp) ans.push_back(i);
				}
			} else {
				chkmin(low[x], dfl[to]);
				if (inedge != r && dfl[to] < dfl[x]) st.push({-2, r});
			}
		}
	}
}
using namespace VDCC;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef ONLINE_JUDGE
#else 
	freopen("1.in", "r", stdin), freopen("1.out", "w", stdout);
#endif
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v; cin >> u >> v, add(u, v);
	}
    for (int i = 1; i <= n; ++i) if (!dfl[i]) dfs1(i, 0);
	cout << ans.size() << "\n", sort(ans.begin(), ans.end());
	for (int i : ans) cout << i << " ";
}
 					 		  					   			    		 	