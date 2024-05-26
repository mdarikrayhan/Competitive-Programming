#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <array>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <fstream>
#include <cstdint>
#define res(a, n) a.clear(); a.resize(n);
#define ress(a, n, b) a.clear(); a.resize(n, b); 
#define int long long
#define endl '\n'
#define INF INT64_MAX
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")

using namespace std;

int n, kk, q, mod = 998244353, mod2 = 998244353, st = 30;
const int N = 2e6 + 7;

vector<vector<int>> d;

void solve() {
    cin >> n >> kk;
    res(d, n + 1);
    for (auto& x : d) { ress(x, kk + 1, 0); }
    d[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= min(i, kk); j++) {
            if (j == 0 && i != 0) continue;
            d[i][j] %= mod;
            for (int k = 1; i + j * (k - 1) + k <= n && j + k <= kk + 1 && k <= kk; k++) {
                d[i + j * (k - 1) + k][k] += d[i][j];
            }
        }
    }
    int ans = 0;
    for (auto u : d[n]) {
        ans = (ans + u) % mod;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= kk; j++) {
            int k = (n - i) / j;
            if (n - i == k * j && j + k <= kk) {
                ans = (ans + d[i][j]) % mod;
            }
        }
    }

    cout << ans << endl;

}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1; cin >> t;
    while (t--) {
        solve();
    }
}
// QpCsrhqlnrn