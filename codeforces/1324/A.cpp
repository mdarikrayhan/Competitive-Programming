#include<iostream>
#include<algorithm>
#include<array>
#include<string>
#include<math.h>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<deque>
#include<queue>
#include<cstdio>
#include <iomanip>
#define endl '\n'
#define ll long long
#define N 100010
#define yes "YES"
#define no "NO"
#define pairl pair<ll,ll>
const double pi = acosl(-1);
using namespace std;
void solve() {
    ll n;
    cin >> n;
    vector<ll>a(n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ans += a[i] % 2;
    }
    if (ans == 0 || ans == n) {
        cout << yes << endl;
    }
    else {
        cout << no << endl;
    }

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}