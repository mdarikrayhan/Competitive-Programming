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

const int maxn = 1.5e5 + 20;
int n, a[maxn];
ll ans;

vector<int> g[maxn];

#define ls (u << 1)
#define rs (ls | 1)
#define mid ((l + r) >> 1)

struct Line {
    ll k, b;
    Line (ll k = 0ll, ll b = 0ll):
        k (k), b (b) {}
    ll calc (int p) const {
        return k * p + b;
    }
};

const int maxtrnum = 4 * maxn;
int trnum; Line tr[maxtrnum];
bool tag[2 * maxtrnum];

// void build (int u, int l, int r) {
//     tr[u] = {};
//     if (l == r) return;
//     build (ls, l, mid);
//     build (rs, mid + 1, r);
// }

void modify (int u, int l, int r, Line line) {
    if (tag[u]) { tr[u] = line; tag[ls] = tag[rs] = 1; tag[u] = 0; return; }
    if (tr[u].calc (mid) < line.calc (mid)) swap (tr[u], line);
    if (tr[u].calc (l) < line.calc (l)) modify (ls, l, mid, line);
    if (tr[u].calc (r) < line.calc (r)) modify (rs, mid + 1, r, line);
}

ll query (int u, int l, int r, int p) {
    if (l == r) return tr[u].calc (p);
    if (tag[u]) return 0ll;
    return max (
        tr[u].calc (p), p <= mid ?
        query (ls, l, mid, p) :
        query (rs, mid + 1, r, p));
}

#undef ls
#undef rs
#undef mid

int rt, tot, siz[maxn], szmx[maxn];
bool vis[maxn];

void findrt (int u) {
    siz[u] = 1; szmx[u] = 0;
    vis[u] = 1;
    for (int v : g[u]) {
        if (!vis[v]) {
            findrt (v);
            siz[u] += siz[v];
            chmax (szmx[u], siz[v]);
        }
    }
    vis[u] = 0;
    chmax (szmx[u], tot - siz[u]);
    if (szmx[u] < szmx[rt]) rt = u;
}

int nu, tarr;
ll sarr[maxn], xsarr[maxn];

void caldfs (int u, int d, ll sum, ll xsum) {
    bool flag = 0; sum += a[u]; xsum += sum;
    vis[u] = 1;
    for (int v : g[u]) {
        if (!vis[v]) {
            flag = 1; caldfs (v, d + 1, sum, xsum);
        }
    }
    vis[u] = 0;
    if (!flag) {
        chmax (ans, query (1, 0, trnum, d) + xsum);
        ++tarr;
        sarr[tarr] = sum + a[nu];
        xsarr[tarr] = sum * (d + 2) - xsum + a[nu];
    }
}

int top, stk[maxn];

void dvd (int u) {
    int ntot = trnum = tot;
    vis[nu = u] = 1;
    tag[1] = 1;
    modify (1, 0, trnum, Line (a[u], a[u]));
    for (int v : g[u]) {
        if (!vis[v]) {
            stk[++top] = v;
            tarr = 0;
            caldfs (v, 1, 0ll, 0ll);
            for (int i = 1; i <= tarr; ++i) {
                modify (1, 0, trnum, Line (sarr[i], xsarr[i]));
            }
        }
    }
    chmax (ans, query (1, 0, trnum, 0));
    tag[1] = 1;
    modify (1, 0, trnum, Line (a[u], a[u]));
    while (top) {
        tarr = 0;
        caldfs (stk[top--], 1, 0ll, 0ll);
        for (int i = 1; i <= tarr; ++i) {
            modify (1, 0, trnum, Line (sarr[i], xsarr[i]));
        }
    }
    chmax (ans, query (1, 0, trnum, 0));
    for (int v : g[u]) {
        if (!vis[v]) {
            tot = siz[v] > siz[u] ? ntot - siz[u] : siz[v];
            rt = 0; findrt (v); dvd (rt);
        }
    }
}

void solve () {
    scanf ("%d", &n);

    for (int i = 1, u, v; i < n; ++i) {
        scanf ("%d%d", &u, &v);
        g[u].emplace_back (v);
        g[v].emplace_back (u);
    }

    for (int i = 1; i <= n; ++i) {
        scanf ("%d", &a[i]);
    }

    szmx[rt = 0] = tot = n;
    findrt (1); dvd (rt);

    printf ("%lld\n", ans);
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