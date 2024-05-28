#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
void solve() {
    int n, m, q;
    cin >> n >> m;
    vector<int> c(n + 1), sum(m + 1);
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        sum[c[i]]++;
    }
    for (int i = 1; i <= m; i++)
        sum[i] += sum[i - 1];
    vector<vector<int>> f(m + 1, vector<int>(20, 0));
    for (int i = 1; i <= n; i++)
        f[i][0] = 0;
    for (int i = 1; i < 20; i++) {
        for (int j = 1; j + (1 << i) - 1 <= m; j++) {
            int k = (1 << (i - 1));
            f[j][i] = f[j][i - 1] ^ f[j + k][i - 1];
            f[j][i] ^= ((sum[j + 2 * k - 1] - sum[j + k - 1]) & 1) * (1 << (i - 1));
        }
    }
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;
        int ans = 0;
        for (int j = 19; j >= 0; j--) {
            if (l + (1 << j) > r)
                continue;
            ans ^= f[l][j];
            l += (1 << j);
            ans ^= ((sum[r] - sum[l - 1]) & 1) * (1 << j);
        }
        if (ans)
            cout << "A";
        else
            cout << "B";
    }
    cout << "\n";
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}