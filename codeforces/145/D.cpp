// LUOGU_RID: 159772520
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
template <typename T> void write(T x) {
	if (x < 0) putchar('-'), x *= -1;
	if (x > 9) write(x / 10);
	putchar(x % 10 + 48);
}
template <typename T> inline void writes(T x) { write(x); putchar(32); }
template <typename T> inline void writeln(T x) { write(x); puts(""); }
const int N = 1e5 + 10;
int n, a[N], tl[N], tr[N], tot, id[N], vv, b[N], di[N];
__int128 sum;
bool ok[N], vis[N];
vector <int> pos[N];
unordered_map <int, int> mp;
// int info[N];
signed main() {
	read(n);
	F(i, 1, n) {
		read(a[i]);
		int t = a[i];
		ok[i] = true;
		while (t) {
			int w = t % 10;
			ok[i] &= w == 4 || w == 7;
			t /= 10;
		}
		if (ok[i]) {
			if (!mp[a[i]]) mp[a[i]] = ++vv;
			di[id[i] = ++tot] = i;
			pos[b[id[i]] = mp[a[i]]].push_back(i);
		}
	}
	int t = 0;
	F(i, 1, n) {
		t++;
		if (ok[i]) tl[id[i]] = t, t = 0;
	}
	t = 0;
	DF(i, n, 1) {
		t++;
		if (ok[i]) tr[id[i]] = t, t = 0;
	}
	// debug << tot << endl;
	di[tot + 1] = n + 1;
	F(i, 1, tot + 1) {
		set <int> s;
		s.insert(0);
		s.insert(di[i - 1] + 1);
		ll ans = (ll) di[i - 1] * (di[i - 1] + 1) / 2;
		sum += (__int128) ans * (di[i] - di[i - 1] - 1) * (di[i] - di[i - 1]) / 2;
		sum += (__int128) (di[i] - di[i - 1] - 1) * (di[i] - di[i - 1]) * (di[i] - di[i - 1] - 2) / 6 * di[i - 1];
		sum += (__int128) (di[i] - di[i - 1]) * (di[i] - di[i - 1] - 1) * (di[i] - di[i - 1] - 2) * (di[i] - di[i - 1] + 1) / 24;
		// debug << ans << endl;
		// debug << i << " " << sum << " " << ans << endl;
		F(j, 1, tot) vis[j] = false;
		F(j, i, tot) {
			if (!vis[b[j]]) {
				vis[b[j]] = true;
				for (int k: pos[b[j]]) if (k <= di[i - 1]) {
					auto it = s.insert(k).first;
					int nx = * next(it), pv = * prev(it);
					int len = nx - pv - 1, l1 = k - pv - 1, l2 = nx - k - 1;
					ans -= (ll) len * (len + 1) / 2;
					ans += (ll) l1 * (l1 + 1) / 2;
					ans += (ll) l2 * (l2 + 1) / 2;
				}
			}
			sum += (__int128) ans * tl[i] * tr[j];
			// debug << i << " " << j << " " << sum << " " << ans << endl;
			sum += (__int128) tr[j] * (tl[i] + 1) * tl[i] * (tl[i] - 1) / 6;
			int g = * prev(prev(s.end()));
			// debug << i << " " << j << " " << sum << ' ' << tl[i] << endl;
			sum += (__int128) tr[j] * tl[i] * (tl[i] - 1) / 2 * (di[i - 1] - g);
			// debug << i << " " << j << " " << sum << endl;
		}
	}
	write(sum);
	return 0;
}
/* why?
*/