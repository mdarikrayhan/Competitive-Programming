// LUOGU_RID: 159747995
#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int N = 1e5 + 5;
const int mod = 1e9 + 7, base = 114514;
int n, p[N], invp[N], k, a[N], q;
int inv(int x)
{
    int res = 1, y = mod - 2;
    while (y)
    {
        if (y & 1)
            res = (i64)res * x % mod;
        x = (i64)x * x % mod;
        y >>= 1;
    }
    return res;
}
struct node
{
    int lcnt, rcnt;
    int lval, rval;
    bool flag;
    bool operator==(const node &tmp)
    {
        return lcnt == tmp.lcnt &&
               rcnt == tmp.rcnt &&
               lval == tmp.lval &&
               rval == tmp.rval &&
               flag == tmp.flag;
    }
} st[N << 2];
#define lc cur << 1
#define rc cur << 1 | 1
int l_query(int cur, int l, int r, int siz)
{
    if (!siz)
        return 0;
    if (st[cur].lcnt == siz)
        return st[cur].lval;
    if (l == r)
        return 0;
    int mid = l + r >> 1;
    if (st[rc].lcnt >= siz)
        return l_query(rc, mid + 1, r, siz);
    auto res = make_pair(st[rc].lval, st[rc].rval);
    int nxt = l_query(lc, l, mid, siz + st[rc].rcnt - st[rc].lcnt);
    nxt = (nxt + mod - res.second) % mod;
    nxt = (i64)nxt * invp[st[rc].rcnt] % mod;
    res.first = ((i64)nxt * p[st[rc].lcnt] % mod + res.first) % mod;
    return res.first;
}
int r_query(int cur, int l, int r, int siz)
{
    if (!siz)
        return 0;
    if (st[cur].rcnt == siz)
        return st[cur].rval;
    if (l == r)
        return 0;
    int mid = l + r >> 1;
    if (st[lc].rcnt >= siz)
        return r_query(lc, l, mid, siz);
    auto res = make_pair(st[lc].rval, st[lc].lval);
    int nxt = r_query(rc, mid + 1, r, siz + st[lc].lcnt - st[lc].rcnt);
    nxt = (nxt + mod - res.second) % mod;
    nxt = (i64)nxt * invp[st[lc].lcnt] % mod;
    res.first = ((i64)nxt * p[st[lc].rcnt] % mod + res.first) % mod;
    return res.first;
}
node pushup(node l_node, node r_node, int cur, int l, int mid, int r)
{
    node res{0, 0, 0, 0, true};
    res.rcnt = l_node.rcnt + max(0, r_node.rcnt - l_node.lcnt);
    res.lcnt = r_node.lcnt + max(0, l_node.lcnt - r_node.rcnt);
    if (!l_node.flag || !r_node.flag)
    {
        res.flag = false;
        return res;
    }
    if (l_node.lcnt == r_node.rcnt)
    {
        if (l_node.lval != r_node.rval)
        {
            res.flag = false;
            return res;
        }
        res.lval = r_node.lval;
        res.rval = l_node.rval;
        return res;
    }
    if (l_node.lcnt < r_node.rcnt)
    {
        int h = r_query(rc, mid + 1, r, l_node.lcnt);
        if (h != l_node.lval)
        {
            res.flag = false;
            return res;
        }
        r_node.rval = (r_node.rval + mod - h) % mod;
        r_node.rval = (i64)r_node.rval * invp[l_node.lcnt] % mod;
        res.lval = r_node.lval;
        res.rval = (l_node.rval + (i64)r_node.rval * p[l_node.rcnt] % mod) % mod;
        return res;
    }
    else
    {
        int h = l_query(lc, l, mid, r_node.rcnt);
        if (h != r_node.rval)
        {
            res.flag = false;
            return res;
        }
        l_node.lval = (l_node.lval + mod - h) % mod;
        l_node.lval = (i64)l_node.lval * invp[r_node.rcnt] % mod;
        res.rval = l_node.rval;
        res.lval = ((i64)p[r_node.lcnt] * l_node.lval % mod + r_node.lval) % mod;
        return res;
    }
}
node query(int cur, int l, int r, int a, int b)
{
    if (a <= l && r <= b)
        return st[cur];
    int mid = l + r >> 1;
    if (b <= mid)
        return query(lc, l, mid, a, b);
    if (a > mid)
        return query(rc, mid + 1, r, a, b);
    return pushup(query(lc, l, mid, a, b), query(rc, mid + 1, r, a, b), cur, l, mid, r);
}
void build(int cur, int l, int r)
{
    if (l == r)
    {
        if (a[l] > 0)
            st[cur] = {1, 0, a[l], 0, true};
        else
            st[cur] = {0, 1, 0, -a[l], true};
        return;
    }
    int mid = l + r >> 1;
    build(lc, l, mid), build(rc, mid + 1, r);
    st[cur] = pushup(st[cur << 1], st[cur << 1 | 1], cur, l, mid, r);
}
void update(int cur, int l, int r, int p, int x)
{
    if (l == r)
    {
        if (x > 0)
            st[cur] = {1, 0, x, 0, true};
        else
            st[cur] = {0, 1, 0, -x, true};
        return;
    }
    int mid = l + r >> 1;
    if (p <= mid)
        update(lc, l, mid, p, x);
    else
        update(rc, mid + 1, r, p, x);
    st[cur] = pushup(st[cur << 1], st[cur << 1 | 1], cur, l, mid, r);
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    p[0] = invp[0] = 1;
    for (int i = 1; i <= n; i++)
        p[i] = (i64)p[i - 1] * base % mod, invp[i] = inv(p[i]);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);

    cin >> q;
    while (q--)
    {
        int opt, x, y;
        cin >> opt >> x >> y;
        if (opt == 1)
            update(1, 1, n, x, y);
        else
        {
            auto tmp = query(1, 1, n, x, y);
            if (tmp.lcnt + tmp.rcnt == 0 && tmp.flag)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }
}