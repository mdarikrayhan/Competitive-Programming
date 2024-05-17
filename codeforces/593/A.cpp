// #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#ifdef ILOCAL
#define debug(x) cerr << (#x) << " = " << (x) << endl
#else
#define debug(x)
#endif

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vii = vector<int>;
using vll = vector<long long>;
using pll = pair<long long, long long>;
using vpl = vector<pair<long long, long long>>;
using vpi = vector<pair<int, int>>;
using ull = unsigned long long;
using ql = __int128_t;
using uql = __uint128_t;

void solve() {
    int n;
    cin >> n;
    string s[n];
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    int maxi = 0;
    for (char i = 'a'; i <= 'z'; ++i) {
        for (char j = 'a'; j <= 'z'; ++j) {
            if (i == j) continue;
            int tmp = 0;
            for (auto &x : s) {
                if (count(x.begin(), x.end(), i) +
                        count(x.begin(), x.end(), j) ==
                    x.size()) {
                    tmp += x.size();
                }
            }
            maxi = max(maxi, tmp);
        }
    }
    cout << maxi;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("output.txt", "r", stdin);
    //  freopen("dices.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
