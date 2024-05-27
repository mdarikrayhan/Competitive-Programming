/*
 * Author: Andy Zhu
 * @date    2024-04-20 18:40:20
 * @version 1.0.0
 */

// optimize
#pragma GCC optimize(2)

//include
#include <bits/stdc++.h>
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

// template <typename T>
// using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
// template <typename T>
// using ordered_multiset = tree<T, null_type,less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;

// pairs
#define fir first
#define sec second

// STL Data Structures
#define eb emplace_back
#define ef emplace_front
#define pb push_back
#define pf push_front
#define all(v) v.begin(), v.end()
#define ins insert
#define lb lower_bound
#define ub upper_bound

// random
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define random(a, b) rng() % (b - a + 1) + a

// Data Structure Shorten
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
template <typename T> using vec = vector<T>;
template <typename T> using us = unordered_set<T>;
template <typename T> using os = set<T>;
template <typename T1, typename T2> using um = unordered_map<T1, T2>;
template <typename T1, typename T2> using om = map<T1, T2>;
template <typename T> using pq = priority_queue<T>; 
template <typename T> using pqg = priority_queue<T, vector<T>, greater<T> >;
using vi = vector<int>;
using vpii = vector<pair<int, int> >;
using vll = vector<long long>;
using vpll = vector<pair<long long, long long> >;
using vb = vector<bool>;

// common functions

namespace comfun {
    template <typename T1, typename T2> inline void ckmax(T1& u, T2 v) { u = max(u, v); }
    template <typename T1, typename T2> inline void ckmin(T1& u, T2 v) { u = min(u, v); }
    template <typename T1, typename T2, typename T3> inline T1 fp(T1 a, T2 b, T3 mod) 
    {T1 c = 1;while(b) {if(b & 1) c = c * a % mod;b >>= 1;a = a * a % mod;}return c;}
    template <typename T1, typename T2> inline T1 fp(T1 a, T2 b) 
    {if(b == 1) return a;T1 tmp = fp(a, b >> 1);if(b & 1) return tmp * tmp * a;else return tmp * tmp;}
}

#ifndef ONLINE_JUDGE
template<typename T>
concept Printable = requires(T a) { { cerr << a }; };

struct Debug {
    template<typename T, typename U>
    Debug& operator<<(const pair<T, U>& a) { *this << '(' << a.first << ", " << a.second << ')'; return *this; }
    Debug& operator<<(const char& a) { cerr << '\'' << a << '\''; return *this; }
    Debug& operator<<(const string& a) { cerr << '\"' << a << '\"'; return *this; }
    template<Printable T>
    Debug& operator<<(const T& a) { cerr << boolalpha << a; return *this; }
    template<typename T>
    Debug& operator<<(const T& a) {
        cerr << '{';
        for (auto it = begin(a); it != end(a); it++){
            *this << *it;
            if (next(it) != end(a)) { cerr << ", "; }
        }
        cerr << '}';
        return *this;
    }
};

template<typename T, typename... U>
void __print(T t, U... u) { 
    Debug() << t; 
    if constexpr (sizeof...(u)) { 
        cerr << ", "; 
        __print(u...);
    }
}

#define dbg(x...) cerr << "[DEBUG] "<<__func__<<": "<<__LINE__<<", [" << #x << "] = ["; __print(x); cerr << "]" << endl;
#else
#define dbg(x...) ;
#endif

namespace fast_io {
    int read() {int x = 0, f = 0; char ch = getchar();while (!isdigit(ch)) f |= ch == '-', ch = getchar();while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();return f ? -x : x;}
    long long readLL() {long long x = 0, f = 0; char ch = getchar();while (!isdigit(ch)) f |= ch == '-', ch = getchar();while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();return f ? -x : x;}
    template <typename T> T read(T& x) {x = 0; int f = 0; char ch = getchar();while (!isdigit(ch)) f |= ch == '-', ch = getchar();while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();x = f ? -x : x; return x;}
    template <typename T> void print(T x) {if (x < 0) putchar('-'), x = -x;if (x >= 10) print(x / 10);putchar(x % 10 + '0');}
    template <typename T> void print(T x, char let) {print(x), putchar(let);}
}

// using namespaces
using namespace comfun;
using namespace fast_io;

// common variables
const int inf = 0x3f3f3f3f;
const long long llinf = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
const int dir[8][2] = {{0, 1}, {0, -1}, {0, 0}, {1, 0}, {-1, 1}, {1, -1}, {-1, -1}, {1, 1}};
const unordered_set<char> vowel = {'a', 'e', 'i', 'o', 'u'};
template <int mod = 998'244'353> class mint {
    // obtaining inverse
    void exgcd(int a, int b, int& x, int& y) {
        if(1ll * a * b == 0) { x = 1, y = 0; return; }
        exgcd(b, a % b, x, y); int tmp = y; y = x - a / b * y; x = tmp; 
    }
public:
    int v;
    explicit operator int() const { return v; }

    // constructors
    mint():v(0) {}
    template <typename T> mint(T _v) :v((int)(_v % mod)) { v = (v + mod) % mod; }

    template <typename T> mint& operator=(T a) { v = (a + mod) % mod; return *this; }
     mint operator-() { return mint((-v + mod) % mod); } 
    mint& operator+=(mint o) { v = (v + o.v) % mod; return *this; }
    mint& operator-=(mint o) { v = (v - o.v + mod) % mod; return *this; }
    mint inv() { int x, y; exgcd(v, mod, x, y); return mint((x + mod) % mod); }
    mint& operator*=(mint o) { v = (long long)v * o.v % mod; return *this; }
    mint& operator/=(mint o) { v = (long long)v * o.inv().v % mod; return *this; }

    mint operator+(mint o) { return mint((v + o.v) % mod); } 
    mint operator-(mint o) { return mint((v - o.v + mod) % mod); } 
    mint operator*(mint o) { return mint((long long)v * o.v % mod); } 
    mint operator/(mint o) { return mint((long long)v * o.inv().v % mod); }

    template <typename T> mint& operator+=(T o) { v = (v + o) % mod; return *this; }
    template <typename T> mint& operator-=(T o) { v = (v - o + mod) % mod; return *this; }
    template <typename T> mint& operator*=(T o) { v = (long long)v * o % mod; return *this; }
    template <typename T> mint& operator/=(T o) { v = (long long)v * mint(o).inv().v % mod; return *this; }

    template <typename T> mint operator+(T o) { return mint((v + o) % mod); } 
    template <typename T> mint operator-(T o) { return mint((v - o + mod) % mod); } 
    template <typename T> mint operator*(T o) { return mint((long long)v * o % mod); } 
    template <typename T> mint operator/(T o) { return mint((long long)v * mint(o).inv().v % mod); }

    mint& operator++() { v = (v + 1) % mod; return *this; }
    mint& operator--() { v = (v - 1 + mod) % mod; return *this; }

    mint operator++(int) { mint old = *this; operator++(); return old; }
    mint operator--(int) { mint old = *this; operator--(); return old; }

    bool operator==(mint o) { return v == o.v; }
    bool operator!=(mint o) { return v != o.v; }

    template <typename T> bool operator==(T o) { return v == o; }
    template <typename T> bool operator!=(T o) { return v != o; }
    
    template <typename T> friend mint operator+(T o, mint x) { return x + o; }
    template <typename T> friend mint operator-(T o, mint x) { return x * (-1) + o; }
    template <typename T> friend mint operator*(T o, mint x) { return x * o; }
    template <typename T> friend mint operator/(T o, mint x) { return x.inv() * o; }

    template <typename T> mint& operator%=(T o) { v %= o; return *this; }
    template <typename T> friend T operator%(T o, mint x) { return o % x.v; }
    template <typename T> friend mint operator%(mint x, T o) { return mint(x.v % o); }
    
    friend std::ostream& operator<<(std::ostream& os, mint const& a) { return os << a.v; }
    friend istream& operator>>(istream& is, mint& a) { long long x; is >> x; a = mint(x); return is; }
};

using mt = mint<(int)1e9 + 9>;
//------------------- start of initialize --------------------
// initialize for all cases
inline void init1(){

}

//-------------------  end of initialize  --------------------

//--------------------- start of program ---------------------

const int N = 1e5 + 5;
int m;
array<int, 2> a[N];
map<array<int, 2>, int> vis;

map<array<int, 2>, set<array<int, 2>>> e, ee;
map<array<int, 2>, int> in;

bool ok(array<int, 2> u) {
    bool flag = 1;
    for(auto x : e[u]) {
        flag &= ee[x].size() > 1;
    }
    return flag;
}

inline void solve(){
    read(m);
    for(int i = 1;i<=m;++i) {
        read(a[i][0]), read(a[i][1]);
        vis[a[i]] = i - 1;
    }
    for(int i = 1;i<=m;++i) {
        for(int j = -1;j<=1;++j) {
            array<int, 2> tmp = {a[i][0] + j, a[i][1] + 1};
            if(vis.count(tmp)) {
                e[a[i]].ins(tmp);
                ee[tmp].ins(a[i]);
            }
        }
    }
    set<pair<int, array<int, 2>>> q;
    for(int i = 1;i<=m;++i) {
        if(ok(a[i])) q.ins({i - 1, a[i]});
    }
    int cnt = 0;
    mt ans;
    while(!q.empty()) {
        int x;
        array<int, 2> u;
        if(cnt & 1) {
            x = (*q.begin()).fir;
            u = (*q.begin()).sec;
            q.erase(q.begin());
        } else {
            x = (*q.rbegin()).fir;
            u = (*q.rbegin()).sec;
            q.erase(prev(q.end()));
        }
        for(auto x : e[u]) {
            ee[x].erase(u);
            if(ee[x].size() == 1) {
                for(auto y : ee[x]) {
                    q.erase({vis[y], y});
                }
            }
        }
        for(auto x : ee[u]) {
            e[x].erase(u);
        }
        ans = ans * m + x;
        dbg(x);
        for(auto x : ee[u]) if(ok(x) && !q.count({vis[x], x})) q.ins({vis[x], x});
        ++cnt;
    }
    print(ans.v, '\n');
}


//---------------------  end of program  ---------------------


#define doCase 0
#define config LOCAL
// #define kickstart
#define unsync 0

inline void setIO() {
#if config
    // configuration here
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
#if unsync
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
}

signed main(){
    setIO();
    init1();
    srand(time(0));
#if doCase
    int t; t = read();
    for(int i = 1;i<=t;i++) {
#ifdef kickstart 
        printf("Case #%d: ", i);
#endif
        solve();
    }
#else 
    solve();
#endif
    string jack = "Jack is always within you";
    return 0;
}

 
/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/