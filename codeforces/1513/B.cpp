#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#ifdef ONLINE_JUDGE
#define cerr   \
    if (false) \
    cerr
#endif
#define watch(x) cerr << #x << " = " << x << '\n'
#define watch1(x)                     \
    cerr << #x << " = ";              \
    for (auto tmpVariable11 : x)      \
        cerr << tmpVariable11 << " "; \
    cerr << "\n"
#define watch2(x)                 \
    cerr << #x << "\n";           \
    for (auto tvar1 : x)          \
    {                             \
        for (auto tvar2 : tvar1)  \
            cerr << tvar2 << " "; \
        cerr << "\n";             \
    }

template <typename... T>
#ifndef ONLINE_JUDGE
inline void dbg(T... args)
{
    ((cerr << " " << args), ...);
    cerr << '\n';
}
#else
inline void dbg(T... args)
{
    return;
}
#endif

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;

#define alice cout << "Alice\n"
#define bob cout << "Bob\n"
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define pb push_back
#define eb emplace_back
#define all(v) v.begin(), v.end()
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;

#define mp make_pair
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define _USE_MATH_DEFINES
#define mpi M_PI
#define me M_E
#define mphi 1.618033933 // Golden Ratio

const int MOD = 1e9 + 7;

// safe_map bfsOfGraph dfsIterOfGraph dfsRecurOfGraph flood_fill dijkstra kruskal

// dp sparse_table segtree myTrees

bool comp(pair<int, int> p1, pair<int, int> p2)
{ // just a sample
    if (p1.second > p2.second)
        return true;
    if (p1.second < p2.second)
        return false;
    if (p1.second == p2.second && p1.first > p2.first)
        return true;
    return false;
}

ll bin_mul(ll a, ll b, ll m)
{
    a %= m;
    ll res = 0;
    while (b > 0)
    {
        if (b & 1)
            res = (res + a) % m;
        a = (a + a) % m;
        b >>= 1;
    }
    return res;
}

ll bin_exp_iter(ll a, ll b, ll m)
{
    a %= m;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

ll pow_no_mod(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

ll floor_sqrt(ll x)
{
    ll ans = 0;
    for (ll k = 1LL << 30; k != 0; k /= 2)
    {
        if ((ans + k) * (ans + k) <= x)
            ans += k;
    }
    return ans;
}

class dsu
{
public:
    vl parent, size;
    dsu(ll n)
    { // makes new set
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (ll i = 0; i <= n; i++)
            parent[i] = i;
    }
    ll find_set(ll v)
    {
        if (v == parent[v])
            return v;
        // path compression
        return parent[v] = find_set(parent[v]);
    }
    void union_sets(ll a, ll b)
    {
        // union by size
        a = find_set(a);
        b = find_set(b);
        if (a != b)
        {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
};

void solve()
{
    ll n, entry;
    string s;
    cin >> n;
    vl v(n);
    for (ll i = 0; i < n; i++)
        cin >> v[i];
    ll val = v[0];
    for (ll i = 1; i < n; i++)
    {
        val &= v[i];
    }
    ll cnt = 0;
    for (ll i = 0; i < n; i++)
    {
        if (v[i] == val)
            cnt++;
    }
    if (cnt < 2)
    {
        cout << 0 << "\n";
        return;
    }
    ll ans = cnt;
    ans = (ans * (cnt - 1)) % MOD;
    ll fac = 1;
    for (ll i = 1; i <= n - 2; i++)
    {
        fac = (fac * i) % MOD;
    }
    ans = (ans * fac) % MOD;
    cout << ans << "\n";
}

// Focus on n = 1
// Never rule out brute force
// See whether to take set or multiset
// Focus on 0 or 1 indexing
// Be careful with global variables for multiple testcases (v.clear())
// If need recursion with N=1e18 => go for memoized DP, memoize using map

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}