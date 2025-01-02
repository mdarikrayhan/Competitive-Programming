#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define YES cout << "YES" \
                 << "\n";
#define NO cout << "NO" \
                << "\n";
#define endl "\n"

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    if (n == 1)
    {
        cout << "1" << endl;
        return;
    }
    sort(v.begin(), v.end());
    int a = v[n - 1];
    int x = 1;
    int gcd = a - v[0];

    for (int i = 0; i < n - 1; i++)
    {
        gcd = __gcd(gcd, a - v[i]);
    }

    x = gcd;

    int ans = 0;

    for (auto &i : v)
    {
        ans += (a - i) / x;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (v[i] != a)
        {
            break;
        }
        ans++;
        a -= x;
    }

    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    //  t1=t;
    while (t--)
    {
        solve();
    }
    return 0;
}
