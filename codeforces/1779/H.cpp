#include "bits/stdc++.h"

using namespace std;

vector<vector<long long>> build(vector<long long> a, long long s) {
    vector<vector<long long>> dp(9);
    function<void(int, long long, int x)> dfs = [&] (int i, long long x, int cnt) {
          if (x > s) {
              return;
          }
          if (cnt > 8) {
              return;
          }
          if (i == (int) a.size()) {
              dp[cnt].push_back(x);
              return;
          }
          dfs(i + 1, x, cnt);
          dfs(i + 1, x + a[i], cnt + 1);
    };
    dfs(0, 0, 0);
    for (auto& x : dp) {
        sort(x.begin(), x.end());
    }
    return dp;
}

bool solve(long long s, int cnt, vector<long long> a) {
    //cout << s << " " << cnt << " " << (int) a.size() << endl;
    if (cnt == (int) a.size()) {
        long long s2 = accumulate(a.begin(), a.end(), 0ll);
        return (s >= s2);
    }
    { // fast?
        long long sum = s + accumulate(a.begin(), a.end(), 0ll);
        if (s * (32 / cnt) < sum) {
            return false;
        }
    }
    int n = (int) a.size();
    if (cnt == 1) {
        int i = 0;
        while (i < n && a[i] > s) {
            i++;
        }
        if (i == n) {
            return false;
        }
        s += a[i];
        a.erase(a.begin() + i);
        return solve(s, 2, a);
    }
    if (cnt == 2) {
        vector opt(n, n);
        for (int i = 0; i < n; i++) {
            if (i) {
                opt[i] = min(opt[i], opt[i - 1]);
            }
            int res = n;
            if (i + 1 < n) {
                res = i + 1;
                while (res < n && a[i] + a[res] > s) {
                    res++;
                }
            }
            if (res < opt[i]) {
                opt[i] = res;
                auto A = a;
                A.erase(A.begin() + res);
                A.erase(A.begin() + i);
                if (solve(s + a[i] + a[res], 4, A)) {
                    return true;
                }
            }
        }
        return false;
    }
    if (cnt == 4) {
        vector opt(n, vector(n, vector<int> (n, n)));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (i) {
                        opt[i][j][k] = min(opt[i][j][k], opt[i - 1][j][k]);
                    }
                    if (j) {
                        opt[i][j][k] = min(opt[i][j][k], opt[i][j - 1][k]);
                    }
                    if (k) {
                        opt[i][j][k] = min(opt[i][j][k], opt[i][j][k - 1]);
                    }
                    int res = n;
                    if (i < j && j < k && k + 1 < n) {
                        res = k + 1;
                        while (res < n && a[i] + a[j] + a[k] + a[res] > s) {
                            res++;
                        }
                    }
                    if (res < opt[i][j][k]) {
                        opt[i][j][k] = res;
                        auto A = a;
                        A.erase(A.begin() + res);
                        A.erase(A.begin() + k);
                        A.erase(A.begin() + j);
                        A.erase(A.begin() + i);
                        if (solve(s + a[i] + a[j] + a[k] + a[res], 8, A)) {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
    if (cnt == 8) {
        long long need = (accumulate(a.begin(), a.end(), 0ll) + s + 1) / 2 - s;
        auto L = build(vector<long long>(a.begin(), a.begin() + 12), s);
        auto R = build(vector<long long>(a.begin() + 12, a.end()), s);
        for (int i = 0; i <= 8; i++) {
            for (auto x : L[i]) {
                auto it = lower_bound(R[8 - i].begin(), R[8 - i].end(), need - x) - R[8 - i].begin();
                if (it < R[8 - i].size() && x + R[8 - i][it] <= s) {
                    return true;
                }
            }
        }
        return false;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<pair<long long, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    int l = -1, r = n - 1;
    while (l + 1 < r) {
        int m = (l + r) / 2;
        long long x = a[m].first;
        vector<long long> A;
        for (int i = 0; i < n; i++) {
            if (i != m) {
                A.push_back(a[i].first);
            }
        }
        reverse(A.begin(), A.end());
        (solve(x, 1, A) ? r : l) = m;
    }
    vector<int> ans(n);
    for (int i = r; i < n; i++) {
        ans[a[i].second] = 1;
    }
    for (auto x : ans) {
        cout << x;
    }
}