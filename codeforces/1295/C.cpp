#include <bits/stdc++.h>

using namespace std;
#define IOS ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
#define int long long

# ifdef LOCAL

# include "C:\Program Files\DEBUG\debug.h"

# else
# define debug(...) 114514
# define ps 114514
# endif


void solve() {
    string s, t;
    cin >> s >> t;
    int n = s.size();
    s = ' ' + s;
    t = ' ' + t;
    vector<vector<int>> nxt(n + 2, vector<int>(26, 0));
    vector<int> fir(26, 0x3f3f3f3f);
    for (int i = n; i >= 1; i--) {
        fir[s[i] - 'a'] = i;
    }
    //  ps;
    for (int i = n; i >= 0; i--) {

        for (int j = 0; j < 26; j++) {
            if (i == n) nxt[i][j] = fir[j];
            else nxt[i][j] = nxt[i + 1][j];
        }
        if (i != n)nxt[i][s[i + 1] - 'a'] = i + 1;
        //fir[s[i + 1] - 'a'] = i + 1;
    }
    debug(nxt);
    int now = 0;
    int ans = 1;
    for (int i = 1; i < t.size(); i++) {
        if (fir[t[i] - 'a'] == 0x3f3f3f3f) {
            cout << -1 << endl;
            return;
        }
    }

    for (int i = 1; i < t.size(); i++) {

        if (nxt[now][t[i] - 'a'] <= now) {
            ans++;
        }
        now = nxt[now][t[i] - 'a'];
    }
    cout << ans << endl;
}

signed main() {
    IOS
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}