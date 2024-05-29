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
#define lc              id<<1
#define rc              lc|1
#define mid             ((l+r)/2)
mt19937_64              rng(chrono::steady_clock::now().time_since_epoch().count());

const ll  INF = 1e9 + 23;
const ll  MOD = 998244353;
const int MXN = 5e3 + 2;
const int LOG = 23;

ll F[MXN], I[MXN], dp[MXN][MXN], ans[MXN];

ll C(int n, int r) {
    return r<0||r>n ? 0 : F[n] * I[r] % MOD * I[n-r] % MOD;
}

void Main() {
    F[0] = 1;
    for(int i=1; i<MXN; i++) F[i] = F[i-1] * i % MOD;
    I[0] = I[1] = 1;
    for(int i=2; i<MXN; i++) I[i] = (MOD - MOD/i) * I[MOD%i] % MOD;
    for(int i=2; i<MXN; i++) (I[i] *= I[i-1]) %= MOD;
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        dp[i][1] = 1;
        for(int j=2; j<=i; j++)
            dp[i][j] = (j*dp[i-1][j] + (i-j+1)*dp[i-1][j-1]) % MOD;
    }
    for(int i=1; i<=n; i++)
        for(int j=1; j<=i; j++)
            (ans[j] += dp[i][j] * C(n, i) % MOD * F[n-i] % MOD) %= MOD;
    for(int i=1; i<=n; i++)
        cout << ans[i] << ' ';
    cout << '\n';
}

int32_t main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int T = 1;
    // cin >> T;
    while(T--) Main();
    return 0;
}