#include <bits/stdc++.h>
using namespace std;
#define db(...) (cerr << " (:> " << #__VA_ARGS__ << " |=  ", __prnt(__VA_ARGS__), cerr << '\n')
template<class T1, class T2> istream& operator>>( istream& istrm, pair<T1, T2>& prs ){ istrm >> prs.first >> prs.second; return istrm; }template<class T> istream& operator>>( istream& istrm, vector<T>& vtr1 ){ for( auto& iloo : vtr1 ) istrm >> iloo; return istrm; }template<class T1, class T2> ostream& operator<<( ostream& ostrp, pair<T1, T2> prs ){ ostrp << "(" << prs.first << ", " << prs.second << ")"; return ostrp; }
#define Vout(Con) template<class T> ostream& operator<<(ostream& ostrp, Con<T>& vtr1) { bool fst = 1; ostrp << "{ "; for(auto& iloo: vtr1) { if(!fst) ostrp << ", "; ostrp << iloo; fst = 0; } ostrp << " }"; return ostrp; }
#define Vout2(Con) template<class T1, class T2> ostream& operator<<(ostream& ostrp, Con<T1,T2>& vtr1) { bool fst = 1; ostrp << "{ "; for(auto& [iloo, jloo]: vtr1) { if(!fst) ostrp << ", "; ostrp << iloo << " : " << jloo; fst = 0; } ostrp << " }"; return ostrp; }
Vout( vector ) Vout( set ) Vout( multiset ) Vout2( map )template<class... Ts> void __prnt( auto& arg, auto&... args ){ cerr << arg; ( ( cerr << ", " << args ), ... ); };
template<typename T>void print( const T& arg ){ if constexpr( is_same_v<T, char> ) arg == '\n' ? cout << arg : cout << arg << ' '; else cout << arg << ' '; }template<typename... Args>void print( const Args&... args ){ ( print( args ), ... ); }
template<typename... Args>void scan( Args&... args ){ ( ( cin >> args ), ... ); }
#define int long long
#define ll long long
const int md = 1e9 + 7, inf = 1e18, N = 1e6;

void __(){
   int n, k = -1, c, d;
   scan( n, c, d );
   vector<int> v( n ), p( n, 0 );
   for( int i = 0; i < n; i++ ){
      scan( v[ i ] );
      }
   sort( v.rbegin(), v.rend() );
   p[ 0 ] = v[ 0 ];
   for( int i = 1; i < n; i++ ){
      p[ i ] = v[ i ] + p[ i - 1 ];
      }
   if( p[ min( d - 1, n - 1 ) ] >= c ){
      print( "Infinity", '\n' );
      return;
      }
   if( v[ 0 ] * d < c ){
      print( "Impossible", '\n' );
      return;
      }
   for( int l = 0ll, r = inf, mid; l <= r; ){
      mid = l + r >> 1;
      int s = d / ( mid + 1 ) * p[ min( n - 1, mid ) ];
      if( min( n, d % ( mid + 1 ) ) - 1 >= 0 ) s += p[ min( n, d % ( mid + 1 ) ) - 1 ];
      if( s >= c ){
         k = mid;
         l = mid + 1;
         }
      else r = mid - 1;
      }
   print( k );
   cout << "\n";
   }

signed main(){
   ios_base::sync_with_stdio( false ); cin.tie( nullptr );
   int _ = 1;
   cin >> _;
   while( _-- ) __();
   return 0;
   }
