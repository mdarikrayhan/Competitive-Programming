// #pragma GCC optimize("03")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("avx2,bmi2,fma")

#include <bits/stdc++.h>
#include <random>

using namespace std;

#define int long long

using ll = long long;
// using int128 = __int128;
using i64 = long long;
using ld = long double;

istream& operator>>(istream& in, vector<int>& a) {
    int sz = (int)a.size();
    for (int i = 0; i < sz; i++) {
        in >> a[i];
    }
    return in;
}

ostream& operator<<(ostream& out, vector<int>& a) {
    int sz = (int)a.size();
    for (int i = 0; i < sz; i++) {
        out << a[i] << ' ';
    }
    out << '\n';
    return out;
}

istream& operator>>(istream& in, vector<pair<int, int>>& a) {
    int sz = (int)a.size();
    for (int i = 0; i < sz; i++) {
        in >> a[i].first >> a[i].second;
    }
    return in;
}

// const int INF = 0x3f3f3f3f;
const ll INF = 1e18;
const ll maxn = 1e5 + 7;
const int pw = 350;
const ll mod = 1000000007;
const int eps = 1e-6;

signed main() {
    std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
    // freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
    cout << fixed << setprecision(16);
    int T = 1;
    cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> mas(n); cin >> mas;
        vector<int> mn(2);
        mn[0] = INF;
        mn[1] = 0;
        int d = 0, curr = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 1) {
                curr += mas[i];
            } else {
                curr -= mas[i];
            }
            d = max(d, curr - mn[i % 2]);
            mn[i % 2] = min(mn[i % 2], curr);
        }
        int ans = 0;
        for (int i = 0; i < n; i += 2) {
            ans += mas[i];
        }
        cout << ans + d << '\n';
    }
}
