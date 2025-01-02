#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n ; cin >> n ;
    vector<int> arr(n+1) ; for(int i = 1 ; i <= n ; i++) cin >> arr[i] ;
    if(arr[1] == 1) {
        cout << n+1 << " " ;
        for(int i = 1 ; i <= n ; i++) {
            cout << i << " " ;
        } cout << endl ;
        return ;
    }
    if(arr[n] == 0) {
        for(int i = 1 ; i <= n+1 ; i++) {
            cout << i << " " ;
        } cout << endl ;
        return ;
    }
    int shift = -1 ;
    for(int i = 1 ; i < n ; i++) {
        if(arr[i] == 0 && arr[i+1] == 1) {
            shift = i ; break ;
        }
    }
    if(shift == -1) {
        cout << -1 << endl ; return ;
    }
    for(int i = 1 ; i <= shift ; i++) {
        cout << i << " " ;
    } 
    cout << n+1 << " " ;
    for(int i = shift+1 ; i <=n ; i++) {
        cout << i << " " ;
    }cout << endl ;
}

signed main() {
    ios_base::sync_with_stdio(false) ; cin.tie(NULL) ;
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        // online submission
    #endif
    int t ; cin >> t ; while(t--) solve() ;
}