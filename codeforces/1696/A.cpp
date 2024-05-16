#include "bits/stdc++.h"
using ll = long long  ;
const ll mod = 1e9 + 7 ;
const ll OO = 1e18 + 5 ;
const ll N = 5e5 + 5   ;
using namespace std;
ll n , z, a[N] , tt = 1 ;

int main()
{
    ios_base::sync_with_stdio(0) ;
    cin.tie(0) ;

    cin >> tt ;
    while(tt--)
    {
        cin >> n >> z ;

        ll mx = 0 ;
        for(ll i = 1 ; i <= n ; ++i)
        {
            cin >> a[i] ;
            mx = max(mx , a[i] | z);
        }

        cout << mx << "\n";

    }


}



