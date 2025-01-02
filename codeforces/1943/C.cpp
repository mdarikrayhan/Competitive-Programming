#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define PB push_back
#define FS first
#define SD second
#define ary(k) array<int,k>
template<class A,class B> void cmx(A& x, B y) {x=max<A>(x,y);}
template<class A,class B> void cmn(A& x, B y) {x=min<A>(x,y);}
typedef pair<int, int> pii;
typedef vector<int> vi;
void solve(){
    int n; cin >> n;
    vector<vi> adj(n);
    rep(i,1,n){
        int x,y; cin >> x >> y;
        x--; y--;
        adj[x].PB(y); adj[y].PB(x);
    }
    vi par(n);
    int mxd = -1, mxu = 0;
        auto dfs = [&](auto&& dfs, int u, int p, int d)->void{
        par[u] = p;
        if(d > mxd){
            mxd = d;
            mxu = u;
        }
        for(int v : adj[u]) if(v != p){
            dfs(dfs,v,u,d+1);
        }
    };
    dfs(dfs,0,-1,0);
    int d0 = mxu;
    mxd = -1;
    dfs(dfs,d0,-1,0);
    int d1 = mxu;
    vi path;
    for(int u = d1; ; u = par[u]){
        path.PB(u);
        if(u == d0) break;
    }
    if(mxd % 4 == 3){
        // 3 : 2
        cout << (mxd+1)/2 << "\n";
        int u = path[sz(path)/2],v = path[sz(path)/2-1];
        for(int i = 1; i <= (mxd+1)/2; i += 2){
            cout << u+1 << " " << i << "\n"; 
            cout << v+1 << " " << i << "\n"; 
        } 
    } else{
        cout << (mxd+1)/2 + 1 << "\n";
        int u = path[sz(path)/2];
        for(int i = 0; i <= (mxd+1)/2; i++){
            cout << u+1 << " " << i << "\n";
        }
    }
}
signed main() {
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(cin.failbit);
    int t; cin >> t; while(t--) solve();
}