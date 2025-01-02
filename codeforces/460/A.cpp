#include <bits/stdc++.h>
using namespace std;

#define hlll ios_base::sync_with_stdio(NULL);cin.tie(0);cout.tie(0);
#define  ll long long
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
//#define r return
#define co continue
#define br break

bool st(string s) {
    for (int i = 0; i < s.size ()-1; i++) {
        if (s[i] == '1' && s[i+1] == '0') {
            return false ;
        }
    }
    return true;
}

ll l , r, n, x , y, ans =0  ;
const int c = 1e6;
int arr [c] ;
ll eps = 10e-16;
bool ok (ll mid , int mn , int mx) {


     int a = mid / mn ;
     int b = ( mid -mn)/ mx;
         return ( a +b) >= n;
}
   void solve () {
       int m ;
     cin >> n >> m ;
     int ans = 0;

     for (int i = 1 ; i <=n ; i ++ ) {
        if ( i % m == 0 ) n++;
                 }

     cout << n << endl;

}

int32_t main(){
    hlll
   int t ;
//cin >> t ;
t =1 ;
    while (t--) {
      solve ();
    }

    return 0;
}
