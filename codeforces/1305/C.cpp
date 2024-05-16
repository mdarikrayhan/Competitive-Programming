#include "bits/stdc++.h"
using ll = long long  ;
const ll mod = 1e9 + 9 ;
const ll OO = 1e18 + 5 ;
const ll N = 1e6 + 5   ;
using namespace std;
ll n  , a[N] , m , tt = 1 ;
int main()
{
    ios_base::sync_with_stdio(0) ;
    cin.tie(0) ;

    //cin >> tt ;
    while(tt--)
    {
        cin >> n >> m ;

        for(ll i = 1 ; i <= n ; ++i)cin >> a[i] ;

        sort(a + 1 , a + n + 1);

        ll ans = 1 ;
        for(ll i = 1 ; i + 1 <= n ; ++i)
        {
            ans = ans * abs(a[i] - a[i + 1]) % m ;
        }

        if(ans == 0)
        {
            cout << ans << "\n";
            continue ;
        }

        ans = 1 ;
        for(ll i = 1 ; i <= n ; ++i)
        {
            for(ll j = i + 1 ; j <= n ; ++j)
            {
                ans = ans * abs(a[i] - a[j]) % m ;
                if(ans == 0)
                {
                    i = n + 1 ;
                    break ;
                }
            }
        }

        cout << ans << "\n";

    }

}



