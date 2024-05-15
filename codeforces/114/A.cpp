#include <bits/stdc++.h>
#define ll long long 
#define ul unsigned long long 
#define ld long double 
#define M 1e9 + 7
#define endl '\n' 
using namespace std; 

void solve() {
    ll k, l; cin >> k >> l;
    
    ll temp = k, count = 0;
    while(temp < l){
        temp *= k;
        count++;
    }
    if(temp == l) cout << "YES\n" << count;
    else cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // int _t; cin >> _t; while(_t--) 
        solve();
    return 0;
}