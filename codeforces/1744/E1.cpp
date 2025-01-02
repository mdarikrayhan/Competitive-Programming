// try to implement what you are thinking instead of wasting time by thinking its not the way
// do in all possible ways to implement what you are thinking
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vll>
#define vpll vector<pll>
#define mll map<ll, ll>
#define msll multiset<ll>
#define sll set<ll>
#define ins insert
#define pb push_back
#define ppb pop_back
#define F first
#define S second
#define takeinp(a, n) \
    vll a(n);         \
    forl(i, 0, n, 1) { cin >> a[i]; }
#define sz(x) ((ll)(x).size())
#define all(x) (x).begin(), (x).end()
#define forl(i, a, b, k) for (ll i = a; i < b; i += k)
#define revforl(i, b, a, k) for (ll i = b; i >= a; i -= k)
#define ll2dbl static_cast<double>
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define PI 3.141592653589793238462
#define M 998244353
#define MOD 1000000007
#define nl endl
#define spc " "
#define show(a)               \
    {                         \
        for (auto i : a)      \
        {                     \
            cout << i << spc; \
        }                     \
        cout << nl;           \
    }
#define setpr(n) cout << fixed << setprecision(n);
#define Sort(a) sort(all(a))
#define Dsort(a) sort(a.rbegin(), a.rend())
#define Rev(a) reverse(all(a))
#define acsum(a) accumulate(all(a), 0LL)
#define MIN(a) min_element(all(a))
#define MAX(a) max_element(all(a))
#define lgmx LLONG_MAX
#define lgmi LLONG_MIN
#define Distinct(a) \
    Sort(a);        \
    a.erase(unique(all(a)), a.end())
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set_pair;
// a.order_of_key(x)-----gives no of elements less than that number
// a.find_by_order(k)---kth element starting from 0
const int N = 2e5 + 1;
ll power(ll x, ll y);
ll modpower(ll x, ll y, ll m);
ll modInverse(ll a, ll m);
ll fast_pow(ll a, ll p, ll m);
ll ncr(ll n, ll k, ll m);
ll fact[N];
ll invFact[N];
ll mul(ll a, ll b, ll m)
{
    return ((a % m) * (b % m)) % m;
}
ll add(ll a, ll b, ll m)
{
    return ((a % m) + (b % m)) % m;
}
void primeFactors(ll n, mll &m)
{
    while (n % 2 == 0)
    {
        m[2]++;
        n = n / 2;
    }
    for (ll i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            m[i]++;
            n = n / i;
        }
    }
    if (n > 2)
        m[n]++;
}
inline void solve()
{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll val = a * b;
    forl(i, a + 1, c + 1, 1)
    {
        ll curr = __gcd(val, i), ans = val / curr;
        ll fl = d / ans, cl = (b + ans) / ans;
        if (fl - cl >= 0)
        {
            cout << i << spc << ans * fl << nl;
            return;
        }
    }
    cout << "-1 -1" << nl;
    return;
}
int main()
{
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
    int tt = clock();
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    setpr(10);
    // ncr which reduces time complexity
    // fact[0] = invFact[0] = 1;
    // for (int i = 1; i < N; i++)
    // {
    //     fact[i] = (fact[i - 1] * i) % MOD;
    //     invFact[i] = fast_pow(fact[i], MOD - 2, MOD);
    // }
    int _;
    cin >> _;
    while (_--)
    {
        solve();
#ifdef _DEBUG
        cerr << "TIME = " << clock() - tt << endl;
        tt = clock();
#endif
    }
    return 0;
}
// JAI SHREE RAM
ll power(ll x, ll y)
{
    ll power = x, sum = 1;
    if (x == 0)
    {
        sum = 0;
    }
    while (y > 0)
    {
        if ((y & 1) == 1)
        {
            sum *= power;
        }
        power = power * power;
        y = y >> 1;
    }
    return sum;
}
ll modInverse(ll a, ll m)
{
    return modpower(a, m - 2, m);
}
ll modpower(ll x, ll y, ll m)
{
    if (y == 0)
    {
        return 1;
    }
    ll p = modpower(x, y / 2, m) % m;
    p = ((p % m) * (p % m)) % m;
    return (y % 2 == 0) ? p : ((x % m) * (p % m)) % m;
}
ll fast_pow(ll a, ll p, ll m)
{
    ll res = 1;
    while (p)
    {
        if (p % 2 == 0)
        {
            a = (a * a) % m;
            p /= 2;
        }
        else
        {
            res = (res * a) % m;
            p--;
        }
    }
    return res % m;
}
ll ncr(ll n, ll k, ll m)
{
    if (k > n)
    {
        return 0;
    }
    return fact[n] * invFact[k] % m * invFact[n - k] % m;
}