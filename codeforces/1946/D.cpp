#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, x;
    cin >> n >> x;

    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    ll mx = LLONG_MIN;
    ll ans = n;
    vector<ll> partition;
    for (ll i = 29; i >= 0; i--)
    {
        ll cnt = 0;
        for (ll j = 0; j < n; j++)
        {
            if ((arr[j] & (1LL << i)))
                cnt++;
        }

        ll p = (x & (1LL << i));

        if (cnt % 2 == 1)
        {
            if (p == 0)
            {
                if (mx == LLONG_MIN)
                    cout << -1 << endl;
                else
                    cout << mx << endl;
                return;
            }
            else
                continue;
        }

        
        partition.push_back(i);
        vector<ll>c(30);
        ll y = 0;
        for (ll j = 0; j < n; j++)
        {
            for (ll k = 0; k < 30; k++)
            {
                if(arr[j] & (1LL << k))c[k] ^= 1;
            }
            
            ll z = 1;
            for (auto u : partition)
            {
                if(c[u])z = 0;
            }
            y += z;
        }

        if(x & (1LL << i)){
            partition.pop_back();
            mx = max(mx, y);
        }
        else ans = y;
        
    }
    cout << max(mx, ans) << endl;;
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}