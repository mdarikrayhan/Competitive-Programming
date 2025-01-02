#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define fi first
#define se second
#define mk make_pair
using namespace std;
typedef pair<int, int> PII;
const int N = 2e5 + 10;
PII p[N];
PII ans[N];
void solve() {
    int n;
    cin >> n;

    p[1] = make_pair(1, 1);
    ans[1] = make_pair(0, 1);
    int cur = 1;
    while (n--) {
        char op;
        int v, x, u, k;
        cin >> op;

        if (op == '+') {
            cin >> v >> x;
            cur++;
            int l = x, r = x;
            if (x == 1) {
                l = min(l, p[v].fi + 1);
                r = max(r, p[v].se + 1);
                p[cur] = mk(l, r);
                ans[cur] = mk(min(l, ans[v].fi), max(r, ans[v].se));
            } else {
                l = min(l, p[v].fi - 1);
                r = max(r, p[v].se - 1);
                p[cur] = mk(l, r);
                ans[cur] = mk(min(l, ans[v].fi), max(r, ans[v].se));
            }
        } else {
            cin >> u >> v >> k;
            int l = ans[v].fi;
            int r = ans[v].se;
            if (k >= l && k <= r) cout << "YES" << endl;
            else cout << "NO\n";
        }
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
