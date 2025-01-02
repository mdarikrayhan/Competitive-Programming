#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair <ll,ll> pll;
typedef pair <int,int> pii;
typedef pair <int,pii> piii;

#define forr(_a,_b,_c) for(int _a = (_b); _a <= (_c); ++_a)
#define ford(_a,_b,_c) for(int _a = (_b) + 1; _a --> (_c);)
#define forf(_a,_b,_c) for(int _a = (_b); _a < (_c); ++_a)
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define all(x) begin(x),end(x)
#define mask(i) (1LL << (i))
#define bit(x, i) (((x) >> (i)) & 1)
#define bp __builtin_popcountll
#define file "test"

const int N = 5e5 + 5;
const ll oo = 1e9;
const ll mod = 1e9 + 7; // 998244353;

vector <int> a[N];
ll res, sz[N], n;


void dfs (int u, int p){
    sz[u] = 1;
    ll x = 0, z = 0;
    for (int v : a[u])
    if (v != p){
        dfs(v, u);
        res += z * sz[v] * (sz[v] - 1) / 2;
        x += sz[u] * sz[v];
        z += sz[v] * (sz[v] - 1) / 2;
        sz[u] += sz[v];
    }
    
    reverse(all(a[u]));

    ll tmp = sz[u];
    sz[u] = 1;

    for (int v : a[u])
    if (v != p){
        res += (x - sz[v] * (tmp - sz[v])) * sz[v] * (sz[v] - 1) / 2;
        res += (tmp - sz[v]) * (n - tmp) * sz[v] * (sz[v] - 1) / 2;
        sz[u] += sz[v];
    }

 //   cout << u << " " << sz[u] << " " << res << "\n";

}

ll u, v;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifdef hqm
        freopen(file".inp", "r", stdin); freopen(file".out", "w", stdout);
    #endif

    cin >> n;

    forf (i, 1, n){
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }

    dfs(1, 1);

    cout << res * 2;

    return 0;
}
/*



*/

