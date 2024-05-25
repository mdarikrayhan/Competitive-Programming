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

class Segment_Tree
{
    public : 

    int n;
    vl tree;
    int NEUTRAL_CALC_OP = 0;

    Segment_Tree(vi &v)
    {
        this->n = sz(v);
        tree.resize(4*n + 5);        
        build(1 , 0 , sz(v)-1 , v);
    }

    int calc(int x, int y) {return __gcd(x,y);}

    void build(int v, int lv, int rv , vi &a)
    {
        if(lv == rv) {tree[v] = a[lv]; return;}
        
        int m = (lv+rv)/2;
        build(2*v , lv , m , a);
        build(2*v + 1, m+1 , rv , a);
        tree[v] = calc(tree[2*v],tree[2*v + 1]);
    }

    void set(int i, int x)
    {
        set(i , x, 1 , 0, n-1);
    }

    void set(int i, int x, int v, int lv ,int rv)
    {
        if(lv == rv) {tree[v] = x; return;}

        int m = (lv+rv)/2;
        if(i <= m) set(i,x, 2*v , lv , m);
        else set(i,x, 2*v + 1 , m+1 , rv);
        tree[v] = calc(tree[2*v],tree[2*v + 1]);
    }

    ll query(int l, int r)
    {
        return query(l, r, 1, 0, n-1);
    }
    
    // Return value --> Answer for the interval I = [l,r] ∩ [lv,rv]
    ll query(int l, int r, int v, int lv, int rv)
    {
        if(r < lv or rv < l) return NEUTRAL_CALC_OP;
        if(l <= lv and rv <= r) return tree[v];

        int m = (lv+rv)/2;
        ll left = query(l, r, 2*v, lv, m);
        ll right = query(l, r, 2*v + 1, m+1, rv);
        return calc(left , right);
    }
};

void SOLVE()
{
  INT(n);
  vi a(n); inp(a);
  if(n == 1) {outn((int)(a[0] == 1)); return;}
  
  Segment_Tree s(a);
  int ans = 0, prev = -1;
  rep(i,n) 
  {
    int l = prev+1 , r = i;
    bool flag = 0;
    while(l <= r) 
    {
        int m = (l+r) >> 1;
        int g = s.query(m , i), len = i-m+1;
        if(g == len) {flag = 1; break;}
        else if(g < len) l = m+1;
        else r = m-1;
    }
    if(flag) ans++ , a[i] = (i ? a[i-1] + 1 : a[i+1] + 1) , s.set(i, a[i]) , prev = i;
    cout << ans << ' ';
  }
  pnl();
}

int main()
{
  int t = 1;
  while(t--) SOLVE();

  return 0;
}
// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------