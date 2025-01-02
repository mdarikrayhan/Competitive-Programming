#define loopi(p,n) for( int i = p   ; i < n  ; ++i )
#define loopj(r,m) for( int j = r   ; j < m  ; ++j )
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#include <bits/stdc++.h>
using namespace std;

int main() {

    ll n , s ;
    cin >> n >> s ;

    vector < ll > freq ( s + 1 , 0 ) ;
    loopi( 0 , n )
    {
        ll a , b ;
        cin >> a >> b ;
        freq[a] = max ( b  ,  freq[a] ) ;
    }

    ll countS = freq[s] ;
    for ( int i = s - 1 ; i >= 0  ; i-- )
    {
        countS++ ;
        freq[i]-= countS ;
        if ( freq[i] > 0 ) countS+= freq[i] ;
    }
    cout << countS ;
}
