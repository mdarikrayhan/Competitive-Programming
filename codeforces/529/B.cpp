// LUOGU_RID: 156497056
#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;


void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int> (2));
    vector<int> v;
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
        v.push_back(a[i][0]);
        v.push_back(a[i][1]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    int res = 1e18;
    for (int limit : v) {
        bool ok = 1;
        for (int j = 0; j < n; j++) {
            if (a[j][0] > limit && a[j][1] > limit) {
                ok = 0;
                break;
            }
        }
        if (!ok) {
            continue;
        }
        vector<vector<int>> a1, a2;
        for (int j = 0; j < n; j++) {
            if (a[j][1] > limit) {
                a1.push_back(a[j]);
            } else {
                a2.push_back(a[j]);
            }
        }
        if (a1.size() > n / 2) {
            continue;
        }
        int cnt = n / 2 - a1.size();
        sort(a2.begin(), a2.end(), [](vector<int>& x, vector<int>& y) {
            return x[0] - x[1] > y[0] - y[1];
        });
        for (int j = 0; j < a2.size() && cnt > 0; j++) {
            if (a2[j][0] > a2[j][1] && a2[j][0] <= limit) {
                swap(a2[j][0], a2[j][1]);
                cnt--;
            }
        }
        int w = 0, h = limit;
        for (int j = 0; j < a1.size(); j++) {
            w += a1[j][1];
        }
        for (int j = 0; j < a2.size(); j++) {
            w += a2[j][0];
        }
        res = min(res, w * h);
    }
    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(15);
    // int t;
    // cin >> t;
    // while (t--) {
        solve();
    // }
    return 0;
}
