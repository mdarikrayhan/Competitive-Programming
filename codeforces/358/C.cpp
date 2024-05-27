/*
 ~ Author    : @tridib_2003
*/

#pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")

#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> indexed_set;

#define ll                  long long
#define ull                 unsigned long long
#define PI                  3.1415926535897932384626
#define MOD                 998244353 // 1000000007
#define vi                  vector<int>
#define vb                  vector<bool>
#define vvi                 vector<vector<int> >
#define vll                 vector<long long>
#define pb                  push_back
#define eb                  emplace_back
#define mp(a, b)            make_pair(a, b)
#define pii                 pair<int, int>
#define vpii                vector<pair<int, int> >
#define mk(arr, n, type)    type *arr = new type[n];
#define FOR(i, a, b)        for (int(i) = (a); (i) < (b); ++(i))
#define RFOR(i, a, b)       for (int(i) = (a)-1; (i) >= (b); --(i))
#define FORALL(i, a)        for (auto& (i) : (a))
#define printall(a)         for (auto& (i) : (a)) cout << i << ' '
#define print(a)            cout << a << '\n'
#define rsort(a)            sort((a).rbegin(), (a).rend())
#define w(x)                int x; cin >> x; while(x--)
#define all(c)              (c).begin(), (c).end()
#define sz(c)               (int)(c).size()
#define pqmx                priority_queue<int>
#define pqmn                priority_queue<int, vector<int>, greater<int> >
#define max3(a, b, c)       max((a), max((b), (c)))
#define min3(a, b, c)       min((a), min((b), (c)))
#define mx_all(c)           *max_element((c).begin(), (c).end())
#define mn_all(c)           *min_element((c).begin(), (c).end())
#define lwr_b(c, a)         lower_bound((c).begin(), (c).end(), (a)) - ((c).begin())
#define upr_b(c, a)         upper_bound((c).begin(), (c).end(), (a)) - ((c).begin())
#define FIO                 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);


vi arr;
int max1, max2, max3;

void findMax3() {
	vi temp = arr;
	rsort(temp);

	if (temp.empty())
		return;
	else if (sz(temp) == 1) {
		max1 = temp[0];
	}
	else if (sz(temp) == 2) {
		max1 = temp[0];
		max2 = temp[1];
	}
	else if (sz(temp) >= 3) {
		max1 = temp[0];
		max2 = temp[1];
		max3 = temp[2];
	}
}

void solve() {

	int n;
	cin >> n;

	FOR (i, 0, n) {
		int val;
		cin >> val;

		if (val == 0) {

			if (sz(arr) == 0) {
				cout << 0 << '\n';
			}
			else {

				max1 = -1, max2 = -1, max3 = -1;
				findMax3();

				//print(max1); print(max2); print(max3);

				bool pushStack = false, pushQueue = false, pushFront = false;
				int cnt = 0;

				FOR (j, 0, sz(arr)) {
					if (!pushStack && arr[j] == max1) {
						cout << "pushStack";
						pushStack = true;
						++cnt;
					}
					else if (!pushQueue && arr[j] == max2) {
						cout << "pushQueue";
						pushQueue = true;
						++cnt;
					}
					else if (!pushFront && arr[j] == max3) {
						cout << "pushFront";
						pushFront = true;
						++cnt;
					}
					else {
						cout << "pushBack";
					}

					cout << '\n';
				}

				cout << cnt << ' ';

				if (cnt == 1)
					cout << "popStack";
				if (cnt == 2)
					cout << "popStack popQueue";
				if (cnt == 3)
					cout << "popStack popQueue popFront";

				cout << '\n';

				arr.clear();
			}
		}
		else {
			arr.eb(val);
		}
	}

	if (!arr.empty()) {
		FOR (i, 0, sz(arr)) {
			cout << "pushBack" << '\n';
		}
	}
}

int32_t main() {

	FIO;

	int tc = 1;
	// cin >> tc;
	while (tc--) {
		solve();
		// cout << '\n';
	}

	return 0;
}
