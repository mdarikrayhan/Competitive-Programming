#include <bits/stdc++.h>
using namespace std;
// free Palestine
void fast() {
    ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
const int N = 104, OO = 0x3f3f3f3f;
int dp[104][200004], calories[N], taste[N], n, k;
int solve(int in = 1, int ratio = 0) {
    if (in > n) return (ratio ? -OO : 0);

    int &ret = dp[in][ratio];
    if (~ret) return ret;
    return ret = max(solve(in + 1, ratio), solve(in + 1, ratio + taste[in] - k * calories[in]) + taste[in]);
}
signed main() {
    fast();

    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> taste[i];
    for (int i = 1; i <= n; ++i) cin >> calories[i];

    memset(dp, -1, sizeof dp);

    cout << (solve() > 0 ? solve() : -1);

    return (0 - 0); // ♡ ♡ ♡
}
	  	 	 	 	 		     			 	 	   	