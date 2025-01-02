#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define M 1000000007
#define max_range_of_ll 9223372036854775807
// #define pi 3.141592653
typedef long long int ll;
typedef long double ld;
typedef vector<long long> vll;
typedef pair<long long, long long> pll;
typedef pair<int,int> pii;
typedef vector<pair<long long, long long> > vpl;
typedef vector<int> vii;
typedef vector<vector<long long> > vvl;
typedef vector<vector<pair<long long, long long> > > vvpl;
#define all(v) v.begin(),v.end()
#define sz(v) (ll)v.size()
#define FF(i,a,b) for(ll i=a;i<b;i++)
#define FB(i,a,b) for(ll i=a;i>=b;i--)
#define fix(f,n) std::fixed<<std::setprecision(n)<<f	
#define fi first
#define se second
#define pb push_back
#define popb pop_back
#define usl unordered_set <ll>
#define msl multiset <ll>
#define I(a,n) for(ll i = 0; i < n; i++) cin>>a[i];
#define IN(a,n,m) for(ll i = 0; i < n; i++) for(ll j = 0; j < m; j++) cin>>a[i][j];
#define OU(a,n) for(ll i = 0; i < n; i++) cout<<a[i]<<" ";
#define Io(a,n) for(ll i = 0+1; i < n+1; i++) cin>>a[i];
#define INo(a,n,m) for(ll i = 0+1; i < n+1; i++) for(ll j = 0+1; j < m+1;ll j++) cin>>a[i][j];
#define OUo(a,n) for(ll i = 0+1; i < n+1; i++) cout<<a[i]<<" ";
#define sptr(s,itr) set< ll, greater <ll> > :: iterator itr;
#define msptr(s,itr) multiset< ll, greater <ll> > :: iterator itr;
#define endl '\n'// comment for interactive questions
#define take(v,n) for(ll qwerty=0;qwerty<n;qwerty++){cin>>v[qwerty];}
const ll INF=(ll)1e18;
void __print(int x) {cerr<<x;}
void __print(long x) {cerr<<x;}
void __print(long long x) {cerr<<x;}
void __print(unsigned x) {cerr<<x;}
void __print(unsigned long x) {cerr<<x;}
void __print(unsigned long long x) {cerr<<x;}
void __print(float x) {cerr<<x;}
void __print(double x) {cerr<<x;}
void __print(long double x) {cerr<<x;}
void __print(char x) {cerr<<'\''<<x<<'\'';}
void __print(const char *x) {cerr<<'\"'<<x<<'\"';}
void __print(const string &x) {cerr<<'\"'<<x<<'\"';}
void __print(bool x) {cerr<<(x==1);}
template<typename T,typename V>	void __print(const pair<T,V> &x) {cerr<<'{';__print(x.first);cerr<<',';__print(x.second);cerr<<'}';}
template<typename T>	void __print(const T &x) {int f = 0;cerr<<'{';for(auto &i:x) cerr<<(f++?",":""),__print(i);cerr<<"}";}
void _print() {cerr<<"]\n";}
template <typename T,typename... V>	void _print(T t,V... v) {__print(t);if (sizeof...(v)) cerr<<",";_print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr<<"["<<#x<<"] = ["; _print(x);
#else
#define debug(x...);
#endif
ll temp1,temp,temp2,temp3,temp4=700000005;
#define LIM1 ((ll)1e5+4)
#define LIM2 ((ll)2e5+4)
#define LIM3 ((ll)3e5+4)
#define LIM4 ((ll)1e6+4)

const ld eps=1e-11;
const ll mymod=998244353;

class DisjointSet{ public:
    vector<ll> parent;
    DisjointSet(ll n): parent(n) { for(ll i=0; i<n; i++) parent[i] = i; }
    void join(ll a, ll b) { parent[find(b)] = find(a); }
    ll find(ll a){ return a == parent[a] ? a : parent[a] = find(parent[a]); }
    bool check(ll a, ll b){ return find(a) == find(b); }
};


ll sm(ll a,ll b){
	ll k=a/b;
	a=a-k*b;
	if(a<0){
	    a+=b;
	}
	return a;
}
ll cd(ll a,ll b){
	ll k=a/b;
    if(a>b*k){
        return k+1;
    }
    else{
        return k;
    }
}

ll gd(ll a , ll b)
{
   if(b==0){ return a;}
   else{
       ll k=a/b;
       a=a-b*k;
       return gd(b,a);
    }
}

ll ex(ll a, ll n)
{
    ll ans = 1;
    while(n)
    {
        if(n&1)
            ans = (ans*a)%M;
        a = (a*a)%M;
        n>>=1;
    }
    return ans;
}
vvl v;
ll n;
void f(){
	vector<ll>oo,ee,oe,eo;
	ll ooo=0,eeo=0,eoo=0,oeo=0;
	FF(i,1ll,n+1ll){
		ll o,t;
		o=v[i-1][0];
		t=v[i-1][1];
        if(abs(o)%2==1 && abs(t)%2==1){
        	oo.pb(i);ooo++;
        }
        else if(abs(o)%2==0 && abs(t)%2==0){
        	ee.pb(i);eeo++;
        }
        else if(abs(o)%2==1){
        	oe.pb(i);oeo++;
        }
        else{
        	eo.pb(i);eoo++;
        }
	}
	if(oo.size()+ee.size()!=int(n) && oe.size()+eo.size()!=int(n)){
    	cout<<ooo+eeo<<endl;
    	FF(i,0ll,ooo){
    		cout<<oo[i]<<' ';
    	}
    	FF(i,0ll,eeo){
    		cout<<ee[i]<<' ';
    	}return;
    }
    else if(ooo+eeo==int(n) && ooo*eeo!=0){
    	cout<<ooo<<endl;
    	FF(i,0ll,ooo){
    		cout<<oo[i]<<' ';
    	}return;
    }
    else if(oeo+eoo==int(n) && oeo*eoo!=0){
    	cout<<eoo<<endl;
    	FF(i,0ll,eoo){
    		cout<<eo[i]<<' ';
    	}return;
    }
    ll o,t;
    o=v[0][0],t=v[0][1];
    FF(i,0ll,n){
    	v[i][0]=(v[i][0]-o)/2;
    	v[i][1]=(v[i][1]-t)/2;
    }
    f();
    return ;
}
void solve()
{
//	ll n;
	cin>>n;
	
	
	FF(i,1,n+1){
        ll o,t;
        cin>>o>>t;
        v.pb({o,t});
        
	}
    
    f();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc=1;
	//cin>>tc;
	FF(p,1,tc+1)
	{
		solve();
	}
return 0;}