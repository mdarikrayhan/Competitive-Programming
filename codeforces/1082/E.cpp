#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define pb push_back
#define ins insert
#define f first 
#define s second 

int dp[500001];
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int n, k; cin >> n >> k;
    int mx = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        if (c == k) ++cnt;
        else dp[c] = max(dp[c], cnt) + 1;
        mx = max(mx, dp[c] - cnt);
    }
    cout << mx + cnt << '\n';
}