#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int n, d; cin >> n >> d;
        vector<int> l(n);
        for(int i = 0; i < n; i++) {
            cin >> l[i];
        }
        sort(l.begin(), l.end()); reverse(l.begin(), l.end());
        if(l[0] + l[1] > d) {
            cout << "No\n";
            continue;
        }
        reverse(l.begin(), l.end());
        int big = l.back(); l.pop_back();
        vector<bitset<2001>> dp(d + 1);
        dp[0][0] = true;
        for(int len: l) {
            for(int i = d; i >= 0; i--) {
                dp[i] |= (dp[i] << len);
                if(i >= len) {
                    dp[i] = (dp[i] | dp[i - len]);
                }
            }
        }
        bool ok = false;
        for(int i = 0; i <= d; i++) {
            for(int j = 0; j <= d; j++) {
                if(i >= big && j >= big && i + j == d && dp[i][j]) {
                    ok = true;
                }
                if(i + j == d - big && dp[i][j]) ok = true;
            }
        }
        cout << (ok ? "Yes" : "No") << '\n';
    }
}
