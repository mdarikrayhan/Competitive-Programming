// Hydro submission #664f2a48bf5c09e48a9140df@1716464201206
#include <bits/stdc++.h>
using namespace std;
int n, k;
int h[500005], s[500005];
struct edge
{
    int from, to;
} e[500005 << 1];
int head[500005], Stree;
void addedge(int x, int y)
{
    e[++Stree].to = y;
    e[Stree].from = head[x], head[x] = Stree;
}
int L(int x)
{
    return lower_bound(s + 1, s + 1 + k, x) - s;
}
int R(int x)
{
    return upper_bound(s + 1, s + 1 + k, x) - s - 1;
}
int minn[500005], minn_[500005], f[500005];
void dfs(int now, int fa)
{
    f[now] = fa;
    minn[now] = minn[fa], minn_[now] = minn_[fa];
    if (h[now] < minn[now])
        minn_[now] = minn[now], minn[now] = h[now];
    else
        minn_[now] = min(minn_[now], h[now]);
    for (int i = head[now]; i; i = e[i].from)
    {
        int u = e[i].to;
        if (u == fa)
            continue;
        dfs(u, now);
    }
}
vector<int> vec[500005];
void dfs2(int now, int fa, int F)
{
    if (now == F && minn[fa] <= h[now])
        return;
    vec[F].push_back(now);
    for (int i = head[now]; i; i = e[i].from)
    {
        int u = e[i].to;
        if (u == fa)
            continue;
        if (h[u] > h[F])
            dfs2(u, now, F);
    }
}
struct SGT
{
    int tree[500005 << 2], tag[500005 << 2];
#define ls (now << 1)
#define rs (now << 1 | 1)
#define mid ((l + r) >> 1)
    void pushtag(int now, int val)
    {
        tree[now] += val, tag[now] += val;
    }
    void pushdown(int now)
    {
        if (tag[now])
        {
            pushtag(ls, tag[now]);
            pushtag(rs, tag[now]);
            tag[now] = 0;
        }
    }
    void add(int now, int l, int r, int x, int y, int val)
    {
        if (x > y)
            return;
        if (l >= x && r <= y)
        {
            pushtag(now, val);
            return;
        }
        pushdown(now);
        if (mid >= x)
            add(ls, l, mid, x, y, val);
        if (mid < y)
            add(rs, mid + 1, r, x, y, val);
        tree[now] = min(tree[ls], tree[rs]);
    }
    int ask()
    {
        return tree[1];
    }
    void build(int now, int l, int r)
    {
        if (l == r)
        {
            tree[now] = -(k - l + 1);
            return;
        }
        build(ls, l, mid);
        build(rs, mid + 1, r);
        tree[now] = min(tree[ls], tree[rs]);
    }
} T;
int c[500005];
int lim;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        addedge(x, y), addedge(y, x);
    }
    cin >> k;
    for (int i = 1; i <= k; i++)
        cin >> s[i];
    sort(s + 1, s + 1 + k);
    minn[0] = minn_[0] = 1e9 + 1;
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
        dfs2(i, f[i], i);
    T.build(1, 1, k);
    for (int i = 1; i <= n; i++)
    {
        int pos = R(minn[i]);
        T.add(1, 1, k, 1, pos, 1);
        c[pos]++;
    }
    for (int i = k; i; i--)
    {
        c[i] += c[i + 1];
        if (c[i] < k - i + 1)
        {
            lim = max(lim, s[i]);
        }
    }
    int ans = 1e9;
    if (!lim)
    {

        cout << 0;
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        if (h[i] > lim)
            continue;
        for (int u : vec[i])
        {
            T.add(1, 1, k, L(minn[u] + 1), R(min(minn_[u], lim)), 1);
        }
        if (T.ask() >= 0)
        {
            ans = min(ans, lim - h[i]);
        }
        for (int u : vec[i])
        {
            T.add(1, 1, k, L(minn[u] + 1), R(min(minn_[u], lim)), -1);
        }
    }
    if (ans == 1e9)
        cout << -1;
    else
        cout << ans;
}