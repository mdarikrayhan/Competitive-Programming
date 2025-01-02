#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    string s;
    cin >> s;
    int n = (int)s.size();
    int i = 0, j = n - 1;
    while(i <= j) {
        if (s[i] == (char)('a' + n - 1)) {
            ++i;
        } else if (s[j] == (char)('a' + n - 1)) {
            --j;
        } else {
            cout << "NO\n";
            return;
        }
        --n;
    }
    cout << "YES\n";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}