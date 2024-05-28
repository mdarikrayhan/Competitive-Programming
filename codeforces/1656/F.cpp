// LUOGU_RID: 160167250
#include <bits/stdc++.h>
#define int long long

#define F(i, a, b) for (int i = (a); i <= (b); i++)
#define dF(i, a, b) for (int i = (a); i >= (b); i--)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 200005, M = (N << 1), inf = LLONG_MAX, mod = 1e9 + 7;
int n, an, a[N], s[N];
void solve(int TC) {
    cin >> n, an = -inf;
    F(i, 1, n) cin >> a[i];
    sort(a + 1, a + n + 1);
    F(i, 1, n) s[i] = s[i - 1] + a[i];
    if (s[n - 1] + (n - 1) * a[n] < 0 || s[n] - a[1] + (n - 1) * a[1] > 0) {
        cout << "INF\n"; return ;
    }
    F(i, 1, n) {
        an = max(an, a[1] * (s[n - 1] - s[i]) - a[i] * ((n - i - 1) * a[1] + s[n - 1] - s[i]) + a[n] * (s[i]) - a[i] * (i * a[n] + s[i]));
    }
    cout << an << '\n';
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i ++) {
        solve(i);
    }
    return 0;
}
