#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int a[N], dp[N], ans, n, mx;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[a[i]]++, mx = max(mx, a[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 2; j * a[i] <= mx; j++) {
            dp[j * a[i]] = max(dp[j * a[i]], dp[a[i]] + 1);
        }
        ans = max(ans, dp[a[i]]);
    }
    cout << ans;
    return 0;
}
		     		  			 		 		  							 	