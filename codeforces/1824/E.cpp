// LUOGU_RID: 159980798
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

typedef long long ll;
typedef double lf;

// #define DEBUG 1
struct IO
{
    #define MAXSIZE (1 << 20)
    #define isdigit(x) (x >= '0' && x <= '9')
    char buf[MAXSIZE], *p1, *p2;
    char pbuf[MAXSIZE], *pp;
    #if DEBUG
    #else
    IO() : p1(buf), p2(buf), pp(pbuf) {}
    ~IO() {fwrite(pbuf, 1, pp - pbuf, stdout);}
    #endif
    #define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin), p1 == p2) ? ' ' : *p1++)
    #define blank(x) (x == ' ' || x == '\n' || x == '\r' || x == '\t')

    template <typename T>
    void Read(T &x)
    {
        #if DEBUG
        std::cin >> x;
        #else
        bool sign = 0; char ch = gc(); x = 0;
        for (; !isdigit(ch); ch = gc())
            if (ch == '-') sign = 1;
        for (; isdigit(ch); ch = gc()) x = x * 10 + (ch ^ 48);
        if (sign) x = -x;
        #endif
    }
    void Read(char *s)
    {
        #if DEBUG
        std::cin >> s;
        #else
        char ch = gc();
        for (; blank(ch); ch = gc());
        for (; !blank(ch); ch = gc()) *s++ = ch;
        *s = 0;
        #endif
    }
    void Read(char &c) {for (c = gc(); blank(c); c = gc());}

    void Push(const char &c)
    {
        #if DEBUG
        putchar(c);
        #else
        if (pp - pbuf == MAXSIZE) fwrite(pbuf, 1, MAXSIZE, stdout), pp = pbuf;
        *pp++ = c;
        #endif
    }
    template <typename T>
    void Write(T x)
    {
        if (x < 0) x = -x, Push('-');
        static T sta[35];
        int top = 0;
        do sta[top++] = x % 10, x /= 10; while (x);
        while (top) Push(sta[--top] ^ 48);
    }
    template <typename T>
    void Write(T x, char lst) {Write(x), Push(lst);}
} IO;
#define Read(x) IO.Read(x)
#define Write(x, y) IO.Write(x, y)
#define Put(x) IO.Push(x)

using namespace std;

const int MAXN = 2e5 + 10, M = 2e5;

int n, a[MAXN], b[MAXN], vid[MAXN];
int c[MAXN], d[MAXN], eid[MAXN];
ll ans;

int aval[MAXN << 1], valt;

struct Edge
{
    int u, v, dpt;
}e[MAXN];
vector <int> g[MAXN];

int dfn[MAXN], idx[MAXN], clk, sz[MAXN];
void DFS(int u, int t)
{
    dfn[u] = ++clk, idx[clk] = u, sz[u] = 1;
    for (auto v : g[u])
        if (v != t) DFS(v, u), sz[u] += sz[v];
}
namespace DFStree
{
    int tr[MAXN << 2];
    inline void Pushup(int cur) {tr[cur] = max(tr[cur << 1], tr[cur << 1 | 1]);}
    void Build(int cur, int l, int r) {if (l == r) tr[cur] = a[idx[l]]; else {int mid = l + r >> 1; Build(cur << 1, l, mid), Build(cur << 1 | 1, mid + 1, r), Pushup(cur);}}
    int Query(int cur, int l, int r, int x, int y) {if (x > y) return 0; if (x <= l && r <= y) return tr[cur]; int mid = l + r >> 1, res = 0; if (x <= mid) res = max(res, Query(cur << 1, l, mid, x, y)); if (y > mid) res = max(res, Query(cur << 1 | 1, mid + 1, r, x, y)); return res;}
}

struct Vtree
{
    ll sum[MAXN << 2]; int cnt[MAXN << 2];
    inline void Pushup(int cur) {sum[cur] = sum[cur << 1] + sum[cur << 1 | 1], cnt[cur] = cnt[cur << 1] + cnt[cur << 1 | 1];}
    void Update(int cur, int l, int r, int x, int k) {if (l == r) sum[cur] += l * k, cnt[cur] += k; else {int mid = l + r >> 1; if (x <= mid) Update(cur << 1, l, mid, x, k); else Update(cur << 1 | 1, mid + 1, r, x, k); Pushup(cur);}}
    ll Query(int cur, int l, int r, int x)
    {
        if (l == r) return (ll)x * l;
        int mid = l + r >> 1, rs = cnt[cur << 1 | 1];
        if (x > rs) return sum[cur << 1 | 1] + Query(cur << 1, l, mid, x - rs);
        return Query(cur << 1 | 1, mid + 1, r, x);
    }
}V, E;

int fa[MAXN], deg[MAXN];
inline int Find(int k) {return k == fa[k] ? k : fa[k] = Find(fa[k]);}

set <pair <int, int>, greater <pair <int, int>>> st[MAXN];

int main()
{
    #if DEBUG
    #else
    ios::sync_with_stdio(0), cin.tie(0);
    #endif
    Read(n);
    for (int i = 1; i <= n; i++) Read(a[i]), vid[i] = i, aval[++valt] = a[i];
    for (int i = 1; i <= n; i++) Read(b[i]);
    for (int i = 1; i < n; i++) Read(e[i].u), Read(e[i].v), Read(c[i]), Read(d[i]), g[e[i].u].push_back(e[i].v), g[e[i].v].push_back(e[i].u);
    DFS(1, 0), DFStree::Build(1, 1, n);
    for (int i = 1; i < n; i++)
    {
        if (dfn[e[i].u] > dfn[e[i].v]) swap(e[i].u, e[i].v);
        e[i].dpt = min(c[i], min(DFStree::Query(1, 1, n, dfn[e[i].v], dfn[e[i].v] + sz[e[i].v] - 1), max(DFStree::Query(1, 1, n, 1, dfn[e[i].v] - 1), DFStree::Query(1, 1, n, dfn[e[i].v] + sz[e[i].v], n))));
        eid[i] = i, aval[++valt] = c[i];
    }
    sort(vid + 1, vid + n + 1, [&](int x, int y) {return a[x] < a[y];});
    sort(eid + 1, eid + n, [&](int x, int y) {return e[x].dpt < e[y].dpt;});
    sort(aval + 1, aval + valt + 1), valt = unique(aval + 1, aval + valt + 1) - aval - 1;
    
    for (int i = 1; i <= n; i++) V.Update(1, 1, M, b[i], 1), fa[i] = i, st[i].insert(make_pair(b[i], i));
    for (int i = 1; i < n; i++) E.Update(1, 1, M, d[i], 1), deg[e[i].u]++, deg[e[i].v]++;
    int lcnt = 0; ll lsum = 0;
    for (int i = 1; i <= n; i++)
        if (deg[i] == 1)
        {
            lcnt++, lsum += b[i];
            V.Update(1, 1, M, b[i], -1);
        }
    for (int s = 1, i = 1, j = 1; s <= valt; s++)
    {
        while (j < n && e[eid[j]].dpt < aval[s])
        {
            int u = e[eid[j]].u, v = e[eid[j]].v, ru = Find(u), rv = Find(v);
            E.Update(1, 1, M, d[eid[j]], -1);
            if (st[ru].size() < st[rv].size()) swap(u, v), swap(ru, rv);
            int tu = st[ru].begin() -> second, tv = st[rv].begin() -> second;
            if (deg[ru] == 1) lsum -= b[tu];
            if (deg[rv] == 1) lsum -= b[tv];
            fa[rv] = ru; int ndeg = deg[ru] + deg[rv] - 2;
            for (auto x : st[rv]) st[ru].insert(x);
            if (ndeg == 1)
            {
                int leaf = (deg[ru] == 1 ? tu : tv);
                if (st[ru].begin() -> second != leaf) V.Update(1, 1, M, b[leaf], 1), V.Update(1, 1, M, st[ru].begin() -> first, -1), lsum += st[ru].begin() -> first;
                else lsum += b[leaf];
            }
            else
            {
                if (deg[ru] == 1) lcnt--, V.Update(1, 1, M, b[tu], 1);
                if (deg[rv] == 1) lcnt--, V.Update(1, 1, M, b[tv], 1);
            }
            deg[ru] = ndeg;
            j++;
        }
        while (i <= n && a[vid[i]] < aval[s])
        {
            int u = vid[i], rt = Find(u);
            if (deg[rt] == 1 && st[rt].begin() -> second == u)
            {
                lsum -= b[u];
                st[rt].erase(st[rt].begin());
                if (st[rt].size()) V.Update(1, 1, M, st[rt].begin() -> first, -1), lsum += st[rt].begin() -> first;
                else lcnt--;
            }
            else V.Update(1, 1, M, b[u], -1), st[rt].erase(make_pair(b[u], u));
            i++;
        }
        int ecnt = min(n - j, n - i);
        if (ecnt < 0) continue;
        ll sum = E.Query(1, 1, M, ecnt) + lsum + V.Query(1, 1, M, ecnt + 1 - lcnt);
        ans = max(ans, sum * aval[s]);
    }
    cout << ans << '\n';
    return 0;
}