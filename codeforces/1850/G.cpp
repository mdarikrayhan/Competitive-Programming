#include <bits/stdc++.h>
#include <utility>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;

int mod = 1e9 + 7;
int nn = 1e5;
const int MAXN = 1e6;
long long inv[MAXN + 1];
long long facmod[MAXN + 1];
vector<int> fact(nn + 1);

#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair
#define sz(a) (int)a.size()
#define fr(i, k, n) for (int i = k; i < n; i++)
#define frit(i, k) for (auto i : k)
#define frb(i, k, n) for (int i = k; i >= n; i--)
#define ll long long int
#define all(x) (x).begin(), (x).end()
#define mpll map<ll, ll>
#define vpll vector<pair<ll, ll>>
#define vvl vector<vector<ll>>
#define vll vector<long long>
#define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))

const ll pinf = INT64_MAX;
const ll ninf = INT64_MIN;

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

template <typename T>
bool eparity(T x, T y)
{
    return !((x & 1) ^ (y & 1));
}
template <typename T>
void add(T &a, T b, T M)
{
    a = ((a % M) + (b % M)) % M;
}

template <typename T>
void mul(T &a, T b, T M)
{
    a = ((a % M) * (b % M)) % M;
}

template <typename T>
void sub(T &a, T b, T M)
{
    a = (a - b + M) % M;
}

//-------------------------------------------------------------------------------------------------------------------------------

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define PI 3.141592653589793238462
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) { return (a.second < b.second); }
string to_binary(ll n) { return bitset<64>(n).to_string(); }
vll leastPrimeFactor(int n)
{
    vll least_prime(n, 0);
    least_prime[1] = 1;
    for (ll i = 2; i <= n; i++)
    {
        if (least_prime[i] == 0)
        {
            least_prime[i] = i;
            for (ll j = i * i; j <= (n); j += i)
                if (least_prime[j] == 0)
                    least_prime[j] = i;
        }
    }
    return least_prime;
}
template <typename T>
void console_ln(T t) { cout << t << '\n'; }
template <typename T>
void console_sp(T t) { cout << t << " "; }
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << p.first << " " << p.second << endl; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v)
{
    for (const T &x : v)
        os << x << " ";
    return os << endl;
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
    cerr << ' ' << H;
    dbg_out(T...);
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll getRandomNumber(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rng); }
vll getPresum(vll &arr)
{
    vll t(arr);
    fr(i, 0, arr.size() - 1) t[i + 1] += t[i];
    return t;
}
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define invll(x, n)            \
    vector<long long> x(n);    \
    for (ll i = 0; i < n; i++) \
        cin >> x[i];

ll lcm(ll a, ll b)
{
    return a / __gcd(a, b) * b;
}

bool pcomp(const pair<ll, ll> &a, const pair<ll, ll> &b)
{
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

ll binexp(ll a, ll b, ll mod = 998244353)
{
    ll res = 1; // note: mod * mod must be less than 2^63 to avoid ll overflow

    while (b > 0)
    {
        if (b & 1)
        {
            res = res * 1LL * a % mod;
        }
        a = (a * 1LL * a) % mod;
        b >>= 1;
    }
    return res;
}

int pow2(int exp)
{
    if (exp < 30)
        return (1 << exp);
    // auto [q, r]=div(exp, 30);
    auto k = div(exp, 30);
    int q = k.quot;
    int r = k.rem;
    int B = (1 << 30) - mod;
    return binexp(B, q, mod) * (1 << r) % mod;
}

bool prime[1000001] = {1};
ll k = 0;
void sieve()
{
    memset(prime, 1, sizeof(prime));
    prime[0] = 0;
    prime[1] = 0;
    for (ll i = 2; i <= 1000000; i++)
    {
        if (prime[i] == 1 && i * i <= 1000000)
        {
            for (ll j = i * i; j <= 1000000; j += i)
            {
                prime[j] = 0;
            }
        }
    }
}
bool boolpower2(ll i)
{
    ll req = 1;
    if (i == 1 || i == 2 || i == 4)
        return true;
    if (i == 3)
        return false;
    ll p = (ll)(log2(i));
    for (ll j = 0; j <= p + 1; j++)
    {
        req = req * 2;
        if (req == i)
            return true;
    }
    return false;
}
ll power2(ll i)
{
    ll req = 1;
    if (i == 1)
        return 0;
    if (i == 2)
        return 1;
    if (i == 4)
        return 2;
    ll p = (ll)(log2(i));
    for (ll j = 0; j <= p + 1; j++)
    {
        req = req * 2;
        if (req == i)
            return j + 1;
    }
    return -1;
}

int gcdExtended(int a, int b, int *x = NULL, int *y = NULL)
{
    // Base Case
    if (a == 0)
    {
        if (!x && !y)
        {
            *x = 0;
            *y = 1;
        }
        return b;
    }

    int x1, y1; // To store results of recursive call
    int gcd = gcdExtended(b % a, a, &x1, &y1);

    // Update x and y using results of
    // recursive call
    if (!x && !y)
    {
        *x = y1 - (b / a) * x1;
        *y = x1;
    }

    return gcd;
}

void diffgcd(int a, int b, int *ans)
{
    // Everything divides 0
    if (a == 0)
        return;
    if (b == 0)
        return;

    // Base case
    if (a == b)
    {
        return;
    }

    // a is greater
    if (a > b)
    {
        if (a % b == 0)
        {
            return;
        }
        *ans += 1;
        diffgcd(a - b, b, ans);
    }
    if (b % a == 0)
    {
        return;
    }
    *ans += 1;
    diffgcd(a, b - a, ans);
}

vector<int> factor(int n)
{
    vector<int> ret;
    for (int i = 2; i <= n; i++)
    {
        while (n % i == 0)
        {
            ret.push_back(i);
            n /= i;
        }
    }
    return ret;
}

ll countdiv(ll n)
{
    ll divisors = 0;
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (i * i == n)
                divisors++;
            else
                divisors += 2;
        }
    }
    return divisors;
}

vector<ll> quickfactor(ll n)
{
    vector<ll> ret;
    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            ret.push_back(i);
            n /= i;
        }
    }
    if (n > 1)
    {
        ret.push_back(n);
    }
    return ret;
}

void uniqfactor(int n, unordered_set<ll> &ret)
{
    // vector<ll> ret;
    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            ret.insert(i);
            n /= i;
        }
    }
    if (n > 1)
    {
        ret.insert(n);
    }
}

int pvc(vector<ll> vec)
{
    for (auto it : vec)
        cout << it << " ";
    cout << endl;
}

template <typename T>
T roundup(T a, T b)
{
    return (a / b + ((a ^ b) > 0 && a % b));
}

ll power(ll a, ll b)
{
    ll res = 1;
    a %= mod;
    assert(b >= 0);
    for (; b; b >>= 1)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
    }
    return res;
}
ll modInverse(ll a, ll m) { return power(a, m - 2); }

long long readInt(long long l, long long r, char endd)
{
    long long x = 0;
    int cnt = 0;
    int fi = -1;
    bool is_neg = false;
    while (true)
    {
        char g = getchar();
        if (g == '-')
        {
            assert(fi == -1);
            is_neg = true;
            continue;
        }
        if ('0' <= g && g <= '9')
        {
            x *= 10;
            x += g - '0';
            if (cnt == 0)
            {
                fi = g - '0';
            }
            cnt++;
            assert(fi != 0 || cnt == 1);
            assert(fi != 0 || is_neg == false);

            assert(!(cnt > 19 || (cnt == 19 && fi > 1)));
        }
        else if (g == endd)
        {
            if (is_neg)
            {
                x = -x;
            }

            if (!(l <= x && x <= r))
            {
                cerr << l << ' ' << r << ' ' << x << '\n';
                assert(1 == 0);
            }

            return x;
        }
        else
        {
            assert(false);
        }
    }
}
string readString(int l, int r, char endd)
{
    string ret = "";
    int cnt = 0;
    while (true)
    {
        char g = getchar();
        assert(g != -1);
        if (g == endd)
        {
            break;
        }
        cnt++;
        ret += g;
    }
    assert(l <= cnt && cnt <= r);
    return ret;
}
long long readIntSp(long long l, long long r)
{
    return readInt(l, r, ' ');
}
long long readIntLn(long long l, long long r)
{
    return readInt(l, r, '\n');
}
string readStringLn(int l, int r)
{
    return readString(l, r, '\n');
}
string readStringSp(int l, int r)
{
    return readString(l, r, ' ');
}

// For Weighted graphs
// ----------------UNDIRECTED GRAPH INPUT ---------------------------
#define wudg(graph, n, m)           \
    ll n, m;                        \
    cin >> n >> m;                  \
    vector<vll> graph[n + 1];       \
    for (ll i = 0; i < m; ++i)      \
    {                               \
        ll u, v, w = 1;             \
        cin >> u >> v >> w;         \
        graph[u].push_back({v, w}); \
        graph[v].push_back({u, w}); \
    }

// ----------------DIRECTED GRAPH INPUT ---------------------------
#define wdg(graph, n, m)            \
    int n, m;                       \
    cin >> n >> m;                  \
    vector<vll> graph[n + 1];       \
    for (ll i = 0; i < m; ++i)      \
    {                               \
        ll u, v, w = 1;             \
        cin >> u >> v >> w;         \
        graph[u].push_back({v, w}); \
    }

// For Unweighted graphs
// ----------------UNDIRECTED GRAPH INPUT ---------------------------
#define udg(graph, n, m)       \
    ll n, m;                   \
    cin >> n >> m;             \
    vector<ll> graph[n + 1];   \
    for (ll i = 0; i < m; ++i) \
    {                          \
        ll u, v;               \
        cin >> u >> v;         \
        graph[u].push_back(v); \
        graph[v].push_back(u); \
    }

// ----------------DIRECTED GRAPH INPUT ---------------------------
#define dg(graph, n, m)        \
    int n, m;                  \
    cin >> n >> m;             \
    vector<ll> graph[n + 1];   \
    for (ll i = 0; i < m; ++i) \
    {                          \
        ll u, v;               \
        cin >> u >> v;         \
        graph[u].push_back(v); \
    }

#define treeinit(tree, n)               \
    ll n = readInt(0, 2 * (1e5), '\n'); \
    vvl tree(n + 1);                    \
    for (int i = 0; i < n - 1; i++)     \
    {                                   \
        int u, v;                       \
        cin >> u >> v;                  \
        tree[u].push_back(v);           \
        tree[v].push_back(u);           \
    }

ll maxprimefactor(ll num)
{
    ll max_prime = 1;
    for (ll i = 2; i <= sqrt(num); i++)
    { // find maximum of all the prime factors till sqrt
        while (num % i == 0)
        {
            num /= i;
            max_prime = max(max_prime, i);
        }
    }
    max_prime = max(max_prime, num); // either GCD is reduced to 1 or a prime factor
                                     // greater than sqrt(GCD)
    return max_prime;
}

bool check(int GCD, int K)
{
    int max_prime = 1;
    for (int i = 2; i <= sqrt(GCD); i++)
    { // find maximum of all the prime factors till sqrt
        while (GCD % i == 0)
        {
            GCD /= i;
            max_prime = max(max_prime, i);
        }
    }
    max_prime = max(max_prime, GCD); // either GCD is reduced to 1 or a prime factor
                                     // greater than sqrt(GCD)
    if (max_prime <= K)
        return true;
    else
        return false;
}

void dfs_trav(ll node, vector<ll> graph[], vector<ll> &vis, vector<ll> &dfs)
{
    for (auto it : graph[node])
    {
        if (!vis[it])
        {
            dfs.push_back(it);
            vis[it] = 1;
            dfs_trav(it, graph, vis, dfs);
        }
    }
}

#define dfstrav(dfs, graph, n) \
    vector<ll> dfs;            \
    ll vis[n + 1] = {0};       \
    ll root = 1;               \
    vis[root] = 1;             \
    dfs.push_back(root);       \
    dfs_trav(root, graph, vis, dfs);

#define iterative_bfs(graph, node, n)                  \
    vector<ll> vis(n + 1, 0);                          \
    queue<ll> q;                                       \
    q.push(node);                                      \
    vis[node] = 1;                                     \
    while (!q.empty())                                 \
    {                                                  \
        ll tempnode = q.front();                       \
        q.pop();                                       \
        for (auto it : graph[tempnode])                \
        {                                              \
            if (!vis[it])                              \
            {                                          \
                q.push(it);                            \
                cout << tempnode << " " << it << endl; \
                vis[it] = 1;                           \
            }                                          \
        }                                              \
    }

ll floorSqrt(ll n)
{
    ll ans = -1;
    ll l = 1;
    ll r = 1e9 + 100;
    while (l <= r)
    {
        ll mid = (l + r) >> 1;
        if (mid * mid > n)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
            ans = mid;
        }
    }
    return ans;
}
/*-----------------------------------------------code here---------------------------------------*/

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

/**
 * Precomputes all modular inverse factorials
 * from 0 to MAXN in O(n + log n) time
 */
void factinverses(long long m)
{
    inv[MAXN] = binexp(facmod[MAXN], m - 2, m);
    for (int i = MAXN; i >= 1; i--)
    {
        inv[i - 1] = inv[i] * i % m;
    }
}

/** Computes nCr mod p */
long long choose(long long n, long long r, long long m)
{
    return facmod[n] * inv[r] % m * inv[n - r] % m;
}

void factorial(long long m)
{
    facmod[0] = 1;
    for (int i = 1; i <= MAXN; i++)
    {
        facmod[i] = facmod[i - 1] * i % m;
    }
}

bool hassolution(ll num)
{

    ll n = num;
    int x, y;
    int res = gcdExtended(2, 7, &x, &y);
    if (x >= 0 && y >= 0)
        return 1;
    else
    {
        if (x < 0)
        {
            float lw = (-n * x) / 7.0;
            int up = (n * y) / 2;
            if (up >= lw)
                return 1;
        }
        else
        {
            int up = (n * x) / 7;
            float lw = (-n * y) / 2.0;
            if (up >= lw)
                return 1;
        }
    }
    return 0;
}

int _mergeSort(vector<ll> arr, vector<ll> temp,
               int left, int right);
int merge(vector<ll> arr, vector<ll> temp,
          int left, int mid, int right);

/* This function sorts the input
   array and returns the number
   of inversions in the array */
int mergeSort(vector<ll> arr, int array_size)
{
    vector<ll> temp(array_size);
    return _mergeSort(arr, temp, 0,
                      array_size - 1);
}

/* An auxiliary recursive function that
   sorts the input array and returns the
   number of inversions in the array. */
int _mergeSort(vector<ll> arr, vector<ll> temp,
               int left, int right)
{
    int mid, inv_count = 0;
    if (right > left)
    {
        /* Divide the array into two parts and
           call _mergeSortAndCountInv() for
           each of the parts */
        mid = (right + left) / 2;

        /* Inversion count will be sum of inversions
           in left-part, right-part and number of
           inversions in merging */
        inv_count += _mergeSort(arr, temp,
                                left, mid);
        inv_count += _mergeSort(arr, temp,
                                mid + 1, right);

        // Merge the two parts
        inv_count += merge(arr, temp,
                           left, mid + 1, right);
    }
    return inv_count;
}

/* This funt merges two sorted arrays and
   returns inversion count in the arrays.*/
int merge(vector<ll> arr, vector<ll> temp,
          int left, int mid, int right)
{
    int i, j, k;
    int inv_count = 0;

    // i is index for left subarray
    i = left;

    // j is index for right subarray
    j = mid;

    // k is index for resultant merged
    // subarray
    k = left;

    while ((i <= mid - 1) &&
           (j <= right))
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];

            /* This is tricky -- see above
               explanation/diagram for merge()*/
            inv_count = inv_count + (mid - i);
        }
    }

    /* Copy the remaining elements of left
       subarray (if there are any) to temp*/
    while (i <= mid - 1)
        temp[k++] = arr[i++];

    /* Copy the remaining elements of right
       subarray (if there are any) to temp*/
    while (j <= right)
        temp[k++] = arr[j++];

    /* Copy back the merged elements to
       original array*/
    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

// ----------------------</BITWISE>--------------------------
/* a=target variable, b=bit number to act upon 0-n */
#define BIT_SET(a, b) ((a) |= (1ULL << (b)))
#define BIT_CLEAR(a, b) ((a) &= ~(1ULL << (b)))
#define BIT_FLIP(a, b) ((a) ^= (1ULL << (b)))

// '!!' to make sure this returns 0 or 1
#define BIT_CHECK(a, b) (!!((a) & (1ULL << (b))))

#define BITMASK_SET(x, mask) ((x) |= (mask))
#define BITMASK_CLEAR(x, mask) ((x) &= (~(mask)))
#define BITMASK_FLIP(x, mask) ((x) ^= (mask))
#define BITMASK_CHECK_ALL(x, mask) (!(~(x) & (mask)))
#define BITMASK_CHECK_ANY(x, mask) ((x) & (mask))
// ----------------------</BITWISE END>--------------------------

// DISJOINT SET UNION implementation

class Disjoint
{
    vector<ll> rank, size, parent;

public:
    Disjoint(ll n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1, 0);
        fr(i, 0, n + 1) parent[i] = i;
        size.resize(n + 1, 1);
    }

    ll findUltimateparent(ll n)
    {
        if (parent[n] == n)
            return n;
        return parent[n] = findUltimateparent(parent[n]);
    }

    bool Unionbyrank(ll a, ll b)
    {
        ll ul_pa = findUltimateparent(a);
        ll ul_pb = findUltimateparent(b);
        if (ul_pa == ul_pb)
            return 1;
        if (rank[ul_pa] > rank[ul_pb])
            parent[ul_pb] = ul_pa;
        else if (rank[ul_pa] < rank[ul_pb])
            parent[ul_pa] = ul_pb;
        else
        {
            rank[ul_pa]++;
            parent[ul_pb] = ul_pa;
        }
        return 0;
    }

    bool Unionbysize(ll a, ll b)
    {
        ll ul_pa = findUltimateparent(a);
        ll ul_pb = findUltimateparent(b);
        if (ul_pa == ul_pb)
            return 1;
        if (size[ul_pa] >= size[ul_pb])
        {
            size[ul_pa] += size[ul_pb];
            parent[ul_pb] = ul_pa;
        }
        else
        {
            size[ul_pb] += size[ul_pa];
            parent[ul_pa] = ul_pb;
        }
        return 0;
    }
};

// for building MST and returning weight of whole MST
ll Kruskal_spanningTree(ll V, vector<vector<ll>> adj[], Disjoint &ds)
{
    multimap<long long, pair<long long, long long>> hash;
    for (long long i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            long long node = i;
            long long adjnode = it[0];
            long long weight = it[1];
            hash.insert({weight, {node, adjnode}});
        }
    }
    long long Mst_wt = 0;
    for (auto it : hash)
    {
        long long node = it.second.first;
        long long adjnode = it.second.second;
        long long weight = it.first;
        if (ds.findUltimateparent(node) != ds.findUltimateparent(adjnode))
        {
            Mst_wt += weight;
            ds.Unionbyrank(node, adjnode);
        }
    }
    return Mst_wt;
}

/// segment tree class implementation
int m;

template <typename T, class F = function<T(const T &, const T &)>>
class Segtree
{
public:
    int n;
    vector<T> seg;
    vector<T> v;
    F func;

    Segtree(const vector<T> &a, const F &f) : func(f)
    {
        n = a.size();
        v.resize(n);
        seg.resize(4 * n + 5);
        v = a;
    }

    void build(int si, int ss, int se)
    {
        if (ss == se)
        {
            seg[si] = v[ss];
            return;
        }
        int mid = (ss + se) >> 1;
        build(2 * si, ss, mid);
        build(2 * si + 1, mid + 1, se);
        seg[si] = func(seg[2 * si], seg[2 * si + 1]);
    }

    void update(int si, int ss, int se, int I, T val)
    {
        if (ss == se)
        {
            seg[si] = val;
            return;
        }
        int mid = (ss + se) >> 1;
        if (I <= mid)
            update(2 * si, ss, mid, I, val);
        else
            update(2 * si + 1, mid + 1, se, I, val);
        seg[si] = func(seg[2 * si], seg[2 * si + 1]);
    }

    void Update(int I, T val)
    {
        v[I] = val;
        return update(1, 0, n - 1, I, val);
    }

    T query(int si, int ss, int se, int L, int R, T ret)
    {
        // no overlap
        // ret = 0 :: sum query
        // ret = 1E18 :: min query
        // ret = -1E18 :: max query
        if (R < ss || se < L)
            return ret;
        // complete overlap
        if (ss >= L && se <= R)
            return seg[si];
        // partial overlap
        int mid = (ss + se) >> 1;
        T Left = query(2 * si, ss, mid, L, R, ret);
        T Right = query(2 * si + 1, mid + 1, se, L, R, ret);
        return func(Left, Right);
    }

    T Query(int L, int R, T ret)
    {
        return query(1, 0, n - 1, L, R, ret);
    }
};

template <class T>
class FenwickTree
{
    T(*combine)
    (T obj1, T obj2);
    vector<T> fenwickarr;
    T identity;
    ll N;

public:
    FenwickTree(vector<T> data, T (*combine)(T obj1, T obj2), T identityVal)
    {
        this->combine = combine;
        // cout<<"here";
        N = sz(data);
        fenwickarr.resize(N);
        identity = identityVal;
        fill(all(fenwickarr), identity);
        buildfenwickTree(data);
    }

    void updatefenwickTree(ll indx, T element)
    {
        while (indx < N)
        {
            fenwickarr[indx] = combine(element, fenwickarr[indx]);
            if (indx == 0)
                return;
            indx += (indx & (-indx));
        }
    }

    void buildfenwickTree(vector<T> data)
    {
        fr(i, 0, sz(data))
        {
            updatefenwickTree(i, data[i]);
            // cout<<"here";
        }
    }

    T Query(ll q_indx)
    {
        T res = identity;
        while (q_indx >= 0)
        {
            res = combine(fenwickarr[q_indx], res);
            if (q_indx == 0)
                break;
            q_indx -= (q_indx & (-q_indx));
        }
        return res;
    }
};

#ifndef SEGMENTTREE_H
#define SEGMENTTREE_H
#define left(i) (2*i + 1)
#define right(i) (2*i + 2)
#define parent(i) ((i-1)/2)
#include <vector>

template<class T>
class SegmentTree
{
    public:
        //tree constructors.
        SegmentTree(std::vector<T> data, T value, T (*combine)(T obj1, T obj2));
        SegmentTree(T ar[], int n, T value, T (*combine)(T obj1, T obj2));
        
        //query the range l to r, 0 based array indexing.
        T query(int l, int r);
        
        //update the element at index idx to val.
        void update(int idx, T val);
        ///TODO lazy propagation
    private:
        //represents the segment tree.
        T *tree;
    
        //builds the segment tree.
        void buildTree(std::vector<T> data);
        
        //size of the segment tree array.
        int segTreeSize;
    
        //extra nodes must be added to array to make its size a power of 2
        //this is the value to be filled for the those nodes.
        T valueForExtraNodes;
    
        //specifies how to combine child node results to form parent node result.
        T (*combine)(T obj1, T obj2);
    
        //used to calculate the size of array needed to store the tree.
        int calculateSize(int n);
    
        //helps to solve a range query.
        T queryHelper(int l,int r, int st, int ed, int node);
};

template<class T> SegmentTree<T>::SegmentTree(std::vector<T> data,
                                                T value, T (*combine)(T obj1, T obj2))
{
   this->combine = combine;
   valueForExtraNodes = value;
   segTreeSize = calculateSize(data.size());
   buildTree(data);
}

template<class T> SegmentTree<T>::SegmentTree(T ar[], int n,
                                            T value, T (*combine)(T obj1, T obj2))
{
   this->combine = combine;
   valueForExtraNodes = value;
   segTreeSize = calculateSize(n);

   std::vector<T> data;
   for(int i = 0; i < n; i++)
         data.push_back(ar[i]);

   buildTree(data);
}


template<class T> int SegmentTree<T>::calculateSize(int n)
{
    int pow2 = 1;
    while( pow2 < n)
    {
        pow2 = pow2 << 1;
    }
    return 2*pow2 - 1;
}

template<class T> T SegmentTree<T>::query(int l, int r)
{
    int st = 0, ed = segTreeSize/2;
    return queryHelper(l, r, st, ed, 0);
}

template<class T> T SegmentTree<T>::queryHelper(int l,int r, int st, int ed, int node)
{
    if( (r < st) || (l > ed) || (l > r) )
        return valueForExtraNodes;
    if(st >= l && ed <= r)
        return tree[node];
    T leftVal = queryHelper(l, r, st, (st + ed)/2, left(node));
    T rightVal = queryHelper(l, r, (st+ed)/2 + 1, ed, right(node));
    return combine(leftVal, rightVal);
}

template<class T> void SegmentTree<T>::buildTree(std::vector<T> data)
{
   int n = data.size();
   tree = new T[segTreeSize];
   int extraNodes = (segTreeSize/2 + 1) - n;
   for(int i = segTreeSize - 1; i >= 0; i--)
   {
       if(extraNodes>0)
           {
               tree[i] = valueForExtraNodes;
               extraNodes--;
           }
       else if(n>0)
           {
               tree[i] = data[n-1];
               n--;
           }
       else
           tree[i] = combine(tree[left(i)], tree[right(i)]);
   }
}

template<class T> void SegmentTree<T>::update(int idx, T val)
{
    int segTreeIdx = (segTreeSize/2) + idx;
    tree[segTreeIdx] = val;
    while(parent(segTreeIdx) >= 0)
    {
        segTreeIdx = parent(segTreeIdx);
        if(right(segTreeIdx) < segTreeSize)
          tree[segTreeIdx] = combine(tree[left(segTreeIdx)], tree[right(segTreeIdx)]);
        if(segTreeIdx == 0)
            break;
    }
}

#endif // SEGMENTTREE_H

vector<ll> printDivisors(ll n)
{
    vector<ll> ans;
    // Note that this loop runs till square root
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            // If divisors are equal, print only one
            if (n / i == i)
                ans.pb(i);

            else // Otherwise print both
                ans.pb(i);
            ans.pb(n / i);
        }
    }
    // ans.pb(n);
    return ans;
}

// Code for Miller rabin for prime number checking of numbers of order 1e18

using u64 = uint64_t;
using u128 = uint64_t; // here real data type is __int128_t for miller rabin on online c++20 compiler

u64 bigbinpower(u64 base, u64 e, u64 mod)
{
    u64 result = 1;
    base %= mod;
    while (e)
    {
        if (e & 1)
            result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(u64 n, u64 a, u64 d, int s)
{

    u64 x = bigbinpower(a, d, n);

    if (x == 1 || x == n - 1)

        return false;

    for (int r = 1; r < s; r++)
    {

        x = (u128)x * x % n;

        if (x == n - 1)

            return false;
    }

    return true;
};

// Main code of MILLER RABIN
bool MillerRabin(u64 n)
{ // returns true if n is prime, else returns false.

    if (n < 2)

        return false;

    int r = 0;

    u64 d = n - 1;

    while ((d & 1) == 0)
    {

        d >>= 1;

        r++;
    }

    for (u64 a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37})
    {
        if (n == a)
        {
            return true;
        }

        if (check_composite(n, a, d, r))
            return false;
    }

    return true;
}

// Function to invert bits of a number
int invertBits(int n)
{
    // Calculate number of bits of N-1;
    int x = log2(n);

    int m = 1 << x;

    m = n | m - 1;

    n = n ^ m;

    return n;
}

int N = 50000;
bool check_prime(int n){
	for(int i = 2; i < min(N, n); i++)
		if(n % i == 0)
			return 0;
	return 1;
}
const int P = 1e9 + 7;
#define finish(x,y) return cout << x << " " << y <<endl, 0
#define finish1(x) {cout << x <<endl;continue;}
int32_t main(void)
{
    //  cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    // cout << fixed << setprecision(12);
    // sieve();
    ll tc = 1;
    cin>>tc;
    while (tc-- > 0)
    {
     ll n;
     cin>>n;
     map<ll,ll> hashx,hashy,hashadd,hashsub;
     fr(i,0,n){
        ll x,y;
        cin>>x>>y;
        hashx[x]++;
        hashy[y]++;
        hashsub[x-y]++;
        hashadd[x+y]++;
     }
     ll ans = 0;
     for(auto it : hashx){
        if(it.second==1) continue;
        ans+=(it.second*(it.second-1));
     }
     for(auto it : hashy){
        if(it.second==1) continue;
        ans+=(it.second*(it.second-1));
     }
     for(auto it : hashadd){
        if(it.second==1) continue;
        ans+=(it.second*(it.second-1));
     }
     for(auto it : hashsub){
        if(it.second==1) continue;
        ans+=(it.second*(it.second-1));
     }
     cout<<ans<<endl;
     }

    

    // ---------------- PREFIX SUM ---------------------------
    // ll hsh[n];
    // hsh[0]=arr[0];
    // for(ll i = 1; i < n; ++i)
    // {
    //      hsh[i]=hsh[i-1]+arr[i];
    // }

    // ---------------- SUFFIX SUM ---------------------------
    // hsh[n-1]=arr[n-1];
    // for(ll i = n-2; i >= 0; --i)
    // {
    //      hsh[i]=hsh[i+1]+arr[i];
    // }
    // assert(getchar()==-1);
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";

    return 0;
}