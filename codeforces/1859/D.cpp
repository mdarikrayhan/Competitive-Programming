#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 2e5 + 5;
int T;
int n, Q;
struct cdd {
    int l, r, a, b;
}a[maxn];
struct opt {
    int x, id, ans;
}q[maxn];
int t[maxn << 2], lazy[maxn << 2];
void build(int l, int r, int p) {
    lazy[p] = t[p] = 0;
    if (l == r) return (void)(t[p] = q[l].x);
    int mid = (l + r) >> 1;
    build(l, mid, p << 1);
    build(mid + 1, r, p << 1 | 1);
    t[p] = max(t[p << 1], t[p << 1 | 1]);
}
void pushdown(int l, int r, int p) {
    if (lazy[p]) {
        int ls = p << 1, rs = p << 1 | 1, k = lazy[p];
        t[ls] = max(t[ls], k), t[rs] = max(t[rs], k);
        lazy[ls] = max(lazy[ls], k), lazy[rs] = max(lazy[rs], k);
        lazy[p] = 0;
    }
}
void update(int l, int r, int x, int y, int k, int p) {
    if (x <= l && r <= y) {
        t[p] = max(t[p], k);
        lazy[p] = max(lazy[p], k);
        return ;
    }
    pushdown(l, r, p);
    int mid = (l + r) >> 1;
    if (x <= mid) update(l, mid, x, y, k, p << 1);
    if (y > mid) update(mid + 1, r, x, y, k, p << 1 | 1);
    t[p] = max(t[p << 1], t[p << 1 | 1]);
}
int query(int l, int r, int x, int y, int p) {
    if (x <= l && r <= y) {
        return t[p];
    }
    pushdown(l, r, p);
    int mx = 0, mid = (l + r) >> 1;
    if (x <= mid) mx = max(mx, query(l, mid, x, y, p << 1));
    if (y > mid) mx = max(mx, query(mid + 1, r, x, y, p << 1 | 1));
    t[p] = max(t[p << 1], t[p << 1 | 1]);
    return mx;
}

bool cmp1(cdd x, cdd y) {
    return x.b < y.b;
}
bool cmp2(opt x, opt y) {
    return x.x < y.x;
}
bool cmp3(opt x, opt y) {
    return x.id < y.id;
}
int read() {
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + (ch ^ 48);
       ch = getchar();
    }
    return x * w;
}
int main()
{
    T = read();
    while (T--) {
        n = read();
        for (int i = 1; i <= n; i++)
            a[i] = {read(), read(), read(), read()};
        Q = read();
        for (int i = 1; i <= Q; i++) q[i] = {read(), i, 0};

        sort(a + 1, a + 1 + n, cmp1);
        sort(q + 1, q + 1 + Q, cmp2);
        build(1, Q, 1);


        for (int i = 1; i <= n; i++) {
            int l = a[i].l, r = a[i].b;
            int st = 0, ed = Q + 1;
            int L = 1, R = Q;
            while (L <= R) {
                int mid = (L + R) >> 1;
                if (query(1, Q, mid, mid, 1) >= l) R = mid - 1, st = mid;
                    else L = mid + 1;
            }
            // L = 1, R = Q;
            // while (L <= R) {
            //     int mid = (L + R) >> 1;
            //     if (query(1, Q, mid, mid, 1) <= r) L = mid + 1, ed = mid;
            //         else R = mid - 1;
            // }
           // if (st == 0 && ed == Q + 1) continue;
            if (st == 0) continue;
            //if (st == 0) st = 1;
            //if (ed == Q + 1) ed = Q;
            update(1, Q, st, Q, r, 1);
        }

        for (int i = 1; i <= Q; i++) {
            q[i].ans = query(1, Q, i, i, 1);
        }
        sort(q + 1, q + 1 + Q, cmp3);
        for (int i = 1; i <= Q; i++)
            printf("%d ", q[i].ans);
        putchar('\n');
    }

    return 0;
}
