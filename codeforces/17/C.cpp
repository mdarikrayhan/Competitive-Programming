#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define BIT(n) (1ll << n)
#define GBIT(x, i) ((x >> i) & 1)
#define all(v) v.begin(), v.end()
#define eb emplace_back
#define pb push_back
#define endl '\n'

#define fu(i, l, r) for (int i = (int) (l); i <= (int) (r); i++)
#define fd(i, r, l) for (int i = (int) (r); i >= (int) (l); i--)

typedef pair <int, int> pii;
typedef pair <long long, long long> pll;
typedef unsigned long long ull;
typedef long long ll;
typedef double dl;

const int MAXN = 100 + 55;
const int MOD = 51123987;
const ll oo = 1ll * MOD * MOD;

int n, s[MAXN];

void rf() {
    cin >> n;
    fu(i, 1, n) {
        char t; cin >> t;
        s[i] = t - 'a';
    }
}

int add(int &a, int b) {
    a += b;
    if (a >= MOD) a-= MOD;
    return a;
}

int nxt[MAXN][3], dp[155][55][55][55];

void solve() {
    fd(i, n, 1) {
        fu(j, 0, 2) nxt[i][j] = nxt[i + 1][j];
        nxt[i][s[i]] = i;
    }

    dp[1][0][0][0] = 1;
    int res = 0;

    fu(i, 1, n) fu(a, 0, 50) fu(b, 0, 50) fu(c, 0, 50) {

        if (a + b + c == n && abs(a - b) <= 1 && abs(b - c) <= 1 && abs(c - a) <= 1) add(res, dp[i][a][b][c]);
        add(dp[nxt[i][0]][a + 1][b][c], dp[i][a][b][c]);
        add(dp[nxt[i][1]][a][b + 1][c], dp[i][a][b][c]);
        add(dp[nxt[i][2]][a][b][c + 1], dp[i][a][b][c]);
    }

    cout << res << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    #define task "prob"
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    int ntest = 1;
//    cin >> ntest;
    fu(i, 1, ntest) rf(), solve();
}

