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
const ll  MOD = 998244353;
const int MXN = 15e4 + 23;
const int LOG = 30;

int N=1, ch[MXN*LOG][2], sz[MXN*LOG];
void ins(int x) {
    int v=1;
    sz[v]++;
    for(int i=LOG-1; i>=0; i--) {
        if(!ch[v][x>>i & 1]) ch[v][x>>i & 1] = ++N;
        sz[v = ch[v][x>>i & 1]]++;
    }
}

int x;
ll two[MXN], ans;

// non empty (p in v) (q in u) p^q<=x
ll solve2(int v, int u, int b) {
    if(!v) return (two[sz[u]]-1+MOD)%MOD;
    if(!u) return (two[sz[v]]-1+MOD)%MOD;
    if(b == -1) return (two[sz[v]+sz[u]]-1+MOD)%MOD;
    if(x>>b & 1) return ((solve2(ch[v][0], ch[u][1], b-1)+1)
                        *(solve2(ch[v][1], ch[u][0], b-1)+1)
                        -1+MOD) % MOD;
    return (solve2(ch[v][0], ch[u][0], b-1)
           +solve2(ch[v][1], ch[u][1], b-1)
           -(two[sz[ch[v][0]]]-1)
           -(two[sz[ch[v][1]]]-1)
           -(two[sz[ch[u][0]]]-1)
           -(two[sz[ch[u][1]]]-1) // har do daste na tohi
           +(two[sz[v]]-1)
           +(two[sz[u]]-1) // faghat az v ya faghat az u
           + 4*MOD) % MOD; 
    
}

// non empty (p,q in v) p^q<=x
ll solve1(int v, int b) {
    if(!v) return 0;
    if((1<<(b+1))-1 <= x) return (two[sz[v]] - 1 + MOD) % MOD;
    if(x>>b & 1) return solve2(ch[v][0], ch[v][1], b-1);
    return solve1(ch[v][0], b-1) + solve1(ch[v][1], b-1);
}

void Main() {
    two[0] = 1;
    for(int i=1; i<MXN; i++)
        two[i] = two[i-1]*2 % MOD;
    int n;
    cin >> n >> x;
    int a;
    while(n--) {
        cin >> a;
        ins(a);
    }
    cout << solve1(1, LOG-1) << '\n';
}

int32_t main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int T = 1;
    // cin >> T;
    while(T--) Main();
    return 0;
}