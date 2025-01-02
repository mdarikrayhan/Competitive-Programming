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
const int MXN = 3e3 + 23;
const int LOG = 23;

int n;

vector<int> V;
bool mark[MXN];
void dfs_cycle(int v, int *p) {
    mark[v] = 1;
    V.pb(v);
    if(!mark[p[v]]) dfs_cycle(p[v], p);
}

vector<vector<int>> cycles(int *p) {
    fill(mark+1, mark+n+1, 0);
    vector<vector<int>> res;
    for(int i=1; i<=n; i++)
        if(!mark[i]) {
            V.clear();
            dfs_cycle(i, p);
            sort(all(V));
            res.pb(V);
        }
    return res;
}

int intersect(vector<int> &A, vector<int> &B) {
    int i=0, j=0;
    while(i<SZ(A) && j<SZ(B))
        if(A[i]<B[j]) i++;
        else if(A[i]>B[j]) j++;
        else return A[i];
    return -1;
}

int a[MXN], b[MXN];
vector<vector<int>> A, B;
vector<int> g[MXN];
int n1, n2, ma[MXN], mb[MXN];

bool try_kuhn(int v) {
    mark[v] = 1;
    for(int u : g[v])
        if(mb[u]==-1 || (!mark[mb[u]] && try_kuhn(mb[u]))) {
            ma[v] = u;
            mb[u] = v;
            return 1;
        }
    return 0;
}

void kuhn() {
    fill(ma, ma+n1, -1);
    fill(mb, mb+n2, -1);
    bool fnd=1;
    while(fnd) {
        fnd=0;
        fill(mark, mark+n1, 0);
        for(int i=0; i<n1; i++)
            if(ma[i] == -1)
                fnd |= try_kuhn(i);
    }
}

void Main() {
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++) cin >> b[i];
    A = cycles(a);
    B = cycles(b);
    n1 = SZ(A), n2=SZ(B);
    for(int i=0; i<n1; i++)
        for(int j=0; j<n2; j++)
            if(intersect(A[i], B[j]) != -1)
                g[i].pb(j);
    kuhn();
    set<int> opr;
    for(int i=1; i<=n; i++)
        opr.insert(i);
    for(int i=0; i<n1; i++)
        if(ma[i] != -1)
            opr.erase(intersect(A[i], B[ma[i]]));
    cout << SZ(opr) << '\n';
    for(int i : opr)
        cout << i << ' ';
    cout << '\n';
}

int32_t main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int T = 1;
    // cin >> T;
    while(T--) Main();
    return 0;
}