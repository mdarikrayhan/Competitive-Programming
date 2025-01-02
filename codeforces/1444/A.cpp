#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(__null);
using namespace std;

void sol()
{
    int p, q;
    cin >> p >> q;
    
    if (p % q) {
        cout << p << endl;
        return;
    }
    
    int t = q;
    int ans = 0;
    for (int i = 2; i * i <= t; i++) {
        if (t % i == 0) {
            while (t % i == 0) {
                t /= i;
            }
            int k = p;
            while (k % q == 0) {
                k /= i;
                if (k % q) {
                    ans = max(ans, k);
                    break;
                }
            }
        }
    }
    if (t > 1) {
        int k = p;
            while (k % q == 0) {
                k /= t;
                if (k % q) {
                    ans = max(ans, k);
                    break;
                }
            }
    }
    
    cout << ans << endl;
}

signed main()
{
    fastio()
    
        int k;
    k = 1;
    cin >> k;
    while (k--)
        sol();
    return 0;
}