// LUOGU_RID: 158539387
#include <bits/stdc++.h>
using i64 = long long;
constexpr int mod = 998244353;
constexpr i64 MOD = 1e9 + 7;
constexpr int inf = 0x3f3f3f3f;
constexpr i64 INF = 0x3f3f3f3f3f3f3f3f;

i64 power(i64 a, i64 b)
{
    i64 res = 1;
    while(b)
    {
        if(b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

void solve()
{
    int n;
    std::cin >> n;
    int tot = power(2, n);
    std::vector<std::vector<std::pair<int, int>>> adj(tot);
    for(int i = 0; i < tot; i++)
    {
        int a, b;
        std::cin >> a >> b;
        adj[i].emplace_back(i * 2 + 1, a);
        adj[i].emplace_back(i * 2 + 2, b);
    }
    int ans = 0;
    auto dfs = [&](auto self, int u) -> int
    {
        if(u >= tot - 1) return 0;
        int ls = self(self, u * 2 + 1);
        int rs = self(self, u * 2 + 2);
        auto [s1, w1] = adj[u][0];
        auto [s2, w2] = adj[u][1];
        ans += abs(ls + w1 - rs - w2);
        return std::max(ls + w1, rs + w2);
    };
    dfs(dfs, 0);
    std::cout << ans;
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