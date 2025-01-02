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

const int MAXN = 2e6 + 5;
const int MOD = 1e9 + 7;
const ll oo = 1ll * MOD * MOD;
const long double eps = 1e-9;

string s;
char a[MAXN];
int n;
dl f[MAXN][2];

void rf() {
    cin >> s;
}

bool check(dl mid) {
    f[0][1] = 0, f[0][0] = -mid;

    fu(i, 1, n) {
        f[i][0] = max(f[i - 1][0] + (a[i] == 'L') - mid - mid, f[i - 1][1] + (a[i] == 'L') - mid);
        f[i][1] = max(f[i - 1][1] + (a[i] == 'R') - mid - mid, f[i - 1][0] + (a[i] == 'R') - mid);
    }
    return max(f[n][0] - mid, f[n][1]) >= 0;
}

void solve() {
    int m = s.size() - 1;
    if(s[0] == s[m] && s[0] == 'R') a[++n] = 'X';
    a[++n] = s[0];
    fu(i, 1, m) {
        if (s[i] == s[i - 1] && s[i] != 'X') a[++n] = 'X';
        a[++n] = s[i];
    }
    if (s[0] == s[m] && s[0] == 'L') a[++n] = 'X';

    dl l = 0, r = 100, res;
    while (r - l > eps) {
        dl mid = (l + r) / 2;

        if (check(mid / 100.0)) l = mid, res = mid;
        else r = mid;
    }

    printf("%.6lf",(int)(r*1e6)/(1e6));
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

