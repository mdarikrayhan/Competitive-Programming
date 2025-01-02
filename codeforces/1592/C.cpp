#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
i64 const &N = 2E5 + 500; 
i64 const &INF = 999999999999999999;

i64 n, k, cnt, x;
vector<i64> G[N], xorValue(N, 0), A(N, 0);

void dfs(i64 u, i64 p) {
    xorValue[u] = A[u];
    for (auto x : G[u]) {
        if (x == p) continue;
        dfs(x, u);
        xorValue[u] ^= xorValue[x];
    }
    if (xorValue[u] == x) {
        cnt++;
        xorValue[u] = 0;
    }
}

void clearAll(i64 n) {
    x = cnt = 0;
    for (i64 i = 0; i <= n; ++i) {
        G[i].clear();
        xorValue[i] = A[i] = 0;
    }
}

void Solution() {
    cin >> n >> k;
    clearAll(n);
    for (i64 i = 1; i <= n; i ++) {
        cin >> A[i];
        x ^= A[i];
    }
    for (i64 i = 0; i < n - 1; i ++) {
        i64 u, v; cin >> u >> v;
        G[u].push_back(v), G[v].push_back(u);
    }
    dfs(1, -1);
    bool ok = 0;
    if (x == 0 || (k > 2 && cnt >= 3)) {
        ok = 1;
    }
    cout << (ok ? "YES\n" : "NO\n");
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    i64 T;
    cin >> T;

    while (T --) {
        Solution();
    }

    return 0;
}