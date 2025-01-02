// LUOGU_RID: 160085554

#include <bits/stdc++.h>
#define pb emplace_back
#define fst first
#define scd second
#define mkp make_pair
#define mems(a, x) memset((a), (x), sizeof(a))

using namespace std;
typedef long long ll;
typedef double db;
typedef unsigned long long ull;
typedef long double ldb;
typedef pair<int, int> pii;

const int maxn = 51000;

int n, m, id[26][26], ntot, f[680][maxn], g[680][maxn];
int q[maxn * 2];
char s[maxn];
vector<pii> G[maxn], T[maxn];

void solve() {
    scanf("%s%d", s + 1, &m);
    n = strlen(s + 1);
    ntot = n;
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) {
            id[i][j] = ++ntot;
        }
    }
    for (int i = 1; i < n; ++i) {
        if (i > 1) {
            G[i].pb(i - 1, 1);
            T[i].pb(i - 1, 1);
        }
        if (i + 1 < n) {
            G[i].pb(i + 1, 1);
            T[i].pb(i + 1, 1);
        }
        G[i].pb(id[s[i] - 'a'][s[i + 1] - 'a'], 1);
        T[id[s[i] - 'a'][s[i + 1] - 'a']].pb(i, 1);
        G[id[s[i] - 'a'][s[i + 1] - 'a']].pb(i, 0);
        T[i].pb(id[s[i] - 'a'][s[i + 1] - 'a'], 0);
    }
    mems(f, 0x3f);
    mems(g, 0x3f);
    for (int S = n + 1; S <= ntot; ++S) {
        int hd = maxn, tl = maxn - 1, k = S - n;
        q[++tl] = S;
        f[k][S] = 0;
        while (hd <= tl) {
            int u = q[hd++];
            for (pii p : G[u]) {
                int v = p.fst, d = p.scd;
                if (f[k][v] > f[k][u] + d) {
                    f[k][v] = f[k][u] + d;
                    if (d) {
                        q[++tl] = v;
                    } else {
                        q[--hd] = v;
                    }
                }
            }
        }
        hd = maxn;
        tl = maxn - 1;
        q[++tl] = S;
        g[k][S] = 0;
        while (hd <= tl) {
            int u = q[hd++];
            for (pii p : G[u]) {
                int v = p.fst, d = p.scd;
                if (g[k][v] > g[k][u] + d) {
                    g[k][v] = g[k][u] + d;
                    if (d) {
                        q[++tl] = v;
                    } else {
                        q[--hd] = v;
                    }
                }
            }
        }
    }
    while (m--) {
        int x, y;
        scanf("%d%d", &x, &y);
        int ans = abs(x - y);
        for (int i = 1; i <= 676; ++i) {
            ans = min(ans, g[i][x] + f[i][y] + 1);
        }
        printf("%d\n", ans);
    }
}

int main() {
    int T = 1;
    // scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}