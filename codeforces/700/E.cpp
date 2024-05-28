// LUOGU_RID: 160479016
// MagicDark
#include <bits/stdc++.h>
#define mid ((l + r) >> 1)
#define link sdjfhdkhgkrjdhgkjdsrhfgkjlhfdkljghkjdf
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
const int N = 4e5 + 10, M = N * 30;
int n, tot = 1, son[N][26], link[N], len[N], endpos[N], rt[N];
int ls[M], rs[M];
string st;
vector <int> v[N];
int extend(int p, int c) {
	int nw = ++tot;
	len[nw] = len[p] + 1;
	while (p && !son[p][c]) {
		son[p][c] = nw;
		p = link[p];
	}
	if (!p) link[nw] = 1;
	else {
		int q = son[p][c];
		if (len[p] + 1 == len[q]) link[nw] = q;
		else {
			int cl = ++tot;
			F(i, 0, 25) son[cl][i] = son[q][i];
			len[cl] = len[p] + 1;
			link[cl] = link[q];
			while (p && son[p][c] == q) {
				son[p][c] = cl;
				p = link[p];
			}
			link[q] = link[nw] = cl;
		}
	}
	return nw;
}
int ttot;
void ins(int& num, int l, int r, int x) {
	num = ++ttot;
	if (l == r) return;
	if (mid >= x) ins(ls[num], l, mid, x);
	else ins(rs[num], mid + 1, r, x);
}
bool query(int num, int l, int r, int L, int R) {
	if (!num) return false;
	if (L <= l && r <= R) return true;
	if (mid >= R) return query(ls[num], l, mid, L, R);
	if (mid < L) return query(rs[num], mid + 1, r, L, R);
	return (query(ls[num], l, mid, L, R) || query(rs[num], mid + 1, r, L, R));
}
int merge(int num1, int num2) {
	if (!num1 || !num2) return num1 ^ num2;
	int nw = ++ttot;
	ls[nw] = merge(ls[num1], ls[num2]);
	rs[nw] = merge(rs[num1], rs[num2]);
	return nw;
}
void dfs(int x) {
	if (endpos[x]) ins(rt[x], 1, n, endpos[x]);
	for (int i: v[x]) {
		dfs(i);
		rt[x] = merge(rt[x], rt[i]);
		if (!endpos[x]) endpos[x] = endpos[i];
	}
}
int ans = 1, f[N], g[N];
void dfs2(int x) {
	if (x != 1) {
		if (link[x] == 1) {
			f[x] = 1;
			g[x] = x;
		} else {
			if (query(rt[g[link[x]]], 1, n, endpos[x] - len[x] + len[g[link[x]]], endpos[x] - 1)) {
				chkmax(ans, f[x] = f[g[link[x]]] + 1);
				g[x] = x;
			} else {
				// f[x] = f[link[x]];
				g[x] = g[link[x]];
			}
		}
		// debug << x << " " << len[x] << " " << f[x] << " " << g[x] << endl;
	}
	for (int i: v[x]) dfs2(i);
}
signed main() {
	cin.tie(0) -> sync_with_stdio(0); // don't use puts
	cin >> n >> st;
	st = ' ' + st;
	int num = 1;
	F(i, 1, n) endpos[num = extend(num, st[i] - 'a')] = i;
	F(i, 2, tot) v[link[i]].push_back(i);
	dfs(1);
	dfs2(1);
	cout << ans;
	return 0;
}
/* why?
*/