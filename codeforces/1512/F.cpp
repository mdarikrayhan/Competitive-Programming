#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int maxn = 2e5 + 5;

int n, c;
int a[maxn], b[maxn], dp[maxn];

int solve(int i, int j)
{
    if(dp[i] != -1) return dp[i];
    if(i == n) return 1e10;
    if(j >= c) return 0;

    int x = 1e10, y = 1e10;

    x = ceil((double)(c - j) / (double) a[i]);
    if(i != n - 1)
    {
        y = ceil((double) (b[i] - j) / (double) a[i]);
        int l = max(y, 0LL);
        y = solve(i + 1, j + (l * a[i]) - b[i]) + l + 1;
    }
    return dp[i] = min(x, y);
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        memset(dp, -1, sizeof dp);

        cin >> n >> c;

        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n - 1; i++) cin >> b[i];

        cout << solve(0, 0) << endl;
    }


    return 0;
}
