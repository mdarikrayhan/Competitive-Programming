#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int n; cin >> n;

    array<int, 26> cnt;
    cnt.fill(0);
    for (int i = 0; i < 2 * n; i++) {
        string s; cin >> s;
        for (char& c : s)
            cnt[c - 'a']++;
    }
    string s; cin >> s;
        for (char& c : s)
            cnt[c - 'a']++;
    
    for (int i = 0; i < 26; i++)
        if (cnt[i] & 1) {
            cout << char('a' + i) << nl;
            return;
        }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}