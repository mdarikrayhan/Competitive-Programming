#include <bits/stdc++.h>

using namespace std;

void solve(){
    int a, b;
    cin >> a >> b;
    if ( a >= 2)
        cout << "1\n";
    else {
        cout << (a+b) << "\n";
    }
    return; 
}
int main(int, char**){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    #ifdef LOCAL
    freopen("../test.in", "r", stdin);
    freopen("../test.out", "w", stdout);
    #endif

    int t;
    cin >> t;
    while ( t--)
        solve();
    
    // solve();    
}
