#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define cy cout << "YES\n"
#define cn cout << "NO\n"
#define c1 cout << "-1\n"
#define all(x) x.begin(), x.end()
#define re(x) x.rbegin(), x.rend()
#define F first
#define S second
#define ii pair<ll, ll>
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using namespace std;

int main()
{
    IOS
        ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n, l, r;
        cin >> n >> l >> r;
        vector<ll> left(l), right(r);
        map<ll, ll> mp, mp1;
        ll temp = n / 2;
        ll l2 = l;
        for (ll i = 0; i < l; i++)
        {
            cin >> left[i];
            mp[left[i]]++;
        }

        for (ll i = 0; i < r; i++)
        {
            cin >> right[i];
            if (mp[right[i]] > 0)
            {
                temp--;
                mp[right[i]]--;
                l2--;
            }
            else
            {
                mp1[right[i]]++;
            }
        }

        ll ans = 0;
        ll l1 = 0, r1 = 0;

        for (auto it : mp)
        {
            l1 += it.second;
        }
        for (auto it : mp1)
        {
            r1 += it.second;
        }
        if (l == r)
        {
            cout << l2 << endl;
            continue;
        }
        ans += min(l1, r1);
        temp -= min(l1, r1);
        // cout << ans << endl;
        if (l >= r)
        {

            for (auto it : mp)
            {
                if (it.second > 1)
                {
                    ll temp2 = it.second / 2;
                    if (temp2 >= temp)
                    {
                        ans += temp;
                        temp = 0;
                        break;
                    }
                    temp -= temp2;

                    ans += temp2;
                }
                if (temp == 0)
                    break;
            }
        }
        else
        {
            for (auto it : mp1)
            {
                if (it.second > 1)
                {
                    ll temp2 = it.second / 2;
                    if (temp2 >= temp)
                    {
                        ans += temp;
                        temp = 0;
                        break;
                    }
                    temp -= temp2;
                    ans += temp2;
                }
                if (temp == 0)
                    break;
            }
        }

        ans += temp * 2;

        cout << ans << endl;
    }
    return 0;
}
