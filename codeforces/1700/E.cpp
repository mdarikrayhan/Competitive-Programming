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
    int n, m;
    cin >> n >> m;

    vector G(n, vector<int>(m));
    cin >> G;

    const vector<pair<int, int>> dir{
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };

    auto valid = [&](int x, int y) {
        return 0 <= x and x < n and 0 <= y and y < m;
    };
    
    auto cal = [&](int x, int y) -> int {
        for (auto [dx, dy] : dir) {
            if (valid(x + dx, y + dy) and G[x + dx][y + dy] < G[x][y])
                return 1;
        }
        return 0;
    };

    int tot = 0;
    vector vis(n, vector<bool>(m));
    auto take = [&](int x, int y) {
        if (vis[x][y]) {
            tot -= cal(x, y);
            vis[x][y] = 0;
        }
        for (auto [dx, dy] : dir) {
            if (valid(x + dx, y + dy) and vis[x + dx][y + dy]) {
                tot -= cal(x + dx, y + dy);
                vis[x + dx][y + dy] = 0;
            }
        }
    };
    auto put = [&](int x, int y) {
        if (!vis[x][y]) {
            tot += cal(x, y);
            vis[x][y] = 1;
        }
        for (auto [dx, dy] : dir) {
            if (valid(x + dx, y + dy) and !vis[x + dx][y + dy]) {
                tot += cal(x + dx, y + dy);
                vis[x + dx][y + dy] = 1;
            }
        }
    };

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            put(i, j);
        }

    auto check = [&] {
        return tot == n * m - 1;
    };

    if (check()) {
        cout << 0 << '\n';
        return;
    }
    
    pair<int, int> p;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (G[i][j] != 1 and cal(i, j) == 0) {
                p = {i, j};
            }

    auto Swap = [&](int a, int b, int x, int y) {
        take(a, b);
        take(x, y);
        swap(G[a][b], G[x][y]);
        put(a, b);
        put(x, y);
    };

    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (pair{i, j} != p) {
                Swap(i, j, p.ff, p.ss);
                if (check()) ans++;
                Swap(i, j, p.ff, p.ss);
            }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (pair{i, j} != p) {
                for (auto [dx, dy] : dir) {
                    int x = p.ff + dx;
                    int y = p.ss + dy;
                    if (valid(x, y) and pair{i, j} != pair{x, y}) {
                        Swap(i, j, x, y);
                        if (check()) ans++;
                        Swap(i, j, x, y);
                    }
                }
            }

    if (ans) {
        cout << 1 << ' ' << ans << '\n';
    } else {
        cout << 2 << '\n';
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


