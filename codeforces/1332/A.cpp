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
    ll a, b, c, d, x, y, x1, y1, x2, y2;
    cin >> a >> b >> c >> d;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;

    ll fx = x + b - a, fy = y + d - c;

    if(fx <= x2 && fx >= x1 && fy <= y2 && fy >= y1){
        if((a > 0 && b > 0) && a == b && (!(x + 1 >= x1 && x + 1 <= x2) && !(x - 1 >= x1 && x - 1 <= x2))){
            cout << "No\n";
            return;
        }

        if((c > 0 && d > 0) && c == d && !(y + 1 >= y1 && y + 1 <= y2) && !(y - 1 >= y1 && y - 1 <= y2)){
            cout << "No\n";
            return;
        }

        cout << "Yes\n";
    }else{
        cout << "No\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << 'Case #' << t << ':';
        solve();
    }
}