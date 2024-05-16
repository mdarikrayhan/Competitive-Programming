#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // n chests and m keys
    // i-th chest has an integer ai
    // j-th key has an integer bj

    // even + even = even
    // even + odd = odd
    // odd + odd = even

    ll n, m;
    cin >> n >> m;

    ll odds1 = 0, evens1 = 0;
    ll odds2 = 0, evens2 = 0;

    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        if (x % 2 == 0)
        {
            evens1++;
        }
        else
        {
            odds1++;
        }
    }

    for (ll i = 0; i < m; i++)
    {
        ll x;
        cin >> x;
        if (x % 2 == 0)
        {
            evens2++;
        }
        else
        {
            odds2++;
        }
    }

    cout << min(evens1, odds2) + min(odds1, evens2);
}

 	 		 	  		  	  		 				 						