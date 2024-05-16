#include <bits/stdc++.h>
using namespace std;
      /* Chef OMF */
  /*    A r h i b o       */

#define ll long long
#define F first
#define Sec second
#define Pb push_back
#define Ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const int N = 2e5 + 1;
const ll inf = 1e18 + 1;
const ll mod = 998244353;
void Tamm()
{
   int n , k ;
   cin >> n >> k  ;
   ll Mult = 1  , Sum  = 0 ;
   int Num ;
   int Last = 0 ;
   for(int i = 1 ; i <= n ; i ++ )
   {

       cin >> Num ;
       if( Num >= n - k + 1 )
       {
           Sum += Num ;
           if(Last != 0 )
             Mult = ( Mult *  ( i- Last) ) % mod ;
           Last = i ;
       }

   }
   cout << Sum  << " " <<  Mult   << "\n" ;
}
int main()
{
    Ios;
    int T = 1;
    //cin >> T;
    while(T--)
        Tamm();
    return 0;
}
