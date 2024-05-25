#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

ll modPow(ll base, ll exponent, ll modulus)
{
    ll result = 1;
    base %= modulus;
    while (exponent > 0)
    {
        if (exponent & 1)
            result = (result * base) % modulus;
        exponent >>= 1;
        base = (base * base) % modulus;
    }
    return result;
}

ll gcd(ll a, ll b)
{
    while (b)
    {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

ll lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}

ll factorial(ll n)
{
    ll result = 1;
    for (ll i = 2; i <= n; ++i)
    {
        result *= i;
    }
    return result;
}

ll nCr(ll n, ll r)
{
    ll result = 1;
    for (ll i = 1; i <= r; ++i)
    {
        result = result * (n - i + 1) / i;
    }
    return result;
}

ll nPr(ll n, ll r)
{
    ll result = 1;
    for (ll i = 0; i < r; ++i)
    {
        result *= (n - i);
    }
    return result;
}

bool isPrime(ll n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (ll i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}
// ordered set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

void fastInput()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void fastOutput()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool checkCycle(ll ind, vector<ll> &vis, vector<ll> adj[], ll par)
{
    vis[ind] = 1;
    bool ans = false;
    for (auto it : adj[ind])
    {
        if (vis[it] == 1)
        {
            if (it != par)
            {
                ans = true;
                // ans = (checkCycle(it, vis, adj, ind) | ans);
            }
        }
        else
        {
            ans = (checkCycle(it, vis, adj, ind) | ans);
        }
    }
    return ans;
}

int main()
{
    fastInput();
    fastOutput();
    // Your competitive programming logic here
    ll n, m;
    cin >> n >> m;
    vector<ll> adj[n];
    for (ll i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<ll> vis(n, 0);
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            if (checkCycle(i, vis, adj, i) == false)
            {
                ans++;
            }
        }
    }
    cout << ans << endl;

    return 0;
}