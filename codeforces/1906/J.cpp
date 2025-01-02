#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define trav(a, x) for(auto& a : x)
#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define ROF(i, a, b) for (int i=(a); i>=(signed)(b); i--)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define vi vector<int>
#define f first
#define s second
#define all(v) (v).begin(), (v).end()
typedef long long ll;

const ll mod = 1e9 + 7, MOD = 998244353;

ll dp[5000][5000];

long long exp(long long x, long long y, long long p=MOD) {
    long long res = 1; x %= p;
    while (y) {
        if (y & 1) {
            res *= x; res %= p; 
        }
        x *= x; x %= p;
        y >>= 1;
    }
    return res;
}

ll cook (ll y) {
    return exp(2, y);
}

int main() 
{	
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> v(n); 
    F0R(i, n) cin >> v[i];
    dp[1][0] = 1;
    FOR(i, 2, n-1) {
        F0R(j, i-1) {
            if(v[i-1] < v[i]) dp[i][j] += cook(i-j-1)*dp[i-1][j]%MOD;
            else if(j > 0) dp[i][j] += cook(i-j-1)*dp[i-1][j-1]%MOD;
            if(j>0) dp[i][j] += dp[i][j-1];
            dp[i][j] %= MOD;
        }
        (dp[i][i-1] += dp[i-1][i-2]+dp[i][i-2]) %= MOD;
    }
    cout << dp[n-1][n-2] << "\n";
    return 0;
}   
