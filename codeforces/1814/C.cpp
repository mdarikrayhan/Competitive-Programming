#include <bits/stdc++.h>
using ll = long long;

void solve()
{
    int n, s[2];
    std::cin >> n >> s[0] >> s[1];

    std::vector<int> r(n), pos(n);
    std::vector<std::vector<int>> v(2);
    for (int i = 0; i < n; i++)
    {
        std::cin >> r[i];
        pos[i] = i;
    }
    std::sort(pos.begin(), pos.end(), [&](int i, int j)
              { return r[i] > r[j]; });

    int last[2]{};
    for (auto i : pos)
    {
        if (last[0] + s[0] <= last[1] + s[1])
            v[0].push_back(i + 1), last[0] += s[0];
        else
            v[1].push_back(i + 1), last[1] += s[1];
    }

    for (auto a : v)
    {
        std::cout << a.size() << " ";
        for (auto x : a)
        {
            std::cout << x << " ";
        }
        std::cout << "\n";
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int _ = 1;
    std::cin >> _;

    while (_--)
    {
        solve();
    }
    return 0;
}
