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
    for (int i = 1; i <= T; i++)
    {
        double a, b, c;
        cin >> a >> b >> c;
        double s = (a + b + c) / 2;
        double p = s * (s - a) * (s - b) * (s - c);
        double r = sqrt(p);
        cout << "Case " << i << ": " << fixed << setprecision(10) << r << nl;
    }
    return 0;
}