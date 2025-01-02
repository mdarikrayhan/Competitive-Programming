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
template<class T>
struct RMQ {
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
			jmp.emplace_back(sz(V) - pw * 2 + 1);
			rep(j,0,sz(jmp[k]))
				jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) {
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};
struct LCA {
	int T = 0;
	vi time, path, ret;
	RMQ<int> rmq;

	LCA(vector<vi>& C, int rt) : time(sz(C)), rmq((dfs(C,rt,-1), ret)) {}
	void dfs(vector<vi>& C, int v, int par) {
		time[v] = T++;
		for (int y : C[v]) if (y != par) {
			path.PB(v), ret.PB(time[v]);
			dfs(C, y, v);
		}
	}

	int lca(int a, int b) {
		if (a == b) return a;
		tie(a, b) = minmax(time[a], time[b]);
		return path[rmq.query(a, b)];
	}
	//dist(a,b){return depth[a] + depth[b] - 2*depth[lca(a,b)];}
};
signed main() {
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(cin.failbit);
    int t; cin >> t; while(t--){
        int n,m,q; cin >> n >> m >> q;
        vi par(n+m); iota(all(par),0); 
        auto find = [&](int u){
            while(par[u] != u){
                par[u] = par[par[u]];
                u = par[u];
            }
            return u;
        };
        // make u root
        auto join = [&](int u, int v){
            u = find(u); v = find(v);
            if(u == v) return;
            par[v] = u;
        };
        vector<vi> adj(n+m);
        int rt = 0;
        rep(i,0,m){
            int u,v; cin >> u >> v; u--; v--;
            if(find(u) == find(v)) continue;
            rt = n+i;
            adj[n+i].PB(find(u));
            adj[n+i].PB(find(v));
            join(n+i,find(u));      
            join(n+i,find(v));
        }
        LCA lca(adj,rt); 
        vi times(n),back(n+m);
        rep(i,0,n){
            times[i] = lca.time[i];
            back[times[i]] = i;
            //cout << i << " " << times[i] << "\n";
        }
        RMQ mint(times);
        rep(i,0,n) times[i] *= -1;
        RMQ maxt(times);
        while(q--){
            int l,r; cin >> l >> r;
            l--;
            int u = back[mint.query(l,r)];
            int v = back[-maxt.query(l,r)];
            if(u == v) cout << "0";
            else cout << lca.lca(u,v)-n+1;
            cout << " \n"[q==0];
        }
    }
}
