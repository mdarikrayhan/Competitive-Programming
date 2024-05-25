// LUOGU_RID: 159649035
#include <bits/stdc++.h>
using i64 = long long;
constexpr int mod = 998244353;
constexpr i64 MOD = 1e9 + 7;
constexpr int inf = 0x3f3f3f3f;
constexpr i64 INF = 0x3f3f3f3f3f3f3f3f;

void solve()
{
    int n, q;
    std::cin >> n >> q;
    std::vector<int> s(n);
    while(q--)
    {
        int t, k, d, cnt = 0, res = 0;
        std::cin >> t >> k >> d;
        std::vector<int> v;
        for(int i = 0; i < n; i++)
        {
            if(cnt == k) break;
            if(s[i] <= t)
            {
                cnt++;
                v.push_back(i);
                res += i + 1;
            }
        }
        if(cnt != k)
        {
            std::cout << -1 << "\n";
            continue;
        }
        for(int i : v) s[i] = t + d;
        std::cout << res << "\n";
    }
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