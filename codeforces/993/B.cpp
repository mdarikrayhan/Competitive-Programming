#include<bits/stdc++.h>


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>



using namespace std;
using namespace __gnu_pbds;


// #pragma GCC optimize("O1")
// #pragma GCC optimize("O2")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")


/*----------------------------------------PBDS-----------------------------------------*/
//order_of_key (k) : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero)//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//template<typename T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//template<typename T> using indexed_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
/*-------------------------------------------------------------------------------------
*/
/*----------------------------------------MACROS---------------------------------------*/
#define fs                      first
#define se                      second
#define ll                      long long int
#define pb                      push_back
#define ppb                     pop_back
#define nl                      (string)"\n"
#define sz(x)                   (int)x.size()
#define all(x)                  x.begin(), x.end()
#define rall(x)                 x.rbegin(), x.rend()
#define prec(n)                 fixed<<setprecision(n)
#define fra(i, x)               for (auto &i : x)
#define fr(i, x, y)             for (int i = (int)x; i < (int)y; ++i)
#define fr1(i, x, y)            for (int i = (int)x; i <= (int)y; ++i)
#define frr(i, x, y)            for (int i = (int)x; i >= (int)y; --i)

typedef pair<ll, ll>            pll;
typedef pair<int, int>          pii;
typedef vector<ll>              vl;
typedef vector<int>             vi;
typedef vector<vi>              vvi;
typedef vector<vl>              vvl;
typedef vector<pii>             vpi;
typedef vector<pll>             vpl;
typedef vector<bool>            vb;
typedef vector<string>          vs;
/*-------------------------------------------------------------------------------------*/

/*--------------------------------------DEGUG------------------------------------------*/
#ifndef ONLINE_JUDGE
#define debug(x...) cout << #x<<" = "; wrt(x); wrt();
#define ____divider____ cout << "-------output-------\n"
#else
#define debug(x...)
#define ____divider____
#endif
/*-------------------------------------------------------------------------------------*/

/*---------------------------------------I/O-------------------------------------------*/
void read() { return; }
void wrt() { cout << nl; }
//void wrt(ll t) {cout << t ;}
//void wrt(int t) {cout << t ;}
void wrt(char t) {cout << t ;}
void wrt(string t) {cout << t ;}
void wrt(double t) {cout << t ;}
template <class T> void wrt(set <T> v);
template <class T> void wrt(vector <T> v);
template <class T> void wrt(multiset <T> v);
template <class T, class V> void wrt(map <T, V> v);
template <class T, class V> void wrt(pair <T, V> p);
template <size_t T> void wrt(const char (&a)[T]) { string s=a; wrt(s); wrt(); }
template <class T> void wrt(set <T> v) { for (T i : v) {wrt(i); wrt(' ');} wrt(); }
template <class T> void wrt(vector <T> v) { for (T i : v) {wrt(i); wrt(' ');} wrt(); }
template <class T> void wrt(multiset <T> v) { for (T i : v) {wrt(i); wrt(' ');} wrt(); }
template <class T, class V> void wrt(map <T, V> v){for(auto i:v){wrt(i);wrt(' ');}wrt();}
template <class T, class V> void wrt(pair <T, V> p){wrt(p.fs); wrt(' ');wrt(p.se);wrt();}
template <class T, class... V> void wrt(T x, V... args){(wrt(x), wrt(' '),wrt(args...));}
template <class T, class... V> void read(T &x, V &...args) { ((cin >> x),read(args...));}
template <class T> void readArr(T &arr, int x, int y) { fr(i, x, y) cin >> arr[i]; }
template <class T> void wrtArr(T &arr, int x, int y){fr(i, x, y)cout<<arr[i]<<' ';wrt();}
/*-------------------------------------------------------------------------------------*/

/*----------------------------------------CONST----------------------------------------*/
//int MOD = 0;
const int N = 2e5;
const int INF = 1e9;
const ll neg = -100000000000;
// const ll INF = 2e15;
const ll MOD = 998244353;
const ll m =  998244353;
//const int MOD = 1e9+7;
const double PI = 3.14159265358979312;
const int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};     // {x, y}
/*-------------------------------------------------------------------------------------*/

/*----------------------------------------FUNCT----------------------------------------*/
template<class T> ll _sum(vector<T>& arr) { return accumulate(all(arr), 0ll); }
template<class T> bool _min(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool _max(T &a, T b) { return a < b ? (a = b, true) : false; }
template<class T> T _bits(T x) { T cnt = 0; while(x>0) { cnt++; x>>=1; } return cnt; }
template<class T> T _setbits(T x) { T cnt = 0; while(x>0) { if(x&1) cnt++; x>>=1; } return cnt;}
template<class T> T _ceil(T a, T b) { return (a+b-1)/b; }
template<class T> T _gcd(T a, T b) { return (b == 0) ? (a) : (_gcd(b, a %= b)); }
template<class T> T _lcm(T a, T b) { if (a < b) swap(a, b); return a / _gcd(a, b) * b; }
template<class T> T _add(T x, T y) { x %= MOD; y %= MOD; return (x + y) % MOD; }
template<class T> T _sub(T x, T y) { x %= MOD; y %= MOD; return (x - y + MOD) % MOD; }
template<class T> T _mul(T x, T y) { x %= MOD; y %= MOD; return (x * 1ll * y) % MOD; }
template<class T> T _pow(T x, T y) { if (y == 0) return 1; T _tmp=_pow(x, y / 2); _tmp = _mul(_tmp, _tmp); return (y&1 ? _mul(x, _tmp) : _tmp); }
template<class T> T _inv(T p) { return _pow(p, MOD - 2); }
template<class T> T _div(T x, T y) { x %= MOD, y %= MOD; return _mul(x, _inv(y)); }
template<class T> T _nCr(T n, T r, vector<T> & fact){ return _mul(fact[n], _inv(_mul(fact[r], fact[n - r])));}
/*--------------------------------DSU Algo-----------------------------------------------*/

// C++ implementation of disjoint set

#include <bits/stdc++.h>
using namespace std;

// class DisjSet {
// 	ll *rank, *parent, *count, n;

// public:
// 	DisjSet(ll n)
// 	{
// 		rank = new ll[n];
// 		parent = new ll[n];
// 		count = new ll[n];
// 		this->n = n;
// 		makeSet();
// 	}
// 	void makeSet()
// 	{
// 		for (ll i = 0; i < n; i++) {
// 			parent[i] = i;
// 		}
// 	}
	
// 	ll count(ll x) {
// 	    ll ct=0;
// 	    for(i,0,n) {if(parent[i]==x) ct++;};
// 	    return ct;
// 	}
	
// 	ll find(ll x)
// 	{
// 		if (parent[x] != x) {
// 			parent[x] = find(parent[x]);
// 		}
// 		return parent[x];
// 	}

// 	void Union(ll x, ll y)
// 	{
// 		ll xset = find(x);
// 		ll yset = find(y);
// 		if (xset == yset)
// 			return;
// 		if (rank[xset] < rank[yset]) {
// 			parent[xset] = yset;
// 		}
// 		else if (rank[xset] > rank[yset]) {
// 			parent[yset] = xset;
// 		}
// 		else {
// 			parent[yset] = xset;
// 			rank[xset] = rank[xset] + 1;
// 		}
// 	}
// };

/*---------------------------------------------------------------------------------------*/
ll fast_pow(ll b, ll e){
	ll res = 1;
	while(e > 0){
		if(e % 2 == 1){
			res = res * b % MOD;
		}
		b = b * b % MOD;
		e /= 2;
	}
	return res;
}

ll fact(ll n,ll m) {
    ll p = 1;
    while(n) {
        p = (p*n)%m;
        n--;
    }
    return p;
}

ll gcdExtended(ll a, ll b, ll *x, ll *y);
 
ll modInverse(ll b, ll m)
{
    ll x, y; 
    ll g = gcdExtended(b, m, &x, &y);
 
    if (g != 1)
        return -1;
 
    return (x%m + m) % m;
}
 
ll modDivide(ll a, ll b, ll m)
{
    a = a % m;
    ll inv = modInverse(b, m);
    return (inv * a) % m;
}
 
ll gcdExtended(ll a, ll b, ll *x, ll *y)
{
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
 
    ll x1, y1; 
    ll gcd = gcdExtended(b%a, a, &x1, &y1);
    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
}

ll count_bits(ll num){
    ll a=0;
    while(num>0) {
     //   cout<<num<<endl;
        if((1&num) == 1) {a++;}
        num=num>>1;
    }
    return a;
}

ll cout_dig(ll num) {
    ll ct = 0;
    while(num > 0) {
        ct++;
        num /= 10;
    }
    ct--;
    return ct;
}


/*----------------------------------------MAIN-CODE------------------------------------*/

/*----------------------------------------STANDARD-SEGEMNT-TREE------------------------------------*/

void build(vector<ll> &t,vector<ll> &a, ll v, ll tl, ll tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        ll tm = (tl + tr) / 2;
        build(t,a, v*2, tl, tm);
        build(t,a, v*2+1, tm+1, tr);
        t[v] = min(t[v*2], t[v*2+1]);
    }
}

ll minn(vector<ll> &t,ll v, ll tl, ll tr, ll l, ll r) {
    if (l > r) 
        return 1e9;
    if (l == tl && r == tr) {
        return t[v];
    }
    ll tm = (tl + tr) / 2;
    return min(minn(t,v*2, tl, tm, l, min(r, tm))
          ,minn(t,v*2+1, tm+1, tr, max(l, tm+1), r));
}

void build1(vector<ll> &t,vector<ll> &a, ll v, ll tl, ll tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        ll tm = (tl + tr) / 2;
        build1(t,a, v*2, tl, tm);
        build1(t,a, v*2+1, tm+1, tr);
        t[v] = max(t[v*2], t[v*2+1]);
    }
}

ll maxx(vector<ll> &t,ll v, ll tl, ll tr, ll l, ll r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    ll tm = (tl + tr) / 2;
    return max(maxx(t,v*2, tl, tm, l, min(r, tm))
          ,maxx(t,v*2+1, tm+1, tr, max(l, tm+1), r));
}

void update(vector<ll> &t,ll v, ll tl, ll tr, ll pos, ll new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        ll tm = (tl + tr) / 2;
        if (pos <= tm)
            update(t,v*2, tl, tm, pos, new_val);
        else
            update(t,v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}

/*---------------------------------------------------------------------------------------------*/

/*----------------------------------------LAZY-SEGMENT-TREE------------------------------------*/

// void build(vector<int> &t,vector<int> &a, int v, int tl, int tr) {
//     if (tl == tr) {
//         t[v] = a[tl];
//     } else {
//         int tm = (tl + tr) / 2;
//         build(t,a, v*2, tl, tm);
//         build(t,a, v*2+1, tm+1, tr);
//         t[v] = t[v*2] + t[v*2+1];
//     }
// }

// void push(vector<int> &t,vector<int> &marked,int v) {
//     if (marked[v]) {
//         t[v*2] = t[v*2+1] = t[v]/2;
//         marked[v*2] = marked[v*2+1] = 1;
//         marked[v] = 0;
//     }
// }

// void update(vector<int> &t,vector<int> &marked,int v, int tl, int tr, int l, int r, int new_val) {
//     if (l > r) 
//         return;
//     if (l == tl && tr == r) {
//         t[v] = (r-l+1)*new_val;
//         marked[v] = 1;
//     } else {
//         push(t,marked,v);
//         int tm = (tl + tr) / 2;
//         update(t,marked,v*2, tl, tm, l, min(r, tm), new_val);
//         update(t,marked,v*2+1, tm+1, tr, max(l, tm+1), r, new_val);
//         t[v] = t[v*2] + t[v*2+1];
//     }
// }


// int sum(vector<int> &t,vector<int> &marked,int v, int tl, int tr, int l, int r) {
//     if (l > r) 
//         return 0;
//     if(marked[v]==1) return ((t[v] > 0)?(r-l+1):0);    
//     if (l == tl && r == tr) {
//         return t[v];
//     }
//     int tm = (tl + tr) / 2;
//     return sum(t,marked,v*2, tl, tm, l, min(r, tm))
//           + sum(t,marked,v*2+1, tm+1, tr, max(l, tm+1), r);
// }

// int checkEquality(vector<int> &t, vector<int> &base,vector<int> &marked,int v,int tl, int tr) {
//     if(tl==tr) {
//         if(t[v]==base[v]) return 1;
//         else return 0;
//     }
    
//     if(marked[v]==1) {
//         if(t[v]==base[v]) return 1;
//         else return 0;
//     }
    
//     int mid = (tl+tr)/2;
//     int r = (checkEquality(t,base,marked,v*2,tl, mid) && checkEquality(t,base,marked,v*2+1,mid+1, tr));
//     return r;
    
// }

ll get_max(ll a, ll b) {
    if(a > b) return a;
    return b;
}
ll get_min(ll a, ll b) {
    if(a < b) return a;
    return b;
}



long double maxx(long double a,long double b) {
    if(a>b) return a;
    else return b;
}

long double minn(long double a,long double b) {
    if(a<b) return a;
    else return b;
}


bool sortby_2nd(const vector<ll>& v1, const vector<ll>& v2)
{
    return v1[1] < v2[1];
}




/*-----------------------------------------------------------------------------------------*/


ll find(vl &parents,ll node) {
    if(parents[node]==node) return parents[node];
    
    parents[node] = find(parents,parents[node]);
    
    return parents[node];
}


int64_t calculate(int64_t p, 
					int64_t q) 
{ 
	int64_t mod = 1000000007, expo; 
	expo = mod - 2; 

	// Loop to find the value 
	// until the expo is not zero 
	while (expo) { 

		// Multiply p with q 
		// if expo is odd 
		if (expo & 1) { 
			p = (p * q) % mod; 
		} 
		q = (q * q) % mod; 

		// Reduce the value of 
		// expo by 2 
		expo >>= 1; 
	} 
	return p; 
}

// void manacher(string s) {
//     ll n=s.size();
//     string new_s = "";
//     fr(i,0,n-1) {
//         new_s+=s[i];new_s+='#';
//     }
//     new_s+=s[n-1];
//     s=new_s;
//     ll nn=s.size();
    
//     ll i=0,j=0,c=0;
    
//     fr(i,0,nn) {
//         ll ct=0;
//         while()
//     }
// }


// ll solve(vl &num,ll p) {
//     ll n = num.size();
//     ll ct_nz=0;
//     ll last=0;
//     ll r=0;
//     fr(i,0,n) {
       
//         last *= 10;
//         last += num[i];
//         r += (9-num[i])*vals[n-1-i][3-ct_nz-1];
//         if(num[i]>0) ct_nz++;
//         if(ct_nz==3) {r++;break;}
//     }
    
//     return r;
// }

// ll solve1(vl &num,ll p) {
//     ll n = num.size();
//     ll ct_nz=0;
//     ll last=0;
//     ll r=0;
//     fr(i,0,n) {
       
//         last *= 10;
//         last += num[i];
//         r += max(num[i]-1,0)*vals[n-1-i][3-ct_nz-1];
//         if(num[i]>0) ct_nz++;
//         r += vals[n-1-i][3-ct_nz];
//         if(ct_nz==3) break;
//     }
    
//     return r;
// }





//const int N = 2e5;

const int nn = 2750131;
bool prime[nn+1];
int minP[nn+1];

typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


int main(){
    cin.tie(0)->sync_with_stdio(0);
    // ios_base::sync_with_stdio(0);
    // cin.tie(0), cout.tie(0);
    // ____divider____;
    
    // vl pr(2e6+1,0);
    // memset(prime, true, sizeof(prime));
    // memset(minP, 0, sizeof(minP));
    // prime[1] = false;
    // for (int p = 2; p * p <= nn; p++) {
        
    //     if (prime[p] == true) {
    //         minP[p]=p;
    //         for (int i = p * p; i <= nn; i += p){
    //             prime[i] = false;
    //             pr[i]++;
    //             if(minP[i]==0) minP[i]=p;
    //         }    
    //     }
    // }
    
    // vl prime_list;
    // fr(i,2,nn+1) {
    //     if(prime[i]) prime_list.pb(i);
    // }
    
    
    ll n,m;
    cin>>n>>m;
    
    vvl p1,p2;
    fr(i,0,n) {
        ll a,b;cin>>a>>b;
        vl pa = {a,b};sort(pa.begin(),pa.end());
        p1.pb(pa);
    }
    
    fr(i,0,m) {
        ll a,b;cin>>a>>b;
        vl pa = {a,b};sort(pa.begin(),pa.end());
        p2.pb(pa);
    }
    
    set<ll> st;
    fr(i,0,n) {
        fr(j,0,m) {
            set<ll> s;s.insert(p1[i][0]);s.insert(p1[i][1]);s.insert(p2[j][0]);s.insert(p2[j][1]);
            vl v;v.pb(p1[i][0]);v.pb(p1[i][1]);v.pb(p2[j][0]);v.pb(p2[j][1]);
            sort(v.begin(),v.end());
            if(s.size()==3) {
                if(v[0]==v[1]) st.insert(v[1]);
                else if(v[1]==v[2]) st.insert(v[2]);
                else st.insert(v[3]);
            } 
        }
    }
    
    if(st.size()==1) {
        cout<<(*st.begin())<<endl;
    } else {
        ll f1=0;
        ll f2=0;
        fr(i,0,n) {
            if(st.find(p1[i][0])!=st.end() && st.find(p1[i][1])!=st.end()) f1=1;
        }
        fr(i,0,m) {
            if(st.find(p2[i][0])!=st.end() && st.find(p2[i][1])!=st.end()) f2=1;
        }
        if(f1==0 && f2==0) cout<<0<<endl;
        else {
            ll ff1=0;
            ll ff2=0;
            if(f1==1) {
            fr(i,0,n) {
                if(st.find(p1[i][0])!=st.end() && st.find(p1[i][1])!=st.end()) {
                    ll ct=0;
                    fr(j,0,m) {
                        if(p2[j][0]==p1[i][0] && p2[j][1]==p1[i][1]) continue;
                        if(p2[j][0]==p1[i][0] || p2[j][1]==p1[i][1] || p2[j][1]==p1[i][0] || p2[j][0]==p1[i][1]) ct++;
                    }
                    if(ct>1) ff1=1;
                  //  cout<<ct<<endl;
                }
            }
            
        } 
        if(f2==1) {
            
            fr(i,0,m) {
                if(st.find(p2[i][0])!=st.end() && st.find(p2[i][1])!=st.end()) {
                    ll ct=0;
                    fr(j,0,n) {
                        if(p1[j][0]==p2[i][0] && p1[j][1]==p2[i][1]) continue;
                        if(p1[j][0]==p2[i][0] || p1[j][1]==p2[i][1] || p1[j][1]==p2[i][0] || p1[j][0]==p2[i][1]) ct++;
                    }
                    if(ct>1) ff2=1;
                }
            }
            
            
        }
        
        if(ff1==1 || ff2==1) cout<<-1<<endl;
        else cout<<0<<endl;
        }
    }
 
     
}