#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <queue>
#include <map>
#include <cmath>
#include <iomanip>
using namespace std;

#define ff first
#define sc second
#define pb push_back
#define ll long long
#define pll pair<ll, ll>
#define pii pair <int, int>
#define ull unsigned long long

// #define int long long
// #define int unsigned long long

const ll inf = 1e9 + 7;
const ll weirdMod = 998244353;

void solve() {
    int a[5];
    cin >> a[1] >> a[2] >> a[3] >> a[4];
    sort(a + 1, a + 5);
    if (a[1] + a[2] > a[3] || a[2] + a[3] > a[4]) cout << "TRIANGLE";
    else if (a[1] + a[2] == a[3] || a[2] + a[3] == a[4]) cout << "SEGMENT";
    else cout << "IMPOSSIBLE";
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }
    return 0;
}