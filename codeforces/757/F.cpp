#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//#include<boost/algorithm/string.hpp>

//pragmas
#pragma GCC optimize("O3")

//types
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ull unsigned long long int
#define vec vector<long long int>
#define pall pair<long long int, long long int>
#define vecpair vector<pair<long long int,long long int>>
#define vecvec(a, i, j) vector<vector<long long int>> a (i, vec (j, 0))
#define vecvecvec(a, i, j, k) vector<vector<vector<long long int>>> dp (i + 1, vector<vector<long long int>>(j + 1, vector<long long int>(k + 1, 0)))


using namespace std;
using namespace __gnu_pbds;

//random stuff
#define all(a) a.begin(),a.end()
#define read(a) for (auto &x : a) cin >> x
#define endl "\n"
#define pb push_back
#define sz(x) (long long int)x.size()
#define print(a) for(auto x : a) cout << x << " "; cout << endl
#define sp " " 
ll INF = 9223372036854775807;
typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};
#define safe_map unordered_map<long long, int, custom_hash>


//debug
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#define reach cerr<<"reached"<<endl
#else
#define debug(x...)
#define reach 
#endif


/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
void swap(int &x, int &y) {int temp = x; x = y; y = temp;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (ll i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (ll j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m = 1000000007) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m = 1000000007) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m = 1000000007) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m = 1000000007) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
void precision(int a) {cout << setprecision(a) << fixed;}
ll ceil_div(ll x, ll y){return (x + y - 1) / y;}
unsigned long long power(unsigned long long x,ll y, ll p){unsigned long long res = 1;x = x % p; while (y > 0){if (y & 1)res = (res * x) % p;y = y >> 1;x = (x * x) % p;}return res;}
unsigned long long modInverse(unsigned long long n,int p){return power(n, p - 2, p);}
ll nCr(ll n,ll r, ll p){if (n < r)return 0;if (r == 0)return 1;unsigned long long fac[n + 1];fac[0] = 1;for (int i = 1; i <= n; i++)fac[i] = (fac[i - 1] * i) % p;return (fac[n] * modInverse(fac[r], p) % p* modInverse(fac[n - r], p) % p)% p;}
ll accumulate(const vec &nums){ll sum = 0; for(auto x : nums) sum += x; return sum;}
ll tmax(ll a, ll b, ll c = 0, ll d = -INF, ll e = -INF, ll f = -INF){return max(a, max(b, max(c, max(d, max(e, f)))));}
int log2_floor(unsigned long long i) {return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;}
string bin(ll n){return bitset<32>(n).to_string();}
/*--------------------------------------------------------------------------------------------------------------------------*/

const ll MAXN = 2 * 1e5 + 1;

int dep[MAXN],par[19][MAXN],sz[MAXN];
int LCA(int u,int v)
{
    if(dep[u] < dep[v]) swap(u, v);
    for(int i = 18; i >= 0; i--)
        if(dep[u] - (1 << i) >= dep[v])	u = par[i][u];
    if(u == v)	return u;
    for(int i = 18; i >= 0; i--)
	{
        if(par[i][u] != par[i][v])
		{
            u = par[i][u];
            v = par[i][v];
        }
    }
    return par[0][u];
}



ll sad = 0;
vec mark(MAXN, 0), order, dis(MAXN, INF), dp(MAXN, 0), put(MAXN), closer(MAXN, INF), rg[MAXN], fg[MAXN], fin[MAXN];				
vecpair adj[MAXN];			//adj[u][i] = {ui, wi}

//code starts
int main()
{
	fastio();
	ll n, m, s;
	cin >> n >> m >> s;
	for(ll i = 0, u, v, w; i < m; i ++)	cin >> u >> v >> w, adj[u].pb({v, w}), adj[v].pb({u, w});
	set<pall> dij;
	for(ll i = 1; i <= n; i ++)
		if(i != s)
			dij.insert({INF, i});
	dis[s] = 0;
	dij.insert({dis[s], s});
	
	while(!dij.empty())
	{
		pall at = *dij.begin();
		dij.erase(dij.begin());
		ll u = at.second;
		mark[u] = 1;
		order.push_back(u);
		for(auto v : adj[u])
		{
			if(!mark[v.first])
			{
				if(dis[v.first] >= dis[u] + v.second)
				{
					dij.erase({dis[v.first], v.first});
					dij.insert({dis[u] + v.second, v.first});
					if(dis[v.first] > dis[u] + v.second)	rg[v.first].clear();
					rg[v.first].pb(u);
					dis[v.first] = dis[u] + v.second;
				}
			}
		}
	}
	par[0][s]=0;
    dep[s]=1;
    for(int i = 1; i < order.size(); i++)
	{
        int p = 0, v = order[i];
        for(auto x : adj[v])
		{
            if(dis[x.first] + x.second == dis[v])
			{
                if(!p)	p = x.first;
                else	p = LCA(p, x.first);
            }
        }
        par[0][v] = p;
        dep[v] = dep[p] + 1;
        for(int j = 1; j < 19; j++)
            par[j][v] = par[j - 1][par[j - 1][v]];
    }

	for(ll v = 1; v <= n; v ++)					//construct forward graph from reverse graph
		for(auto u : rg[v])
			fg[u].pb(v);
	mark.assign(MAXN, 0);


	// remember in a dom tree, a vertice is attached to the (lca of all its parent nodes in the original DAG)
	function<void(ll)> dfs = [&](ll u)
	{
		mark[u] = 1;
		for(auto v : fg[u])
		{
			if(mark[v] == 0)
			{
				if(!put[v])
				{
					put[v] = 1;
					ll mind = u;
					for(auto w : rg[v])
						mind = LCA(mind, w);
					fin[mind].pb(v);
				}
				dfs(v);
			}
		}
	};
	dfs(s);

	
	function<void(ll)> dfs2 = [&](ll u)
	{
		dp[u] = 0;
		for(auto v : fin[u])
			dfs2(v), dp[u] += dp[v];
		dp[u] ++;
	};
	dfs2(s);
	for(auto v : fin[s]) sad = max(sad, dp[v]);
	cout << sad << endl;
}






// There is an idea of a Patrick Bateman. Some kind of abstraction.
// But there is no real me. Only an entity. Something illusory. 
// And though I can hide my cold gaze, and you can shake my hand and
// feel flesh gripping yours, and maybe you can even sense our lifestyles
// are probably comparable, I simply am not there.