#include <bits/stdc++.h>
#include <algorithm>
using namespace std; using namespace chrono;

#define ff first
#define ss second
#define pb push_back
#define gan(x) x.begin(),x.end()
#define rgan(x) x.rbegin(),x.rend()
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define sumn(n) n*(n+1)/2

#define forn(i,/**/ n) for (int i = 0/******/; i < int(n); i++)
/*www*/typedef long long ll; /*www*/typedef vector<ll> vecs; /*www*/typedef vector<vector<ll>> matrix;
void freopen (){ freopen(".in", "r", stdin); freopen(".out", "w", stdout); }
const int mod = 1000000007; const char nl = '\n';

void ShikiMoril() {
    ll n,a,b; cin >> n >> a >> b ;
    ll cnt = 0;
    if ( n % 2 != 0 ) {
        cnt += a;
        n -- ;
    }
    ll mn = min ( a * 2 , b ) ;
    cnt += ( n / 2 ) * mn   ;
    cout << cnt << "\n";
}

int main (){
    iostream::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); // <<<>>> activation
    // bool mych = false ; ll myf = 1 ; if ( myf != 0 ) {mych = true ;} if ( mych == true ){ freopen (); }
    long long t = 1; cin >> t; 
    while ( t -- ){ ShikiMoril(); }
    return 0;
}
