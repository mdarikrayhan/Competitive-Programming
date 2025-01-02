/*
Problem: 1027E
Date: 28-05-2024 01:37 AM
*/


#include <bits/stdc++.h>

#define ll long long
using namespace std;

// row and column have bitmasks
// max rectangle size is max(contiguous row labels) * max(contiguous col labels)
// n <= 500
// dp[i][j] = number of ways with all n rows, i columns, and max contig. row is j
// dp[i][j] = sum_{l = 1}^min(i, (k-1)/j) dp[i - l][j]
// how many ways where max contig. row is j? Coin change problem
// dp2[i][j] = how many ways to split i rows so that max contig piece is at most j
// (for exactly j, take difference)
// dp2[i][j] = sum_{l = 1}^min(i,j) dp2[i - l][j]

// At end, multiply everything by 2 for all parities

const int N = 505, M = 998244353;
int n, k;
ll dp[N][N], dp2[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    ll ans = 0;
    for(int j = 1; j <= min(k, n); j++) {
        dp[0][j] = dp2[0][j] = 1;
        for(int i = 1; i <= n; i++) {
            for(int l = 1; l <= min(i, (k - 1) / j); l++) {
                dp[i][j] = (dp[i][j] + dp[i - l][j]) % M;
            }
            for(int l = 1; l <= min(i, j); l++) {
                dp2[i][j] = (dp2[i][j] + dp2[i - l][j]) % M;
            }
            ans = ((ans + (dp2[n][j] - dp2[n][j - 1]) * dp[n][j]) % M + M) % M;
        }
    }
    cout << ((ans * 2) % M) << endl;
}