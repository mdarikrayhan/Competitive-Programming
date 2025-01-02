#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ff first
#define sc second
#define mp make_pair
#define pb push_back
#define pp pop_back
#define nn "\n"

void solve()
{
    ll a, b;
    cin >> a >> b;
    if (b == 1)
    {
        ll s = ((a) * (a - 1)) / 2;
        cout << s << " " << s << nn;
    }
    else
    {
        ll k = a - b + 1;
        ll s = ((k) * (k - 1)) / 2;
        ll x = a / b;

        ll md = a % b;

        ll m = (b - md) * (x * (x - 1)) / 2;

        x++;

        m += md * (x * (x - 1)) / 2;

        cout << m << " " << s << nn;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}