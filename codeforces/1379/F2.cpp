// LUOGU_RID: 160462253
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 200005;
int n, m, q;
struct Tree
{
    int lm[N << 2], rm[N << 2];
    bool ok[N << 2];
    set<int> pl[N], pr[N];
    void build(int rt, int l, int r)
    {
        lm[rt] = m + 1, rm[rt] = 0, ok[rt] = 1;
        if (l == r)
        {
            pl[l].insert(m + 1);
            pr[l].insert(0);
            return;
        }
        int mid = l + r >> 1;
        build(rt << 1, l, mid), build(rt << 1 | 1, mid + 1, r);
    }
    void update(int rt, int l, int r, int s, int op, int x)
    {
        if (l == r)
        {
            if (op == 1)
            {
                if (pl[l].count(x))
                    pl[l].erase(x);
                else
                    pl[l].insert(x);
                lm[rt] = *pl[l].begin();
            }
            else
            {
                if (pr[l].count(x))
                    pr[l].erase(x);
                else
                    pr[l].insert(x);
                rm[rt] = *pr[l].rbegin();
            }
            ok[rt] = lm[rt] > rm[rt];
            return;
        }
        int mid = l + r >> 1;
        if (s <= mid)
            update(rt << 1, l, mid, s, op, x);
        else
            update(rt << 1 | 1, mid + 1, r, s, op, x);
        lm[rt] = min(lm[rt << 1], lm[rt << 1 | 1]), rm[rt] = max(rm[rt << 1], rm[rt << 1 | 1]), ok[rt] = ok[rt << 1] && ok[rt << 1 | 1] && lm[rt << 1] > rm[rt << 1 | 1];
    }
} tree;
signed main()
{
    scanf("%lld%lld%lld", &n, &m, &q);
    tree.build(1, 1, n);
    for (int i = 1; i <= q; i++)
    {
        int x, y, a, b, op;
        scanf("%lld%lld", &a, &b);
        x = a + 1 >> 1, y = b + 1 >> 1, op = a & 1;
        tree.update(1, 1, n, x, op, y);
        printf("%s\n", tree.ok[1] ? "YES" : "NO");
    }

    return 0;
}