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
    std::vector<std::pair<i64, i64>> a(n - 1);
    std::priority_queue<i64, std::vector<i64>, std::greater<>> q;
    i64 tt, ww;
    std::cin >> tt >> ww;
    for(int i = 0; i < n - 1; i++)
    {
        auto &[t, w] = a[i];
        std::cin >> t >> w;
    }
    std::ranges::sort(a, [&](auto i, auto j) {
        if(i.first == j.first) return i.second < j.second;
        return i.first > j.first;
    } );
    int cur = 0, ans = inf;
    while(true)
    {
        while(cur < n - 1 && a[cur].first > tt)
        {
            q.emplace(a[cur].second - a[cur].first + 1);
            cur++;
        }
        ans = std::min(ans, int(q.size()) + 1);
        if(q.empty() || tt < q.top())
        {
            break;
        }
        tt -= q.top();
        q.pop();
    }
    std::cout << ans;
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