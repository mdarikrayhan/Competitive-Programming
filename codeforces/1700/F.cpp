#include <bits/stdc++.h>
 
using namespace std;

template<class F, class S>
ostream &operator<<(ostream &s, const pair<F, S> &v) {
    s << "(" << v.first << ", " << v.second << ")";
    return s;
}
 
template<ranges::range T> requires (!is_convertible_v<T, string_view>)
istream &operator>>(istream &s, T &&v) { 
    for (auto &&x : v) s >> x; 
    return s; 
}
template<ranges::range T> requires (!is_convertible_v<T, string_view>)
ostream &operator<<(ostream &s, T &&v) { 
    for (auto &&x : v) s << x << ' '; 
    return s; 
}
 
#ifdef LOCAL
template<class... T> void dbg(T... x) {
    char e{};
    ((cerr << e << x, e = ' '), ...);
}
#define debug(x...) dbg(#x, '=', x, '\n')
#else
#define debug(...) ((void)0)
#endif
 
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define ff first
#define ss second
 
template <class T> inline constexpr T inf = numeric_limits<T>::max() / 2;
template <class T> bool chmin(T &a, T b) { return (b < a and (a = b, true)); }
template <class T> bool chmax(T &a, T b) { return (a < b and (a = b, true)); }
 
using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr i64 mod = 998244353;

void solve() {
    int n;
    cin >> n;

    array A{vector<int>(n), vector<int>(n)};
    cin >> A;

    for (int i : {0, 1})
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            A[i][j] -= x;
        }

    auto sgn = [&](i64 x) {
        return (x > 0) - (x < 0);
    };

    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        if (sgn(A[0][i]) * sgn(A[1][i]) < 0) {
            ans++;
            if (A[0][i] > 0) {
                A[0][i]--;
                A[1][i]++;
            } else {
                A[0][i]++;
                A[1][i]--;
            }
        }
        ans += abs(A[0][i]) + abs(A[1][i]);
        if (i + 1 < n) {
            A[0][i + 1] += A[0][i];
            A[1][i + 1] += A[1][i];
        }
    }

    if (A[0][n - 1] + A[1][n - 1] != 0) {
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
    }
    
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);

    int t = 1;
    // cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}


