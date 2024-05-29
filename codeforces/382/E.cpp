#include <bits/stdc++.h>
using namespace std;

typedef long long       ll;
typedef long double     ld;
typedef pair<int, int>  pii;
typedef pair<ll, ll>    pll;

#define deb(x)          cout << x
#define X               first
#define Y               second
#define SZ(x)           int(x.size())
#define all(x)          x.begin(), x.end()
#define mins(a,b)       (a = min(a,b))
#define maxs(a,b)       (a = max(a,b))
#define pb              push_back
#define Mp              make_pair
#define kill(x)         {cout << (x) << '\n'; exit(0);}
#define killt(x)        {cout << (x) << '\n'; return;}
#define md(x)           ((x)%MOD)
#define lc              id<<1
#define rc              lc|1
#define mid             ((l+r)/2)
mt19937_64              rng(chrono::steady_clock::now().time_since_epoch().count());

const ll  INF = 1e9 + 23;
const ll  MOD = 1e9 + 7;
const int MXN = 53;
const int LOG = 23;

ll power(ll a, ll b) {
    ll res=1;
    while(b) {
        if(b&1) res = md(res*a);
        a = md(a*a);
        b >>= 1;
    }
    return res;
}

int n, k;
ll dp[MXN][MXN][2], C[MXN][MXN], i2;

void Main() {
    cin >> n >> k;
    i2 = MOD - MOD/2;
    for(int i=0; i<MXN; i++) C[i][0] = 1;
    for(int i=1; i<MXN; i++)
        for(int j=1; j<=i; j++)
            C[i][j] = md(C[i-1][j-1] + C[i-1][j]);
    dp[1][0][0] = 1;
    for(int s=2; s<=n; s++) 
        for(int m=0; m<=s/2; m++) {
            // 2 child
            for(int s0=1, s1=s-2; s1; s0++, s1--) {
                ll add[2] = {0, 0};
                for(int m0=0; m0<=s0/2; m0++)
                    for(int op0=0; op0<2; op0++)
                        for(int op1=0; op1<2; op1++) {
                            int m1 = m-m0-op0-op1;
                            if(m1>=0)
                                add[!(op0&op1)] = md(add[!(op0&op1)] + dp[s0][m0][op0]*dp[s1][m1][op1]);
                        }
                dp[s][m][0] = md(dp[s][m][0] + add[0]*md(C[s-1][s0]*md(s0*s1)));
                dp[s][m][1] = md(dp[s][m][1] + add[1]*md(C[s-1][s0]*md(s0*s1)));
            }
            dp[s][m][0] = md(dp[s][m][0]*i2);
            dp[s][m][1] = md(dp[s][m][1]*i2);

            // 1 child
            if(m) dp[s][m][0] = md(dp[s][m][0] + (s-1)*dp[s-1][m-1][1]);
            dp[s][m][1] = md(dp[s][m][1] + (s-1)*dp[s-1][m][0]);
        }
    cout << md(dp[n][k][0] + dp[n][k-1][1]) << '\n';
}

int32_t main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int T = 1;
    // cin >> T;
    while(T--) Main();
    return 0;
}