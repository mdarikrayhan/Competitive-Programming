// LUOGU_RID: 159211143
#include <bits/stdc++.h>
using i64 = long long;
constexpr int mod = 998244353;
constexpr i64 MOD = 1e9 + 7;
constexpr int inf = 0x3f3f3f3f;
constexpr i64 INF = 0x3f3f3f3f3f3f3f3f;

void solve()
{
    double y1, y2, yw, xb, yb, r;
    std::cin >> y1 >> y2 >> yw >> xb >> yb >> r;
    double a = yw - y1 - 2 * r;
    double b = yw - yb - r;
    double x = a * xb / (a + b);
    double l = std::sqrt(x * x + a * a);
    double ans = x * (y2 - y1 - r) / l;
    if(r > ans)
    {
        std::cout << -1;
    }
    else
    {
        std::cout << std::fixed << std::setprecision(10) << x;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}