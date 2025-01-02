// LUOGU_RID: 160149472
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 200'005
#define endl '\n'
int n, m, a[N];
void solve()
{
    cin >> n;
    for (int i = 2; i <= n; i += 2)
        cin >> a[i];
    int sum = 0;
    for (int i = 1; i <= n; i += 2)
    {
        bool ok = 0;
        for (int j = sqrt(a[i + 1]); j >= 1; j--)
            if (a[i + 1] % j == 0 && (j % 2 == (a[i + 1] / j) % 2))
            {
                int x = (a[i + 1] / j - j) / 2, y = (a[i + 1] / j + j) / 2;
                if (x * x > sum)
                {
                    a[i] = x * x - sum;
                    ok = 1;
                    break;
                }
            }
        if (!ok)
        {
            cout << "No";
            return;
        }
        sum += a[i] + a[i + 1];
    }
    cout << "Yes\n";
    for (int i = 1; i <= n; i++)
        cout << a[i] << ' ';
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}