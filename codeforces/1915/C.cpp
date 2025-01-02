#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
#define ll long long
bool isPerfectSquare(ll x)
{
    if (x >= 0)
    {
        ll sr = sqrt(x);
        return (sr * sr == x);
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--)
    {
        ll n;
        cin >> n;
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            ans += x;
        }
        if (isPerfectSquare(ans))
        {
            cout << "YES" << nl;
        }
        else
        {

            cout << "NO" << nl;
        }
    }
    return 0;
}