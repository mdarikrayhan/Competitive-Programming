#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long T = 1;
    cin >> T;
    for (long long i = 1; i <= T; i++)
    {
        unsigned long long n;
        cin >> n;
        if (n % 180 == 0 && n >= 180)
        {
            long long ans = (n / 180) + 2;
            long double angle = (long double)n / ans;
            cout << "Case " << i << ": " << ans << " " << setprecision(10) << round(angle) << nl;
        }
        else
        {
            cout << "Case " << i << ": Impossible" << nl;
        }
    }
    return 0;
}