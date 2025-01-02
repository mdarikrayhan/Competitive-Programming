#include <bits/stdc++.h>

#define all(v) v.begin(),v.end()
#define input(v)  for(auto&it:v) cin >> it;

using namespace std;

/*
Many Mistakes Breed Mastery!
*/
void Fast() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

const int N = 75;
int dp[N][N][N][N];
int v[N][N];
int n, m, k;

int dop(int i, int cnt, int sum, int last) {
    if (i == n)
        return (sum == 0 ? 0 : -1e9);

    int &ret = dp[i][cnt][sum][last];
    if (~ret)return ret;
    if (cnt == m / 2 || last == m)
        return ret = dop(i + 1, 0, sum, 0);
    ret = dop(i, cnt + 1, (sum + v[i][last]) % k, last + 1) + v[i][last];
    ret = max(ret, dop(i, cnt, sum, last + 1));
    ret = max(ret, dop(i + 1, 0, sum, 0));
    return ret;
}

void solve() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; j++)
            cin >> v[i][j];
    memset(dp, -1, sizeof dp);
    cout << dop(0, 0, 0, 0);
}

int32_t main() {
    Fast();
    int t = 1;
    //  cin >> t;
    while (t--)
        solve();
    return 0;
}