#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n, k; cin >> n >> k;
    cout << (n+k-2)/k+1 << '\n';
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
 
    int tc; cin >> tc;
    while(tc--) solve();
 
    return 0;
}