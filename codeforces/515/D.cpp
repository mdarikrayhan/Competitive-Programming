#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
using namespace __gnu_pbds;
#define F first
#define S second
using ll = long long;
using pii = pair<int,int>;
using pil = pair<int,ll>;
using pli = pair<ll,int>;
using pll = pair<ll,ll>;
#define str string
#define MP make_pair
#define EB emplace_back
#define PB push_back
#define si(x) int(x.size())
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define LB lower_bound
#define UB upper_bound
#define i28 __int128
using ull = unsigned long long;
#define one(X) memset((X), -1, sizeof((X)))
#define zero(X) memset((X), 0, sizeof((X)))
#define ar array
//for loop
#define gnr(i,a,b) for(int i=int(b);i>=int(a);i--)
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rngg(i,a,b) for(int i=int(a);i<=int(b);i++)
#define rep(i,b) rng(i,0,b)
#define repp(i,b) rng(i,1,b+1)

template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;
template<class t> using vvvc = vc<vvc<t>>;

#define vv(type,name,n,...) \
    vector<vector<type>> name(n,vector<type>(__VA_ARGS__))
#define vvv(type,name,n,m,...) \
    vector<vector<vector<type>>> name(n,vector<vector<type>>(m,vector<type>(__VA_ARGS__)))
using vi = vc<int>;
using vl = vc<ll>;

template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

//bit manipulation referenced from maroonrk
template<class T> int topbit(T t){return t==0?-1:63-__builtin_clzll(t);}
template<class T> int botbit(T t){return t==0?64:__builtin_ctzll(t);}
template<class T> int popcount(T t){return __builtin_popcountll(t);}


template<typename T> T gcd(T a,T b){ return b>0 ? gcd(b,a%b):a;}

template<typename T, typename TT> istream& operator >> (istream& i, pair<T,TT> &p){return i >> p.F >> p.S;}
template<typename T, typename TT> ostream& operator << (ostream& o, const pair<T,TT> &p){return o << p.F << ' ' << p.S;}

//cin vc<T>
template<typename T> istream& operator >> (istream& i, vc<T> &v){for(auto &x: v) i >> x; return i;}

//print 管理
template<typename T> void W(vector<vector<T>>& x){for(auto i: x){ for(auto j: i){cout << j << ' ';} cout << "\n";}}
template<typename T> void W(vector<T>& x){for(auto i: x) cout << i << ' ';cout << "\n";}
template<typename T> void W(set<T>& x){for(auto i: x) cout << i << ' ';cout << "\n";}
template<typename T> void W(unordered_set<T>& x){for(auto i: x) cout << i << ' ';cout << "\n";}
template<typename T> void W(T && x) {cout << x << "\n";}
template<typename T, typename... S> void W(T && x, S&&... y) {cout << x << ' ';W(y...);}

template <class t> using mxheap = priority_queue<t>;
template <class t> using mnheap = priority_queue<t,vc<t>,greater<t>>;

template <class T> using ordtree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//custom hash
struct chash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};// gp_hash_table<int,int,chash> 

ll binpow(ll a, ll b, ll MOD){
	ll res = 1;
	while(b){
		if(b & 1) res = (res * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return res;
}




//start here 105
const ll dx[4] = {1,0,-1,0};
const ll dy[4] = {0,1,0,-1};
const ll dx8[8] = {-1,-1,-1,0,0,1,1,1};
const ll dy8[8] = {-1,0,1,-1,1,-1,0,1};
const int MAXN = 1<<20;
const int inf = 1e9;
const ll linf = 1e18;
void bling_bang_bang_bling_bang_bang_bling_bang_bang_born(){
	int n,m;
	cin >> n >> m;
	vv(char, g, n, m);
	cin >> g;
	vv(bool,vis,n,m,0);
	auto check = [&](int x, int y) -> bool{
		return x >= 0 && x < n && y >= 0 && y < m && vis[x][y] == 0;
	};
	vvc<int> deg(n,vi(m));
	rep(i,n) rep(j,m) if(g[i][j] == '*') vis[i][j] = 1;
	rep(i,n) rep(j,m) if(vis[i][j] == 0){
		rep(k,4){
			int x = i + dx[k], y = j + dy[k];
			if(check(x, y)){
				deg[x][y]++;
			}
		}
	}
	/*rep(i,n){
		rep(j,m) cout << deg[i][j] << ' ';
		cout << '\n';
	}*/
	queue<pii> q;
	rep(i,n) rep(j,m){
		if(deg[i][j] == 1){
			q.emplace(i, j);
		}
		
	}
	while(si(q)){
		auto [x, y] = q.front();
		q.pop();
		bool f = 0;
		if(vis[x][y]) continue;
		vis[x][y] = 1;
		rep(i,4){
			int a = x + dx[i], b = y + dy[i];
			if(check(a, b)){
				f = 1;
				vis[a][b] = 1;
				if(x == a){
					g[x][y] = '<', g[a][b] = '>';
					if(y > b) swap(g[x][y], g[a][b]);
				}else{
					g[x][y] = '^', g[a][b] = 'v';
					if(x > a) swap(g[x][y], g[a][b]);
				}
				rep(t, 4){
					int j = a + dx[t], k = b + dy[t];
					if(!check(j, k)) continue;
					deg[j][k]--;
					if(deg[j][k] == 1){
						q.emplace(j, k);
					}
				}
				break;
			}
		}
		if(f == 0){
			W("Not unique");
			return;
		}
	}
	rep(i,n) rep(j,m){
		if(vis[i][j] == 0){
			W("Not unique");
			return;
		}
	}
	rep(i, n){ 
		rep(j ,m) cout << g[i][j];
		cout << '\n';
		
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t = 1;
	
	while(t--){
		bling_bang_bang_bling_bang_bang_bling_bang_bang_born();
	}

}
