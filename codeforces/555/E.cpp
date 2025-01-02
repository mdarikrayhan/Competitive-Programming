// Problem: H. Case of Computer Network
// Contest: Codeforces - SCC + BCC Marathon (Intermediate)
// URL: https://codeforces.com/group/tBfXCBDL6L/contest/523067/problem/H
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2", "popcnt")
using namespace std;
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll , ll> PII ;
typedef vector<bool> vb ;
typedef vector<ll> vi;
typedef vector<PII> vpi;
typedef vector<vector<ll>> vvi;
typedef vector<vector<PII>> vvpi;
typedef vector<char> vc ;
 
const double EBS = 1e-9;
const double pi = 3.14159265358979 ;
 
 
#define Log(x) (31^__builtin_clz(x)) 
#define logll(x) (63^__builtin_clzll(x))

// processor cycle counter can be used to get a random number easily :)
#define rand __builtin_ia32_rdtsc() 

	

#define popcount(i) __builtin_popcount(i)
#define popcountll(i) __builtin_popcountll(i)
 
 
#define mp make_pair

 
#define Time cerr << "Time Taken: " << (float)clock() / CLOCKS_PER_SEC << " Secs"  << "\n";
 
#define testCase ll t; cin >> t; while (t--)
#define fast  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define rep(f, s, i) for (ll i = f; (int) i < s; i++)
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
#define calunique(v)  disance(v.begin(),unique(v.begin(),v.end()));
#define el cout << "\n"
#define mb make_pair
#define pb push_back
#define no cout << "NO\n"
#define yes cout << "YES\n"
#define all(v) v.begin(), v.end()
#define INF (ll) 1e9
#define INFLL (ll)1e18
#define debug cout << "\n___________________________________\n" 
#define int ll

#define Left  ((p << 1) + 1) 
#define Right ((p << 1) + 2)

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const int N = 2e5 + 9 ;
vvpi adj(N) ;
int up[N][20] ;
int depth[N] , dir[2][N];

map< PII , int> cnt , sum1 , sum2 ;
bool ok = true ;

struct dsu{
	vi parent , size; 
	
	void init(int n){
		parent = vi(n + 1);
		size = vi(n + 1 , 1);
		rep(0 , n +1 , i) parent[i] = i ;
	}
	
	
	int find(int node){
		if(node == parent[node]) return node;
		return parent[node] = find(parent[node]);
	}
	
	bool Union(int a , int b){
		a = find(a) , b = find(b);
		if(a == b) return false ; 
		if(size[a] > size[b]) swap(a , b);
		
		parent[a] = b ; 
		size[b] += size[a] ; 
		return true ;
	}
};

struct BCC{
	vvpi adj , bcc_tree ; 
	vi stk , vis , dp , tin , bcc;
	int n , tick , bcc_cnt  ; 
	vpi bridges ;
	dsu ds;
	BCC(int n , vvpi&adj): n(n) , adj(adj){
		bcc_tree = vvpi(n + 1) ;
		vis = vi(n + 1) ; 
		ds.init(n + 1) ;
		dp = vi(n + 1) ;
		tin= vi(n + 1) ;
		bcc= vi(n + 1) ; 
		tick = 0 ;
		bcc_cnt = 0 ;
	}
	void build(){
		for(int node = 1 ; node <= n ; node++){
			if(!vis[node]){
				dfs1(node , node);
				if(!stk.empty()){
					bcc_cnt++;
					while(!stk.empty()){
						int node = stk.back() ; stk.pop_back() ; 
						bcc[node] = bcc_cnt ;
					}
				}
			}
		}
		vis.assign(n + 1 , 0) ;
		for(int node = 1 ; node <= n ; node++){
			if(!vis[node]){
				dfs2(node , node);
			}
		}
		
		vis.assign(n + 1 , 0) ;
		build_lca(1 , 1);
	}
	
	void dfs1(int node , int par){
		vis[node] = true ;
		tin[node] = ++tick ;
		dp [node] = tin[node];
		
		stk.pb(node) ;
		for(auto [nd , idx] : adj[node]){
			if(nd == par) continue ;
			ds.Union(nd , node);
			if(vis[nd]){
				dp[node] = min(dp[node] , tin[nd]) ;
			}else{
				dfs1(nd , node);
				dp[node] = min(dp[node] , dp[nd]);
			}
		}
		if(dp[node] > tin[par]){
			bcc_cnt++;
			bridges.pb(mp(node , par)) ;
			
			while(true){
				int nd = stk.back() ; stk.pop_back() ;
				bcc[nd] = bcc_cnt ; 
				if(nd == node) break;
			}
		}
	}
	void dfs2(int node , int par){
		vis[node] = true ;
		for(auto [nd , idx] : adj[node]){
			if(vis[nd]) continue ;
			if(bcc[nd] != bcc[node]){
				bcc_tree[ bcc[nd] ].pb( mp(bcc[node] , idx) ) ; 
				bcc_tree[ bcc[node] ].pb( mp(bcc[nd] , idx) ) ;
			}
			dfs2(nd , node) ;
		}
	}
	
	void build_lca(int node , int par){
		for(auto [nd , idx] : bcc_tree[node]){
			if(nd != par ){
				depth[nd] = depth[node] + 1 ; 
				up[nd][0] = node ; 
				for(int bit = 1 ; bit < 20 ; bit++){
					up[nd][bit] = up[ up[nd][bit-1] ][bit - 1] ;
				}
				build_lca(nd , node) ;
			}
		}
	}
	int lca(int a , int b){
		if(depth[a] < depth[b]) swap(a , b) ; 
		int k = depth[a] - depth[b] ;
		while(k){
			int bit = Log(k) ; 
			a = up[a][bit] ; 
			k ^= (1 << bit) ;
		}
		if(a == b) return a ; 
		
		for(int bit = 19 ; bit >= 0 ; bit--){
			if(up[a][bit] != up[b][bit]){
				a = up[a][bit] ; 
				b = up[b][bit] ;
			}
		}
		return up[a][0] ;
	}
	void query(int u , int v){
		u = bcc[u] , v = bcc[v] ;
		if(u == v) return ;
		int lc = lca(u , v) ;
		dir[0][u]++;
		dir[0][lc]--;
		
		dir[1][v]++;
		dir[1][lc]--;
	}
	void accum(int node , int par){
		for(auto [nd , idx] : bcc_tree[node]){
			if(nd == par) continue ; 
			accum(nd , node) ;
			sum1[ mp(node , nd) ] = dir[0][nd] ;	
			sum1[ mp(nd , node) ] = dir[0][nd] ;	
			sum2[ mp(node , nd )] = dir[1][nd] ;
			sum2[ mp(nd , node) ] = dir[1][nd] ;
			dir[0][node] += dir[0][nd];
			dir[1][node] += dir[1][nd];
		}
	}
	
	bool check(){
		for(auto [u , v] : bridges){
			PII bridge = mp(u , v) ;
			u = bcc[u] , v = bcc[v] ;
			if(sum1[mp(u , v)] && sum2[mp(u , v)] && cnt[bridge] == 1) return false ;
		}
		
		return true ;
	}
	
};

int32_t main() {
    fast;
    auto begin = std::chrono::high_resolution_clock::now();
    int n , m , q ; cin >> n >> m >> q ; 
    rep(0 , m , i){
    	int u , v ; cin >> u >> v ; 
    	cnt[mp(u , v)]++;
    	cnt[mp(v , u)]++;
    	if(cnt[mp(u , v)] > 1) continue ;
    	adj[u].pb(mp(v , i));
    	adj[v].pb(mp(u , i));
    }
    BCC bcc(n , adj);
    bcc.build();
    while(q--){
    	int u , v ; cin >> u >> v ; 
    	bcc.query(u , v) ;
    	if(bcc.ds.find(u) != bcc.ds.find(v)){
    		no;
    		return 0 ;
    	}
    	
    }
    bcc.accum(1 , 1);
    if(bcc.check())
    	cout << "Yes" ;
    else
    	cout << "No" ;
    
    
	auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr <<fixed <<  "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
	return 0;
 
}
