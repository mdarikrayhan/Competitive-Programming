// LUOGU_RID: 160269439
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

#ifdef ONLINE_JUDGE
#define debug(...) 0
#else
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, S;
        cin >> n >> S;
        using edge = tuple<int, int, int>;
        vector<tuple<int, int, int>> e(n - 1);
        for (int i = 0, u, v, w; i < n - 1; i++) {
            cin >> u >> v >> w;
            u--, v--;
            e[i] = {u, v, w};
        }

        const int mod = 998244353;
        auto qpow = [](int a, ll b) {
            int res = 1;
            while (b) {
                if (b & 1) res = 1ll * res * a % mod;
                a = 1ll * a * a % mod;
                b >>= 1;
            }
            return res;
        };

        vector<int> fa(n), siz(n);
        iota(fa.begin(), fa.end(), 0);
        fill(siz.begin(), siz.end(), 1);
        function<int(int)> find = [&](int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);};
        auto merge = [&](int x, int y) {
            x = find(x), y = find(y);
            if (x != y) {
                siz[y] += siz[x];
                fa[x] = y;
            }
        };

        sort(e.begin(), e.end(), [](const edge &a, const edge &b) {return get<2>(a) < get<2>(b);});

        int ans = 1;

        for (auto [u, v, w]: e) {
            u = find(u), v = find(v);
            ans = 1ll * ans * qpow(S - w + 1, 1ll * siz[u] * siz[v] - 1) % mod;
            merge(u, v);
        }

        cout << ans << "\n";
    }
    return 0;
}