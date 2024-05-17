// LUOGU_RID: 159219387
#include <iostream>
#include <vector>

using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<vector<int>> dp(n + 1, vector<int> (n + 1));
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i][i] = 1;
    }

    for(int i = 1; i < n; i++) {
        dp[i][i + 1] = a[i] == a[i + 1] ? 1 : 2;
    }

    for(int i = 3; i <= n; i++) {
        for(int j = 1; j <= n - i + 1; j++) {
            if(a[j] == a[j + i - 1]) 
                dp[j][j + i - 1] = dp[j + 1][j + i - 2];
            else
                dp[j][j + i - 1] = 999999;
            for(int k = j; k <= j + i - 2; k++)
                dp[j][j + i - 1] = min(dp[j][k] + dp[k + 1][j + i - 1], dp[j][j + i - 1]);
        }
    }

    cout << dp[1][n];
}