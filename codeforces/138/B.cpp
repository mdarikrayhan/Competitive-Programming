#include <bits/stdc++.h>
using i64 = long long;
constexpr int mod = 998244353;
constexpr i64 MOD = 1e9 + 7;
constexpr int inf = 0x3f3f3f3f;
constexpr i64 INF = 0x3f3f3f3f3f3f3f3f;

void solve()
{
    std::string s;
    std::cin >> s;
    std::vector<int> d1(10), d2(10), num(10);
    for(auto c : s)
    {
        num[c - '0']++;
    }
    std::string s1, s2;
    int mx = 0;
    for(int i = 1; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            d1[j] = d2[j] = num[j];
        }
        std::string t1, t2;
        int sum = 0, mn = inf;
        if(d1[i] && d2[10 - i])
        {
            sum += 1;
            t1 += std::to_string(i);
            t2 += std::to_string(10 - i);
            d1[i] -= 1, d2[10 - i] -= 1;
            for(int j = 0; j < 10; j++)
            {
                mn = std::min(d1[j], d2[9 - j]);
                d1[j] -= mn, d2[9 - j] -= mn;
                sum += mn;
                t1 = std::string(mn, j + '0') + t1;
                t2 = std::string(mn, 9 - j + '0') + t2;
            }
        }
        mn = std::min(d1[0], d2[0]);
        d1[0] -= mn, d2[0] -= mn;
        sum += mn;
        t1 += std::string(mn, '0');
        t2 += std::string(mn, '0');
        for(int j = 0; j < 10; j++)
        {
            t1 = std::string(d1[j], j + '0') + t1;
            t2 = std::string(d2[j], j + '0') + t2;
        }
        if(sum >= mx)
        {
            mx = sum;
            s1 = t1;
            s2 = t2;
        }
    }
    std::cout << s1 << "\n" << s2;
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