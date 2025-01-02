// LUOGU_RID: 160457349
#include <bits/stdc++.h>
#define int long long
#define ls (k << 1)
#define rs (k << 1 | 1)
using namespace std;

const int N = 2e5 + 5;
int n, m, num, head[N], f[N], fd[N], dep[N], siz[N], top[N], id[N], w[N], a[N], son[N], cnt, s, ans = 1e18, ans1, tmax, tid, h[N];
bool us[N];

struct edge
{
    int u, v, w, nxt;
} e[N << 1];

struct bian
{
    int u, v, w, c, id;
} b[N];

void add(int u, int v, int w)
{
    e[++num].nxt = head[u];
    e[num].v = v;
    e[num].u = u;
    e[num].w = w;
    head[u] = num;
}

int find(int x) { return fd[x] == x ? x : fd[x] = find(fd[x]); }

bool cmp(bian x, bian y) { return x.w < y.w; }

struct TREE
{
    struct Tree
    {
        int l, r, maxx, maxxid;
    } t[N << 2];

    void pushup(int k)
    {
        t[k].maxx = max(t[ls].maxx, t[rs].maxx);
        if (t[ls].maxx > t[rs].maxx)
            t[k].maxxid = t[ls].maxxid;
        else
            t[k].maxxid = t[rs].maxxid;
    }

    void build(int l, int r, int k)
    {
        t[k].l = l, t[k].r = r;
        if (l == r)
        {
            t[k].maxx = w[l];
            t[k].maxxid = l;
            return;
        }
        int mid = (l + r) >> 1;
        build(l, mid, ls);
        build(mid + 1, r, rs);
        pushup(k);
    }

    void find(int l, int r, int k)
    {
        if (t[k].l >= l && t[k].r <= r)
        {
            if (t[k].maxx > tmax)
                tmax = t[k].maxx, tid = t[k].maxxid;
            return;
        }
        int mid = (t[k].l + t[k].r) >> 1;
        if (l <= mid)
            find(l, r, ls);
        if (r > mid)
            find(l, r, rs);
        return;
    }
} T;

void dfs1(int x, int fa, int deep)
{
    f[x] = fa, dep[x] = deep, siz[x] = 1;
    int mson = -1;
    for (int i = head[x]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (v == fa)
            continue;
        dfs1(v, x, deep + 1);
        a[v] = e[i].w;
        siz[x] += siz[v];
        if (siz[v] > mson)
            mson = siz[v], son[x] = v;
    }
}

void dfs2(int x, int topf)
{
    top[x] = topf, id[x] = ++cnt, w[cnt] = a[x], h[cnt] = x;
    if (!son[x])
        return;
    dfs2(son[x], topf);
    for (int i = head[x]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (v == f[x] || v == son[x])
            continue;
        dfs2(v, v);
    }
}

void lca(int x, int y)
{
    tmax = tid = 0;
    while (top[x] != top[y])
    {
        if (dep[top[x]] < dep[top[y]])
            swap(x, y);

        T.find(id[top[x]], id[x], 1);
        // cout << tot << endl;
        x = f[top[x]];
    }
    if (dep[x] > dep[y])
        swap(x, y);
    T.find(id[x] + 1, id[y], 1);
}

signed main()
{
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= m; i++)
        scanf("%lld", &b[i].w), b[i].id = i;
    for (int i = 1; i <= m; i++)
        scanf("%lld", &b[i].c);
    for (int i = 1; i <= m; i++)
        scanf("%lld%lld", &b[i].u, &b[i].v);
    scanf("%lld", &s);
    sort(b + 1, b + 1 + m, cmp);
    for (int i = 1; i <= n; i++)
        fd[i] = i;
    int sum = 0, ct = 0, delu = 0, delv = 0;
    for (int i = 1; i <= m; i++)
    {
        int u = b[i].u, v = b[i].v;
        int xx = find(u), yy = find(v);
        if (xx != yy)
        {
            fd[xx] = yy;
            sum += b[i].w;
            ct++;
            us[i] = 1;
        }
        if (ct == n - 1)
            break;
    }
    // cout << sum << endl;
    for (int i = 1; i <= m; i++)
    {
        if (us[i])
        {
            int minus = s / b[i].c;
            if (ans > sum - minus)
                ans = sum - minus, ans1 = i;
            add(b[i].u, b[i].v, b[i].w);
            add(b[i].v, b[i].u, b[i].w);
            // cout << b[i].id << ":";
            // cout << b[i].u << " " << b[i].v << " " << b[i].w << endl;
            //  cout << ans << " " << ans1 << endl;
        }
        // cout << i << endl;
    }
    // cout << "&"<<endl;
    dfs1(1, 0, 1);
    dfs2(1, 1);
    T.build(1, n, 1);
    // cout << "%"<<endl;
    bool fg = 0;
    for (int i = 1; i <= m; i++)
    {
        if (us[i])
            continue;
        int u = b[i].u, v = b[i].v;
        int minus = b[i].w - (s / b[i].c);
        lca(u, v);
        // cout << tmax <<" "<<b[tid].id<< endl;
        if (ans > sum - tmax + minus)
        {
            ans = sum - tmax + minus, ans1 = i, fg = 1;
            delv = h[tid];
            delu = f[h[tid]];
        }
    }
    printf("%lld\n", ans);
    if (fg == 0)
    {
        for (int i = 1; i <= m; i++)
        {
            if (!us[i])
                continue;
            if (i == ans1)
                printf("%lld %lld\n", b[i].id, b[i].w - (s / b[i].c));
            else
                printf("%lld %lld\n", b[i].id, b[i].w);
        }
    }
    else
    {
        // cout << ans << " " << ans1 << endl;
        // cout << b[del].id << endl;
        for (int i = 1; i <= m; i++)
        {
            if (ans1 == i)
            {
                printf("%lld %lld\n", b[i].id, b[i].w - (s / b[i].c));
                continue;
            }
            if ((b[i].u == delu && b[i].v == delv) || (b[i].v == delu && b[i].u == delv))
                continue;
            if (us[i])
                printf("%lld %lld\n", b[i].id, b[i].w);
        }
    }
}
/*
1 2
2 3
3 5
3 6
4 5
*/