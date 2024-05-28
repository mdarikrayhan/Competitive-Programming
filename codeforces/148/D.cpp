#include <bits/stdc++.h>
#define ll long long
#define int long long
#define ull unsigned long long
#define vb v.begin()
#define ve v.end()
#define vc v.clear()
#define vs (int)v.size()
#define ss (int)s.size()
#define sb s.back()
#define rs(i) resize(i)
#define ft first
#define sd second
#define inf 0x3f3f3f3f
#define P pair<int, int>
#define forn(i, a, b) for (int i = a; i < b; i++)
#define fore(i, a, b) for (int i = a; i <= b; i++)
#define rofn(i, a, b) for (int i = a; i > b; i--)
#define rofe(i, a, b) for (int i = a; i >= b; i--)
#define Ios ios::sync_with_stdio(false), cin.tie(0)
using namespace std;
const int mod = 1e9 + 7;
const int N = 1005;
double dp[N][N];
void solve() {
    int w, b;
    cin >> w >> b;
    fore(i, 1, w) dp[i][0] = 1;
    fore(i, 1, b) dp[0][i] = 0;
    fore(i, 1, w) {
        fore(j, 1, b) {
            dp[i][j] += 1.0 * i / (i + j);
            if (j >= 3)
                dp[i][j] += 1.0 * j / (i + j) * (j - 1) / (i + j - 1) * (j - 2) / (i + j - 2) * dp[i][j - 3];
            if (i >= 1 && j >= 2)
                dp[i][j] += 1.0 * j / (i + j) * (j - 1) / (i + j - 1) * i / (i + j - 2) * dp[i - 1][j - 2];
        }
    }
    cout << fixed << setprecision(9) << dp[w][b] << "\n";
}
signed main() {
    Ios;
    solve();
    return 0;
}