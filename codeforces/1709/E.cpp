#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <array>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <list>
#include <iterator>
#include <numeric>
#include <complex>
#include <utility>
#include <random>
#include <cassert>
#include <fstream>
using namespace std;
mt19937 rnd(7069);

/* -------------------- Typedefs -------------------- */

typedef int itn;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef float fl;
typedef long double ld;

/* -------------------- Usings -------------------- */

using vi = vector<int>;
using vll = vector<ll>;
using mii = map<int, int>;
using mll = map<ll, ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

/* -------------------- Defines -------------------- */

#define ff first
#define ss second
#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define mpr make_pair
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define all(x) (x).begin(), (x).end()
#define USACO freopen("feast.in", "r", stdin); freopen("feast.out", "w", stdout);

/* -------------------- Constants -------------------- */

const int dx[8] = { -1, 0, 1, 0, -1, -1, 1, 1 };
const int dy[8] = { 0, -1, 0, 1, -1, 1, -1, 1 };
const int MAX = int(1e9 + 5);
const ll MAXL = ll(1e18) + 5ll;
const ll MOD = ll(1000000007);
const ll MOD2 = ll(998244353);

/* -------------------- Functions -------------------- */

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void precision(int x) {
    cout.setf(ios::fixed | ios::showpoint);
    cout.precision(x);
}

ll gcd(ll a, ll b) {
    if (a == 0 || b == 0) return(max(a, b));
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

ll range_sum(ll a, ll b) {
    if (a > b) return 0ll;
    ll dif = a - 1, cnt = b - a + 1;
    ll ans = ((b - a + 1) * (b - a + 2)) / 2;
    ans += ((b - a + 1) * dif);
    return ans;
}

string dec_to_bin(ll a) {
    string s = "";
    for (ll i = a; i > 0; ) {
        ll k = i % 2;
        i /= 2;
        char c = k + 48;
        s += c;
    }
    if (a == 0) {
        s = "0";
    }
    reverse(all(s));
    return s;
}

ll bin_to_dec(string s) {
    ll num = 0;
    for (int i = 0; i < s.size(); i++) {
        num *= 2ll;
        num += (s[i] - '0');
    }
    return num;
}

ll factorial_by_mod(ll n, ll mod) {
    ll ans = 1;
    ll num;
    for (ll i = 1; i <= n; ++i) {
        num = i % mod;
        ans *= num;
        ans %= mod;
    }
    return ans;
}

int isPrime(ll a) {
    if (a == 1) return 0;
    for (ll i = 2; i * i <= a; i++) {
        if (a % i == 0) return 0;
    }
    return 1;
}

ll binpow(ll a, ll b) {
    if (!a) return 0;
    ll ans = 1;
    while (b) {
        if (b & 1) {
            ans *= a;
        }
        b >>= 1;
        a *= a;
    }
    return ans;
}

ll binpow_by_mod(ll a, ll b, ll mod) {
    if (!a) return 0;
    ll ans = 1;
    while (b) {
        if (b & 1) {
            ans *= a;
            ans %= mod;
        }
        b >>= 1;
        a *= a;
        a %= mod;
    }
    return ans;
}

/* -------------------- Solution -------------------- */

const int N = 200005;
int a[N], pref[N], par[N], p[N], sz[N];
mii mp[N];
vi g[N], dep[N];
int n;

void dfs(int u = 1, int depth = 0) {
    dep[depth].pub(u);
    pref[u] ^= a[u];
    for (auto to : g[u]) {
        if (to == par[u]) continue;
        par[to] = u;
        pref[to] = pref[u];
        dfs(to, depth + 1);
    }
}

void make_set(int u) {
    p[u] = u;
    sz[u] = 1;
    mp[u][pref[u]] = 1;
}

int find_set(int u) {
    if (u == p[u]) return u;
    return p[u] = find_set(p[u]);
}

bool union_sets(int x, int y, int val) {
    x = find_set(x);
    y = find_set(y);
    if (x == y) return false;
    if (sz[x] > sz[y]) swap(x, y);
    sz[y] += sz[x];
    p[x] = y;
    for (auto elem : mp[x]) {
        if (!elem.ss) continue;
        if (mp[y][elem.ff ^ val]) return true;
    }
    for (auto elem : mp[x]) {
        if (!elem.ss) continue;
        mp[y][elem.ff] = 1;
    }
    return false;
}

void slv() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        g[x].pub(y);
        g[y].pub(x);
    }
    dfs();
    int ans = 0;
    for (int i = n; i >= 0; --i) {
        for (auto u : dep[i]) {
            make_set(u);
        }
        for (auto u : dep[i]) {
            for (auto to : g[u]) {
                if (to == par[u]) continue;
                bool f = union_sets(u, to, a[u]);
                if (f) {
                    int ux = find_set(u);
                    mp[ux].clear();
                    ++ans;
                    break;
                }
            }
        }
    }
    cout << ans;
}

void cs() {
    int tstc = 1;
    //cin >> tstc;
    while (tstc--) {
        slv();
    }
}

void precalc() {
    return;
}

int main() {
    fastio();
    precalc();
    //precision(0);
    cs();
    return 0;
}