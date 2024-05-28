// LUOGU_RID: 159052797
#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef pair<int, int> pii;
const int N = 2e5 + 10, mod = 1e9 + 7;
int x[N];
double p[N];
int n, m, c;
struct SegmentTree
{
    int l, r;
    double lmax, rmax;
    double max1, sum;
} tr[N * 4];
int idx = 1;
void pushup(int u)
{
    tr[u].sum = (tr[u << 1].sum + tr[u << 1 | 1].sum);
    tr[u].max1 = max({tr[u << 1].max1, tr[u << 1 | 1].max1, tr[u << 1].rmax + tr[u << 1 | 1].lmax});
    tr[u].lmax = max({tr[u << 1].sum + tr[u << 1 | 1].lmax, tr[u << 1].lmax});
    tr[u].rmax = max({tr[u << 1 | 1].sum + tr[u << 1].rmax, tr[u << 1 | 1].rmax});
}
void pushup(SegmentTree &a, SegmentTree &b, SegmentTree &c)
{
    a.sum = b.sum + c.sum;
    a.max1 = max({b.max1, c.max1, c.lmax + b.rmax});
    a.lmax = max({b.sum + c.lmax, b.lmax});
    a.rmax = max({c.sum + b.rmax, c.rmax});
}
void build(int u, int l, int r)
{
    if (l == r)
    {
        double e = (1.0 * (x[l + 1] - x[l]) / 2 - p[l] * c);
        tr[u] = {l, r, e, e, e, e};
        return;
    }
    tr[u] = {l, r};
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}
SegmentTree ask(int u, int l, int r, int x, int y)
{
    if (x <= l && r <= y)
    {
        return tr[u];
    }
    int mid = l + r >> 1;
    SegmentTree ans, t1, t2;
    int f1 = 0, f2 = 0;
    if (mid >= x)
    {
        t1 = ask(u << 1, l, mid, x, y);
        f1 = 1;
    }

    if (mid < y)
    {
        t2 = ask(u << 1 | 1, mid + 1, r, x, y);
        f2 = 1;
    }
    if (f1 && f2)
    {
        pushup(ans, t1, t2);
        return ans;
    }
    else if (f1)
        return t1;
    else
        return t2;
}
void solve()
{

    cin >> n >> m >> c;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
    }
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> p[i];
        p[i] /= 100.0;
    }
    build(1, 1, n - 1);
    double ans = 0.0;
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        ans += max(ask(1, 1, n - 1, l, r - 1).max1, 0.0);
    }
    printf("%.10lf", ans);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    t = 1;
    // cout << idx << "\n";
    while (t--)
        solve();
    return 0;
}
