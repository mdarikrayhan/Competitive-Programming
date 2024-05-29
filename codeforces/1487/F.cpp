#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    s = "0" + s;
    int n = s.length();
    map<array<int, 3>, int> dp;
    auto dfs = [&](auto &dfs, int cur, int val, int add) -> int
    {
        if (abs(val) > 1000)
            return 1e9;
        if (dp.count({cur, val, add}))
            return dp[{cur, val, add}];
        if (cur == n)
        {
            if (val)
                dp[{cur, val, add}] = 1e9;
            else
                dp[{cur, val, add}] = 0;
            return dp[{cur, val, add}];
        }
        int ret = 1e9;
        for (int i = -18; i <= 18; i++)
        {
            int now = val + add + i - (s[cur] - '0');
            ret = min(ret, dfs(dfs, cur + 1, now * 10, add + i) + abs(i) * (n - cur));
        }
        return dp[{cur, val, add}] = ret;
    };
    cout << dfs(dfs, 0, 0, 0) << '\n';
}
