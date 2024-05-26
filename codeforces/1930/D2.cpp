//James it's Valtteri
#include <bits/stdc++.h>
using namespace std;

long long n, dp[1000005], res, cur, pos;
string s;

int main(){
    int t;
    cin >> t;
    while (t--){
        cin >> n >> s;
        s = "," + s;
        res = 0;
        for (int i = 1; i <= n + 4; i++) dp[i] = 0;
        for (int i = n; i >= 1; i--){
            if (s[i] == '1') dp[i] = dp[i + 3] + n - i + 1;
            else dp[i] = dp[i + 1];
            //cout << dp[i] << " ";
            res += dp[i];
        }
        cout << res << "\n";
    }
}