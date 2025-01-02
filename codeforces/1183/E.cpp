/*
Problem: 1183E
Date: 25-05-2024 02:03 PM
*/


#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 105;
int n;
ll k;
string s;
ll dp[N][N];
int last[N];
int idx[26];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k >> s;
    fill(idx, idx + 26, -1);
    for(int i = 0; i < n; i++) {
        last[i + 1] = idx[s[i] - 'a'];
        idx[s[i] - 'a'] = i;
    }
    for(int i = 0; i <= n; i++) {
        dp[0][i] = 0;
        dp[i][0] = 1;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            if(last[i] >= 0) {
                dp[i][j] -= dp[last[i]][j - 1];
            }
            dp[i][j] = min(dp[i][j], (ll) 1e16);
        }
    }
    ll score = 0;
    for(int i = n; i >= 0; i--) {
        ll amt = min(k, dp[n][i]);
        score += amt * (n - i);
        k -= amt;
    }
    cout << (k == 0 ? score : -1) << endl;
}