#include <bits/stdc++.h>

using namespace std;

/*
The problem is equivalent to knapsack with a capacity of 2^T, and items of weights 2^t and value q
Consider the items from lowest to highest weight

The only info about our capacity we need to store is the amount in terms of the current block size,
since the remainder won't matter going forward

For the last one it needs to be <= 1, <= 2 before that, <= 4 before that, etc
So dp[prefix of weights][amount of current weight used] = max weight
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, T;
    cin >> N >> T;
    vector<vector<int>> tasks(T);
    for (int i = 0; i < N; i++) {
        int t, q;
        cin >> t >> q;
        t--;
        tasks[t].push_back(q);
    }
    for (int i = 0; i < T; i++) {
        sort(tasks[i].begin(), tasks[i].end(), greater<>());
    }

    vector<int> dp(N + 1);
    dp[0] = 0;

    for (int i = 0; i < T; i++) {
        vector<int> new_dp(N + 1);

        int pref = 0;
        for (int j = 0; j < int(tasks[i].size()) + 1; j++) {
            for (int k = 0; k <= N; k++) {
                int nxt = (k + 1) / 2 + j;
                if (nxt <= N && (T - i > 10 || nxt <= 1 << (T - i))) {
                    new_dp[nxt] = max(new_dp[nxt], dp[k] + pref);
                }
            }

            if (j < int(tasks[i].size())) {
                pref += tasks[i][j];
            }
        }

        dp = new_dp;
    }

    cout << dp[1] << '\n';
}