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
#define md(x)           ((((x)%MOD)+MOD)%MOD)
#define lc              id<<1
#define rc              lc|1
#define mid             ((l+r)/2)
mt19937_64              rng(chrono::steady_clock::now().time_since_epoch().count());

const ll  INF = 1e9 + 23;
const ll  MOD = 1e9 + 7;
const int MXN = 1e6 + 23;
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

ll F[MXN], I[MXN];
void prep_F() {
    F[0] = 1;
    for(int i=1; i<MXN; i++) F[i] = md(F[i-1]*i);
    I[MXN-1] = power(F[MXN-1], MOD-2);
    for(int i=MXN-2; i>=0; i--) I[i] = md(I[i+1]*(i+1));
}
ll C(int n, int r) {
    return r<0||r>n ? 0 : md(F[n]*md(I[r]*I[n-r]));
}

vector<int> D[MXN], pr[MXN];
bool ispr[MXN];

void sieve() {
    fill(ispr+2, ispr+MXN, 1);
    for(int i=1; i<MXN; i++) {
        for(int j=i; j<MXN; j+=i) {
            D[j].pb(i);
            if(ispr[i]) {
                pr[j].pb(i);
                if(i<j) ispr[j] = 0;
            }
        }
        reverse(all(D[i]));
    }
}

int n, k, q;
ll ans=0, dp[10][MXN], ct[MXN];

void ins(int x) {
    for(int d : D[x]) {
        dp[SZ(pr[x])][d] = C(ct[d]++, k-1);
        for(int i=SZ(pr[x])-1; i>=0; i--)
            dp[i][d] = md(dp[i+1][d] - ((ll)d*pr[x][i] <= x ? dp[i+1][(ll)d*pr[x][i]] : 0));
        ans = md(ans+dp[0][d]*d);
    }
    for(int d : D[x])
        for(int i=SZ(pr[x]); i>=0; i--)
            dp[i][d] = 0;
}

void Main() {
    prep_F();
    sieve();
    cin >> n >> k >> q;
    for(int i=1, x; i<=n; i++) {
        cin >> x;
        ins(x);
    }
    for(int i=1, x; i<=q; i++) {
        cin >> x;
        ins(x);
        cout << ans << '\n';
    }
}

int32_t main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int T = 1;
    // cin >> T;
    while(T--) Main();
    return 0;
}