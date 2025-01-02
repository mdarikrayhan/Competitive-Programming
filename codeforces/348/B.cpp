#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<ld, ld>;
using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<ld>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;
using vvi = vector<vi>;

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define nL "\n"

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n; cin >> n;
    vvi adj(n);
    const ll lcminf = 1e9;
    const ll inf = 1e18;
    vl a(n);
    rep(i,0,n) cin >> a[i];
    rep(i, 0, n-1){
        int u, v; cin >> u >> v; u--, v--;
        adj[u].pb(v);adj[v].pb(u);
    }
    // {step size, max}
    auto dfs = [&](int u, int p, auto &&dfs) -> pl{
        vpl c;
        for(int v : adj[u]) if(v != p) {
            c.pb(dfs(v, u, dfs));
        }
        if(sz(c) == 0){
            return {1, a[u]};
        }
        ll l = 1;
        ll mxval = inf;
        for(auto [step, mx] : c){
            l = min(lcminf, l * step / __gcd(l, step));
        }
        for(auto [step, mx] : c){
            mxval = min(mxval, mx / l * l);
        }
        mxval = min(inf, mxval * sz(c));
        l *= sz(c);
        // cout << u << " " << l << "," << mxval << "\n";
        return {l, mxval};
    };
    auto [step, mx] = dfs(0, -1, dfs);
    // cout << step << " " << mx << "\n";
    cout << accumulate(all(a), 0LL) - mx << "\n";

    
    return 0;
}
