#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, m, a[300001], dp[300001];

bool check(int tar){
	memset(dp, 0, sizeof(dp));
	int pos = 0, tmp = 0;
	dp[0] = 1;
	for(int i = m; i <= n; i++){
		tmp += dp[i - m];
		while(pos <= n && a[i] - a[pos] > tar) tmp -= dp[pos], pos++;
		if(tmp + dp[pos - 1] > 0) dp[i] = 1;
	}
	return dp[n];
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	} 
	a[0] = INT_MIN;
	sort(a + 1, a + n + 1);
	int l = 0, r = INT_MAX;
	while(l < r - 1){
		//cout << l << " " << r << endl;
		int mid = (l + r) / 2;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	cout << (check(r - 1) ? r - 1 : r) << endl;
	return 0;
}