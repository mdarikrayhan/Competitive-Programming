#include <bits/stdc++.h>
using i64 = long long;
constexpr int mod = 998244353;
constexpr i64 MOD = 1e9 + 7;
constexpr int inf = 0x3f3f3f3f;
constexpr i64 INF = 0x3f3f3f3f3f3f3f3f;

void solve()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> s1(n), s2(m);
    for(int i = 0; i < n; i++)
    {
        std::cin >> s1[i];
    }
    for(int i = 0; i < m; i++)
    {
        s2[i].resize(n);
    }
    auto check = [&](std::vector<std::string> s)
    {
        if(n % 3)
            return false;
        int d = n / 3;
        if(s[d][0] == s[0][0] || s[d * 2][0] == s[0][0] || s[d][0] == s[d * 2][0])
            return false;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(s[i][j] != s[i / d * d][0]) return false;
            }
        }
        return true;
    };
    if(check(s1))
    {
        std::cout << "YES";
        return;
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            s2[j][i] = s1[i][j];
        }
    }
    std::swap(n, m);
    if(check(s2))
    {
        std::cout << "YES";
        return;
    }
    std::cout << "NO";
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