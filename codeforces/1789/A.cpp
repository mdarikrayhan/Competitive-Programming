#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define gcd(a, b) __gcd(a, b)
int main()
{

    int t;
    cin >> t;
    for (int x = 0; x < t; x++)
    {
        ll n;
        cin >> n;
        ll mini = INT_MAX;
        vector<ll> a(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                mini = min(mini, gcd(a[i], a[j]));
            }
        }
        sort(a.begin(), a.end());
        if (mini > 2)
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
        }
    }

    return 0;
}