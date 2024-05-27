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
#pragma GCC optimize("O3")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
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

ll power(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a);
        a = (a * a);
        b >>= 1;
    }
    return res;
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

const int NUM = 4e5 + 7;
const ll INF = 1e18 + 5;
vp moves = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

void solve()
{
    ll n;
    cin >> n;
    ll m;
    cin >> m;
    vll people;
    vin(people, n);
    vll ice;
    vin(ice, m);
    srt(ice);
    map<long double, ll> pre;
    long double d = 1;
    rep(i, n)
    {
        auto x1 = lower_bound(all(ice), 100 * i);
        long double mindist = 1e11;
        if (x1 != ice.end())
        {
            mindist = *x1 - 100 * i - 0.5;
        }
        if (x1 != ice.begin())
        {
            x1--;
            mindist = min(mindist, 100 * i * d - *x1 - 0.5);
        }
        pre[100 * i - mindist] += people[i];
        pre[100 * i + mindist + 1] -= people[i];
    }
    ll ans = 0;
    ll sum = 0;
    for (auto i : pre)
    {
        sum += i.second;
        ans = max(ans, sum);
    }
    cout << ans << endl;
}

// clear all data structures between test cases
// handle all corner cases
// confusing between n and m , i and j?
// uninitialized variables?

int main()
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
        // break;
    }
    return 0;
}
