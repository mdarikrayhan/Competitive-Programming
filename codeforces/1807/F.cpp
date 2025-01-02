#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lll __int128
#define ulll unsigned __int128
#define all(x) x.begin(),x.end()
using namespace std;
const int mod = 1e9 + 7;

// #pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
// #pragma GCC target("avx,avx2,fma,bmi,bmi2,lzcnt,popcnt,sse,sse2,sse3,sse4,mmx")

#ifndef ONLINE_JUDGE
#include "debug.h"
#endif

bool is_square(ll n) { ll l = 1, r = 3037000500, mid; while (r - l > 1) { mid = (l + r) / 2; ll x = mid * mid; if (x <= n) { l = mid; } else { r = mid; } } return (l * l == n); }
ll power(ll a, ll b) { ll ans = 1; while (b) { if (b % 2) ans *= a; a *= a; b /= 2; } return ans; }
ll powmod(ll a, ll b, ll mod) { ll ans = 1; a %= mod; while (b) { if (b % 2) ans = (a * ans) % mod; a = (a * a) % mod; b /= 2; } return ans; }
ll factmod(ll n, ll mod) { ll ans = 1; while (n) { ans = (ans * (n--)) % mod; } return ans; }
ll ncrmod(ll n, ll r, ll mod) { return (((factmod(n, mod) * powmod(factmod(r, mod), mod - 2, mod)) % mod) * powmod(factmod(n - r, mod), mod - 2, mod)) % mod; }

map<string, pair<int, int>> dirs = {
	{"DR", {1, 1}},
	{"DL", {1, -1}},
	{"UR", {-1, 1}},
	{"UL", {-1, -1}}
};

void solve() {
	int n, m, xi, yi, xn, yn;
	cin >> n >> m >> xi >> yi >> xn >> yn;

	string s; cin >> s;
	pair<int, int> dir = dirs[s];

	pair<int, int> curr = {xi, yi};
	pair<int, int> target = {xn, yn};

	set<array<int, 4>> vis;
	int bounces = 0;

	auto isval = [&](int x, int n) {
		return x >= 1 && x <= n;
	};

	while (curr != target) {
		// cout << curr << ' ' << bounces << '\n';
		if (vis.count({curr.first, curr.second, dir.first, dir.second})) {
			cout << "-1\n";
			return;
		}

		vis.insert({curr.first, curr.second, dir.first, dir.second});

		bool bounce = false;
		if (isval(curr.first + dir.first, n))
			curr.first += dir.first;
		else {
			bounce = true;
			dir.first *= -1;
			curr.first += dir.first;
		}

		if (isval(curr.second + dir.second, m))
			curr.second += dir.second;
		else {
			bounce = true;
			dir.second *= -1;
			curr.second += dir.second;
		}

		bounces += bounce;
	}

	cout << bounces << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}