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
        int n;
        cin >> n;
        vector<long long> a(n), b(n), c(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i] >> b[i];
        }

        for (int i = 0; i < n; i++)
        {
            c[i] = a[i] * b[i];
        }
        long long gcd = c[0];
        long long lcm = b[0];
        long long ans = 0;
        for (int i = 1; i < n; i++)
        {
            gcd = __gcd(gcd, c[i]);
            lcm = (lcm * b[i]) / (__gcd(lcm, b[i]));
            if (gcd % lcm)
            {
                ans++;
                gcd = c[i];
                lcm = b[i];
            }
        }
        cout << ans + 1 << endl;
    }
    return 0;
}