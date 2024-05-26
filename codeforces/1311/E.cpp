// LUOGU_RID: 160022064
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 200005
#define endl '\n'
int n, d, sum, cd[N], dep[N], f[N];
void solve()
{
    cin >> n >> d;
    sum = 0;
    for (int i = 2; i <= n; i++)
        sum += __lg(i);                 // 每一个数最大深度
    if (d > n * (n - 1) / 2 || d < sum) // 判断是否有解
    {
        cout << "NO\n";
        return;
    }
    dep[1] = 0;
    for (int i = 2; i <= n; i++) // 从链开始维护
    {
        f[i] = i - 1;
        dep[i] = dep[i - 1] + 1;
        cd[i - 1] = 1;
    }
    cd[n] = 0;
    sum = n * (n - 1) / 2; // 现在深度
    // cout << sum << endl;
    while (sum > d)
    {
        int maxn = 0, pos = 0;
        for (int i = n; i >= 2; i--)
            if (maxn < dep[i])
            {
                maxn = dep[i];
                pos = i;
            }
        cd[f[pos]]--;
        int dis = n, fa = 0;
        for (int i = n; i >= 1; i--)
            if (sum - (maxn - 1 - dep[i]) >= d && cd[i] <= 1)
            {
                if (dis > dep[i])
                {
                    dis = dep[i];
                    fa = i;
                }
            }
        cd[fa]++;
        f[pos] = fa;
        dep[pos] = dis + 1;
        sum -= maxn - 1 - dis;
        // cout << pos << ' ' << fa << ' ' << maxn << ' ' << dis << endl;
        // cout << sum << endl;
    }
    cout << "YES\n";
    for (int i = 2; i <= n; i++)
        cout << f[i] << ' ';
    cout << endl;
}
signed main()
{
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}