#include "bits/stdc++.h"
using ll = long long  ;
const ll mod = 1e9 + 9 ;
const ll OO = 1e18 + 5 ;
const ll N = 1e6 + 5   ;
using namespace std;
ll n  , a[N] ,  b[N] , tt = 1 ;
int main()
{
    ios_base::sync_with_stdio(0) ;
    cin.tie(0) ;

    cin >> tt ;
    while(tt--)
    {
        cin >> n ;

        for(ll i = 1 ; i <= n ; ++i)cin >> a[i] ;
        for(ll i = 1 ; i <= n ; ++i)cin >> b[i] ;

        sort(a + 1 , a + n + 1) ;
        sort(b + 1 , b + n + 1) ;
        for(ll i = 1 ; i <= n ; ++i)cout << a[i] << " \n"[i == n] ;
        for(ll i = 1 ; i <= n ; ++i)cout << b[i] << " \n"[i == n] ;

    }

}



