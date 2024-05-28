#include<bits/stdc++.h>
//#pragma GCC target("avx,avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
#ifdef LOCAL
#include <debug.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pll = pair<ll,ll>;
using pii = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vvvl = vector<vvl>;
using vul = vector<ull>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using vs = vector<string>;
template<class T> using pq = priority_queue<T,vector<T>, greater<T>>;
#define overload4(_1, _2, _3, _4, name, ...) name
#define overload3(a,b,c,name,...) name
#define rep1(n) for (ll UNUSED_NUMBER = 0; UNUSED_NUMBER < (n); ++UNUSED_NUMBER)
#define rep2(i, n) for (ll i = 0; i < (n); ++i)
#define rep3(i, a, b) for (ll i = (a); i < (b); ++i)
#define rep4(i, a, b, c) for (ll i = (a); i < (b); i += (c))
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define rrep1(n) for(ll i = (n) - 1;i >= 0;i--)
#define rrep2(i,n) for(ll i = (n) - 1;i >= 0;i--)
#define rrep3(i,a,b) for(ll i = (b) - 1;i >= (a);i--)
#define rrep4(i,a,b,c) for(ll i = (a) + ((b)-(a)-1) / (c) * (c);i >= (a);i -= c)
#define rrep(...) overload4(__VA_ARGS__, rrep4, rrep3, rrep2, rrep1)(__VA_ARGS__)
#define all1(i) begin(i) , end(i)
#define all2(i,a) begin(i) , begin(i) + a
#define all3(i,a,b) begin(i) + a , begin(i) + b
#define all(...) overload3(__VA_ARGS__, all3, all2, all1)(__VA_ARGS__)
#define sum(...) accumulate(all(__VA_ARGS__),0LL)
template<class T> bool chmin(T &a, const T &b){ if(a > b){ a = b; return 1; } else return 0; }
template<class T> bool chmax(T &a, const T &b){ if(a < b){ a = b; return 1; } else return 0; }
template<class T> auto min(const T& a){return *min_element(all(a));}
template<class T> auto max(const T& a){return *max_element(all(a));}
template<class... Ts> void in(Ts&... t);
#define INT(...) int __VA_ARGS__; in(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__; in(__VA_ARGS__)
#define STR(...) string __VA_ARGS__; in(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__; in(__VA_ARGS__)
#define DBL(...) double __VA_ARGS__; in(__VA_ARGS__)
#define LD(...) ld __VA_ARGS__; in(__VA_ARGS__)
#define VEC(type, name, size) vector<type> name(size); in(name)
#define VV(type, name, h, w) vector<vector<type>> name(h, vector<type>(w)); in(name)
ll intpow(ll a, ll b){ ll ans = 1; while(b){if(b & 1) ans *= a; a *= a; b /= 2;} return ans;}
ll modpow(ll a, ll b, ll p){ ll ans = 1; a %= p;if(a < 0) a += p;while(b){ if(b & 1) (ans *= a) %= p; (a *= a) %= p; b /= 2; } return ans; }
bool is_clamp(ll val,ll low,ll high) {return low <= val && val < high;}
void Yes() {cout << "Yes\n";return;}
void No() {cout << "No\n";return;}
void YES() {cout << "YES\n";return;}
void NO() {cout << "NO\n";return;}
namespace IO{
#define VOID(a) decltype(void(a))
struct setting{ setting(){cin.tie(nullptr); ios::sync_with_stdio(false);fixed(cout); cout.precision(12);}} setting;
template<int I> struct P : P<I-1>{};
template<> struct P<0>{};
template<class T> void i(T& t){ i(t, P<3>{}); }
void i(vector<bool>::reference t, P<3>){ int a; i(a); t = a; }
template<class T> auto i(T& t, P<2>) -> VOID(cin >> t){ cin >> t; }
template<class T> auto i(T& t, P<1>) -> VOID(begin(t)){ for(auto&& x : t) i(x); }
template<class T, size_t... idx> void ituple(T& t, index_sequence<idx...>){in(get<idx>(t)...);}
template<class T> auto i(T& t, P<0>) -> VOID(tuple_size<T>{}){ituple(t, make_index_sequence<tuple_size<T>::value>{});} 
#undef VOID
}
#define unpack(a) (void)initializer_list<int>{(a, 0)...}
template<class... Ts> void in(Ts&... t){ unpack(IO :: i(t)); }

#undef unpack
static const double PI = 3.1415926535897932;
template <class F> struct REC {
    F f;
    REC(F &&f_) : f(forward<F>(f_)) {}
    template <class... Args> auto operator()(Args &&...args) const { return f(*this, forward<Args>(args)...); }};


constexpr int mod = 998244353;
//constexpr int mod = 1000000007;

void solve() {
    VV(int,a,3,4);
    int cnt = 0;
    int I = 0;
    int IF = 0;
    int J = 0;
    int JF = 0;
    rep(i,3) {
        rep(j,i+1,3) { 
            rep(k,2) {
                rep(l,2) {
                    if(a[i][2*k] == a[j][2*l] && a[i][2*k+1] == a[j][2*l+1]) {
                        cnt++;
                        I = i;
                        J = j;
                        IF = 2 * k;
                        JF = 2 * l;
                    }
                }
            }
        }
    }
    if(cnt != 1) {
        debug(0);
        NO();
        return;
    }
    if(IF > 0) {
        IF = 0;
        swap(a[I][0],a[I][2]);
        swap(a[I][1],a[I][3]);
    }
    if(JF > 0) {
        JF = 0;
        swap(a[J][0],a[J][2]);
        swap(a[J][1],a[J][3]);
    }
    int K = 3 - I - J;
    ll x = 1LL * (a[I][2] - a[I][0]) * (a[J][2] - a[J][0]) + 1LL * (a[I][3] - a[I][1]) * (a[J][3] - a[J][1]);
    if(x < 0) {
        debug(1);
        NO();
        return;
    }
    auto check = [](vi &v,int x,int y) -> int {
        ll dot = 1LL * (x - v[0]) * (x - v[2]) + 1LL * (y - v[1]) * (y - v[3]);
        ll cross = 1LL * (v[0] - x) * (v[3] - y) - 1LL * (v[2] - x) * (v[1] - y);
        if(cross == 0 && dot < 0) return 1;
        else return 0;
    };
    if(check(a[I],a[K][2],a[K][3]) && check(a[J],a[K][0],a[K][1])) {
        swap(a[K][0],a[K][2]);
        swap(a[K][1],a[K][3]);
    }
    if(check(a[I],a[K][0],a[K][1]) && check(a[J],a[K][2],a[K][3])) {
        int f = 1;
        if(a[I][0] != a[I][2]) {
            int D1 = abs(a[I][0] - a[K][0]);
            int D2 = abs(a[I][2] - a[K][0]);
            if(D1 > D2) swap(D1,D2);
            if(D1 * 4 < D2) f = 0;
            debug(f,0);
        }
        else {
            int D1 = abs(a[I][1] - a[K][1]);
            int D2 = abs(a[I][3] - a[K][1]);
            if(D1 > D2) swap(D1,D2);
            if(D1 * 4 < D2) f = 0;
            debug(f,1);
        }
        if(a[J][0] != a[J][2]) {
            int D1 = abs(a[J][0] - a[K][2]);
            int D2 = abs(a[J][2] - a[K][2]);
            if(D1 > D2) swap(D1,D2);
            if(D1 * 4 < D2) f = 0;
            debug(f,2);
        }
        else {
            int D1 = abs(a[J][1] - a[K][3]);
            int D2 = abs(a[J][3] - a[K][3]);
            if(D1 > D2) swap(D1,D2);
            if(D1 * 4 < D2) f = 0;
            debug(f,3);
        }
        if(f) YES();
        else {
            NO();
            debug(2);
        }
    }
    else {
        debug(3);
        NO();
    }
}

int main() {
    INT(TT);
    while(TT--) solve();
} 