#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> pre;
vector<int> v;

int MaxMiddle(int left , int right) {
    int mx = 0;
    for(int i = 1; i < 201; ++i) {
        mx = max(pre[i][right] - pre[i][left] , mx);
    }
    return mx;
}


void solve() {
    int mx = 0;
    cin >> n;

    v = vector<int>(n);
    pre = vector<vector<int>>(201 , vector<int>(n + 1));
    for(int i = 0; i < n; ++i) {
        cin >> v[i];
        pre[v[i]][i + 1]++;
    }

    // Optimize freq
    for(int i = 1; i < 201; ++i) {
        for(int j = 1; j <= n; ++j) {
            pre[i][j] += pre[i][j - 1];
        }
    }

    for(int i = 1; i < 201; ++i) {
        int cur = pre[i][n];
        mx = max(mx , cur);
        for(int j = 1; j <= cur/2; ++j) {
            int left = lower_bound(pre[i].begin() , pre[i].end() , j) - pre[i].begin();
            int right = upper_bound(pre[i].begin() , pre[i].end() , cur - j) - pre[i].begin();
            if(right - 1 <= left) break;
            int middle = MaxMiddle(left , right - 1);
            int ret = 2 * pre[i][left] + middle;
            mx = max(mx , ret);
        }
    }

    cout << mx << '\n';
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    std::ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int t = 1; cin >> t;
    while (t--) solve();
}
