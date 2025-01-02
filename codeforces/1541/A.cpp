#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define ppb pop_back
#define mp make_pair 
#define fi first
#define se second
#define nl '\n'
const int mod = 1e9+7;

void solve(){
    int n; cin >> n;
    int a[n+1];
    for (int i = 1; i <= n; i++){
        a[i] = i;
    }
    for (int i = 2; i <= n; i += 2) swap(a[i], a[i-1]);
    if (n % 2) swap(a[n], a[n-2]);
    for (int i = 1; i <= n; i++){
        cout << a[i] << ' ';
    }
    cout << nl;
}

signed main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--){
        solve();
    }
}