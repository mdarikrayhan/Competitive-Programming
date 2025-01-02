#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll, ll> mp, np;
int main()
{
  
    ll q;
    cin >> q;
    while (q--)
    {
        getchar();
        char op;
        cin >> op;
        ll x;
        cin >> x;
        if (op == '+')
            mp[x] = 1;
        else
        {
            if (!mp[x])
                cout << x << endl;
            else
            {
                if (np[x] == 0)
                {
                    ll t = x;
                    while (1)
                    {
                        if (mp[t] == 0)
                        {
                            cout << t << endl;
                            np[x] = t;
                            break;
                        }
                        else
                            t += x;
                    }
                }
                else
                {
                    ll k = np[x];
                    while (1)
                    {
                        if (mp[k] == 0)
                        {
                            cout << k << endl;
                            np[x] = k;
                            break;
                        }
                        else
                            k += x;
                    }
                }
            }
        }
    }
    return 0;
}