/*---Author:kkdrummer---*/
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
//#include <boost/multiprecision/cpp_int.hpp> 
//using namespace boost::multiprecision; 
using namespace __gnu_pbds;
using namespace std;
typedef    long long                     ll;
typedef    double                   ld;
typedef    unordered_set<ll>              usll;
typedef    unordered_multiset<ll>         umsll;
typedef    multiset<ll>                   msll;
typedef    set<ll>                       sll;
typedef    vector<ll>                    vll;
typedef    pair<ll,ll>                   pll;
typedef    vector<pll>                   vpll;
typedef    priority_queue<ll>            pqll;
typedef    vector<int>                   vi;
typedef    set<int>                      si;
typedef    multiset<int>                 msi;
typedef    unordered_multiset<int>       umsi;
typedef    unordered_set<int>            usi;
typedef    pair<int,int>                    pi;
typedef    vector<pi>                     vpi;
typedef    priority_queue<int>            pqi;
template <class T> using ind_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T> using ind_mset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define    in                  insert
#define    fi                  first
#define    se                  second
#define    pb                  push_back
#define    mp                  make_pair
#define    be                  begin
#define    en                  end
#define    itr                 iterator
#define    io                  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define    inf                 8222372026854775807
#define    ninf                  -inf
#define    ima                  2047483647
#define    imi                  -ima
#define    oncnt               __builtin_popcount
#define    zerobegin           __builtin_clz
#define    zeroend            __builtin_ctz
#define    parity              __builtin_parity
#define    eps                 1e-4
#define    coutd               cout<<setprecision(10)<<fixed
#define    mems(dp,x)          memset(dp,x,sizeof(dp))
#define    fbo                 find_by_order
#define    ook                   order_of_key
#define    all(x)              x.be(),x.en()
#define    upb                   upper_bound
#define    lowb                 lower_bound 
#define    lte(v,x)            (upb(all(v),x)-v.be())
#define    gte(v,x)            (v.end()-lowb(all(v),x))
#define    gt(v,x)             (v.en()-upb(all(v),x))
#define    lt(v,x)             (lowb(all(v),x)-v.be())
const      ld PI =             3.1415926535897932384626433832792884197169399375105820974944;
ll    	   mo    =             1000000007;
inline ll mpow(ll x,ll n){if(n==0)return 1;if(x==0)return 0;if(n==1)return(x%mo);ll u=(mpow(x,n/2));u=(u*u)%mo;if(n%2)u=(u*x%mo)%mo;return u;}
inline ll minv(ll x){return mpow(x,mo-2);}
inline ll mmul(ll a,ll b){if(a>=mo)a=a%mo;if(b>=mo)b=b%mo;if(a*b>=mo)return(a*b)%mo;return(a*b);}
inline ll madd(ll a, ll b){if(a>=mo)a=a%mo;if(b>=mo)b=b%mo;if(a+b>=mo)return(a+b)%mo;return(a+b);}
inline ll msub(ll a, ll b){if(a>=mo)a=a%mo;if(b>=mo)b=b%mo;return(((a-b)%mo+mo)%mo);}
inline ll mdiv(ll a,ll bb){if(a>=mo)a=a%mo;ll b=minv(bb);if(b>=mo)b=b%mo;if(a*b>=mo)return(a*b)%mo;return(a*b);}
inline ll gcd(ll a,ll b){return __gcd(a,b);}
inline ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}
int cint(char x){if(x>='0'&&x<='9')return int(x)-48;if(x>='a'&&x<='z')return int(x)-97;else return int(x)-65;}
// printf("%.0Lf",ans); // for printing 10^19 order ld numbers











int main()
{             io 
int testcases=1;           cin>>testcases;
while(testcases--)
{

string a;
cin>>a;

set<char> s;
int c=0;
for(auto x:a){
	s.insert(x);
	if(s.size()==4){
		c++;
		s.clear();
		s.insert(x);	
	}
}

cout<<c+1<<"\n";









































































}return 0;}
