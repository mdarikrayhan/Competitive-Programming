#include <bits/stdc++.h>
#define int long long
void solve()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> a[i];
    }
    std::sort(begin(a) + 1, end(a));
    for (int i = n; i >= 1; --i)
    {
        if (a[i] >= m)
        {
            std::cout << n - i + 1 << '\n';
            return;
        }
        else
        {
            m -= a[i];
        }
    }
}
signed main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int t = 1;
    // std::cin >> t;
    while (t--)
    {
        solve();
    }
}