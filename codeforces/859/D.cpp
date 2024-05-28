/*
Problem: 859D
Date: 28-05-2024 01:39 PM
*/


#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;

// compute dp[node][winner] = max expected score if winner is node of subtree node
// P[node][winner] = probability winner is correct
// (2^n)^3 time
// max_x (Probability W wins) * (score at this level) + Dp[child1][W] + Dp[child2][x]

const int N = 6;
int n, a[1 << N][1 << N];
double dp[1 << (N + 1)][1 << N], pr[1 << (N + 1)][1 << N];
bool vis[1 << (N + 1)][1 << N];

// range [l, r)
void solve(int i, int l, int r, int w) {
    if(vis[i][w]) return;
    vis[i][w] = true;
    if(r - l == 1) {
        dp[i][w] = 0;
        pr[i][w] = 1;
        return;
    }
    int m = (l + r) / 2;
    rep(x, l, m) solve(2 * i + 1, l, m, x);
    rep(x, m, r) solve(2 * i + 2, m, r, x);
    dp[i][w] = pr[i][w] = 0;
    if(w < m) {
        rep(x, m, r) {
            pr[i][w] += pr[2 * i + 1][w] * pr[2 * i + 2][x] * 0.01 * a[w][x];
            dp[i][w] = max(dp[i][w], dp[2 * i + 1][w] + dp[2 * i + 2][x]);
        }
    }else {
        rep(x, l, m) {
            pr[i][w] += pr[2 * i + 2][w] * pr[2 * i + 1][x] * 0.01 * a[w][x];
            dp[i][w] = max(dp[i][w], dp[2 * i + 2][w] + dp[2 * i + 1][x]);
        }
    }
    dp[i][w] += pr[i][w] * (r - l) / 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 0, (1 << n)) {
        rep(j, 0, (1 << n)) {
            cin >> a[i][j];
        }
    }
    cout << fixed << setprecision(10);
    rep(i, 0, (1 << n)) {
        solve(0, 0, 1 << n, i);
    }
    cout << *max_element(dp[0], dp[0] + (1 << n)) << '\n';
}