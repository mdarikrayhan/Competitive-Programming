/*______In the Name of God_____*/
/**
 * Author:  Mahatab Sheikh
 */
#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
#include "debug.h"
#else
#define dbg(x...)
#endif
#define fastInOut ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int int64_t
#define endl '\n'
typedef long long ll;

void solve()
{
     ll n;
     cin >> n;
     ll a = 0, ans = 0, x = n;
     while (x > 9) {
        a *= 10;
        a += 9;
        x -= 9;
        x /= 10;
        ans += 9;
     }
     ll b = n - a;
     dbg (a, b)
     while (b) {
        ans += b % 10;
        b /= 10;
     }
     cout << ans << endl;
}

int32_t main()
{
        fastInOut;
        int t = 1;
        ///int t; cin >> t;
        for ( int _ = 1; _ <= t; _ ++ ) {
          solve();
        }
        return 0;
}
