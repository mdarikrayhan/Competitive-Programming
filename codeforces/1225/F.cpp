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
const int MXN = 1e5 + 23;
const int LOG = 23;

int n, p[MXN], h[MXN];
set<int> ch[MXN];

void Main() {
    cin >> n;
    p[0] = -1;
    for(int i=1; i<n; i++) {
        cin >> p[i];
        h[i] = h[p[i]]+1;
        ch[p[i]].insert(i);
    }
    int v=0;
    for(int i=1; i<n; i++)
        if(h[i] > h[v])
            v = i;
    vector<int> path, opr;
    while(v) {
        if(SZ(ch[p[v]]) == 1) {
            path.pb(v);
            v = p[v];
            continue;
        }
        opr.pb(v);
        auto it = ch[p[v]].begin();
        if(*it == v) it++;
        int u = *it;
        ch[p[v]].erase(v);
        ch[p[v] = u].insert(v);
    }
    path.pb(0);
    while(SZ(path)) {
        cout << path.back() << ' ';
        path.pop_back();
    }
    cout << '\n';
    cout << SZ(opr) << '\n';
    while(SZ(opr)) {
        cout << opr.back() << ' ';
        opr.pop_back();
    }
    cout << '\n';
}

int32_t main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int T = 1;
    // cin >> T;
    while(T--) Main();
    return 0;
}