// LUOGU_RID: 160015066
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
    std::vector<int> a(n), l(m), r(m);
    int mx = -1, p = 0, res = 0;
    for(int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    for(int i = 0; i < m; i++)
    {
        std::cin >> l[i] >> r[i];
        l[i]--, r[i]--;
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int cur = a[j] - a[i], sum = 0;
            for(int k = 0; k < m; k++)
            {
                if(l[k] <= i && r[k] >= i &&(l[k] > j || r[k] < j))
                {
                    cur++;
                }
                if(l[k] <= i && r[k] >= i)
                {
                    sum++;
                }
            }
            if(mx < cur)
            {
                mx = cur;
                p = i;
                res = sum;
            }
        }
    }
    std::cout << mx << "\n" << res << "\n";
    for(int i = 0; i < m; i++)
    {
        if(l[i] <= p && r[i] >= p)
        {
            std:: cout << i + 1 << " ";
        }
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