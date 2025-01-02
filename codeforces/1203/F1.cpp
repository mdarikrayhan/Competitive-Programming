#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
void solve(){
    int n, curr; cin >> n >> curr;
	vector<pair<int, int>> a, b;
	for (int i = 0; i < n; ++i) {
		pair<int, int> x;
		cin >> x.first >> x.second;
		if (x.second >= 0) a.push_back(x);
		else {
		    x.first = max(x.first, abs(x.second));
		    b.push_back(x);
		}
	}
	int m = b.size();
	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), [](pair<int,int> x, pair<int,int> y) {
        return (x.first + x.second) > (y.first + y.second);
    });
	int cnt = 0;
	for (int i = 0; i < a.size(); i++) {
		if (curr >= a[i].first) {
			curr += a[i].second;
			cnt++;
		}
	}
	vector<vector<int>> dp(m + 1, vector<int>(curr + 1, 0));
	dp[0][curr] = cnt;
	for (int i = 0; i < m; ++i) {
		for (int x = 0; x <= curr; ++x) {
			if (x >= b[i].first && x + b[i].second >= 0) {
				dp[i + 1][x + b[i].second] = max(dp[i + 1][x + b[i].second], dp[i][x] + 1);
			}
			dp[i + 1][x] = max(dp[i + 1][x], dp[i][x]);
		}
	}
	int ans = 0;
	for (int x = 0; x <= curr; x++) ans = max(ans, dp[m][x]);
	cout << (ans == n ? "YES" : "NO") << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1; //cin >> t;
    while (t--) solve();
}
