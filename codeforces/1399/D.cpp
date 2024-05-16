#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
//


using ll = long long;
#define int int_fast64_t

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve();

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

const int MAXN = 2000;
const ll INF = 2e18;
const ll MOD = 1e9 + 7;


void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    set<int>st1;
    set<int>st0;
    int k = 0;
    vector<int>ans(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            if (st1.size() == 0) {
                k++;
                st0.insert(k);
                ans[i] = k;
            } else {
                auto j = *st1.begin();
                st1.erase(j);
                st0.insert(j);
                ans[i] = j;
            }
        } else {
            if (st0.size() == 0) {
                k++;
                st1.insert(k);
                ans[i]=k;
            } else {
                auto j = *st0.begin();
                st0.erase(j);
                st1.insert(j);
                ans[i] = j;
            }
        }
    }
    cout << k << '\n';
    for (int i : ans) {
        cout << i << ' ';
    }cout << '\n';

}