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

    const int m = n * 2;
    vector G(m, vector<int>{});
    
    vector<pair<int, int>> edg(n);
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        edg[i] = {u, v};
        G[u].push_back(i);
        G[v].push_back(i);
    }

    auto get = [&](int u, int e) {
        return u ^ edg[e].ff ^ edg[e].ss;
    };
    
    vector<bool> use(n);
    auto work = [&](int s) -> vector<int> {
        vector<int> path;
        auto dfs = [&](auto self, int u) -> void {
            path.push_back(u);
            while (G[u].size()) {
                int e = G[u].back();
                G[u].pop_back();
                if (use[e]) continue;
                use[e] = 1;
                self(self, get(u, e));
                path.push_back(u);
            }
        };
        dfs(dfs, s);
        debug(path);
        path.pop_back();
        return path;
    };

    vector grid(2, vector<int>{});
    vector<string> sol1(2), sol2(2);

    for (int i = 0; i < m; i++) {
        auto path = work(i);
        if (path.empty()) {
            continue;
        }
        if (path.size() == 2) {
            cout << -1 << '\n';
            return;
        }
        vector<int> val;
        debug(path, path.size());
        int t = path.size() / 2;
        grid[0].insert(grid[0].end(), path.begin(), path.begin() + t);
        grid[1].insert(grid[1].end(), path.rbegin(), path.rbegin() + t);
        if (t % 2 == 0) {
            for (int i = 0; i < t; i++) {
                sol1[0] += "LR"[i % 2];
                sol1[1] += "LR"[i % 2];
            }
            sol2[0] += "U";
            sol2[1] += "D";
            for (int i = 0; i < t - 2; i++) {
                sol2[0] += "LR"[i % 2];
                sol2[1] += "LR"[i % 2];
            }
            sol2[0] += "U";
            sol2[1] += "D";
        } else {
            for (int i = 0; i < t; i++) {
                sol1[0] += "LR"[i % 2];
                sol1[1] += "LR"[i % 2];
            }
            sol1[0].back() = 'U';
            sol1[1].back() = 'D';
            sol2[0] += "U";
            sol2[1] += "D";
            for (int i = 0; i + 1 < t; i++) {
                sol2[0] += "LR"[i % 2];
                sol2[1] += "LR"[i % 2];
            }
        }
    }

    cout << 2 << ' ' << n << '\n';
    for (int i : {0, 1})
        for (int j = 0; j < n; j++)
            cout << grid[i][j] + 1 << " \n"[j == n - 1];

    cout << sol1[0] << '\n';
    cout << sol1[1] << '\n';
    cout << sol2[0] << '\n';
    cout << sol2[1] << '\n';

    
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

