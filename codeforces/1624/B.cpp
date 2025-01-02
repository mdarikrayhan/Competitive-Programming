#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define Fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

void TestCases()
{
    vector<ll> a(3), b;
    for (ll i = 0; i < 3; i++)
        cin >> a[i];

    ll mx = *max_element(a.begin(), a.end());
    ll mn = *min_element(a.begin(), a.end());
    if (mx == a[1])
    {
        ll d = abs(a[1] - a[2]);
        ll p = d + a[1];
        ll f = abs(a[1] - a[0]);
        ll q = f + a[1];
        if (p % a[0] == 0 or q % a[2] == 0)
        {
            cout << "YES" << endl;
            return;
        }
    }
    else
    {
        if (mn == a[1])
        {
            ll t = a.front() + a.back();
            if (t % 2 == 0)
            {
                ll r = t / 2;
                if (r % a[1] == 0)
                {
                    cout << "YES" << endl;
                    return;
                }
            }
        }
        else
        {
            ll t = a.front() + a.back();
            if (t % 2 == 0)
            {
                ll r = t / 2;
                if (r % a[1] == 0)
                {
                    cout << "YES" << endl;
                    return;
                }
            }
            ll d = abs(mx - a[1]);
            if ((a[1] - d) % mn == 0 and (a[1] - d) > 0)
            {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}

int main()
{
    Fast;

    int t = 1;
    cin >> t;
    while (t--)
        TestCases();
    return 0;
}