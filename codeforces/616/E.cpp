#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
ll l, r, x, ans;
ll dls2(ll i)
{
    return ((i % mod) * ((i + 1) % mod) / 2) % mod;
}
ll dls(ll l, ll r)
{
    return (dls2(r) - dls2(l - 1)) % mod;
}
void solve()
{
    ans += (mod - (dls(l, r) * x) % mod);
    ans %= mod;
}
int main()
{
    ll n, m;
    cin >> n >> m;
    ans = (n % mod) * (m % mod) % mod;
    m = min(m, n);
    for (l = 1; l <= m; l = r + 1)
    {
        x = n / l;
        r = min(m, n / x);
        solve();
    }
    cout << ans << endl;
}
