#include <bits/stdc++.h>
//#pragma GCC optimize ("O3")
#define nl '\n'
#define ls k << 1
#define rs k << 1 | 1
#define pb push_back
#define sz(x) (int)x.size()
#define mk std :: make_pair
#define PII std :: pair <int, int>
#define PIL std :: pair <int, i64>
#define PLL std :: pair <i64, i64>
#define DEB std :: cout << "ok" << '\n';
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
typedef unsigned long long ull;
template <class T>
T max(T a, T b) {
	return a > b ? a : b;
}
template <class T>
T min(T a, T b) {
	return a < b ? a : b;
}
template <class T>
T abs(T a) {
	return a < 0 ? -a : a;
}
std :: mt19937 rd(114514);
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
// const int N = ;
void solve() {
	i64 n, l, r;
	std :: cin >> n >> l >> r;
	std :: vector <i64> a(n+1), sum(n+1);
	for(int i = 1; i <= n; ++ i) {
		a[i] = (n - i) * 2;
		if(i == n) {
			a[i] = 1;
		}
		sum[i] = sum[i-1] + a[i];
	}
	i64 st = -1, ed = -1;
	for(int i = 1; i <= n; ++ i) {
		if(sum[i] >= l) {
			if(st == -1) {
				st = i;
			}
		}
		if(sum[i] >= r) {
			if(ed == -1) {
				ed = i;
				break;
			}
		}
	}
	std :: vector <int> ans;
	// std :: cout << st << ' ' << ed << nl;
	for(int i = st; i <= ed; ++ i) {
		if(i == ed && r == n * (n - 1) + 1) {
			ans.pb(1);
		}
		for(int j = i + 1; j <= n; ++ j) {
			ans.pb(i);
			ans.pb(j);
		}
	}
	// deb(sum[st])
	st = sum[st-1] + 1;
	// deb(st);
	// deb(sz(ans))
	for(int i = 0; i < sz(ans); ++ i) {
		if(st + i >= l && st + i <= r) {
			std :: cout << ans[i] << ' ';
		}
	}
	std :: cout << nl;
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int _ = 1;
	std :: cin >> _; 
	while(_ --) solve();
	return 0;
}