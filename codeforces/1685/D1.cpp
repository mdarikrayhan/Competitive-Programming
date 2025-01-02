// LUOGU_RID: 159095076
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

#define MAXN 205

int n;

int val[MAXN];

bool vis[MAXN];

int res[MAXN];

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> val[i];
    }
    for (int i = 1; i < n; i++)
    {
        memset(vis, 0, sizeof(vis));
        for (int j = val[i]; j != i; j = val[j])
        {
            vis[j] = true;
        }
        if (!vis[i + 1])
        {
            iter_swap(find(val + 1, val + n + 1, i), find(val + 1, val + n + 1, i + 1));
        }
    }
    res[n] = 1;
    for (int i = n - 1; i; i--)
    {
        res[i] = val[res[i + 1]];
    }
    for (int i = 1; i <= n; i++)
    {
        cout << res[i] << ' ';
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
