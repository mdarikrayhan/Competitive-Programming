#include <bits/stdc++.h>
using namespace std;

const int SCALE = 100;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, p, k;
    cin >> n >> p >> k;

    auto readAndProcess = [&]() -> vector<long long> {
        int m;
        cin >> m;
        vector<bool> a(n, false);
        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;
            x--;
            a[x] = true;
        }
        vector<long long> res(n + 1);
        res[0] = 0;
        for (int i = 0; i < n; i++) {
            res[i + 1] = (res[i] << 1) | a[i];
            if (res[i + 1] & (1LL << k)) res[i + 1] -= 1LL << k;
        }
        return res;
    };
    vector<vector<long long>> a(2);
    a[0] = readAndProcess();
    a[1] = readAndProcess();

    auto cost = [&](int i, bool who, int last0, int last1) -> int { // the number of new questions seen if peep at i and last peeps at last0, last1
        last0 = max(-1, last0);
        last1 = max(-1, last1);
        i++;
        last0++;
        last1++;
        long long x = a[0][last0] << (i - last0);
        long long y = a[1][last1] << (i - last1);
        long long common = a[who][i] & (x | y);
        return SCALE * (__builtin_popcountll(a[who][i]) - __builtin_popcountll(common));
    };

    auto getExtremum = [&](int lambda) -> pair<int, int> { // {maximum number of questions, minimum peeps used}, penalty is -lambda
        constexpr int INF = 1e8;
        vector<vector<int>> prev(k + 1, vector<int>(k + 1, -INF));
        vector<vector<int>> prev_arg(k + 1, vector<int>(k + 1, -INF));
        prev[k][k] = 0;
        prev_arg[k][k] = 0;
        for (int i = 0; i < n; i++) {
            vector<vector<int>> dp(k + 1, vector<int>(k + 1, -INF));
            vector<vector<int>> arg(k + 1, vector<int>(k + 1, -INF));
            auto transit = [&](int d0, int d1, int prev_d0, int prev_d1, int cost, int cost_arg) {
                if (prev[prev_d0][prev_d1] + cost > dp[d0][d1]) {
                    dp[d0][d1] = prev[prev_d0][prev_d1] + cost;
                    arg[d0][d1] = prev_arg[prev_d0][prev_d1] + cost_arg;
                } else if (prev[prev_d0][prev_d1] + cost == dp[d0][d1]) {
                    arg[d0][d1] = min(arg[d0][d1], prev_arg[prev_d0][prev_d1] + cost_arg);
                }
            };
            for (int d0 = 0; d0 <= k; d0++) {
                for (int d1 = 0; d1 <= k; d1++) {
                    transit(min(k, d0 + 1), min(k, d1 + 1), d0, d1, 0, 0);
                    transit(0, min(k, d1 + 1), d0, d1, cost(i, 0, i - d0 - 1, i - d1 - 1) - lambda, 1);
                    transit(min(k, d0 + 1), 0, d0, d1, cost(i, 1, i - d0 - 1, i - d1 - 1) - lambda, 1);
                    // no point in peeping both at the same segment
                }
            }
            prev = dp;
            prev_arg = arg;
        }
        pair<int, int> res = {0, 0};
        for (int d0 = 0; d0 <= k; d0++) {
            for (int d1 = 0; d1 <= k; d1++) {
                if (prev[d0][d1] > res.first) {
                    res = { prev[d0][d1], prev_arg[d0][d1] };
                } else if (prev[d0][d1] == res.first) {
                    res.second = min(res.second, prev_arg[d0][d1]);
                }
            }
        }
        return res;
    };

    int lambda = [&]() -> int {
        int l = 0, r = 3e3 * SCALE;
        while (r - l > 0) {
            int m = (l + r) / 2;
            auto [extre, arg] = getExtremum(m);
            if (arg <= p) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }();

    auto [extre, arg] = getExtremum(lambda);
    cout << (extre + lambda * p) / SCALE << '\n';
}
