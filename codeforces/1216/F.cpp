#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fi first
#define se second
#define pb push_back
#define is insert
using namespace std ; // Constants
const ll N = 5e5 , mod = 1e9 + 7 , oo = 1e18 ; // Constants
ll dp[N + 5] , last[N + 5] , pos = 0 ;
char c[N + 5] ;
void Treat(){
    int n , k ; cin >> n >> k ;
    for(int i = 1 ; i <= n ; i ++ ) {
        cin >> c[i] ;
    }
    for(int i = n ; i >= 1 ; i -- ) {
        if(c[i] == '1') pos = i ;
        last[i] = pos ;
    }
    for(int i = 1 ; i <= n ; i ++ ) {
        dp[i] = dp[i - 1] + i ;
        int nxt = max(1 , i - k) ;
        nxt = last[nxt] ;
        if(nxt && nxt <= i + k) {
            dp[i] = min(dp[i] , dp[max(0 , nxt - k - 1)] + nxt) ;
        }
    }
    cout << dp[n] << endl ; return ;
}
int main() {
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ; cout.tie(0) ;
    int test = 1 ;
    // cin >> test ;
    while(test -- ) {
        Treat() ;
    }
}
