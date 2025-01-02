#include <bits/stdc++.h>
#define ll long long 
#define ul unsigned long long 
#define ld long double 
#define M 1e9 + 7
#define endl '\n' 
using namespace std; 

void solve() {
    ll n, m; cin >> n >> m;
    ll a[n][m];

    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> a[i][j];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i == 0 && j > 0) a[i][j] += a[i][j-1];
            else if(j == 0 && i > 0) a[i][j] += a[i-1][j];
            else if(j > 0 && i > 0) a[i][j] += max(a[i-1][j], a[i][j-1]);
        }
    }
    for(int i = 0; i < n; i++) cout << a[i][m-1] << " ";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // int _t; cin >> _t; while(_t--) 
        solve();
    return 0;
}