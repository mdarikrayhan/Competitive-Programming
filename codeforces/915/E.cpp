// LUOGU_RID: 160063835
#include <bits/stdc++.h>

using namespace std;
const int N = 6e5 + 10;
struct Q {
    int l, r, k;
} q[N];

inline int read() {
    char c;
    bool flag = false;
    while ((c = getchar()) < '0' || c > '9') if (c == '-') flag = true;
    int res = c - '0';
    while ((c = getchar()) >= '0' && c <= '9') res = (res << 3) + (res << 1) + c - '0';
    return flag ? -res : res;
}

int ls(int p) { return p << 1; }

int rs(int p) { return p << 1 | 1; }

int b[N], sum[N << 2], tag[N << 2], tot[N << 2], len;

void pushup(int p) { sum[p] = sum[ls(p)] + sum[rs(p)]; }

void build(int p, int l, int r) {
    if (l == r) {
        tot[p] = b[l + 1] - b[l];;
        return;
    }
    int mid = (l + r) >> 1;
    build(ls(p), l, mid);
    build(rs(p), mid + 1, r);
    tot[p] = tot[ls(p)] + tot[rs(p)];
}

void pushdown(int p) {
    if (!tag[p]) return;
    if (tag[p] == 1) {
        sum[ls(p)] = tot[ls(p)], sum[rs(p)] = tot[rs(p)];
        tag[ls(p)] = tag[rs(p)] = 1;
    } else {
        sum[ls(p)] = sum[rs(p)] = 0;
        tag[ls(p)] = tag[rs(p)] = -1;
    }
    tag[p] = 0;
}

void update(int p, int lp, int rp, int l, int r, int k) {
    if (lp >= l && rp <= r) {
        if (k) sum[p] = tot[p], tag[p] = 1;
        else sum[p] = 0, tag[p] = -1;
        return;
    }
    pushdown(p);
    int mid = (lp + rp) >> 1;
    if (l <= mid) update(ls(p), lp, mid, l, r, k);
    if (r > mid) update(rs(p), mid + 1, rp, l, r, k);
    pushup(p);
}

int find(int num) { return lower_bound(b + 1, b + len + 1, num) - b; }

int main() {
    int n = read(), m = read();
    for (int i = 1; i <= m; ++i) {
        q[i].l = read();
        q[i].r = read();
        q[i].k = read();
        b[i * 2 - 1] = q[i].l;
        b[i * 2] = ++q[i].r;
    }
    sort(b + 1, b + m * 2 + 1);
    len = unique(b + 1, b + m * 2 + 1) - b - 1;
    build(1, 1, len);
    for (int i = 1; i <= m; ++i) {
        if (q[i].k == 1) update(1, 1, len, find(q[i].l), find(q[i].r) - 1, 1);
        else update(1, 1, len, find(q[i].l), find(q[i].r) - 1, 0);
        printf("%d\n", n - sum[1]);
    }
    return 0;
}