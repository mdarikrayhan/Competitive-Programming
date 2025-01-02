// Written by :- Shekhar1608
// Idhar kyu aaya hai be!!
// Ab aa hi gaya hai toh dekh le code

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define vll vector<ll>
#define sll set<ll>
#define mpll map<ll, ll>
#define fr(i, a, b) for (ll i = a; i < b; i++)
#define frb(i, a, b) for (ll i = a; i >= b; i--)
#define frq(i, a, b) for (ll i = a; i <= b; i++)
#define vi vector<int>
#define vpll vector<pair<ll, ll>>
#define mp make_pair
#define vs vector<string>
#define srt(a) sort(a.begin(), a.end())
#define all(a) a.begin(), a.end()
#define rev(a) reverse(a.begin(), a.end())
#define fnd(vec, n) find(vec.begin(), vec.end(), n)
#define el cout << endl
#define ln length()
#define fi first
#define se second
#define pb push_back
#define cy cout << "Yes" << endl
#define cn cout << "No" << endl
#define minv(v) *min_element(v.begin(), v.end())
#define maxv(v) *max_element(v.begin(), v.end())
#define print(ans) cout << ans << endl
#define prints(ans) cout << ans << " "
#define jake(v) for (auto it = v.begin(); it != v.end(); it++)
#define read(input) cin >> input
ll mod = 1e9 + 7;
bool is_prime[1000005];
void sieve_of_eratosthenes(int n)
{
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= n; p++)
    {
        if (is_prime[p])
        {
            for (int i = p * p; i <= n; i += p)
            {
                is_prime[i] = false;
            }
        }
    }
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    vll a(n);
    // a.pb(0);
    // while (n--)
    // {
    //     ll x;
    //     cin >> x;
    //     a.pb(x);
    // }
    fr(i, 0, n) cin >> a[i];
    ll sum = 0;
    while (m--)
    {
        ll x, y;
        cin >> x >> y;
        x--;
        y--;
        sum += min(a[x], a[y]);
    }
    print(sum);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}