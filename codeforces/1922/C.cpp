#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
#define ll long long
#define vl vector<ll>
#define rep(i, a, b) for (ll i = a; i < b; i++)
#define per(i, a, b) for (ll i = b - 1; i >= a; i--)
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--)
    {
        ll n, x, y, q;
        cin >> n;
        ll a[n], v[n], l[n], r[n];
        v[0] = 1;
        v[n - 1] = -1;
        rep(i, 0, n)
        {
            cin >> a[i];
        }
        rep(i, 1, n - 1)
        {
            v[i] = (abs(a[i] - a[i - 1]) < abs(a[i] - a[i + 1]) ? -1 : 1);
        }
        rep(i, 1, n)
        {
            l[i] = (v[i] == -1 ? 1 + l[i - 1] : abs(a[i] - a[i - 1]) + l[i - 1]);
            r[n - 1 - i] = (v[n - 1 - i] == 1 ? 1 + r[n - i] : abs(a[n - 1 - i] - a[n - i]) + r[n - i]);
        }
        cin >> q;
        while (q--)
        {
            cin >> x >> y;
            if (y >= x)
            {
                cout << r[x - 1] - r[y - 1] << nl;
            }
            else
            {
                cout << l[x - 1] - l[y - 1] << nl;
            }
        }
    }
    return 0;
}