// LUOGU_RID: 160498039
#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
const int N = 2e5 + 5;
int n, D;
struct Segment {
    int l, r, add, mx;
} t[N * 55];
int rt, tot;
// 1. r has duck
// 2. r need recalc f_{r, r}
map<int, vector<int>> dcs;
set<int> ned;
inline void upd(int p, int val) {
    t[p].add += val; t[p].mx += val;
}
inline void pushdown(int p) {
    if (t[p].add) {
        if (t[p].l) upd(t[p].l, t[p].add);
        if (t[p].r) upd(t[p].r, t[p].add);
        t[p].add = 0;
    }
}
inline void pushup(int p) {
    t[p].mx = max(t[t[p].l].mx, t[t[p].r].mx);
}
void modify(int p, int l, int r, int ql, int qr, int val) {
    if (!p) return;
    if (ql <= l && r <= qr) { upd(p, val); return; }
    pushdown(p); int mid = (l + r) >> 1;
    if (ql <= mid) modify(t[p].l, l, mid, ql, qr, val);
    if (mid < qr) modify(t[p].r, mid + 1, r, ql, qr, val);
    pushup(p);
}
void add(int &p, int l, int r, int pos, int val) {
    if (!p) p = ++tot;
    if (l == r) { t[p].mx = val; return; }
    int mid = (l + r) >> 1; pushdown(p);
    if (pos <= mid) add(t[p].l, l, mid, pos, val);
    else add(t[p].r, mid + 1, r, pos, val);
    pushup(p);
}
int qmx(int p, int l, int r, int ql, int qr) {
    if (!p) return 0;
    if (ql <= l && r <= qr) return t[p].mx;
    pushdown(p); int mid = (l + r) >> 1, res = 0;
    if (ql <= mid) res = max(res, qmx(t[p].l, l, mid, ql, qr));
    if (mid < qr) res = max(res, qmx(t[p].r, mid + 1, r, ql, qr));
    return res;
}
int qlst(int p, int l, int r, int pos) {
    if (!p) return -1;
    if (l == r) return t[p].mx;
    pushdown(p); int mid = (l + r) >> 1;
    if (pos <= mid) return qlst(t[p].l, l, mid, pos);
    auto res = qlst(t[p].r, mid + 1, r, pos);
    return (~res) ? res : qlst(t[p].l, l, mid, pos);
}
// void debug(int p, int l, int r) {
//     if (!p) return;
//     if (l == r) { printf("de:%d %d\n", l, t[p].mx); return; }
//     pushdown(p); int mid = (l + r) >> 1;
//     debug(t[p].l, l, mid); debug(t[p].r, mid + 1, r);
// }
int main() {
    scanf("%d%d", &n, &D);
    rep(i, 1, n) {
        int h, t;
        scanf("%d%d", &h, &t);
        if (t >= 0) {
            if (!dcs.count(t)) ned.emplace(t);
            dcs[t].emplace_back(max(h, 0));
        }
    }
    // f[0][0]
    while (!ned.empty()) {
        int r = *ned.begin(); ned.erase(ned.begin());
        int mx = r >= D ? qmx(rt, 0, 1000000000, 0, r - D) : 0;
        // cerr << r << " " << mx << endl;
        int tres = qlst(rt, 0, 1000000000, r - 1);
        if (mx > tres) {
            add(rt, 0, 1000000000, r, mx);
            if (r + D <= 1000000000) ned.emplace(r + D);
        }
        if (dcs.count(r)) {
            const auto &vec = dcs[r];
            for (const auto &l: vec) {
                int rest = qlst(rt, 0, 1000000000, l);
                if (rest == -1) ++rest;
                // cerr << rest << " " << l << endl;
                modify(rt, 0, 1000000000, l, r, 1);
                add(rt, 0, 1000000000, l, rest + 1);
                if (l + D > r) ned.emplace(l + D);
                else ned.emplace(r + 1);
            }
            add(rt, 0, 1000000000, r + 1, r + 1 >= D ? qmx(rt, 0, 1000000000, 0, r + 1 - D) : 0);
        }
        // debug(rt, 0, 1000000000);
    }
    printf("%d\n", t[rt].mx);
    return 0;
}