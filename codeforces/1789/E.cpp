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
#define res(a, n) a.clear(); a.resize(n);
#define ress(a, n, b) a.clear(); a.resize(n, b); 
#define int long long
#define endl '\n'
//#define endl '\n'
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")

using namespace std;

int n, m, q, mod = 998244353, mod2 = 998244353, st = 30;
const int N = 2e6 + 7;

vector<int> a, pref;

int get(int l, int r) {
    l -= 2; --r;
    if (l < 0) return pref[r];
    return pref[r] - pref[l];
}

int x;

void solve() {
    cin >> n;
    res(a, n);
    for (auto& x : a) cin >> x;
    x = a[n - 1];
    res(pref, x);
    for (auto x : a) pref[x - 1]++;
    for (int i = 1; i < x; i++) pref[i] += pref[i - 1];

    vector<pair<int, int>> p;
    int ans = 1;
    for (int i = 2; i <= x; i++) {
        if (x % i == 0) {
            int col = 0, dd = x / i;
            for (int j = dd - 1; j < x; j += dd) {
                col += get(j + 1, j + 1);
            }
            ans = (ans + col * i) % mod;
        }
        else {
            int y = x / i;
            if (p.size() > 0 && p[p.size() - 1].first == y) {
                p[p.size() - 1].second += i;
            }
            else {
                p.push_back({y, i});
            }
        }
    }

    for (auto u : p) {
        int y = u.first; int col = 0;
        for (int a = 1; a < y - 1 && a * y <= x; a++) {
            col += get(y * a, min(y * a + a, x));
        }
        if (y * (y - 1) <= x) {
            col += get(y * y - y, x);
        }
        col %= mod; u.second %= mod;
        ans = (ans + col * u.second) % mod;
    }
    cout << ans << endl;
}

/*





*/


signed main() {
    //freopen("inputik.txt", "r", stdin);
    //freopen("outputik.txt", "w", stdout);
    //cout << fixed;
    //cout.precision(15);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1; cin >> t;
    while (t--) {
        solve();
    }

}


// QpCsrhqlnrn