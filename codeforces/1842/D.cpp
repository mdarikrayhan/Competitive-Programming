// LUOGU_RID: 160028007
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 200'005
#define endl '\n'
#define PII pair<int, int>
int n, m, d[105], dis[105][105], ans[105][105];
void solve()
{
    memset(dis, 0x3f, sizeof(dis));
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        dis[i][i] = 0;
    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        dis[x][y] = min(dis[x][y], z);
        dis[y][x] = min(dis[y][x], z);
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dis[i][j] = min(dis[i][k] + dis[k][j], dis[i][j]);
    if (dis[1][n] == dis[0][0])
    {
        cout << "inf";
        return;
    }
    int top = 0;
    for (int i = 1; i <= n; i++)
        d[i] = dis[n][i];
    priority_queue<int> q;
    for (int i = 1; i <= n; i++)
        if (d[i])
            q.push(-d[i]);
    int pos = 0;
    while (d[1])
    {
        int t = -q.top() - pos;
        q.pop();
        pos += t;
        if (!t)
            continue;
        top++;
        for (int i = 1; i <= n; i++)
        {
            if (d[i])
                ans[top][i] = 1, d[i] -= t;
            else
                ans[top][i] = 0;
        }
        ans[top][0] = t;
    }
    cout << dis[1][n] << ' ' << top << endl;
    for (int i = 1; i <= top; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << ans[i][j];
        cout << ' ' << ans[i][0] << endl;
    }
}
signed main()
{
    int t = 1;
    // cin>>t;
    while (t--)
        solve();
    return 0;
}