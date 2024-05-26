#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct DSU {
    vector<int> e;
    DSU(int N) { e = vector<int>(N, -1); }

    // get representive component (uses path compression)
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

    bool same_set(int a, int b) { return get(a) == get(b); }

    int size(int x) { return -e[get(x)]; }

    bool unite(int x, int y) {  // union by size
        x = get(x), y = get(y);
        if (x == y) return false;
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y];
        e[y] = x;
        return true;
    }
};
void solve() {
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    set<int> s;
    int in[n] = {0};
    int self = 0;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        s.insert(a);
        s.insert(b);

        if (a != b) {
            in[a]++;
            in[b]++;
        }
        else {
            self++;
        }
        dsu.unite(a, b);
    }
    if (dsu.size(*s.begin()) != s.size()) {
        cout << "0\n";
        return;
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += 1LL * in[i] * (in[i] - 1) / 2;
    }
    ans += 1LL * self * (self - 1) / 2 + 1LL * self * (m - self);
    cout << ans << '\n';
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int T;
    // cin >> T;
    T = 1;
    while (T--) {
        solve();
    }
}