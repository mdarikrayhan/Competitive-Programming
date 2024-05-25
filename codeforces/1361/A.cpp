#include <bits/stdc++.h>
#include <math.h>
#define ll long long
#define ull unsigned long long
#define ld long double
using namespace std;
const ll M = 1e9 + 7;
ll inv(ll i)
{
    if (i <= 1)
        return 1;
    return (M - ((M / i) * inv(M % i)) % M) % M;
}
ll mult_m(ll a, ll b)
{
    a = a % M;
    b = b % M;
    return (((a * b) % M) + M) % M;
}
ll add_m(ll a, ll b)
{
    a = a % M;
    b = b % M;
    return (((a + b) % M) + M) % M;
}
ll ceil(ll a, ll b) { return a % b == 0 ? a / b : a / b + 1; }
ll bin_exp(ll a, ll b)
{
    a %= M;
    ll tem = 1;
    while (b > 0)
    {
        if (b & 1)
            tem = tem * a % M;
        a = a * a % M;
        b >>= 1;
    }
    return tem;
}
vector<ll> primes;
void SieveOfEratosthenes(int n)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (int p = 2; p <= n; p++)
        if (prime[p])
            primes.push_back(p);
}
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> g[n + 1];
    for (int i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<pair<ll, ll>> v(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i].first;
        v[i].second = i;
    }
    // cout<<"HI";
    for(int i=1;i<=n;i++)
    {
        set<ll> s;
        for(auto &x:g[i])
        {
            s.insert(v[x].first);
        }
        ll cnt=1;
        for(auto &x:s)
        {
            if(x!=cnt)
            {
                break;
            }
            cnt++;
        }
        if(cnt!=v[i].first)
        {
            cout<<-1<<endl;
            return;
        }
    }
    sort(v.begin(),v.end());
    for(int i=1;i<=n;i++)
    {
        cout<<v[i].second<<" ";
    }
    cout<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}