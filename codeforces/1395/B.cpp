#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve() {
    ll n, m, x, y; cin >> n >> m >> x >> y;

    cout << x << " " << y << "\n";

    for(int j=1; j<=m; j++){
        if(j != y){
            cout << x << " " << j << "\n";
        }
    }   

    bool rev = true;

    for(int i=1; i<=n; i++){
        if(i == x)continue;
        if(rev){
            for(int j=m; j>=1; j--){
                cout << i << " " << j << "\n";
            }
        }else{ 
            for(int j=1; j<=m; j++){
                cout << i << " " << j << "\n";
            }
        }

        rev = !rev;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << 'Case #' << t << ':';
        solve();
    }
}