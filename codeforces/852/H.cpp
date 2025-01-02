// LUOGU_RID: 160515600
#include <bits/stdc++.h>

using LL = long long;

constexpr LL inf64 = (LL)(1e18) + 18;

constexpr int N = 202;

int n, m1, m2, k;
std::pair<int, int> e[N];
LL f[N][55];
bool ok[N][N];
std::vector<std::pair<int, int>> vec;

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d%d", &e[i].first, &e[i].second);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) if (i != j) vec.push_back({i, j});
    std::sort(vec.begin(), vec.end(), [](auto a, auto b) {
        auto [a1, a2] = a;
        auto [b1, b2] = b;
        int x1 = e[a2].first - e[a1].first, y1 = e[a2].second - e[a1].second;
        int x2 = e[b2].first - e[b1].first, y2 = e[b2].second - e[b1].second;
        if ((x1 >= 0) != (x2 >= 0)) return x1 >= 0;
        return 1ll * x1 * y2 - 1ll * x2 * y1 > 0;
    });
    LL max = 0;
    for (int o = 1; o <= n; o++) {
        std::vector<int> h;
        for (int i = 1; i <= n; i++) {
            if (i == o) continue;
            if (e[i].first >= e[o].first) h.push_back(i);
        }
        std::sort(h.begin(), h.end(), [&](auto x, auto y) {
            int x1 = e[x].first - e[o].first, y1 = e[x].second - e[o].second;
            int x2 = e[y].first - e[o].first, y2 = e[y].second - e[o].second;
            return 1ll * x1 * y2 - 1ll * x2 * y1 > 0;
        });
        std::fill_n((bool*)ok, N * N, 0);
        for (int x : h) ok[o][x] = ok[x][o] = 1;
        for (int i = 0; i + 1 < h.size(); i++) {
            ok[h[i]][h[i + 1]] = 1;
            int p = i + 1;
            for (int j = i + 2; j < h.size(); j++) {
                int x1 = e[h[p]].first - e[h[i]].first, y1 = e[h[p]].second - e[h[i]].second;
                int x2 = e[h[j]].first - e[h[p]].first, y2 = e[h[j]].second - e[h[p]].second;
                if (1ll * x1 * y2 - 1ll * x2 * y1 > 0) {
                    ok[h[i]][h[j]] = 1;
                    p = j;
                }
            }
        }
        std::fill_n((LL*)f, N * 55, -inf64);
        f[o][0] = 0;
        for (auto [x, y] : vec) {
            if (!ok[x][y]) continue;
            int x1 = e[x].first - e[o].first, y1 = e[x].second - e[o].second;
            int x2 = e[y].first - e[o].first, y2 = e[y].second - e[o].second;
            LL s = std::abs(1ll * x1 * y2 - 1ll * x2 * y1);
            for (int i = 1; i <= k; i++)
                f[y][i] = std::max(f[y][i], f[x][i - 1] + s);
        }
        max = std::max(max, f[o][k]);
    }
    printf("%.2lf\n", max / 2.);
    return 0;
}