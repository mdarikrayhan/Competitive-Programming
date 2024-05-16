#include <bits/stdc++.h>
typedef long double ld;
typedef long long int ll;
using namespace std;

int main()
{
    ld n;
    cin >> n;

    ld x = log10(n / 5 + 1) / log10(2);
    if (x == ll(x))
    {
        x = ll(x);
    }
    else
    {
        x = ll(x) + 1;
    }

    ll bande = pow(2, x - 1);
    ll sumekkam = 5 * (pow(2, x - 1) - 1);
    ll remaining = ll(n) - sumekkam;
    ld ans = ld(remaining) / ld(bande);

    if (ans == ll(ans))
    {
        ans = ll(ans);
    }
    else
    {
        ans = ll(ans) + 1;
    }

    if (ans == 1) cout << "Sheldon" << endl;
    if (ans == 2) cout << "Leonard" << endl;
    if (ans == 3) cout << "Penny" << endl;
    if (ans == 4) cout << "Rajesh" << endl;
    if (ans == 5) cout << "Howard" << endl;

    return 0;
}
