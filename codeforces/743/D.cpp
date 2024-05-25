// LUOGU_RID: 159002399
#include <bits./stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define N 200005
int n, ans = -1e12, a[N], si[N], dp[N], f[N];
vector<int> e[N];
void dfs(int u, int fa)
{
    f[u] = fa;
    si[u] = a[u];
    for (auto to : e[u])
        if (to != fa)
        {
            dfs(to, u);
            si[u] += si[to];
        }
    dp[u] = si[u];
    for (auto to : e[u])
        if (to != fa)
            dp[u] = max(dp[u], dp[to]);
}
signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
    {
        priority_queue<int, vector<int>, greater<int>> q;
        for (auto to : e[i])
            if (to != f[i])
            {
                if (q.size() < 2)
                    q.push(dp[to]);
                else if (q.top() < dp[to])
                {
                    q.pop();
                    q.push(dp[to]);
                }
            }
        if (q.size() == 2)
        {
            int sum = 0;
            while (!q.empty())
            {
                sum += q.top();
                q.pop();
            }
            ans = max(ans, sum);
        }
        while (!q.empty())
            q.pop();
    }
    if (ans == -1e12)
        cout << "Impossible";
    else
        cout << ans;
    return 0;
}