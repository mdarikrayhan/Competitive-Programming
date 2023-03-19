#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    cin >> T;
    for (int tt = 1; tt <= T; tt++)
    {
        long long n, q;
        cin >> n >> q;
        long long a[n + 3];
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        long long prefixsum[n + 3];
        prefixsum[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            prefixsum[i] = prefixsum[i - 1] + a[i];
        }
        while (q--)
        {
            long long l, r, k;
            cin >> l >> r >> k;
            long long res = prefixsum[n] - prefixsum[r] + prefixsum[l - 1];
            long long index = abs(r - l) + 1;
            long long ans = res + index * k;
            if (ans % 2 != 0)
            {
                cout << "YES" << nl;
            }
            else
            {

                cout << "NO" << nl;
            }
        }
        }
    return 0;
}