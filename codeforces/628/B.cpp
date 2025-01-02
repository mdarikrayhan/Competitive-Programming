#include <bits/stdc++.h>

using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define MOD 1000000007
#define Z 1000001
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.ff);
    cerr << ",";
    _print(p.ss);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
ll maxwithnbits(ll n)
{
    return ((ll)1 << n) - 1;
}
bool ibithset(ll n, ll i)
{
    if ((1 << i) & n)
    {
        return true;
    }
    else
    {
        return false;
    }
}
ll setithbit(ll n, ll i)
{
    return (1 << i | n);
}
ll unsetithbit(ll n, ll i)
{
    return (~(1 << i) & n);
}
void printbinary(ll n)
{
    for (ll i = 31; i >= 0; i--)
    {
        cout << (n >> i & 1);
    }
}
ll toggleithbits(ll n, ll i)
{
    return (1 << i) ^ n;
}
ll countsetbits(ll n)
{
    ll ans = 0;
    for (ll i = 31; i >= 0; i--)
    {
        if (ibithset(n, i))
        {
            ans++;
        }
    }
    return ans;
}
int unsettillithbit(int n, int i)
{
    return (~((1 << (i + 1)) - 1)) & n;
}
bool powerof2(int n)
{
    if (n & (n - 1))
    {
        return false;
    }
    else
    {
        return true;
    }
}

vector<bool> sieve(1000001, true);
void createsieve()
{
    sieve[0] = sieve[1] = false;
    for (int i = 2; i <= Z; i++)
    {
        if (sieve[i])
        {
            for (int j = 2 * i; j <= Z; j = j + i)
            {
                sieve[j] = false;
            }
        }
    }
}
ll multimod(ll a, ll b)
{
    ll ans;
    ans = ((a % MOD) * (b % MOD)) % MOD;
    return ans;
}
ll addmod(ll a, ll b)
{
    ll ans;
    ans = ((a % MOD) + (b % MOD)) % MOD;
    return ans;
}
ll submod(ll a, ll b)
{
    ll ans;
    ans = ((a % MOD) - (b % MOD) + MOD) % MOD;
    return ans;
}
ll binpow(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = ((res) % MOD * (a) % MOD) % MOD;
        a = ((a) % MOD * (a) % MOD) % MOD;
        b >>= 1;
    }
    return res;
}
ll inverse(ll base, ll exp, ll mod)
{
    base = base % mod;
    ll res = 1;
    while (exp)
    {
        if (exp & 1)
        {
            res = ((res % mod) * (base % mod)) % mod;
        }
        base = ((base % mod) * (base % mod)) % mod;
        exp >>= 1;
    }
    return res;
}
int phi[100001];
void createphi(int maxn)
{
    for (int i = 1; i <= maxn; i++)
    {
        phi[i] = i;
    }
    for (int i = 2; i * i <= maxn; i++)
    {
        if (phi[i] == i)
        {
            for (int j = i; j <= maxn; j += i)
            {
                phi[j] /= i;
                phi[j] *= (i - 1);
            }
        }
    }
}
ll fact[1000100];
void createfactorial()
{
    fact[0] = fact[1] = 1;
    for (int i = 2; i <= 1000000; i++)
    {
        fact[i] = (i * fact[i - 1]) % MOD;
    }
}
// pehle factorial create kr bhai//
ll binomial(ll n, ll k)
{
    if (k > n)
    {
        return 0;
    }
    ll res;
    res = fact[n] % MOD;
    res = (res * inverse(fact[k], MOD - 2, MOD)) % MOD;
    res = (res * inverse(fact[n - k], MOD - 2, MOD)) % MOD;
    return res;
}
// inverse(base,MOD-2,MOD)//
void nick()
{
    string s;cin>>s;
    ll ans=0;
    for(int i=0;i<s.size()-1;i++){
        ll num=(s[i]-'0')*10+(s[i+1]-'0');
        if(num%4==0){
            ans+=i+1;
        }
    }
    for(int i=0;i<s.size();i++){
        ll num=(s[i]-'0');
        if(num%4==0){
            ans+=1;
        }
    }
    cout<<ans<<endl;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    fastio();
    int t;
    t=1;
    while (t--)
    {
        nick();
    }
    return 0;
}