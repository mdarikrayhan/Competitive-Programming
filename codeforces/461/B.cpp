// Jaane wo kaise, log the jinke, pyaar ko pyaar milaaaaa
// Hamne to jab kaliyan maangi, kaaton ka haaar milaaaaa

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef long long ll;
typedef long double ld;
using namespace std;
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> indexed_multiset;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #define deb(x) cerr << #x << " is " << x << endl;

#define pb push_back
#define sz(x) static_cast<ll>((x).size())
#define pyes cout << "Yes\n"
#define pno cout << "No\n"
#define ce cout << '\n'
#define endl '\n'
#define fi first
#define se second
#define rev(v) reverse(v.begin(), v.end())
#define srt(v) sort(v.begin(), v.end())
#define all(v) v.begin(), v.end()
#define mnv(v) *min_element(v.begin(), v.end())
#define mxv(v) *max_element(v.begin(), v.end())
#define vll vector<ll>
#define vp vector<pair<long long, long long>>
#define trav(v) for (auto it = v.begin(); it != v.end(); it++)
#define rep(i, n) for (ll i = 0; i < n; i++)
#define forf(i, a, b) for (ll i = a; i < b; i++)
#define forb(i, s, e) for (ll i = s; i >= e; i--)

const ll mod7 = 1e9 + 7;
const ll mod9 = 998244353;

void vin(vector<ll> &a, int n)
{
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        a.push_back(x);
    }
}

template <typename T>
void pin(vector<T> a)
{
    for (int i = 0; i < (int)a.size(); i++)
    {
        cout << a[i] << " ";
    }
    ce;
}

ll exp(ll x, ll y, ll p)
{
    ll res = 1;
    x %= p;
    while (y)
    {
        if (y & 1)
        {
            res *= x;
            res %= p;
        }
        x *= x;
        x %= p;
        y >>= 1;
    }
    return res;
}

const int NUM = 2e5 + 7;
const ll INF = 1e18 + 5;
vp moves = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

vll g[NUM];
ll dp[NUM][2];
ll col[NUM];

void dfs(ll vertex, ll par)
{
    // cout << vertex << endl;
    dp[vertex][0] = ((1ll) ^ col[vertex]);
    dp[vertex][1] = col[vertex];
    ll temp0 = 0;
    ll temp1 = 0;
    // cout << "one " << vertex << " " << dp[vertex][0] << " " << dp[vertex][1] << endl;
    for (auto child : g[vertex])
    {
        if (child == par)
            continue;
        dfs(child, vertex);
        // dp[ver][0]
        // lenge
        temp0 = (dp[vertex][0] * dp[child][0]) % mod7;
        // nahi lenge
        temp0 = (temp0 + (dp[vertex][0] * dp[child][1]) % mod7) % mod7;
        // dp[ver][1]
        // lenge
        temp1 = (dp[vertex][1] * dp[child][0]) % mod7;
        temp1 = (temp1 + (dp[vertex][0] * dp[child][1]) % mod7) % mod7;
        // nahi lenge
        temp1 = (temp1 + (dp[vertex][1] * dp[child][1]) % mod7) % mod7;
        dp[vertex][0] = temp0;
        dp[vertex][1] = temp1;
        temp0 = dp[vertex][0];
        temp1 = dp[vertex][1];
    }
    // cout << "two " << vertex << " " << dp[vertex][0] << " " << dp[vertex][1] << endl;
}

void solve()
{
    ll n;
    cin >> n;
    rep(i, n - 1)
    {
        ll x;
        cin >> x;
        g[x + 1].pb(i + 2);
        g[i + 2].pb(x + 1);
    }
    forf(i, 1, n + 1)
    {
        cin >> col[i];
    }
    // cout << col[1] << endl;
    dfs(1, 0);
    // cout <<dp[3][1]<<endl;
    cout << dp[1][1] << endl;
}
// clear all data structures between test cases
// handle all corner cases
// confusing between n and m , i and j?
// uninitialized variables?

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // memset(dp, -1, sizeof(dp));
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}