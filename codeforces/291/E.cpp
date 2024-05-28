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
const int MXN = 3e5 + 23;
const int LOG = 23;

int f[MXN], nxt[MXN][26];
void kmp(string s) {
    f[1] = 0;
    for(int i=2; i<SZ(s); i++) {
        f[i] = f[i-1];
        while(f[i] && s[i] != s[f[i]+1]) f[i] = f[f[i]];
        if(s[i] == s[f[i]+1]) f[i]++;
    }
    for(int i=0; i<26; i++)
        nxt[0][i] = (s[1]-'a' == i ? 1 : 0);
    for(int i=1; i<SZ(s); i++)
        for(int j=0; j<26; j++)
            nxt[i][j] = (i<SZ(s)-1 && s[i+1]-'a' == j ? i+1 : nxt[f[i]][j]);
}

int n, N;
vector<pii> g[MXN];
string pat;

int ans=0;
void dfs(int v, int len=0) {
    if(len == SZ(pat)-1) ans++;
    for(auto [u, c] : g[v])
        dfs(u, nxt[len][c]);
}

void Main() {
    cin >> n;
    N = n;
    for(int i=2; i<=n; i++) {
        int p;
        string s;
        cin >> p >> s;
        if(SZ(s) == 1) g[p].pb(Mp(i, s[0]-'a'));
        else {
            g[p].pb(Mp(++N, s[0]-'a'));
            for(int i=1; i<SZ(s)-1; i++) {
                g[N].pb(Mp(N+1, s[i]-'a'));
                N++;
            }
            g[N].pb(Mp(i, s.back()-'a'));
        }
    }
    cin >> pat;
    pat = '$' + pat;
    kmp(pat);
    dfs(1);
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int T = 1;
    // cin >> T;
    while(T--) Main();
    return 0;
}