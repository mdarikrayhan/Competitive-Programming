/*
+---------------------------------------------+
|                                             |
|       © 17/05/2024 (08:19) MinaMagdy        |
|                                             |
+---------------------------------------------+
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define multi_ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
#define endl "\n"
#define MOD 1000000007
#define INF 2000000000
#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()
#define sz(x) int(x.size())

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(m);
    ll sum = 0;
    for (int i = 0; i < m; i++) {
        cin >> a[i].first;
        sum += a[i].first;
        a[i].second = i;
    }
    // sort(all(a), [](pair<int, int> x, pair<int, int> y) {
    //     if (x.first == y.first)
    //         return x.second < y.second;
    //     return x.first > y.first;
    // });
    vector<int> colors(m);
    ll r = 0;
    for (ll l = 0; l < m; l++) {
        ll p = min(r, max(l, n - sum));
        ll q = p + a[l].first - 1;
        if (q >= n) {
            cout << -1 << endl;
            return;
        }
        colors[a[l].second] = p + 1;
        r = max(r, q + 1);
        sum -= a[l].first;
    }
    if (r != n) {
        cout << -1 << endl;
        return;
    }
    for (auto& I : colors) {
        cout << I << " ";
    }
    cout << endl;
}

int main(void)
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int testcase = 1;
    // cin >> testcase;
    while (testcase--)
        solve();
    return 0;
}