#include<iostream>
#include<cstring>
#include<vector>
#include<array>
using namespace std;
using LL = long long;

int main(){

#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    string s, t;
    cin >> s >> t;
    const int n = s.size(), m = t.size();
    s = " " + s;
    t = " " + t;
    vector<vector<int> > dp(n + 1, vector<int>(m + 1, 1e9));
    dp[0][0] = 0;
    vector<array<int, 26> > nxts(n + 1), nxtt(m + 1);
    nxts[n].fill(n + 1);
    for(int i = n - 1; i >= 0; i--){
        nxts[i] = nxts[i + 1]; 
        nxts[i][s[i + 1] - 'a'] = i + 1;
    }
    nxtt[m].fill(m + 1);
    for(int i = m - 1; i >= 0; i--){
        nxtt[i] = nxtt[i + 1];
        nxtt[i][t[i + 1] - 'a'] = i + 1;
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if (i + 1 <= n){
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + b);
            }
            if (i + 1 <= n && j + 1 <= m){
                dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + (s[i + 1] != t[j + 1]) * c);
            }
            if (j + 1 <= m){
                dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + a);
            }
            if (i + 1 <= n && j + 1 <= m){
                int nxt1 = nxtt[j + 1][s[i + 1] - 'a'];
                int nxt2 = nxts[i + 1][t[j + 1] - 'a'];
                if (nxt1 <= m && nxt2 <= n){
                    dp[nxt2][nxt1] = min(dp[nxt2][nxt1], dp[i][j] + (nxt1 - j - 2) * a + (nxt2 - i - 2) * b + d);
                }
            }
        }
    }
    cout << dp[n][m] << '\n';

}