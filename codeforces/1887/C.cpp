#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef long double ld;

#define p pair
#define v vector
#define dq deque
#define q queue
#define pq priority_queue
#define uset unordered_set
#define umap unordered_map
#define arr array
#define mset multiset

#define dis distance
#define all(iterable) iterable.begin(), iterable.end()
#define fir first
#define sec second

#define sp " "
#define spsp "  "
#define nl "\n"
#define nlnl "\n\n"

const ll mod = 998244353;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt; cin >> tt;
	while (tt--) {
		int n; cin >> n;
		v<ll> nums(n);
		for (int i =0; i < n; i++) {
			cin >> nums[i];
		}
		v<ll> diff(n, 0);
		map<int, ll> delta;
		int q; cin >> q;
		for (int i = 0; i < q; i++) {
			ll l,r,x; cin >> l >> r >> x;
			--l; --r;
			if (r != n-1) {
				if (delta.count(r+1)) {
					delta[r+1] -= x;
				}
				else {
					delta[r+1] = -x;
				}
				if (delta[r+1] == 0) delta.erase(r+1);
			}
			if (delta.count(l)) {
				delta[l] += x;
			}
			else {
				delta[l] = x;
			}
			if (delta[l] == 0) delta.erase(l);

			if (delta.begin()->sec < 0) {
				// cout << "oof";
				for (p<int,ll> pi : delta) {
					diff[pi.fir] += pi.sec;
				}
				delta.clear();
			}
		}
		// for (int i : nums) {
		// 	cout << i << sp;
		// }
		// cout << nl;
		// for (int i : diff) {
		// 	cout << i << sp;
		// }
		// cout << nl;

		ll run=0;
		for (int i = 0; i < n; i++) {
			run += diff[i];
			cout << nums[i] + run << sp;
		}
		cout << nl;
	}
}