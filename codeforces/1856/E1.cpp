/*AUTHOR : ANTU RANA*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

int ans = 0;

int getans(vector<int> &v)
{
    int n = v.size();
    if (n == 1)
        return 0;
    int sum = 0;
    for (auto i : v)
    {
        sum += i;
    }
    vector<int> dp(sum + 1, 0), newdp(sum + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        newdp = dp;
        for (int j = 1; j <= sum; j++)
        {
            if (j - v[i] >= 0 && dp[j - v[i]] == 1)
            {
                newdp[j] = 1;
            }
        }
        dp = newdp;
    }
    int maxi = 0;
    for (int i = 1; i < sum; i++)
    {
        if (dp[i])
        {
            maxi = max(maxi, i * (sum - i));
        }
    }
    return maxi;
}
int solve(int root, int par, vector<vector<int>> &adj)
{
    vector<int> subtree_sizes;
    int curr_subtree_size = 0;
    for (auto i : adj[root])
    {
        if (i != par)
        {
            int subtree_curr = solve(i, root, adj);
            subtree_sizes.push_back(subtree_curr);
            curr_subtree_size += subtree_curr;
        }
    }
    int maxi = getans(subtree_sizes);
    ans += maxi;
    return curr_subtree_size + 1;
}
signed main()
{

    int n;
    cin >> n;
    vector<vector<int>> adj(n);

    for (int i = 1; i < n; i++)
    {
        int p;
        cin >> p;
        p--;
        adj[i].push_back(p);
        adj[p].push_back(i);
    }

    int root = 0;
    solve(root, -1, adj);
    cout << ans << endl;

    return 0;
}