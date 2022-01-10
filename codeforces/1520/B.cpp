/***************************************************/
/*https://codeforces.com/problemset/problem/1520/B */
/*            Author : Md. Arik Rayhan             */
/*        Github : github.com/mdarikrayhan         */
/***************************************************/
#include <bits/stdc++.h>
typedef long long int ll;
const unsigned int MOD = 1000000007;
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    for (int tt = 0; tt < t; tt++)
    {
        ll n;
        cin >> n;
        ll ans = 0;
        for (ll i = 1; i <= 9; i++)
        {
            for (ll j = i; j <= n;)
            {
                ans++;
                j = (j * 10) + i;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}