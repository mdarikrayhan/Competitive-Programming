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
        ll n, x, ans = 0;
        cin >> n;
        vector<ll> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        reverse(v.begin(), v.end());
        for (int i = 1; i < n; i++)
        {
            if (v[i] > v[i - 1])
            {
                x = (v[i] - 1) / v[i - 1];
                ans += x;
                v[i] /= (x + 1);
            }
        }
        cout << ans << endl;
    }
    return 0;
}