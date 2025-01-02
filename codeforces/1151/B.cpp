/* ------------------------------------ DEFINE HERE ----------------------------------------------*/

  #ifndef ONLINE_JUDGE
  #include "debug.h"
  #else
  #define debug(...) ; 
  #endif
  #include <bits/stdc++.h>
  using namespace std;
  #define ff              first
  #define ss              second
  #define pb              push_back
  // #define int             long long int
  #define pii             pair<int,int>
  #define all( v )        v.begin() , v.end()
  #define rall( v )       v.rbegin() , v.rend()
  #define print( x )      cout<< x <<'\n'; 
  #define mxe( v )        *max_element(v.begin() , v.end())
  #define mne( v )        *min_element(v.begin() , v.end())
  #define yesno( ok )     cout<< (ok ? "TAK" : "NIE") <<'\n';

  const int max_xor = 1023;

/* ---------------------------------------- GLOBAL'S ---------------------------------------------*/
 
 
/* -------------------------------------- OTHER FUNC'S --------------------------------------------*/
   
 
/* ----------------------------------------- SOLVE ------------------------------------------------*/
 
  void solve()
  {
       int n , m; cin >> n >> m;

       vector<vector<int>> a( n + 1 , vector<int> ( m + 1 ) );

       for( int i = 1; i <= n; i++ ) 
          for( int j = 1; j <= m; j++ )
             cin >> a[i][j];

       vector<vector<pii>> dp( n + 1 , vector<pii>( max_xor + 1 , {0 , 0}) );
       dp[0][0].ff = 1;

       for( int i = 1; i <= n; i++ )
       {
           for( int xor_req = 0; xor_req <= max_xor; xor_req++ )
           {
               for( int j = 1; j <= m; j++ )
               {
                   dp[i][xor_req].ff |= dp[i - 1][(xor_req ^ a[i][j])].ff;

                   if( dp[i][xor_req].ff ) 
                   {
                      dp[i][xor_req].ss = j; break;
                   }
               }
           }
       }

       int flag = 0 , xor_possible = 0;
       for( int xr = 1; xr <= max_xor; xr++ )
       {
          if( dp[n][xr].ff ) flag = 1 , xor_possible = xr;
       }

       yesno( flag )
       if( !flag ) return;

       vector<int> choice( n + 1 );
       int curr_row = n;

       while( curr_row > 0 )
       {
          choice[curr_row] = dp[curr_row][xor_possible].ss;
          xor_possible ^= a[curr_row][choice[curr_row]];
          curr_row -= 1;
       }

       for( int i = 1; i <= n; i++ ) cout << choice[i] << ' '; cout << '\n';      
  }

/* ----------------------------------------- MAIN --------------------------------------------------*/

  signed main()
  {
      ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
      int t = 1;
      // cin >> t;
      while(t--) solve();
  }
