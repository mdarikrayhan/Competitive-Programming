#include <bits/stdc++.h>

#define ll long long
using namespace std;
const int N = 1e5 + 10, md = 1e9 + 7;

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> imp, nimp;
    int arr[n];
    int m = 0;
    for (int i = 0; i < n; i++)
        cin >> arr[i], m += arr[i];
    for (int i = 0; i < n; i++) {
        int b;
        cin >> b;
        if (b)
            imp.push_back(arr[i]);
        else nimp.push_back(arr[i]);
    }
    vector<bool> can(m + 1);
    can[0] = 1;
    for (auto w: nimp)
        for (int i = m - 1; i >= 0; i--) {
            if (!can[i])
                continue;
            can[i + w] = 1;
        }
    std::sort(imp.rbegin(), imp.rend());
    vector<int> dp(m + 1);
    for (auto w: imp)
        for (int i = m - 1; i >= 0; i--) {
            if (!can[i])
                continue;
            can[i + w] = 1;
            dp[i + w] = max(dp[i + w], dp[i] + (l <= m - i - w and m - i - w <= r));
        }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
}

int main() {

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tc = 1;
//    cin >> tc;
    for (int i = 1; i <= tc; i++) {
        solve();
    }
}

	  	 		    	  				   	  	 	 	