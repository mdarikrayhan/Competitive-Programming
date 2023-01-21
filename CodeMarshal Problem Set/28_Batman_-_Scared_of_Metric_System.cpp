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
        long double kilo;
        cin >> kilo;
        long double miles = kilo * 0.621371;
        cout << fixed << setprecision(10) << miles << nl;
    }
    return 0;
}