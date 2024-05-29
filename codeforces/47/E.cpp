/*************Hello!!! Stay hydrated!!!*************/
#include "bits/stdc++.h"
using namespace std; 
#define             ld  long double
#define             ll  long long 
#define             db  double 
#define             ve  vector 
#define             vi  vector<int>
#define            vll  vector<ll>
#define            str  string
#define             pb  push_back
#define             pk  pop_back
#define             el  '\n'
#define            pii  pair<int,int>
#define             mp  make_pair 
#define             fi  first 
#define             se  second
#define         uni(a)  sort(all(a)),a.resize(unique(all(a))-a.begin()) 
#define     fod(i,a,b)  for(int i=(int)(a);i<=(int)(b);i++)
#define    fok(i,a,b)  for(int i=(int)(a);i>=(int)(b);i--)
#define         all(a)  a.begin(),a.end()  
#define             LB  lower_bound
#define             UB  upper_bound 
#define     BIT(msk,i)  (msk>>(i)&1ll)
#define        mask(i)  (1ll<<(i))
#define          SZ(_)  (int)(_.size())
#define           btpc  __builtin_popcountll
#define            ctz  __builtin_ctzll 
ll lg(ll a){return __lg(a);}
ld sq(ld a){return (ld)a*a;}  
ll gcd(ll a,ll b){return __gcd(a,b);} 
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll rd(ll l , ll r ){return l+1LL*rand()*rand()%(r-l+1);}
#define DEBUG(x) cerr << #x << " = " << x << el;
struct edge{int u, v, c;};
const ll MOD = 1e9 + 7;
inline void kill(){cerr << "\nTime: " << 1.0 * clock() / CLOCKS_PER_SEC << "s\n"; cerr << " [ .... EtnallirB AnuL ...].\n"; exit(0);}
inline ll bpow(ll x, ll y, ll mod = MOD) { ll ans = 1; while (y) { if (y & 1ll) ans = (ans % mod * x % mod + mod) % mod; x = (x % mod * x % mod + mod) % mod; y >>= 1;} return ans;}
inline ll bp(ll a, ll b){ll res = 1; while (b > 0) {if (b & 1ll) res = res * a; a = a * a; b >>= 1ll; } return res;}
inline ll Inv(ll x, int mod = MOD) { return bpow(x, mod - 2, mod);}
template<class T> bool mini(T& a,T b){return (a>(b))?a=b,1:0;}
template<class T> bool maxi(T& a,T b){return (a<(b))?a=b,1:0;}

/***********Template ends here***********/

#define name ""
const ll base = mask(20) + 5, INF = 2e18, inf = 1e9, multitest = 0;
const ld PI = acos(-1) , EPS = 1e-9;
#define g 9.8
void precalc(){}
int n, m, V;
ld x[base], y[base];
struct Ball{
	int id;
	ld alpha;
	bool operator< (const Ball& other)const{
		return alpha < other.alpha;
	}
}a[base];
void inp(){
	cin >> n >> V;
	fod(i,1,n){
		cin >> a[i].alpha;
		a[i].id = i;
	}
}
 
namespace sub1{
	void init(){
		fod(i,1,n){
			x[i] = V * V * sin(2 * a[i].alpha)/g;
			y[i] = 0;
		}
		sort(a + 1, a + n + 1);
	}
	ld getY(ld x, ld alpha){
		return sin(alpha) * x/cos(alpha)  - g * x * x / (2 * cos(alpha) * cos(alpha) * V * V);
	}
    void solve(){
    	init();
    	map <ld,ld> Data;
    	cin >> m;
    	fod(i,1,m){
    		ld X, Y; cin >> X >> Y;
    		maxi(Data[X], Y);
    	}
    	int i = 1;
    	ld limit = V * V / g;
    	for(auto [X, Y] : Data){
    		if(X > limit) break;
    		while(i <= n ){
    			ld gY = getY(X, a[i].alpha);
    			if(gY > Y) break;
    			if(gY >= 0){
    				x[a[i].id] = X;
	    			y[a[i].id] = gY;
    			}	
    			i++;	
    		}
    	}
    	
    	fod(i,1,n){
    		cout << fixed << setprecision(6) << x[i] << " " << y[i] << el;		
    	} 
    }	
}
namespace sub2{
	void init(){}
	
	void solve(){
		init();
	}
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); srand(time(0)); 
    if(fopen(name".inp", "r")){
      freopen(name".inp", "r", stdin);
      freopen(name".out", "w", stdout);
    }
    int Test = 1; if(multitest) cin >> Test;
    precalc();
    while(Test--){
        inp();
        sub1 :: solve();
        sub2 :: solve();
    }
    kill();
}
//I got nothing to lose anymore