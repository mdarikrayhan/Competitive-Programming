#include <bits/stdc++.h>

using namespace std;
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool is_reg(string s) {
    int cur = 0;
    for (char c : s) {
        if (c == '(') {
            cur++;
        } else {
            cur--;
        }
        if (cur < 0) {
            return false;
        }
    }
    return cur == 0;
}
void solve() {
    string s;
    cin >> s;
    for (int st = 0; st < 8; st++) {
        string t = "";
        for (char c : s) {
            if (st & (1 << (c - 'A'))) {
                t += '(';
            } else {
                t += ')';
            }
        }
        if (is_reg(t)) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}
int main() {
    fast_io();
    int t;
    cin >> t;
    for (; t--;) {
        solve();
    }
}