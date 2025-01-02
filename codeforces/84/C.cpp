#include <bits/stdc++.h>
using i64 = long long;
constexpr int mod = 998244353;
constexpr i64 MOD = 1e9 + 7;
constexpr int inf = 0x3f3f3f3f;
constexpr i64 INF = 0x3f3f3f3f3f3f3f3f;

void solve()
{
    int n, m;
    std::cin >> n;
    std::vector<std::array<int, 3>> c(n);
    for(int i = 0; i < n; i++)
    {
        auto &[x, r, id] = c[i];
        std::cin >> x >> r;
        id = i;
    }
    std::cin >> m;
    std::vector<std::pair<int, int>> p(m);
    for(int i = 0; i < m; i++)
    {
        auto &[x, y] = p[i];
        std::cin >> x >> y;
    }
    std::ranges::sort(c);
    // std::ranges::sort(p);
    int cnt = 0;
    std::vector<int> res(n);
    for(int i = 0; i < m; i++)
    {
        auto [x, y] = p[i];
        auto it = std::lower_bound(c.begin(), c.end(), std::array<int, 3> {x, 0, 0});
        auto [x1, r1, id1] = (it == c.end() ? std::array<int, 3> {inf, 0, 0} : *it);
        auto [x2, r2, id2] = (it == c.begin() ? std::array<int, 3> {-inf, 0, 0} : *std::prev(it));
        if(x >= x1 - r1 && x <= x1 + r1 && y <= r1 && y >= -r1 && (x - x1) * (x - x1) + y * y <= r1 * r1)
        {
            cnt += (res[id1] == 0);
            if(!res[id1]) res[id1] = i + 1;
        }
        if(x >= x2 - r2 && x <= x2 + r2 && y <= r2 && y >= -r2 &&  (x - x2) * (x - x2) + y * y <= r2 * r2)
        {
            cnt += (res[id2] == 0);
            if(!res[id2]) res[id2] = i + 1;
        }
    }
    std::cout << cnt << "\n";
    for(int i : res) std::cout << (i ? i : -1) << " ";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}