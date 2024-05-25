#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ordered_set tree<long long, null_type,less<long long>, rb_tree_tag,tree_order_statistics_node_update> 
#define F first
#define S second
#define EB emplace_back
#define int long long
#define sz(v) (int)v.size()
#define MP make_pair
#define all(o) (o).begin(), (o).end()
#define mset(m,v) memset(m,v,sizeof(m))
#define fr(i,n) for(lli i=0;i<n;++i)
#define rep(i,a,b) for(lli i=a;i<=b;++i)
#define per(i,a,b) for(lli i=a;i>=b;i--)
#define remin(a,b) (a=min((a),(b)))
#define remax(a,b) (a=max((a),(b))) 
#define pb push_back
#define endl '\n'
typedef long long lli;        typedef long double ld;
typedef pair<lli,lli> ii;     typedef vector<lli> vi;
typedef vector<ii> vii;       typedef vector<vi> graph;
long double EPS=1e-9;
long long M = 998244353;
#define debarr(a,n) cout<<#a<<" : ";for(int i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<endl;
#define debmat(mat,row,col) cout<<#mat<<" :\n";for(int i=0;i<row;i++) {for(int j=0;j<col;j++) cerr<<mat[i][j]<<" ";cerr<<endl;}
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const unordered_set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const unordered_map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const multiset<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cerr << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class T> void prc(T a, T b) {cerr <<"["; for (T i = a; i != b; ++i) {if (i != a) cerr << ", "; cerr << *i;} cerr << "]\n";}
lli binpow(lli b,lli p){lli ans=1;;for(;p;p>>=1){if(p&1)ans=ans*b;b=b*b;}return ans;}
 
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res *  a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

const int mod = 1e9+7;
const int inf = 1e18;
void pre(){
	
}
const int N = 3e5 + 9, LG = 18;

vector<int> g[N];
int par[N][LG + 1], dep[N], sz[N];

void dfs(int u, int p = 0) {
    par[u][0] = p;
    dep[u] = dep[p] + 1;
    sz[u] = 1;
    for (int i = 1; i <= LG; i++) par[u][i] = par[par[u][i - 1]][i - 1];
    for (auto v: g[u]) if (v != p) {
        dfs(v, u);
        sz[u] += sz[v];
    }
}
int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int k = LG; k >= 0; k--) if (dep[par[u][k]] >= dep[v]) u = par[u][k];
    if (u == v) return u;
    for (int k = LG; k >= 0; k--) if (par[u][k] != par[v][k]) u = par[u][k], v = par[v][k];
    return par[u][0];
}
int kth(int u, int k) {
    assert(k >= 0);
    for (int i = 0; i <= LG; i++) if (k & (1 << i)) u = par[u][i];
    return u;
}
int dist(int u, int v) {
    int l = lca(u, v);
    return dep[u] + dep[v] - (dep[l] << 1);
}
//kth node from u to v, 0th node is u
int go(int u, int v, int k) {
    int l = lca(u, v);
    int d = dep[u] + dep[v] - (dep[l] << 1);
    assert(k <= d);
    if (dep[l] + k <= dep[u]) return kth(u, k);
    k -= dep[u] - dep[l];
    return kth(v, dep[v] - dep[l] - k);
}

int solve(int s,int f,int t){
	int u = lca(f,s);
	int v = lca(t,f);
	
	if(u != v && (u == f || v == f)){
		return 1;
	}else if(u == v && u == f){
		return 1+dist(lca(s,t),f);
	}
	
	if(u != v){
		return 1+dist(f,1)-max(dist(u,1),dist(v,1));
	}else{
		return 1+dist(lca(s,t),f);
	}
}

int n,q;

void solve(){
    
	cin>>n>>q;
	int x;
	rep(i,2,n){
		cin>>x;
		g[x].EB(i);
		g[i].EB(x);
	}
	
	int a,b,c;
	dfs(1);
	fr(i,q){
		cin>>a>>b>>c;
		int ans = 0;
		remax(ans,solve(a,b,c));
		//cout<<ans<<endl;
		remax(ans,solve(c,b,a));
		//cout<<ans<<endl;
		remax(ans,solve(c,a,b));
		//cout<<ans<<endl;
		remax(ans,solve(b,a,c));
		//cout<<ans<<endl;
		remax(ans,solve(a,c,b));
		//cout<<ans<<endl;
		remax(ans,solve(b,c,a));
		//cout<<ans<<endl;
		cout<<ans<<endl;
	}
	
    return;    
}
 
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //freopen("in.txt","r",stdin);//freopen("out.txt","w",stdout);
    lli t = 1;//cin>>t;
    //sieve();
    pre();
 
	for(lli i=1;i<=t;i++){
        //cout<<i<<endl;
        //cout<<"Case #"<<i<<": ";
        solve();
        
    }
}
