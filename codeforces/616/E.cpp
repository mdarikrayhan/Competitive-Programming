#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
ll dls(ll i)
{
    return ((i % mod) * ((i + 1) % mod) / 2) % mod;
}
int main()
{
    ll n, m,ans;
    cin >> n >> m;
    ans = (n % mod) * (m % mod) % mod;
    m = min(m, n);
    for (ll l = 1,r=0; l <= m; l = r + 1)
    {
        ll x = n / l;
        r = min(m, n / x);

        //cout<<l<<" "<<r<<endl;

        ll a=((r % mod) * ((r + 1) % mod) / 2) % mod;
        ll b=dls(l-1);
        ll y = (a-b)%mod;

        ans += (mod - (y * x) % mod);
        ans %= mod;
    }
    cout << ans << endl;
}
