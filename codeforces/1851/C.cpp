#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int start = a[0], end = a[n - 1];
    if (start == end) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == start) {
                ++cnt;
            }
            if (cnt == k) {
                cout << "YES\n";
                return;
            }
        }
        cout << "NO\n";
    } else {
        int cnt = 0, i = 0;
        while (i < n) {
            if (a[i] == start) {
                ++cnt;
            }
            if (cnt == k) {
                break;
            }
            i++;
        }
        int sec = 0;
        for (int j = i; j < n; j++) {
            if (a[j] == end) {
                sec++;
            }
            if (sec == k) {
                cout << "YES\n";
                return;
            }
        }
        cout << "NO\n";
    }
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
