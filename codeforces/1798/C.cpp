#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
#define int long long
#define vi vector<int>
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    cin >> T;
    for (int tt = 1; tt <= T; tt++)
    {
        int n;
        cin >> n;
        vi a(n), b(n), c(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i] >> b[i];
        }

        for (int i = 0; i < n; i++)
        {
            c[i] = a[i] * b[i];
        }
        int gcd = c[0];
        int lcm = b[0];
        int ans = 0;
        for (int i = 0; i < n - 1; i++)
        {
            gcd = __gcd(gcd, c[i + 1]);
            lcm = (lcm * b[i + 1]) / (__gcd(lcm, b[i + 1]));
            if (gcd % lcm)
            {
                ans++;
                gcd = c[i + 1];
                lcm = b[i + 1];
            }
        }
        cout << ans + 1 << endl;
    }
    return 0;
}