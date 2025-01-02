#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define cyes cout << "YES" << endl
#define cno cout << "NO" << endl
#define cyn(x) cout << (x ? "YES\n" : "NO\n")
#define debug(x) cout << #x << " = " << x << endl
// const int mod=1e7+7;
const int INF = 0x3f3f3f3f;

int x[50], y[50];
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= 4 * n + 1; i++) {
        cin >> x[i] >> y[i];
    }
    for (int i = 1; i <= 4 * n + 1; i++) {
        int Mx = 0, mx = 50, My = 0, my = 50;
        for (int j = 1; j <= 4 * n + 1; j++)
            if (j != i) {
                Mx = max(Mx, x[j]);
                mx = min(mx, x[j]);
                My = max(My, y[j]);
                my = min(my, y[j]);
            }
        bool ok = 1;
        for (int j = 1; j <= 4 * n + 1; j++)
            if (j != i) {
                if (x[j] != mx && x[j] != Mx && y[j] != My && y[j] != my)
                    ok = 0;
            }
        if (ok && Mx - mx == My - my) {
            cout << x[i] << " " << y[i] << endl;
            return;
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
