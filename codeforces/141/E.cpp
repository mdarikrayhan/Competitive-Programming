#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 1e3 + 3;

int n, m, u, v, sc = 0;
char c;
vector<tuple<int, int, int> > M, S, vec;

int par[N], pu, pv;

void reset_dsu (int n) {
    for (int i = 1; i <= n; ++ i) par[i] = i;
}

int fin (int u) {
    return (u == par[u] ? u : par[u] = fin(par[u]));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #define task ""
    if (fopen (task".inp", "r")) {
        freopen (task".inp", "r", stdin);
        freopen (task".out", "w", stdout);
    }

    cin >> n >> m;
    for (int i = 1; i <= m; ++ i) {
        cin >> u >> v >> c;
        if (u == v) continue;
        if (c == 'M') M.push_back({u, v, i});
        else S.push_back({u, v, i});
    }

    if (n == 1) return cout << 0, 0;
    if (n % 2 == 0) return cout << -1, 0;

    reset_dsu(n);
    for (auto [u, v, i] : M) {
        pu = fin(u); pv = fin(v);
        if (pu != pv) {
            par[pv] = pu;
            sc ++;
        }
    }

    for (auto [u, v, i] : S) {
        pu = fin(u); pv = fin(v);
        if (pu != pv) {
            par[pv] = pu;
            sc --;
            vec.push_back({u, v, i});
        }
    }

    reset_dsu(n);
    for (auto [u, v, i] : vec) {
        pu = fin(u); pv = fin(v);
        par[pv] = pu;
    }

    for (auto [u, v, i] : S) {
        if (sc <= 0) break;
        pu = fin(u); pv = fin(v);
        if (pu != pv) {
            par[pv] = pu;
            sc -= 2;
            vec.push_back({u, v, i});
        }
    }

    if (sc != 0) return cout << -1, 0;


    for (auto [u, v, i] : M) {
        pu = fin(u); pv = fin(v);
        if (pu != pv) {
            par[pv] = pu;
            vec.push_back({u, v, i});
        }
    }

    if (vec.size() < n - 1) return cout << -1, 0;

    cout << vec.size() << '\n';
    for (auto [u, v, i] : vec) cout << i << ' ';

    return 0;
}
