#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    int n, m, mx = 0;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    vector<int> pref(m), suf(m);
    int i = 0, cnt = 0;
    while (i < m) {
        if (t[i] == s[cnt]) pref[i++] = cnt;
        cnt++;
    }
    i = m - 1, cnt = n - 1;
    while (i >= 0) {
        if (t[i] == s[cnt]) suf[i--] = cnt;
        cnt--;
    }
    for (int j = 1; j < m; ++j) {
        mx = max(suf[j] - pref[j - 1], mx);
    }
    cout << mx;
    return 0;
}