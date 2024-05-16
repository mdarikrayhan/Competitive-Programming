#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve()
{
    ll n, k;
    cin >> n >> k;
    ll a[n];
    multiset<ll> s;
    for (ll &i : a)
        cin >> i, s.insert(i);
    ll w[k];
    for (ll &i : w)
        cin >> i;
    ll ans = 0;
    sort(w, w + k);
    for (ll &i : w)
    {
        if (i == 1)
            ans += *s.rbegin() * 2, s.erase(--s.end());
        else
            ans += *s.rbegin(), s.erase(--s.end());
        i--;
    }
    sort(w, w + k, greater());
    for (ll i : w)
    if (i)
    {
        ans += *s.begin();
        s.erase(s.begin());
        for (ll j = 0; j < i - 1; j++)
            s.erase(s.begin());
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t = 1;
    // precomp();
    cin >> t;
    for (ll cs = 1; cs <= t; cs++)
        solve();
    // cerr << "\nTime elapsed: " << clock() * 1000.0 / CLOCKS_PER_SEC << " ms\n";
}