#include <bits/stdc++.h>
using i64 = long long;
constexpr int mod = 998244353;
constexpr i64 MOD = 1e9 + 7;
constexpr int inf = 0x3f3f3f3f;
constexpr i64 INF = 0x3f3f3f3f3f3f3f3f;

void solve()
{
    int n;
    std::cin >> n;
    i64 x = 1, y = 1;
    for(int i = 0; i < n; i++)
    {
        std::string s;
        std::cin >> s;
        if(s == "UL" || s == "DR")
        {
            x++;
        }
        else if(s == "UR" || s == "DL")
        {
            y++;
        }
        else
        {
            x++;
            y++;
        }
    }
    std::cout << x * y;
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
 		 	 			  					 	 	   	 	   	