#include <bits/stdc++.h>
using namespace std;
#define int long long

int dfs(int node, int parent, vector<vector<int>> &A, vector<int> &dp)
{
    int count = 1;
    for (int child : A[node])
        if (child != parent)
            count += dfs(child, node, A, dp);
    return dp[node] = count;
}

int solve(int node, int parent, vector<vector<int>> &A, vector<int> &counts, vector<int> &dp)
{
    if (dp[node] != -1)
        return dp[node];

    if (A[node].size() == 1)
    {
        if (node == 1)
            return counts[A[node][0]] - 1;
        else
            return 0;
    }
    else if (node != 1 and A[node].size() == 2)
    {
        for (int child : A[node])
            if (child != parent)
                return counts[child] - 1;
        return 0;
    }

    int curr = 0;
    vector<int> children = {};
    for (int child : A[node])
        if (child != parent)
            children.push_back(child);

    curr = max(curr, counts[children[0]] - 1 + solve(children[1], node, A, counts, dp));
    curr = max(curr, counts[children[1]] - 1 + solve(children[0], node, A, counts, dp));
    return dp[node] = curr;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<vector<int>> A(n + 1);
        for (int i = 1; i < n; i++)
        {
            int u, v;
            cin >> u >> v;

            A[u].push_back(v), A[v].push_back(u);
        }

        vector<int> counts(n + 1, 0);
        dfs(1, -1, A, counts);
        vector<int> dp(n + 1, -1);
        int ans = solve(1, -1, A, counts, dp);
        cout << ans << "\n";
    }
    return 0;
}