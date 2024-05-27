#pragma GCC optimization("O3")
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) ;
#endif

#define int long long
#define endl '\n'
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define pb push_back
#define pf push_front
#define mp make_pair
#define F first
#define S second
#define T third
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<pair<int, int>> vp;
typedef vector<vector<int>> vvi;
typedef vector<vvi> vvvi;
typedef vector<vector<pair<int, int>>> vvp;
typedef vector<vector<char>> vvc;
typedef pair<int, int> pii;

template <typename T>
using PQ_D = priority_queue<T>;
template <typename T>
using PQ_I = priority_queue<T, vector<T>, greater<T>>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<long long> rnd(0, LLONG_MAX);

template <typename T>
std::ostream &operator<<(std::ostream &stream, const vector<T> &vec)
{
    for (size_t i = 0; i < vec.size(); i++)
    {
        stream << vec[i];
        if (i != vec.size() - 1)
            stream << ' ';
    };
    return stream;
}
template <typename T>
std::istream &operator>>(std::istream &stream, vector<T> &vec)
{
    for (T &x : vec)
        stream >> x;
    return stream;
}
template <typename T, typename U>
std::ostream &operator<<(std::ostream &stream, const pair<T, U> &pr)
{
    stream << pr.first << ' ' << pr.second;
    return stream;
}
template <typename T, typename U>
std::istream &operator>>(std::istream &stream, pair<T, U> &pr)
{
    stream >> pr.first >> pr.second;
    return stream;
}

// Policy based data structures

/*
    S.find_by_order(k) => returns iterator to the kth largest element
                        S.find_by_order(sz) returns end(S)
    S.order_of_key(x) => number of items in the set that are strictly smaller than x
*/
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct chash
{
    static uint64_t splitmix64(uint64_t x)
    {
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
    size_t operator()(pair<uint64_t, uint64_t> x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x.first + FIXED_RANDOM) ^ (splitmix64(x.second + FIXED_RANDOM) >> 1); // (or can use 3*F + S as well)
    }
};
template <typename K, typename V>
using hash_table = gp_hash_table<K, V, chash>;

const int C1 = 1e9 + 7;
const int C2 = 998244353;
const int C3 = 1e9;
// const int inf=1e18;
void yes()
{
    cout << "YES" << endl;
}
void no()
{
    cout << "NO" << endl;
}
int binpow(int a, int b, int m = C1)
{
    a %= m;
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return (res % m);
}
int modInverse(int x, int M = C1)
{
    return binpow(x, M - 2, M);
}

const int inf = 1e18;
int *factorial, *inv_factorial, *mod_inverse;
void compute_mod_inverses(int Mxn, int mod = C1)
{
    mod_inverse = new int[Mxn];
    mod_inverse[1] = 1;
    for (int i = 2; i < Mxn; i++)
    {
        mod_inverse[i] = (mod - (mod_inverse[mod % i] * mod / i) % mod) % mod;
    }
}
void compute_mod_factorials(int Mxn, int mod = C1)
{
    factorial = new int[Mxn];
    inv_factorial = new int[Mxn];
    factorial[0] = 1;
    for (int i = 1; i < Mxn; i++)
    {
        factorial[i] = (factorial[i - 1] * i) % mod;
    }
    inv_factorial[Mxn - 1] = modInverse(factorial[Mxn - 1], mod);
    for (int i = Mxn - 2; i >= 1; i--)
    {
        inv_factorial[i] = (inv_factorial[i + 1] * (i + 1)) % mod;
    }
}
int nCr(int n, int r, int mod = C1)
{
    debug(n, r);
    if (n < r)
        return 0;
    if (r == 0)
        return 1;
    int res = (((factorial[n] * inv_factorial[n - r]) % mod) * inv_factorial[r]) % mod;
    debug(n, r, res);
    return res;
}
//******************************************
void precomp()
{
}
void imp()
{
    cout << "IMPOSSIBLE" << endl;
}
void solve()
{
    vp D = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
    vc C = {'D', 'L', 'R', 'U'};
    map<char, char> Rev = {{'D', 'U'}, {'L', 'R'}, {'R', 'L'}, {'U', 'D'}};
    int n, m, k;
    cin >> n >> m >> k;
    pii start;
    vvi a(n, vi(m));
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            if (s[j] == '*')
                a[i][j] = 1;
            else if (s[j] == 'X')
                start = {i, j};
        }
    }
    if (k % 2)
    {
        imp();
        return;
    }
    int len = k;
    pii curr = start;
    map<pii, int> d;
    map<pii, int> vis;
    d[start] = 0;
    queue<pii> q;
    q.push(start);
    vis[start] = 1;
    while (!q.empty())
    {
        auto u = q.front();
        q.pop();
        for (auto [dx, dy] : D)
        {
            int x = u.F + dx, y = u.S + dy;
            if (x >= 0 && x < n && y >= 0 && y < m && a[x][y] == 0 && vis[{x,y}] == 0)
            {
                vis[{x,y}] = 1;
                q.push({x,y});
                d[{x,y}] = d[u] + 1;
            }
        }
    }
    string ans = "";
    while (len--)
    {
        int found = 0;
        for (int i = 0; i < 4; i++)
        {
            int x = curr.F + D[i].F, y = curr.S + D[i].S;
            if (x >= 0 && x < n && y >= 0 && y < m && a[x][y] == 0 && d[{x,y}] <= len)
            {
                found = 1;
                curr = {x, y};
                ans += C[i];
                break;
            }
        }
        if (!found)
        {
            break;
        }
    }
    if(ans.size() == k)
    {
        cout << ans << endl;
        return;
    }
    imp();
}

//*****************************************************

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    precomp();
    int x = 0;
    while (t--)
    {
        x++;
        // cout << "Case #" << x << ": ";
        solve();
    }
}
