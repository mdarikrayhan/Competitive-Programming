#include <bits/stdc++.h>
using namespace std;

#define int     long long
#define nl      '\n'
#define no      cout<<"NO\n"
#define yes     cout<<"YES\n"

void solve(int);

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1, cnt = 1;
    // cin >> t;
    while(t--) {
        solve(cnt++);
    }

    return 0;
}

void solve(int TEST_CASE) {
    int n; cin >> n;

    if(n % 2 == 0) {
        cout << "white\n1 2" << nl;
    } else {
        cout << "black" << nl;
    }
}