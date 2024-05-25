#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;


#define int long long
#define ld  double
#define nl '\n'
#define pb push_back
#define all(v) v.begin(), v.end()
#define pii pair<int,int>
#define ff first
#define ss second
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define db(x...)
#endif

const int inf = 1e18;
// const int mod = 998244353;
const int N = 1e5 + 2;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;

// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>


/*
pbds A -----------
*A.find_by_order(k)  -- finding Kth element
A.order_of_key(X)  -- number of elements less than X

useful builtin function on bits ---------
__builtin_popcountl(x) -> count number of set bits in x
__builtin_clzll(x) -> count number of leading zeros in x
__builtin_ctzll(x) -> count number of trailing zeros in x

vector storing unique elements in sorted order--------
sort(all(v));
v.resize(unique(all(v)) - v.begin());
n = v.size();

*/


void solve() {
	string s; cin >> s;
	int k; cin >> k;
	int n = s.length();
	vector<char>a;
	int req = n - k;
	a.push_back(s[0]);
	for (int i = 1; i < n; ++i) {
		if (s[i] == '0') {
			while ((int)a.size() > 1 && a.back() > s[i] && (int)a.size() + n - 1 - i >= req) {
				a.pop_back();
			}
		}
		else {
			while (!a.empty() && a.back() > s[i] && (int)a.size() + n - 1 - i >= req) {
				a.pop_back();
			}
			if (a[0] > s[i] && n - i >= req) {
				a.clear();
			}
		}
		a.push_back(s[i]);
	}
	// db(a);
	for (int i = 0; i < req; ++i)cout << a[i];
	cout << nl;

}
int32_t main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
	cin >> t;
	while (t--)
	{
		solve();
	}
}
