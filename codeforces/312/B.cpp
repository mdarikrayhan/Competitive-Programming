#include <bits/stdc++.h>
#define ll long long 
#define ul unsigned long long 
#define ld long double 
#define M 1000000007
#define endl '\n' 
using namespace std; 

void solve() {
    double a,b,c,d; cin >> a >> b >> c >> d;
    double t1 = (1 - a/b), t2 = (1 - c/d);
    cout << fixed << setprecision(12) << a / (b * ( 1 - t1 * t2));
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // int _t; cin >> _t; while(_t--) 
        solve();
    return 0;
}