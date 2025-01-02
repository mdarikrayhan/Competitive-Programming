#include <bits/stdc++.h>
using namespace std;

mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#define int long long

int check(int m, vector<int> &req, vector<int> &pos) {
    int res = 0;
    int j = 0;
    for (int i = 0; i < (int)req.size() - 1; ++i) {
        int cur = req[i];
        while (req[i + 1] > m + cur) {
            while (j < (int)pos.size() && pos[j] < cur) {
                j++;
            }
            if (j == (int)pos.size() || pos[j] - cur > m) {
                return -1;
            }
            while (j < (int)pos.size() - 1 && pos[j + 1] <= m + cur) {
                j++;
            }
            res++;
            cur = pos[j];
            j++;
        }
    }
    return res;
}

void solve() {
    int m;
    cin >> m;
    string s;
    cin >> s;
    int n = (int)s.size();
    vector<vector<int>> pos(26);
    for (int i = 0; i < n; ++i) {
        pos[s[i] - 'a'].push_back(i);
    }
    vector<int> req = {-1, n};
    for (int code = 0; code < 26; ++code) {
        int cnt = check(m, req, pos[code]);
        if (cnt != -1) {
            for (int j = 0; j < code; ++j) {
                for (int _ = 0; _ < (int)pos[j].size(); ++_) {
                    cout << char('a' + j);
                }
            }
            for (int _ = 0; _ < cnt; _++) {
                cout << char('a' + code);
            }
            return;
        } else {
            for (int p : pos[code]) {
                req.push_back(p);
            }
            sort(req.begin(), req.end());
        }
    }
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
}