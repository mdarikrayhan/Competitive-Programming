#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
// typedef __int128 lll;
// typedef __float128 lld;
using namespace std;

ll mod = 998244353;

ll solve(int n, int m, vector<int> l, vector<int> r, int g) {
    m /= g;
    for(int i = 0; i < n; i++){
        l[i] = (l[i] + g - 1) / g;
        r[i] = r[i] / g;
        if(l[i] > r[i]){
            return 0;
        }
    }
    if(m == 0){
        return 0;
    }
    vector<vector<ll>> dp(2, vector<ll>(m + 1, 0));
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        //take pfx sum of previous  
        for(int j = 1; j <= m; j++){
            dp[0][j] += dp[0][j - 1];
            dp[0][j] %= mod;
        }
        //compute dp
        for(int j = 0; j <= m; j++){
            int cl = j - r[i - 1] - 1;
            int cr = j - l[i - 1];
            dp[1][j] = 0;
            if(cr >= 0){
                dp[1][j] += dp[0][cr];
            }
            if(cl >= 0){
                dp[1][j] -= dp[0][cl];
                if(dp[1][j] < 0){
                    dp[1][j] += mod;
                }
            }
        }
        swap(dp[0], dp[1]);
    }
    ll ans = 0;
    for(int i = 0; i < dp[0].size(); i++){
        ans += dp[0][i];
        ans %= mod;
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vector<int> l(n), r(n);
    for(int i = 0; i < n; i++){
        cin >> l[i] >> r[i];
    }
    if(n > m){
        cout << "0\n";
        return 0;
    }
    vector<ll> g(m / n + 1);
    for(int i = 1; i < g.size(); i++){
        g[i] = solve(n, m, l, r, i);
    }
    for(int i = g.size() - 1; i >= 1; i--){
        for(int j = i * 2; j < g.size(); j += i){
            g[i] -= g[j];
            if(g[i] < 0){
                g[i] += mod;
            }
        }
    }
    cout << g[1] << "\n";
    
    return 0;
}
