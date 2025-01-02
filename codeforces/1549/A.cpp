#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC target("avx2")
#pragma GCC optimize("O3,unroll-loops")

#define int long long
#define endl '\n'
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define sz(x) (int)x.size()
#define FOR(i, a) for (int i = 0; i < (a); i++)
#define FORd(i, a) for (int i = (a) - 1; i >= 0; i--)

using namespace std;
using namespace __gnu_pbds;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

using pii = pair<int, int>;
using ordered_set = tree<int, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int INF = (int)1e18;
const int mod = (int)1e9 + 7;
const int N = (int)1e5;

void solve() {
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << n / 2 << " " << n << endl;
    }
    else {
        cout << (n - 1) / 2 << " " << n - 1 << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

