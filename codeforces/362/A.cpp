// LUOGU_RID: 158265174
#include <bits/stdc++.h>
using i64 = long long;
constexpr int mod = 998244353;
constexpr i64 MOD = 1e9 + 7;
constexpr int inf = 0x3f3f3f3f;
constexpr i64 INF = 0x3f3f3f3f3f3f3f3f;

void solve()
{
    std::vector<std::string> s(8);
    bool f = 0;
    int x1, y1, x2, y2;
    for(int i = 0; i < 8; i++)
    {
        std::cin >> s[i];
    }
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(s[i][j] == 'K')
            {
                if(f)
                {
                    x1 = i;
                    y1 = j;
                }
                else
                {
                    x2 = i;
                    y2 = j;
                    f = 1;
                }
            }
        }
    }
    std::cout << (((x1 - x2) % 4 == 0 && (y1 - y2) % 4 == 0) ? "YES\n" : "NO\n");
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}