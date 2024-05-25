// LUOGU_RID: 159912835
#include <bits/stdc++.h>
using i64 = long long;
constexpr int mod = 998244353;
constexpr i64 MOD = 1e9 + 7;
constexpr int inf = 0x3f3f3f3f;
constexpr i64 INF = 0x3f3f3f3f3f3f3f3f;

void solve()
{
    i64 n;
    std::cin >> n;
    std::cout << n - (n / 2 + n / 3 + n / 5 + n / 7 - n / 6 - n / 10 - n / 14 - n / 15 - n / 21 - n / 35 + n / 30 + n / 42 + n / 70 + n / 105 - n / 210);
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