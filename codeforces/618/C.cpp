#include "bits/stdc++.h"
using namespace std;

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,bmi,bmi2,lzcnt,popcnt,mmx,avx,avx2,tune=native")

// #define for_(i,s,te) for (ll i=s,e=te; ((i<e)and(s<e)) or ((i>e)and(s>=e)); (s<e)?i++:i--)
#define for_(i,s,e) for (int i=s;i<e; i++)
#define for__(i,s,e) for (int i=s;i>e; i--)
#define popcount(x) __builtin_popcount(x)  // count set bits
#define popcountll(x) __builtin_popcountll(x)
#define gcd(x,y) __gcd(x,y)
#define clz(x) __builtin_clz(x)  // count leading zeros
#define clzll(x) __builtin_clzll(x)
#define ctz(x) __builtin_ctz(x)  // count trailing zeros
#define ctzll(x) __builtin_ctzll(x)
#define MSB(x) bit_floor(x)
#define LSB(x) ((x)&(-(x)))
// #define  bit_ceil(x)
#define ispow2(x) has_single_bit(x)
#define sz(a) int(a.size())
#define all(x) (x).begin(),(x).end()
#define allr(x) x.rbegin(),x.rend()
#define sumv(v,b,e) accumulate((v).begin()+b,(v).begin()+e,0LL)
#define minv(v,b,e) min_element((v).begin()+b,(v).begin()+e)
#define maxv(v,b,e) max_element((v).begin()+b,(v).begin()+e)
#define uniq(v) (v).erase(unique(all(v)),(v).end())
#define mid(l,r) midpoint((l),(r))
#define clr(x) memset(x,0,sizeof(x))
#define precise(n) cout<<fixed<<setprecision((n))
#define nl "\n"
#define _ << ' ' <<
#define elif else if
#define pb emplace_back
#define MP make_pair
#define UB upper_bound
#define LB lower_bound
#define ff first
#define ss second

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vpii> vvpii;
typedef vector<vpll> vvpll;
typedef map<int,int> mii;
typedef map<ll,ll> mll;
typedef __int128 int128;
// typedef array<int, 2> ii;
constexpr ll MOD = 1e9+7; // 998244353;

template<typename T> inline ll mod(T a, ll md = MOD) { return ((a%md)+md)%md; }
template<typename Iter> bool is_unique(Iter begin, Iter end) { set<typename iterator_traits<Iter>::value_type> unique_set; for (Iter it = begin; it != end; ++it) if (!unique_set.insert(*it).second) return false; return true; }

template<typename T1,typename T2> inline istream& operator >>(istream& in, pair<T1,T2>& a) { in>>a.ff>>a.ss; return in; }
template<typename T1,typename T2> inline ostream& operator <<(ostream& out, const pair<T1,T2>& a) { out<<a.ff<<" "<<a.ss; return out; }
template<typename T> inline istream& operator >>(istream& in, vector<T>& v) { for_(i,0,sz(v)) in>>v[i]; return in; }
template<typename T> typename enable_if<!is_same<T,char>::value,ostream&>::type operator<<(ostream& out, const vector<T>& v) { for(auto& e:v) out<<e<<" "; return out; }
template<typename T> inline istream& operator >>(istream& in, set<T>& s) { string str; while(!sz(str)) getline(in,str); istringstream iss(str); T vs; while (iss>>vs) s.insert(vs); return in; }
template<typename T> inline ostream& operator <<(ostream& out, const set<T>& s) { for(auto& vs:s) out<<vs<<" "; return out; }
template<typename T> inline istream& operator >>(istream& in, multiset<T>& s) { string str; while(!sz(str)) getline(in,str); istringstream iss(str); T vs; while(iss>>vs) s.insert(vs); return in; }
template<typename T> inline ostream& operator <<(ostream& out, const multiset<T>& s) { for(auto& vs:s) out<<vs<<" "; return out; }
template<typename T1,typename T2> inline pair<T1,T2> operator +(pair<T1,T2>& l,pair<T1,T2>& r) { return {l.ff+r.ff,l.ss+r.ss}; }

template<typename T> inline void g_in(vector<vector<T>>& g, int m, int rev) { T x,y; for_(i,0,m){ cin>>x>>y; g[--x].pb(--y); if(rev) g[y].pb(x); } }
template<typename T1, typename T2> inline void g_in(vector<vector<pair<T1,T2>>>& g, int m, int rev) { T1 x,y; T2 c; for_(i,0,m){ cin>>x>>y>>c; g[--x].pb(--y,c); if(rev) g[y].pb(x,c); } } 

/* modified from https://codeforces.com/blog/entry/125435 by Anshul_Johri */
namespace __DEBUG_UTIL__ {

template <typename T>
concept is_iterable = requires(T &&x) { begin(x); } and !is_same_v<remove_cvref_t<T>, string>;
void _print(const char *x) { cerr << x; }
void _print(char x) { cerr << "'" << x << "'"; }
void _print(bool x) { cerr << (x ? "T" : "F"); }
void _print(string x) { cerr << "\"" << x << "\""; }
void _print(vector<bool> &&v) { /* Overloaded this because stl optimizes vector<bool> by using
 _Bit_reference instead of bool to conserve space. */
  int f = 0;
  cerr << '{';
  for (auto &&i : v)
    cerr << (f++ ? "," : "") << (i ? "T" : "F");
  cerr << "}";
}
template <typename T>
void _print(T &&x) {
  if constexpr (is_iterable<T>)
    if (size(x) and is_iterable<decltype(*(begin(x)))>) { /* Iterable inside Iterable */
      int f = 0;
      cerr << "\n~~~~~\n";
      int w = max(0, (int)log10(size(x) - 1)) + 2;
      for (auto &&i : x) cerr << setw(w) << left << f++, _print(i), cerr << "\n";
      cerr << "~~~~~\n";
    } else { /* Normal Iterable */
      int f = 0;
      cerr << "{";
      for (auto &&i : x) cerr << (f++ ? "," : ""), _print(i);
      cerr << "}";
    }
  else if constexpr (requires { x.pop(); }) { /* Stacks, Priority Queues, Queues */
    auto temp = x;
    int f = 0;
    cerr << "{";
    if constexpr (requires { x.top(); })
      while (!temp.empty())
        cerr << (f++ ? "," : ""), _print(temp.top()), temp.pop();
    else
      while (!temp.empty())
        cerr << (f++ ? "," : ""), _print(temp.front()), temp.pop();
    cerr << "}";
  } else if constexpr (requires { x.first; x.second; }) { /* Pair */
    cerr << '(', _print(x.first), cerr << ',', _print(x.second), cerr << ')';
  } else if constexpr (requires { get<0>(x); }) { /* Tuple */
    int f = 0;
    cerr << '(', apply([&f](auto... args) { ((cerr << (f++ ? "," : ""), _print(args)), ...); }, x);
    cerr << ')';
  } else
    cerr << x;
}
template <typename T, typename... V>
void printer(const char *names, T &&head, V &&...tail) {
  int i = 0;
  for (size_t bracket = 0; names[i] != '\0' and (names[i] != ',' or bracket != 0); i++)
    if (names[i] == '(' or names[i] == '<' or names[i] == '{')
      bracket++;
    else if (names[i] == ')' or names[i] == '>' or names[i] == '}')
      bracket--;
  cerr.write(names, i) << " = ";
  _print(head);
  if constexpr (sizeof...(tail))
    cerr << " | ", printer(names + i + 1, tail...);
  else
    cerr << "\n";
}
template <typename T, typename... V>
void printerArr(const char *names, T arr[], size_t N, V... tail) {
  size_t i = 0;
  for (; names[i] and names[i] != ','; i++)
    cerr << names[i];
  for (i++; names[i] and names[i] != ','; i++)
    ;
  cerr << " = {";
  for (size_t ind = 0; ind < N; ind++)
    cerr << (ind ? "," : ""), _print(arr[ind]);
  cerr << "}";
  if constexpr (sizeof...(tail))
    cerr << " | ", printerArr(names + i + 1, tail...);
  else
    cerr << "\n";
}

}  // namespace __DEBUG_UTIL__

#ifdef LOCAL
#define print(...) std::cerr << __LINE__ << ": ", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#define printArr(...) std::cerr << __LINE__ << ": ", __DEBUG_UTIL__::printerArr(#__VA_ARGS__, __VA_ARGS__)
#else
#define print(...)
#define printArr(...)
#define cerr if(0) cerr
#endif

void solve(){
  int n; cin>>n;
  vector<pair<pll, ll>> a(n);
  
  for_(i,0,n){
    cin>>a[i].ff;
    a[i].ss = i+1;
  }
  
  sort(all(a), [](auto& l, auto& r){
    if (l.ff.ff != r.ff.ff) return l.ff.ff < r.ff.ff;
    return l.ff.ss < r.ff.ss;
  });
  
  for_(i,2,n){
    if ((a[0].ff.ff - a[1].ff.ff) * (a[1].ff.ss - a[i].ff.ss) == (a[1].ff.ff - a[i].ff.ff) * (a[0].ff.ss - a[1].ff.ss)){
      continue;
    }

    cout<<a[0].ss _ a[1].ss _ a[i].ss<<nl;
    return;
  }

  
}

int main(){
#ifdef LOCAL
  auto fret = freopen("/home/sriteja/Competitive Programming/Debugging/IO/output_01.txt","w",stderr);
  if (!fret) { perror("unable to open stderr"); return 1; }
#endif
  ios_base::sync_with_stdio(false); cin.tie(0);

  int tt=1,ttt;
  print(tt);
  ttt = tt;
  // auto start = chrono::steady_clock::now();
  while (tt--) {
    cerr<<"-------------- TC "<<ttt-tt<<" -----------------"<<nl;
    solve();
  };
  cerr<<"-------------- DONE -----------------"<<nl;
  
  string warning_string;
  while (getline(cin,warning_string).eof() == false or warning_string != ""){
    if (warning_string == "") continue;
    cerr<<"\n!!!!!! WARNING : UNREAD INPUT !!!!!!!\n"<<warning_string<<nl;
    while (getline(cin,warning_string)) cerr<<warning_string<<nl;
    break;
  }
  // auto end = chrono::steady_clock::now();
  // cerr << "Elapsed (s): " << chrono::duration_cast<chrono::milliseconds>(end - start).count()/1000.0 << endl;

  return 0;
}