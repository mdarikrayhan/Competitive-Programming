#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define coded_by_anand_022002         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (ll &x : v)
    {
        cin >> x;
    }
    vector<ll> cnt;
    ll tmp = 0;
    ll pos = 0;
    for (ll i = n - 1; i >= 0; i--)
    {
        tmp++;
        if (v[i] < 0)
        {
            tmp--;
            cnt.push_back(tmp);
            pos += ((tmp * (tmp + 1)) / 2);
            tmp = 0;
        }
    }

    cnt.push_back(tmp);
    pos += ((tmp * (tmp + 1)) / 2);

    for (auto x : cnt)
    {
        cerr << x << " ";
    }
    cerr << pos << endl;
    for (ll i = 0; i < cnt.size(); i++)
    {
        if (i - 2 >= 0)
        {
            pos += ((cnt[i] + 1) * (cnt[i - 2] + 1));
            cnt[i] += (cnt[i - 2] + 1);
        }
    }
    cerr << pos << endl;
    cout << (n * (n + 1)) / 2 - pos << " " << pos << endl;
}

int main()
{
    coded_by_anand_022002;
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}