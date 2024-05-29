// LUOGU_RID: 160036178
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
template <typename T> T& read(T &x) {
	x = 0; int f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
	return x *= f;
}
const int N = 1e5 + 10, B = 300, T = 800;
int n, m, a[N], v[N], w[T + 5], c[T + 5];
vector <int> g;
struct QQ {
	int l, r, id;
	friend bool operator < (QQ x, QQ y) {
		if ((x.l - 1) / B == (y.l - 1) / B) {
			if (((x.l - 1) / B) & 1) return x.r < y.r;
			return x.r > y.r;
		}
		return x.l < y.l;
	}
} q[N];
int cnt[N];
ll ans[N];
// map <int, int> mp;
int mp[N];
void ins(int x) {
	if (cnt[a[x]]) --mp[cnt[a[x]]];
	mp[++cnt[a[x]]]++;
}
void del(int x) {
	--mp[cnt[a[x]]];
	if (--cnt[a[x]]) mp[cnt[a[x]]]++;
}
signed main() {
	read(n);
	F(i, 1, n) v[read(a[i])]++;
	F(i, 1, 1e5)
		if (v[i] > T) g.push_back(i);
	read(m);
	F(i, 1, m) read(q[i].l), read(q[i].r), q[i].id = i;
	sort(q + 1, q + m + 1);
	int l = 1, r = 0;
	F(i, 1, m) {
		while (l > q[i].l) ins(--l);
		while (r < q[i].r) ins(++r);
		while (l < q[i].l) del(l++);
		while (r > q[i].r) del(r--);
		// for (auto [a, b]: mp) cout << a << " " << b << endl;
		// debug << endl;
		ll s = 0;
		{
			F(j, 1, T) c[j] = mp[j];
			priority_queue <int, vector <int>, greater <int>> q;
			for (int j: g)
				if (cnt[j] > T) q.push(cnt[j]);
			int lst = -1;
			F(j, 1, T) {
				int a = j, b = c[j];
				if (!b) continue;
				if (~ lst) {
					s += lst + a;
					// debug << lst + a << endl;
					if (lst + a > T) q.push(lst + a);
					else c[lst + a]++;
					b--;
					lst = - 1;
				}
				if (b >> 1) {
					s += (ll) (b >> 1) * (a * 2);
					if (a * 2 > T) {
						F(_, 1, b >> 1) q.push(a * 2);
					} else c[a * 2] += b >> 1;
				}
				if (b & 1) lst = a;
			}
			if (~ lst) q.push(lst);
			while (q.size() > 1) {
				int x = q.top(); q.pop();
				int y = q.top(); q.pop();
				s += x + y;
				q.push(x + y);
			}
		}
		ans[q[i].id] = s;
	}
	F(i, 1, m) cout << ans[i] << '\n';
	return 0;
}
/* why?
*/