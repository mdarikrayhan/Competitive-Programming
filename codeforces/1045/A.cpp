// LUOGU_RID: 160026860
#include <bits/stdc++.h>
#define FileIO_(file) \
    freopen (file ".in", "r", stdin); \
    freopen (file ".out", "w", stdout);

using namespace std;

template<typename Tp>
inline void chmin (Tp &x, const Tp &y) { if (y < x) x = y; }
template<typename Tp>
inline void chmax (Tp &x, const Tp &y) { if (x < y) x = y; }

typedef double dbl;
typedef long long ll;
typedef long double ldb;

void init () {}

const int maxn = 5e3 + 20;
const int maxm = 5e3 + 20;
const int maxvcnt = 3e4 + 20;
const int maxecnt = 1e5 + 20;
const int s = 2e4 + 20, t = s - 1;
const int inf = 0x3f3f3f3f;
int n, m, ans;
int op[maxn], wp[maxm], cnt[maxn];
int a[maxn], b[maxn], c[maxn];

int ecnt, h[maxvcnt];

struct Edge {
    int w, to, nxt;
} e[2 * maxecnt];

void addEdge (int u, int v, int w) {
    e[ecnt] = {w, v, h[u]}; h[u] = ecnt++;
}

void link (int u, int v, int w) {
    addEdge (u, v, w); addEdge (v, u, 0);
}

#define ls (u << 1)
#define rs (ls | 1)
#define mid ((l + r) >> 1)

const int maxtrnum = 4 * maxm;
int id[maxn], di[maxtrnum];

void build (int u, int l, int r) {
    if (l == r) return link (id[di[u] = l] = u, t, 1);
    link (u, ls, inf); link (u, rs, inf);
    build (ls, l, mid); build (rs, mid + 1, r);
}

void link (int u, int l, int r, int x, int y, int p) {
    if (y < l || r < x) return;
    if (x <= l && r <= y) return link (p, u, 1);
    link (ls, l, mid, x, y, p);
    link (rs, mid + 1, r, x, y, p);
}

#undef ls
#undef rs
#undef mid

int cur[maxvcnt], dis[maxvcnt];

bool bfs () {
    memset (dis, ~0, sizeof (dis)); dis[s] = 0;
    queue<int> q; q.emplace (s);

    while (!q.empty ()) {
        int u = q.front (); q.pop ();
        for (int i = cur[u] = h[u]; ~i; i = e[i].nxt) {
            int v = e[i].to;
            if (e[i].w && !~dis[v]) {
                dis[v] = dis[u] + 1;
                q.emplace (v);
            }
        }
    }

    // cerr << dis[t] << endl;

    return ~dis[t];
}

int dfs (int u, int flow) {
    if (u == t) return flow;
    int res = 0;
    for (int &i = cur[u]; ~i; i = e[i].nxt) {
        int v = e[i].to, &w = e[i].w;
        if (!w || (v != t && dis[v] != dis[u] + 1)) continue;
        int ext = dfs (v, min (w, flow - res));
        w -= ext; e[i ^ 1].w += ext;
        if ((res += ext) == flow) break;
    }
    return res;
}

void solve () {
    scanf ("%d%d", &n, &m);

    memset (h, ~0, sizeof (h));
    build (1, 1, m);

    for (int i = 1; i <= n; ++i) {
        scanf ("%d", &op[i]);
        if (op[i] == 0) {
            link (s, s + i, 1);
            static int k;
            scanf ("%d", &k);
            for (int j = 1, u; j <= k; ++j) {
                scanf ("%d", &u);
                link (s + i, id[u], 1);
            }
        } else if (op[i] == 1) {
            link (s, s + i, 1);
            static int l, r;
            scanf ("%d%d", &l, &r);
            link (1, 1, m, l, r, s + i);
        } else {
            link (s, s + i, 2);
            scanf ("%d%d%d", &a[i], &b[i], &c[i]);
            link (s + i, id[a[i]], 1);
            link (s + i, id[b[i]], 1);
            link (s + i, id[c[i]], 1);
        }
    }

    while (bfs ()) ans += dfs (s, inf);

    printf ("%d\n", ans);
    
    for (int i = h[t]; ~i; i = e[i].nxt) {
        if (!e[i].w) continue;
        int u = di[e[i].to];
        for (int v = e[i].to; v != s; ) {
            for (int j = h[v]; ~j; j = e[j].nxt) {
                if (j & 1 && e[j].w) {
                    if (e[j].to == s)
                        ++cnt[wp[u] = v - s];
                    v = e[j].to; --e[j].w;
                    break;
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (op[i] == 2 && cnt[i] == 1) {
            wp[wp[a[i]] != i ? a[i] : b[i]] = i;
        }
    }

    for (int i = 1; i <= m; ++i) {
        if (wp[i]) {
            printf ("%d %d\n", wp[i], i);
        }
    }
}

int main () {
    // #ifndef LSY
    // FileIO_("");
    // #endif
    int t = 1; init ();
    // scanf ("%d", &t);
    while (t--) solve ();
    return 0;
}

// #ifdef LSY
// bool ed, debug = [] () {
//     static bool st; int memtyp = 0; dbl memsiz = &st - &ed;
//     static const string memstr[] = {"B", "KB", "MB", "GB"};
//     while (memsiz >= 1024.) { ++memtyp; memsiz /= 1024.; }
//     cerr << "Memory: " << memsiz << memstr[memtyp] << endl;
//     return atexit ([] () { cerr << "Time: " << 1000. *
// 		clock () / CLOCKS_PER_SEC << "ms" << endl; });
// } ();
// #endif