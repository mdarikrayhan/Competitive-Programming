#include <iostream>
#include <vector>
#include <set>
#include <utility>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> a(n + 1, vector<int>(n + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                cin >> a[i][j];
            }
        }
        vector<vector<int>> dp(n + 1);
        dp[0] = {0};
        for (int i = 1; i <= n; i++) {
            // dp[i]=max(a[i][i]+dp[i-2], a[i-1][i]+dp[i-3], ..., a[2][i]+dp[0], a[1][i])
            multiset<int> s(dp[i - 1].begin(), dp[i - 1].end());
            s.insert(a[1][i]);
            if (s.size() > k) {
                s.erase(s.begin());
            }
            set<pair<int, pair<int, int>>> pq;
            for (int j = 0; j <= i - 2; j++) {
                pq.insert({dp[j][0] + a[j + 2][i], {0, j}});
            }
            for (int j = 0; j < k && !pq.empty(); j++) {
                auto f = *pq.rbegin();
                pq.erase(--pq.end());
                auto [v, p] = f;
                auto [x, y] = p;
                s.insert(v);
                if (s.size() > k) {
                    s.erase(s.begin());
                }
                if (x + 1 < dp[y].size()) {
                    pq.insert({dp[y][x + 1] + a[y + 2][i], {x + 1, y}});
                }
            }
            dp[i] = vector<int>(s.rbegin(), s.rend());
        }
        for (int dpni: dp[n]) {
            cout << dpni << " ";
        }
        cout << endl;
    }
    return 0;
}
