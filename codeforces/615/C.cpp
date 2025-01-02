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
#define MAXN 100005
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
#define H 27
#define HSH 3
typedef long long ll;
//typedef __int128_t lint;
typedef long double ld;
typedef pair<int,int> ii;
typedef pair<int,ll> ilp;
typedef pair<ll,ii> pl;
typedef pair<ll, ll> pll;
typedef pair<ll,int> ppll;
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
//LCP DP to compute the longest common prefix between 2 strings starting at index i for the first one and index j for the second
//compute for both the forward and reverse direction
//similar to: https://codeforces.com/gym/102428/problem/G greedy always works to cover as much of the string as possible
int main() {
    fast_io();
    //int t; cin >> t;
    //while (t--) solve();
    string s1,s2; cin >> s1 >> s2;
    const int n = sz(s1);
    const int m = sz(s2);
    s1 = "#" + s1 + "@";
    s2 = "(" + s2 + ")";
    vector<vv> dp(2, vv(m + 2, vi(n + 2)));
    rev(i,m,1) {
        rev(j,n,1) if (s2[i] == s1[j]) dp[0][i][j] = dp[0][i + 1][j + 1] + 1;
        repl(j,1,n) if (s2[i] == s1[j]) dp[1][i][j] = dp[1][i + 1][j - 1] + 1;
    }
    vii ans;
    for (int i = 1; i <= m;) {
        int b1 = gmaxid(dp[0][i]);
        int b2 = gmaxid(dp[1][i]);
        int len = max(dp[0][i][b1], dp[1][i][b2]);
        if (!len) {
            cout << -1;
            return 0;
        }
        if (dp[0][i][b1] >= dp[1][i][b2]) ans.eb(b1, b1 + len - 1);
        else ans.eb(b2, b2 - len + 1);
        i += len;
    }
    cout << sz(ans) << '\n';
    trav(i,ans) cout << i.fr << ' ' << i.sc << '\n';
}