#include<bits/stdc++.h>
using namespace std;
#define INF (int)1e17
#define FOR(a, b, c) for (int a = b; a < c; a++)
#define int long long
#define pb push_back
typedef vector <int> vint;
vector < vector < vector < vint > > > dp(105, vector < vector < vint > >(105, vector < vint > (2, vint(2,0))));
void solve(){
    string s;
    cin >> s;
    int k;
    cin >> k;
    int n = s.length();
    if(s[0] == 'F'){
        dp[0][0] = {{INF,-INF}, {1,1}};
        dp[0][1] = {{0, 0}, {INF, -INF}};
    }
    else{
        dp[0][1] = {{INF,-INF}, {1,1}};
        dp[0][0] = {{0, 0}, {INF, -INF}};
    }

    FOR(i,1,n){
        FOR(j,0,k+1){
            if(s[i] == 'T'){
                dp[i][j][0][0] = min(j-1 >= 0 ? dp[i-1][j-1][0][0] - 1 : INF, dp[i-1][j][1][0]);
                dp[i][j][0][1] = max(j-1 >= 0 ? dp[i-1][j-1][0][1] - 1 : -INF, dp[i-1][j][1][1]);
                dp[i][j][1][0] = min(j-1 >= 0 ? dp[i-1][j-1][1][0] + 1 : INF, dp[i-1][j][0][0]);
                dp[i][j][1][1] = max(j-1 >= 0 ? dp[i-1][j-1][1][1] + 1 : -INF, dp[i-1][j][0][1]);
            }
            else{
                dp[i][j][0][0] = min(dp[i-1][j][0][0] - 1, j-1 >= 0 ? dp[i-1][j-1][1][0] : INF);
                dp[i][j][0][1] = max(dp[i-1][j][0][1] - 1, j-1 >= 0 ? dp[i-1][j-1][1][1] : -INF);
                dp[i][j][1][0] = min(dp[i-1][j][1][0] + 1, j-1 >= 0 ? dp[i-1][j-1][0][0] : INF);
                dp[i][j][1][1] = max(dp[i-1][j][1][1] + 1, j-1 >= 0 ? dp[i-1][j-1][0][1] : -INF);
            }
        }
    }
    int ans = 0;
    for(int j = k%2 ; j <= k ; j += 2){
        FOR(l,0,2){
            FOR(m,0,2)
                if(dp[n-1][j][l][m] <= 105 && dp[n-1][j][l][m] >= -105) ans = max(ans, abs(dp[n-1][j][l][m]));
        }
    }
    cout << ans << endl;
    // cout << dp[1][1][1][1];
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(10) << endl;
    int t;
    t = 1;
    while(t--)
    solve();
}