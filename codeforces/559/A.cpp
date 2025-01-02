#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>

using namespace std;
using namespace chrono;

#define pi 3.1415926535897932384626433832795
#define int long long
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
constexpr int MOD = 1e9 + 7;
#define INF 1e18
#define all(x) begin(x), end(x)

#ifndef leomessi
#define debug(x) cerr << #x<<" "; __print(x); cerr << '\n';
#else
#define debug(x);
#endif

void __print(int x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const std::string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <class T, class V> void _print(pair <T, V> p);
template <class T> void __print(vector <T> v);
template <class T> void __print(set <T> v);
template <class T, class V> void __print(map <T, V> v);
template <class T> void __print(multiset <T> v);
template <class T, class V> void __print(pair <T, V> p) {cerr << "{"; __print(p.ff); cerr << ","; __print(p.ss); cerr << "}";}
template <class T> void __print(vector <T> v) {cerr << "[ "; for (T i : v) {__print(i); cerr << " ";} cerr << "]";}
template <class T> void __print(set <T> v) {cerr << "[ "; for (T i : v) {__print(i); cerr << " ";} cerr << "]";}
template <class T> void __print(multiset <T> v) {cerr << "[ "; for (T i : v) {__print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void __print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void pre() {
    
  return;
}

void leo() {
    int n = 6;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int s1 = 0;
    for (int i = 0; i < n / 2; i++) {
        s1 += a[i];
    }
    s1 *= s1;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            s1 -= a[i] * a[i];
        }
    }
    cout << s1 << '\n';
}

signed main() {
#ifndef leomessi
    freopen("Error.txt", "w", stderr);
#endif
    fastio();
    pre();
    //int t; cin >> t; while (t--)
    leo();

    auto start1 = high_resolution_clock::now();
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);


  return 0;
}