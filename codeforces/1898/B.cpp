#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        ll n, ans = 0;
        cin >> n;
        vector<ll> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        for (int i = n - 2; i >= 0; i--)
        {
            if (v[i] > v[i + 1])
            {
                ll x = (v[i] - 1) / v[i + 1];
                ans += x;
                x++;
                v[i] = v[i] / x;
            }
        }
        cout << ans << endl;
    }
    return 0;
}