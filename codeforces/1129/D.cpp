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
const int MXN = 1e5 + 23;
const int LOG = 23;
const int sq  = 350;

int n, k, a[MXN], f[MXN];
ll dp[MXN], ps[sq][2*sq+1], sum[sq];
vector<int> pos[MXN];

void Upd(int t) {
    sum[t] = 0;
    for(int j=-sq; j<=sq; j++) ps[t][j+sq]=0;
    for(int i=min(n, (t+1)*sq-1); i>=t*sq; i--) {
        (ps[t][sum[t]+sq] += dp[i]) %= MOD;
        sum[t] += f[i];
    }
    for(int j=-sq+1; j<=sq; j++)
        (ps[t][j+sq] += ps[t][j+sq-1]) %= MOD;
}

void Modify(int i, int x) {
    f[i] = x;
    Upd(i/sq);
}

void Main() {
    cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> a[i];
    dp[0] = 1;
    Upd(0);
    for(int i=1; i<=n; i++) {
        if(SZ(pos[a[i]])>=2) Modify(pos[a[i]][SZ(pos[a[i]])-2], 0);
        if(SZ(pos[a[i]])>=1) Modify(pos[a[i]][SZ(pos[a[i]])-1], -1);
        Modify(i, 1);
        pos[a[i]].pb(i);
        int cur=f[i];
        for(int j=i-1; j>=0 && j/sq==i/sq; j--) {
            if(cur<=k) (dp[i] += dp[j]) %= MOD;
            cur += f[j];
        }
        for(int j=(i/sq)-1; j>=0; j--) {
            int lim = min(sq, k-cur);
            if(-sq<=lim)
                (dp[i] += ps[j][lim+sq]) %= MOD;
            cur += sum[j];
        }
        Upd(i/sq);
    }
    cout << dp[n] << '\n';
}

int32_t main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int T = 1;
    // cin >> T;
    while(T--) Main();
    return 0;
}