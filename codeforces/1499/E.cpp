/*
Kshitij Sharma
github: meetthehorizon
   /\_/\
  (= ._.)
  / >  \>
*/

#include <bits/stdc++.h> 
using namespace std; 

#define int long long
#define MOD 998244353
#define INF 10000000000000000
#define FOR(i, n) for (size_t i = 0; (i) < (n); (i)++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

void solve(int);
bool test_cases = false;
template <typename T> T next() { T x; cin >> x; return x; }
 
signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; if(test_cases) cin >> t;
    for(size_t i = 1; i <= t; i++)
        solve(i);
    return 0;
}

int dp[1001][1001][2] {};

void solve(int t)
{
    // CHILL BRO
    // I ASSUME YOU ARE HERE BECAUSE YOU HAVE A COMPLETE ALGORITHIM?
    string a, b; cin >> a >> b;
    int na = a.size(), nb = b.size();

    int auxa[na], auxb[nb];
    auxa[na-1] = auxb[nb-1] = 1;

    for (int i = na - 2; i >= 0; --i)
        auxa[i] = 1 + (a[i] != a[i+1]) * auxa[i+1];

    for (int i = nb - 2; i >= 0; --i)
        auxb[i] = 1 + (b[i] != b[i+1]) * auxb[i+1];

    for (int i = na - 1; i >= 0; --i) {
        for (int j = nb - 1; j >= 0; --j) {
            if (a[i] != b[j]) {
                dp[i][j][0] = auxb[j];
                dp[i][j][1] = auxa[i];
            }

            if (i + 1 < na) {
                if (a[i] != a[i+1])
                    dp[i][j][0] += dp[i+1][j][0];
                if (a[i] != b[j])
                    dp[i][j][0] += dp[i+1][j][1];
            }
            if (j + 1 < nb) {
                if (b[j] != b[j+1])
                    dp[i][j][1] += dp[i][j+1][1];
                if (b[j] != a[i])
                    dp[i][j][1] += dp[i][j+1][0];
            }

            dp[i][j][1] %= MOD;
            dp[i][j][0] %= MOD;
        }
    }

    int ans = 0;
    FOR(i, na) FOR(j, nb) ans = (ans + dp[i][j][0] + dp[i][j][1]) % MOD;
    cout << ans << '\n';
}