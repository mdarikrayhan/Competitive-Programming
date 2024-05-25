#include <bits/stdc++.h>
using namespace std;

// Containers
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int>	    pii;
typedef pair<ll, ll>	    pll;
typedef vector<int>		    vi;
typedef vector<ll>		    vl;
typedef vector<pii>		    vpii;
typedef vector<pll>		    vpll;
typedef vector<vi>		    vvi;
typedef vector<vl>		    vvl;
typedef pair<string,string> pss;
typedef map<int, int>	    mii;

// Miscellanous
#define pb push_back
#define ff first
#define ss second
#define sz(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define sortv(v) sort(all(v))
template <class T>
void clr(T* arr, int size) {memset(arr, 0, size * sizeof(T));}

void pnl() {printf("\n");}
void pyes() {printf("YES\n");}
void pno() {printf("NO\n");}

// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- 
// IO
#define INT(...)   \
  int __VA_ARGS__; \
  inp(__VA_ARGS__)
#define LL(...)   \
  ll __VA_ARGS__; \
  inp(__VA_ARGS__)

void scan(int &a) { scanf("%d",&a); }
void scan(uint &a) { scanf("%u",&a); }
void scan(ll &a) { scanf("%lld",&a); }
void scan(ull &a) { scanf("%llu",&a); }
void scan(char &a) { scanf("%c",&a); }
void scan(double &a) { scanf("%lf",&a); }
void scan(string &a) { cin >> a; }
template <class T , class V>
void scan(pair<T, V> &p) {scan(p.first), scan(p.second);}
template <class T>
void scan(vector<T> &a) {for (auto &&i: a) scan(i);}

void inp() {}
template <class Head, class... Tail>
void inp(Head &head, Tail &... tail) {
  scan(head);
  inp(tail...);
}

void print_(int &a) { printf("%d",a); }
void print_(uint &a) { printf("%u",a); }
void print_(ll &a) { printf("%lld",a); }
void print_(ull &a) { printf("%llu",a); }
void print_(char &a) { printf("%c",a); }
void print_(double &a) { printf("%lf",a); }
void print_(string &a) { cout << a; }

template <class T , class V>
void print_(pair<T, V> &p) {print_(p.first), printf(" "), print_(p.second);}

template <class T>
void print_(vector<T> &a) {for (auto &&i: a) print_(i), printf(" ");}

void out() {}
template <class Head, class... Tail>
void out(Head &&head, Tail &&... tail) {
  print_(head);
  if (sizeof...(Tail)) printf(" ");
  out(forward<Tail>(tail)...);
}

template <class Head, class... Tail>
void outn(Head &&head, Tail &&... tail) {
  out(head , forward<Tail>(tail)...);
  printf("\n");
}

// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- 
// Loops
#define loop(i,s,e) for (int (i)=(s);(i)<(e);++(i))
#define loope(i,s,e) for (int (i)=(s);(i)<=(e);++(i))
#define forc(c,s,e) for (char (c)=(s);(c)<=(e);++(c))
#define rep(i,n) loop(i,0,n)
#define repn(i,n) loope(i,1,n)

// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Debug
void _print(int t) {cerr << t;}
void _print(ll t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);

template <class T> void _print(unordered_set <T> v);
template <class T> void _print(unordered_multiset <T> v);
template <class T> void _print(set <T> v);
template <class T> void _print(multiset <T> v);

template <class T, class V> void _print(unordered_map <T, V> v);
template <class T, class V> void _print(unordered_multimap <T, V> v);
template <class T, class V> void _print(map <T, V> v);
template <class T, class V> void _print(multimap <T, V> v);

template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}

template <class T> void _print(unordered_set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(unordered_multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}

template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_multimap <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(multimap <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

#ifndef ONLINE_JUDGE
#define deb(x) cerr << #x << " = ";  _print(x); cerr << endl;
#else
#define deb(x)
#endif

// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void SOLVE()
{
  INT(n);
  vector<string> v(2);
  inp(v[0] , v[1]);

  int sum[n];
  sum[0] = (v[0][0] == '*') + (v[1][0] == '*');
  repn(i,n-1) sum[i] = sum[i-1] + (v[0][i] == '*') + (v[1][i] == '*');

  int pref[2][n];
  rep(i,2) pref[i][0] = v[i^1][0] == '*';
  repn(j,n-1) rep(i,2) 
  {
    bool flag = v[i^1][j] == '*';

    if(sum[j-1] > 0) 
    pref[i][j] = min({ pref[i^1][j-1] + 2 , 
                                pref[i][j-1] + 1 + flag});
    else pref[i][j] = flag;
  }
  
  int suf[2][n];
  rep(i,2) suf[i][n-1] = v[i^1][n-1] == '*';
  for(int j = n-2 ; j >= 0 ; j--) rep(i,2)
  {
    bool flag = v[i^1][j] == '*';

    if(sum[n-1] - sum[j] > 0) 
    suf[i][j] = min({ suf[i^1][j+1] + 2 , 
                                suf[i][j+1] + 1 + flag});
    else suf[i][j] = flag;
  }

  int ans = INT_MAX;
  rep(i,2) rep(j,n) 
  {
    bool left = (j ? sum[j-1] > 0 : 0);
    bool right = sum[n-1] - sum[j] > 0;
    bool flag = (v[i^1][j] == '*');
    
    int l1 = (j ? pref[i][j-1] + 1 : 0); 
    int l2 = (j ? pref[i^1][j-1] + 2 : 0); 
    int r1 = (j+1 < n ? suf[i][j+1] + 1 : 0); 
    int r2 = (j+1 < n ? suf[i^1][j+1] + 2 : 0); 
    
    if(!left and !right)  
    {
        if(flag) ans = min(ans , 1);
        else ans = 0;
    }
    else if(!left) ans = min({ans , r2 , r1 + flag});
    else if(!right) ans = min({ans , l2 , l1 + flag});
    else ans = min({ans , l1 + r2 , l2 + r1 , l2 + r2 , l1 + r1 + flag });
  }
  outn(ans);
}

int main()
{
  int t = 1;
  inp(t);
  while(t--) SOLVE();

  return 0;
}
// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------