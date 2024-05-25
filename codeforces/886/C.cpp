#include "bits/stdc++.h"
using ll = long long  ;
const ll mod = 1e9 + 7 ;
const ll OO = 1e18 + 5 ;
const ll N = 5e5 + 5   ;
using namespace std;
ll n , a[N] , pos[N] , tt = 1 ;


int main()
{
    ios_base::sync_with_stdio(0) ;
    cin.tie(0) ;

    //cin >> tt ;
    while(tt--)
    {
        cin >> n ;

        map < ll , ll > cnt ;

        ll ans = 1 ;
        for(ll i = 1 ; i <= n ; ++i)
        {
            cin >> a[i] ;
            cnt[a[i]] += 1 ;
            if(cnt[a[i]] >= 2)ans += 1 ;
        }

        cout << ans << "\n";





    }


}



