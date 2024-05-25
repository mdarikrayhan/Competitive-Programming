#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string s, t;
    cin >> s >> t;
    int x = count(s.begin(), s.end(), '1'),
        y = count(t.begin(), t.end(), '1');
    x += x % 2;
    if (y > x)
        cout << "NO\n";
    else
        cout << "YES\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}