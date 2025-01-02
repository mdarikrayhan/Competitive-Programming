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

signed main() {
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(cin.failbit);
    int t; cin >> t; while(t--){
        int n,m; cin >> n >> m;
        int p,b; cin >> p >> b;
        vector<vi> adj(n);
        vi tok;
        rep(i,0,p){
            int x; cin >> x; x--;
            tok.PB(x);
        }
        vi red(n);
        rep(i,0,b){
            int x; cin >> x; x--;
            red[x] = 1;
        }
        rep(i,0,m){
            int u,v; cin >> u >> v;
            u--; v--;
            adj[u].PB(v); adj[v].PB(u);
        }
        vi dis(n,-1),id(n,-1),cnt;
        rep(i,0,n) if(dis[i] == -1 && (red[i] || !i)){
            queue<int> q; q.push(i);
            dis[i] = 0; int redc = 0;
            while(sz(q)){
                int u = q.front(); q.pop();
                id[u] = sz(cnt);
                redc += red[u];
                for(int v : adj[u]) if(dis[v] == -1 && red[v]){
                    dis[v] = dis[u]+1;
                    q.push(v);
                }
            }
            cnt.PB(redc); 
        }
        int reachb = 0,reachs = 0;
        vi rb,rs;
        for(int x : tok){
            bool can = 0;
            for(int v : adj[x]) if(red[v] && cnt[id[v]] > 1){
                can = 1;
            }
            rb.PB(can);
            reachb += can;
            can = 0;
            for(int v : adj[x]) if(red[v]){
                can = 1;
            }
            reachs += can;
            rs.PB(can);
        }  
        bool good = 0;
        rep(i,0,p){
            int x = tok[i];
            if(id[x] == id[0]){
                if(reachb-rb[i]) good = 1; 
            } else{
                for(int v : adj[x]) if(id[v] == id[0] && reachb-rb[i]){
                    good = 1;
                } 
            }
        }
        rep(i,0,p){
            int x = tok[i];
            if(id[x] == id[0]){
                if(reachs-rs[i]+1 >= dis[x]) good = 1; 
            } else{
                for(int v : adj[x]) if(id[v] == id[0] && reachs-rs[i]+1 >= dis[v]+1){
                    good = 1;
                } 
            }
        }

        cout << (good ? "YES\n" : "NO\n");
    }
}
// treat 1 as red
// find ccs of red nodes
// call cc big if it's at least 2 nodes
// if one tok can reach cc connected to 1
// and either another tok can reach big cc
// or shortest path from tok to 1 is <= 1+number of other toks that can reach small cc
