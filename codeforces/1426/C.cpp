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
    ll n; cin >> n;

    ll minm = 0;

    ll low = 0, high = n;

    while(low <= high){
        ll mid = (low + high) / 2;

        ll maxm = (mid - mid / 2) * (mid / 2 + 1);
        if(maxm  >= n){
            minm = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }

    cout << high << endl;
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