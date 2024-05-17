#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long
#define fr(i, j, k) for (int i = j; i < k; i++)
#define fr2(i, j, k) for (int i = j - 1; i >= k; i--)
#define vp vector<pair<int, int>>
#define vi vector<int>
#define For(s) for (auto i : s)
#define pii pair<int, int>
#define mp map<int, int>
#define ld long double
#define se set<int>
#define ms multiset<int>
#define pb push_back
#define in insert
#define all(v) (v.begin(), v.end())
template <class T>
using oset = tree<T, null_type, less<T>, rb_tree_tag,
                  tree_order_statistics_node_update>;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // ceil a/b=(a-1+b)/b do remember
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n], b[n];
        for (int i = 0; i<n; i++)
        {
            cin >> a[i] >> b[i];
        }
        vector<vi> dp(n, vi(3, 1e9));
        dp[0][0] = 0;
        dp[0][1] = b[0];
        dp[0][2] = 2 * b[0];
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = 0;
            int p = 1e18;
            if (a[i] != a[i - 1])
            {
                p = min(p, dp[i - 1][0]);
            }
            if (a[i] != a[i - 1] + 1)
            {
                p = min(p, dp[i - 1][1]);
            }
            if (a[i] != a[i - 1] + 2)
            {
                p = min(p, dp[i - 1][2]);
            }
            dp[i][0] += p;
            dp[i][1] = b[i];
            p = 1e18;
            if (a[i] + 1 != a[i - 1])
            {
                p = min(p, dp[i - 1][0]);
            }
            if (a[i] + 1 != a[i - 1] + 1)
            {
                p = min(p, dp[i - 1][1]);
            }
            if (a[i] + 1 != a[i - 1] + 2)
            {
                p = min(p, dp[i - 1][2]);
            }
            dp[i][1] += p;
            p = 1e18;
            dp[i][2] = b[i] * 2;
            if (a[i] + 2 != a[i - 1])
            {
                p = min(p, dp[i - 1][0]);
            }
            if (a[i] + 2 != a[i - 1] + 1)
            {
                p = min(p, dp[i - 1][1]);
            }
            if (a[i] + 2 != a[i - 1] + 2)
            {
                p = min(p, dp[i - 1][2]);
            }
            dp[i][2] += p;
        }
        int ans = min(dp[n - 1][0], dp[n - 1][1]);
        ans = min(ans, dp[n - 1][2]);
        cout << ans << "\n";
    }
}