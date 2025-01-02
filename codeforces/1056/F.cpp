#include <bits/stdc++.h>

#define ll long long
using namespace std;
const int N = 110, md = 1e9 + 7;
const double eps = 0.001;

void solve() {
    int n;
    cin >> n;
    double c, t;
    cin >> c >> t;
    pair<int, int> arr[n];
    int m = 0;
    for (int i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second, m += arr[i].second;
    sort(arr, arr + n, greater<>());
    double pw[n];
    pw[0] = 0.9;
    for (int i = 1; i < n; i++)
        pw[i] = pw[i - 1] * 0.9;
    vector <vector<double>> dp(m + 5, vector<double>(n + 5, 1e15));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int val = m; val >= 0; val--) {
            for (int taken = i; taken >= 0; taken--) {
                if (val + arr[i].second > m or dp[val][taken] > 1e14)
                    continue;
                dp[val + arr[i].second][taken + 1] = min(dp[val + arr[i].second][taken + 1],
                                                         dp[val][taken] + arr[i].first / pw[taken]);
            }
        }
    }
    int mx = 0;
    for (int val = 1; val <= m; val++) {
        for (int taken = 1; taken <= n; taken++) {
            double mn = dp[val][taken];
            if (mn > 1e14)
                continue;
            double st = eps, e = t, ans = 1e15;
            int cnt = 200;
            while (cnt--) {
                double range = e - st;
                double mid1 = st + range / 3.0;
                double mid2 = st + 2.0 * range / 3.0;
                double op1 = mn / (1 + c * mid1) + mid1 + taken * 10;
                double op2 = mn / (1 + c * mid2) + mid2 + taken * 10;
                ans = min({ans, op1, op2});
                if (op1 < op2) {
                    e = mid2;
                } else st = mid1;
            }
            if (ans <= t) {
                mx = max(mx, val);
            }
        }
    }
    cout << mx << '\n';
}

int main() {

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int i = 1; i <= tc; i++) {
        solve();
    }
}

   	  				 					    	 		  				