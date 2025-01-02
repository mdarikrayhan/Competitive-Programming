// LUOGU_RID: 159793378
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
ll n, t, a, b, c;
ll dist(ll a, ll b, ll c, ll d) {
	return abs(a - c) + abs(b - d);
}
ll cc(ll l, ll r) {
	return (r - l + 1) * (l + r) / 2;
}
ll ccc(ll l, ll r) {
	return cc(l + 1, r);
}
ll dcc(ll l, ll r) {
	return cc(r, l - 1);
}
bool check(int x, int y, ll v1, ll v2, ll v3, ll v4) {
	if (x <= a && y <= b) return true;
	// if (x >= a + c && y >= b + c) return true;
	if (x <= a + c) {
		if (y < b) {
			v1 += dcc(dist(x, y, a, b), dist(x, b, a, b));
			v2 += dcc(dist(x, y, a, b + c), dist(x, b, a, b + c));
			v3 += dcc(dist(x, y, a + c, b), dist(x, b, a + c, b));
			v4 += dcc(dist(x, y, a + c, b + c), dist(x, b, a + c, b + c));
			y = b;
		}
		v1 += ccc(dist(x, y, a, b), dist(n, n, a, b));
		v4 += dcc(dist(x, y, a + c, b + c), 0);
		v4 += ccc(0, dist(n, n, a + c, b + c));
		v2 += ccc(dist(a + c, b + c, a, b + c), dist(n, n, a, b + c));
		v3 += ccc(dist(a + c, b + c, a, b + c), dist(n, n, a, b + c));
		ll l1 = dcc(dist(a, b + c, x, y), dist(a, b + c, x, b + c)) + ccc(dist(a, b + c, x, b + c), dist(a, b + c, a + c, b + c));
		ll r1 = ccc(dist(a, b + c, x, y), dist(a, b + c, a + c, y)) + dcc(dist(a, b + c, a + c, y), dist(a, b + c, a + c, b + c));
		ll l2 = dcc(dist(a + c, b, x, y), dist(a + c, b, a + c, y)) + ccc(dist(a + c, b, a + c, y), dist(a + c, b, a + c, b + c));
		ll r2 = ccc(dist(a + c, b, x, y), dist(a + c, b, x, b + c)) + dcc(dist(a + c, b, x, b + c), dist(a + c, b, a + c, b + c));
		if (v1 > t || v4 > t) return false;
		if (v2 + l1 > t || v3 + l2 > t) return false;
		if (v2 + v3 + l1 + r2 > 2 * t) return false;
		return true;
	}
	if (y < b) {
		v1 += dcc(dist(x, y, a, b), dist(x, b, a, b));
		v2 += dcc(dist(x, y, a, b + c), dist(x, b, a, b + c));
		v3 += dcc(dist(x, y, a + c, b), dist(x, b, a + c, b));
		v4 += dcc(dist(x, y, a + c, b + c), dist(x, b, a + c, b + c));
		y = b;
	}
	if (y < b + c) {
		v1 += ccc(dist(x, y, a, b), dist(x, b + c, a, b));
		v2 += dcc(dist(x, y, a, b + c), dist(x, b + c, a, b + c));
		v3 += ccc(dist(x, y, a + c, b), dist(x, b + c, a + c, b));
		v4 += dcc(dist(x, y, a + c, b + c), dist(x, b + c, a + c, b + c));
		y = b + c;
	}
	v1 += ccc(dist(x, y, a, b), dist(x, n, a, b));
	v2 += ccc(dist(x, y, a, b + c), dist(x, n, a, b + c));
	v3 += ccc(dist(x, y, a + c, b), dist(x, n, a + c, b));
	v4 += ccc(dist(x, y, a + c, b + c), dist(x, n, a + c, b + c));
	y = n;
	v1 += ccc(dist(x, y, a, b), dist(n, n, a, b));
	v2 += ccc(dist(x, y, a, b + c), dist(n, n, a, b + c));
	v3 += ccc(dist(x, y, a + c, b), dist(n, n, a + c, b));
	v4 += ccc(dist(x, y, a + c, b + c), dist(n, n, a + c, b + c));
	x = n;
	if (v1 > t || v2 > t || v3 > t || v4 > t) return false;
	return true;
}
string ans;
void dot(int x, int y, ll v1, ll v2, ll v3, ll v4) {
	// debug << ans << endl;
	// debug << x << ' ' << y << ' ' << v1 << ' ' << v2 << ' ' << v3 << ' ' << v4 << endl;
	if (x == n && y == n) {
		cout << ans;
		exit(0);
	}
	if (x < n) {
		int xx = x, yy = y;
		ll vv1 = v1, vv2 = v2, vv3 = v3, vv4 = v4;
		xx++;
		vv1 += dist(xx, yy, a, b);
		vv2 += dist(xx, yy, a, b + c);
		vv3 += dist(xx, yy, a + c, b);
		vv4 += dist(xx, yy, a + c, b + c);
		if (check(xx, yy, vv1, vv2, vv3, vv4)) {
			ans += 'R';
			return dot(xx, yy, vv1, vv2, vv3, vv4);
		}
	}
	ans += 'U';
	int xx = x, yy = y;
	ll vv1 = v1, vv2 = v2, vv3 = v3, vv4 = v4;
	yy++;
	vv1 += dist(xx, yy, a, b);
	vv2 += dist(xx, yy, a, b + c);
	vv3 += dist(xx, yy, a + c, b);
	vv4 += dist(xx, yy, a + c, b + c);
	dot(xx, yy, vv1, vv2, vv3, vv4);
}
signed main() {
	cin >> n >> t >> a >> b >> c;
	// {
	// 	ll v = cc(1, a - 1 + b - 1) + cc(1, n - a + n - b);
	// 	if (v > t) {
	// 		puts("Impossible");
	// 		return;
	// 	}
	// }
	// {
	// 	ll v = cc(1, a + c - 1 - 1 + b + c - 1 - 1) + cc(1, n - (a + c - 1) + n - (b + c - 1));
	// 	if (v > t) {
	// 		puts("Impossible");
	// 		return;
	// 	}
	// }
	c--;
	// {
	// ll v = cc(1, a - 1 + b - 1) + cc(1, n - (a + c - 1) + n - (b + c - 1));
	// ll v1 = v, v2 = v;
	// 	// if (c & 1) v += 
	// }
	string ans = "", ans2 = "";
	int p1 = 1, p2 = 1;
	while (p1 < a || p2 < b) {
		if (p1 < a) {
			p1++;
			ans += 'R';
		} else {
			p2++;
			ans += 'U';
		}
	}
	F(i, 1, c / 2) ans += 'U';
	F(i, 1, c / 2) ans += 'R';
	if (c & 1) {
		ans += 'U';
		ans += 'R';
	}
	F(i, 1, c / 2) ans += 'R';
	F(i, 1, c / 2) ans += 'U';
	p1 = a + c, p2 = b + c;
	while (p1 < n || p2 < n) {
		if (p1 < n) {
			p1++;
			ans += 'R';
		} else {
			p2++;
			ans += 'U';
		}
	}
	ll v1 = 0, v2 = 0, v3 = 0, v4 = 0;
	p1 = 1, p2 = 1;
	F(i, 0, SZ(ans)) {
		if (ans[i] == 'R') p1++;
		else p2++;
		v1 += dist(p1, p2, a, b);
		v2 += dist(p1, p2, a + c, b + c);
		v3 += dist(p1, p2, a + c, b);
		v4 += dist(p1, p2, a, b + c);
	}
	// debug << p1 << " " << p2 << endl;
	if (v1 > t || v2 > t || v3 > t || v4 > t) {
		cout << "Impossible";
		return 0;
	}
	dot(1, 1, 0, 0, 0, 0);
	return 0;
}
/* why?
*/