#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll power(ll n, ll i)
{
    ll res = 1;
    while (i > 0)
    {
        res = (res * n) % mod;
        i--;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        ll msb = __lg(k);
        ll sum = 0;
        for (int i = 0; i <= msb; i++)
        {
            if ((k >> i & 1))
            {
                sum += power(n, i);
                sum %= mod;
            }
        }

        cout << sum << endl;
    }
    return 0;
}
  					 		  	 	   	  		    	  	