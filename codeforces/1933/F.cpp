#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int t;
    cin >> t;
    while (t--){
        int n, m;
    	cin >> n >> m;
    	bool a[n][m + 1];
    	for (int i = 0; i < n; i++) {
    		for (int j = 1; j <= m; j++) {
    			cin >> a[i][j];
    		}
    	}
    	int dp[n][m + 1];
    	for (int i = 0; i < n; i++) {
    		for (int j = 0; j <= m; j++) {
    			dp[i][j] = INT_MAX;
    		}
    	}
    	dp[0][1] = 0;
    	for (int i = 1; i <= m; i++) {
    		for (int j = 0; j < n; j++) {
    			if (a[j][i]){
    			    continue;
    			}
    			dp[j][i] = min(dp[j][i], dp[(j - 1 + n) % n][i - 1] + 1); 
    		}
    		for (int j = 0; j < 3 * n; j++) {
    			if (a[j % n][i] || a[(j - 1 + n) % n][i]){
    			    continue;
    			}
    			dp[j % n][i] = min(dp[j % n][i], dp[(j - 2 + n) % n][i] + 1);
    		}
    	}
    	int ans = INT_MAX;
    	for (int i = 0; i < n; i++) {
    		if (dp[i][m] == INT_MAX){
    		    continue;
    		}
    		int npos = ((n - 1) + dp[i][m]) % n;
    		if (npos < i) npos += n;
    		int cur = dp[i][m] + min(npos - i, n - (npos - i));
    		ans = min(ans, cur);
    	}
    	if(ans == INT_MAX){
    	    cout << -1 << endl;
    	}else{
    	    cout << ans << endl;
    	}
    }
}