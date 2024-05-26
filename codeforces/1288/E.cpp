#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define Acode ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define int long long
int n, m;
const int N = 1e6 + 10;
int b[N], a[N];
int c[N], d[N];

struct info
{
    int miv;
    int cnt;
};

struct node
{
    info val;
} seg[N << 2];

info operator+(const info &a, const info &b)
{
    info c;
    c.cnt = a.cnt + b.cnt;
    return c;
}

void up(int id)
{
    seg[id].val = seg[id << 1].val + seg[id << 1 | 1].val;
}

void build(int id, int l, int r) // id代表区间节点标号，l,r代表该区间节点的左右端点
{
    if (l == r)
    {
        if (l < 1 + m)
            seg[id].val = {0LL, 0LL};
        else
            seg[id].val = {a[l - m], 1};
        return;
    }
    int mid = l + r >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    up(id);
}

void change(int id, int l, int r, int x, int w)
{
    if (l == r)
    {
        if (!w)
            seg[id].val = {0LL, 0LL};
        else
            seg[id].val = {w, 1LL};
        return;
    }
    int mid = l + r >> 1;
    if (x <= mid)
        change(id << 1, l, mid, x, w);
    else
        change(id << 1 | 1, mid + 1, r, x, w);
    up(id);
}

info query(int id, int l, int r, int ql, int qr)
{
    if (ql <= l && r <= qr)
        return seg[id].val;
    int mid = l + r >> 1;
    if (qr <= mid) // 同理，查询区间属于左儿子就向左边去找 ,反之是右儿子
        return query(id << 1, l, mid, ql, qr);
    else if (ql > mid)
        return query(id << 1 | 1, mid + 1, r, ql, qr);
    else
        return query(id << 1, l, mid, ql, qr) + query(id << 1 | 1, mid + 1, r, ql, qr);
}

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        b[i + m] = i;
        a[i] = i + m;
        c[i] = d[i] = i;
    }
    build(1, 1, n + m);
    int tot = m;
    for (int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        int pos = a[x];
        b[pos] = 0;
        c[x] = 1;
        d[x] = max(d[x], query(1, 1, n + m, 1, pos).cnt);
        change(1, 1, n + m, pos, 0LL);
        change(1, 1, n + m, tot, x);
        a[x] = tot;
        b[tot] = x;
        tot--;
    }
    int res = 0;
    for (int i = 1; i <= n + m; i++)
    {
        if (b[i])
        {
            res++;
            c[b[i]] = min(c[b[i]], res);
            d[b[i]] = max(d[b[i]], res);
        }
    }
    for (int i = 1; i <= n; i++)
        cout << c[i] << " " << d[i] << endl;
}

signed main()
{
    Acode;
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}