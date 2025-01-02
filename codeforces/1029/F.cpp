#pragma comment(linker, "/STACK:10000000000")
//#pragma GCC optimize("O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>
#include <numeric>
#include <complex>
#include <vector>
#include <string>
#include <string_view>
#include <array>
#include <sstream>
#include <functional>
#include <ctime>
#include <chrono>
#include <random>
#include <stack>
#include <queue>
#include <deque>
#include <forward_list>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <tuple>
#include <cassert>
#include <climits>
using namespace std;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rep(x) for (int rep_iter = 0; rep_iter < x; ++rep_iter)
#define mp make_pair
#define rt return
using ll = long long;
using db = double;
using ldb = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1LL << 61LL;
const db PI = acos(-1.0);
minstd_rand rng(time(0));
mt19937 rng2(chrono::steady_clock().now().time_since_epoch().count());
uniform_int_distribution<int> uid(-1000000000, 1000000000);
template<typename T>
constexpr auto sqr(T x) { return (x) * (x); }


vector<ll> get_div(ll x) {
	vector<ll> div;
	for (ll i = 1; i * i <= x; ++i) {
		if (x % i == 0)
			div.push_back(i);
	}
	return div;
}


signed main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout.setf(ios::fixed); cout.precision(8);

	ll s, x, y;
	cin >> x >> y;
	s = x + y;
	vector<ll> divs = get_div(s), divx = get_div(x), divy = get_div(y);

	ll ans = 2 * (s + 1);

	for (ll width : divs) {
		ll height = s / width;

		ll width1 = divx[upper_bound(all(divx), width) - divx.begin() - 1];
		ll height1 = x / width1;
		if (height1 <= height)
			ans = min(ans, 2 * (width + height));
	}

	swap(x, y);
	swap(divx, divy);


	for (ll width : divs) {
		ll height = s / width;

		ll width1 = divx[upper_bound(all(divx), width) - divx.begin() - 1];
		ll height1 = x / width1;
		if (height1 <= height)
			ans = min(ans, 2 * (width + height));
	}

	cout << ans << endl;

	return 0;
}