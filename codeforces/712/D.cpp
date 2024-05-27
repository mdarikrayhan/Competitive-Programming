/*
Problem: 712D
Date: 27-05-2024 05:58 AM
*/


#include <bits/stdc++.h>

#define ll long long
using namespace std;

// # games where a > b at end
// Select a number 2t times to offset a.
// (a - b) + v_1 + v_2 + ... + v_2t > 0, how many ways, where each v_i in [-k, k]?
// v_1 + v_2 + ... + v_2t > 2tk + (b - a) = MX, where each v_i in [0, 2k]
// dp[i][j]. first i values, sum of v_1, ..., v_i > j
// dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1] + dp[i - 1][j - 2] + ... + dp[i - 1][j - 2k]
// dp[0][j] = 0

const int N = 105, K = 1005, M = 1e9 + 7;
int a, b, t, k;
ll dp[2 * N][2 * N * K + N];
ll p[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> a >> b >> k >> t;
    p[0] = 1;
    int mx = 2 * t * k + b - a;
    for(int i = 1; i <= 2 * t; i++) {
        p[i] = ((2 * k + 1) * p[i - 1]) % M;
        ll sum = 0;
        for(int j = 0; j <= mx; j++) {
            sum = (sum + dp[i - 1][j]) % M;
            if(j - (2 * k + 1) >= 0) {
                sum = ((sum - dp[i - 1][j - (2 * k + 1)]) % M + M) % M;
            }
            dp[i][j] = (sum + p[i - 1] * max(2 * k - j, 0)) % M;
        }
    }
    cout << dp[2 * t][mx] << endl;
}