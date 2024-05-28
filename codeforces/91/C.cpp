#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) 0
#endif

#define pb push_back
#define ll long long
#define i2 array<int, 2>
#define SZ(x) (int) (x).size()

const int N = 1e5 + 4;
const int M = 1e9 + 9;

int n, m, comp, pw[N], p[N], sz[N];

int root(int v) {
    return p[v] == v ? v : p[v] = root(p[v]);
}

void merge(int v, int u) {
    v = root(v);
    u = root(u);
    if (v == u)
        return;
    if (sz[v] < sz[u])
        swap(v, u);
    comp--;
    p[u] = v;
    sz[v] += sz[u];
}

void solve() {
    pw[0] = 1;
    for (int i = 1; i < N; i++)
        pw[i] = 2LL * pw[i - 1] % M;

    cin >> n >> m;
    comp = n;
    for (int i = 1; i <= n; i++)
        p[i] = i, sz[i] = 1;

    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        merge(a, b);
        cout << (i - n + comp >= 0 ? (pw[i - n + comp] - 1 + M) % M : 0) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

