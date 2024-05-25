#include <bits/stdc++.h>
using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first > b.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i].first;
        }
        for (int i = 0; i < n; ++i) {
            int p;
            cin >> p;
            v[p - 1].second =  i;
        }
        sort(v.begin(), v.end(), cmp);
        vector<int> perm(n);
        for (int i = 0; i < n; ++i) {
            perm[v[i].second] = i;
        }
        int idx = 0;
        int64_t ans = v[0].first;
        int minn = 1;
        for (int i = 1; 2 * i + 1 <= n; ++i) {
            int p = perm[i - 1];

            idx += 1;
            while (idx < n and v[idx].first == 0) {
                idx += 1;
            }
            if (p <= idx) {
                idx += 1;
            } else {
                v[p].first = 0;
            }
            while (idx < n and v[idx].first == 0) {
                idx += 1;
            }
            if (idx >= n) {
                break;
            }
            int64_t u = (i + 1LL) * v[idx].first;

            if (u > ans) {
                ans = u;
                minn = i + 1;
            }
        }
        cout << ans << " " << minn << "\n";
    }
    return 0;
}