#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
 
#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif
 
// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
 
#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
using namespace std;
using i64 = uint64_t;
//using i128 = __int128;
#define MAXN 200005
#define MAXM 11
#define MAXK 65
#define MAXT 102
#define OP 0
#define CLO 1
#define PLUS 0
#define MINUS 1
#define MUL 2
#define HORZ 0
#define VERT 1
#define ITER 65
#define INF 1e9
#define EPS 1e-9
#define MOD 1000000007
#define SRC 0
#define PUSH 0
#define POP 1
#define PI acos(-1)
#define UNVISITED INF
#define FOR 0
#define BACK 1
#define OK 2
#define H 18
#define HSH 3
typedef long long ll;
//typedef __int128_t lint;
typedef long double ld;
typedef pair<int,int> ii;
typedef pair<int,ll> ilp;
typedef pair<ll,ii> pl;
typedef pair<ll, ll> pll;
//typedef pair<ll,int> ppll;
typedef pair<ll,int> li;
typedef pair<ll,ll> iv;
typedef pair<double,int> ip;
typedef tuple<int,int,int> iii;
typedef tuple<ll, ll, ll> tll;
typedef tuple<ld, int, int> iit;
typedef tuple<int,int,ll> i3;
typedef vector<vector<int>> vv;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vii;
typedef vector<vector<ll>> vll;
//typedef complex<ld> cd;
typedef tuple<ll,int,int> tpl;
#define pb push_back
#define eb emplace_back
#define ppb pop_back
#define ppf pop_front
#define pf push_front
#define bk back()
#define frnt front()
#define ins insert
#define er erase
#define sc second
#define fr first
#define mp make_pair
#define mt make_tuple
#define repl(i,x,y) for (int i = (x); i <= (y); ++i)
#define rep(i,x,y) for (int i = (x); i < (y); ++i)
#define rev(i,x,y) for (int i = (x); i >= (y); --i)
#define repd(i,x,y,d) for (int i = (x); i < (y); i += (d))
#define LSOne(S) (S & (-S))
#define trav(i,v) for (auto &i : v)
#define foreach(it,v) for (auto it = begin(v); it != end(v); ++it)
#define bend(v) begin(v), end(v)
#define rbend(v) (v).rbegin(), (v).rend()
#define sortarr(v) sort(bend(v))
#define rsortarr(v) sort(rbend(v))
#define rdup(v) v.er(unique(bend(v)), end(v))
#define rstreak(v) v.resize(unique(bend(v)) - begin(v))
#define extend(A,B) A.insert(end(A), bend(B))
#define sz(A) (int)(A.size())
#define fill(V) iota(bend(V), (0))
#define vfill(V, st) iota(bend(V), st)
#define sum(V) accumulate(bend(V), 0LL)
#define vsum(V, st) accumulate(bend(V), (ll)(st))
#define freq(V, amt) (int)(count(bend(V), amt))
template<class T> bool ckmin(T &a, T b) { return a > b ? a = b, 1 : 0; };
template<class T> bool ckmax(T &a, T b) { return a < b ? a = b, 1 : 0; };
template<class T> void amax(T &a, T b, T c) { a = max(b, c); };
template<class T> void amin(T &a, T b, T c) { a = min(b, c); };
template<class T> T gmax(vector<T> &v) { return *max_element(bend(v)); };
template<class T> T gmin(vector<T> &v) { return *min_element(bend(v)); };
template<class T> T gmaxid(vector<T> &v) { return (int)(max_element(bend(v)) - begin(v)); };
template<class T> T gminid(vector<T> &v) { return (int)(min_element(bend(v)) - begin(v)); };
template<class vi> void distinct(vi &a) { sortarr(a); rdup(a); };
template<class T> int compress(vector<T> &v, T val) { return (int)(lower_bound(bend(v), val) - begin(v)); };
template<class T> int ucompress(vector<T> &v, T val) { return (int)(upper_bound(bend(v), val) - begin(v)); };
template<class T> auto vfind(vector<T> &v, T val) {
    return find(bend(v), val);
}
template<class T> auto verase(vector<T> &v, T val) {
    return v.er(vfind(v, val));
}
template<class T> void revarr(vector<T> &v) { reverse(bend(v)); };
template<class T> void print(vector<T> &v, char end) { trav(i,v) cout << i << end;
}
 
mt19937 gen((int)(chrono::steady_clock::now().time_since_epoch().count()));
ll rng(ll l,ll r) {return uniform_int_distribution<ll>(l,r)(gen);}
void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}
 
ll gcd(ll a, ll b) {
    if (!a) return b;
    return gcd(b % a, a);
}
 
vector<ii> mv = {{-1,0}, {0,1}, {1,0}, {0,-1}};
vector<ii> mv2 = {{-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1}};
//sort characters based on their last seen in decreasing order
//observe sequence is cyclic
//we can perform DP to count the number of distinct subquences
int main() {
    fast_io();
    //int t; cin >> t;
    //while (t--) solve();
    int n,k; cin >> n >> k;
    vi lst(k, -INF);
    string t; cin >> t;
    const int m = sz(t);
    vl dp(m + n + 1);
    dp[0] = 1;
    repl(i,1,m) {
        dp[i] = (2LL * dp[i - 1]) % MOD;
        if (lst[t[i - 1] - 'a'] != -INF) dp[i] = (dp[i] - dp[lst[t[i - 1] - 'a']] + MOD) % MOD;
        lst[t[i - 1] - 'a'] = i - 1;
    }
    vi c(k);
    fill(c);
    sort(bend(c), [&](int a, int b) {
        if (lst[a] == lst[b]) return a < b;
        return lst[a] < lst[b];
    });
    repl(i,1,n) {
        dp[m + i] = (2LL * dp[m + i - 1]) % MOD;
        int id = (i - 1) % k;
        if (lst[c[id]] != -INF) dp[m + i] = (dp[m + i] - dp[lst[c[id]]] + MOD) % MOD;
        lst[c[id]] = m + i - 1;
    }
    cout << dp[n + m];
}