#include<bits/stdc++.h>
#define lson(x) tr[x].ch[0]
#define rson(x) tr[x].ch[1]
#define FILE "CF44G"
using namespace std;

namespace FakeWilson {
const int N = 1e5 + 5;
const int INF = 1e9;
const int K = 2;
int qs[K][2], ans[N];
int D, node_cnt;

struct Plane {
    int x[K][2], z, id;
} a[N];

struct Point {
    int x[K], w;
    bool operator < (const Point& y) {
        if(x[D] == y.x[D]) return x[D ^ 1] < y.x[D ^ 1];
        return x[D] < y.x[D];
    }
} sq[N];

struct Node {
    int mn[K], mx[K], ch[2];
    int fa, val, id;
    Point pt;
    bool f;
} tr[N];

int new_node(Point& x, int fa) {
    tr[++node_cnt].pt = x;
    tr[node_cnt].fa = fa, tr[node_cnt].f = true;
    return node_cnt;
}

void push_up(int p) {
    if(tr[p].f) tr[p].val = tr[p].pt.w, tr[p].id = p;
    else tr[p].val = INF, tr[p].id = 0;
    for(int i = 0; i < K; i++) {
        if(tr[p].f) tr[p].mn[i] = tr[p].mx[i] = tr[p].pt.x[i];
        else tr[p].mn[i] = INF, tr[p].mx[i] = -1;
        if(lson(p)) {
            tr[p].mn[i] = min(tr[p].mn[i], tr[lson(p)].mn[i]);
            tr[p].mx[i] = max(tr[p].mx[i], tr[lson(p)].mx[i]);
            if(tr[lson(p)].val < tr[p].val)
                tr[p].val = tr[lson(p)].val, tr[p].id = tr[lson(p)].id;
        }
        if(rson(p)) {
            tr[p].mn[i] = min(tr[p].mn[i], tr[rson(p)].mn[i]);
            tr[p].mx[i] = max(tr[p].mx[i], tr[rson(p)].mx[i]);
            if(tr[rson(p)].val < tr[p].val) 
                tr[p].val = tr[rson(p)].val, tr[p].id = tr[rson(p)].id;
        }
    }
}

void build(int& p, int l, int r, int d, int fa) {
    if(l > r) return;
    int mid = (l + r) >> 1, nd = (d + 1) % K; D = d;
    nth_element(sq + l, sq + mid, sq + 1 + r);
    p = new_node(sq[mid], fa);
    
    build(lson(p), l, mid - 1, nd, p);
    build(rson(p), mid + 1, r, nd, p);
    push_up(p);
    // cout << p << ": " << sq[mid].x[0] << " " << sq[mid].x[1] << endl;
}

bool in(int p) {
    for(int i = 0; i < K; i++) {
        if(!(qs[i][0] <= tr[p].mn[i] && tr[p].mx[i] <= qs[i][1])) return false;
    }
    return true;
}

bool out(int p) {
    for(int i = 0; i < K; i++) {
        if(qs[i][0] > tr[p].mx[i] || qs[i][1] < tr[p].mn[i]) return true;
    }
    return false;
}

bool at(int p) {
    for(int i = 0; i < K; i++) {
        if(!(qs[i][0] <= tr[p].pt.x[i] && tr[p].pt.x[i] <= qs[i][1])) return false;
    }
    return true;
}

pair<int, int> query(int p) {
    if(!p) return make_pair(INF, 0);
    if(out(p)) return make_pair(INF, 0);
    // cout << p << " " << tr[p].mn[0] << " " << tr[p].mx[0] << endl;
    if(in(p)) return make_pair(tr[p].val, tr[p].id);
    pair<int, int> ls, rs, cur, ans;
    if(at(p) && tr[p].f) cur = make_pair(tr[p].pt.w, p);
    else cur = make_pair(INF, 0);
    ls = query(lson(p)), rs = query(rson(p));
    if(ls.first < rs.first) ans = ls;
    else ans = rs;
    if(cur.first < ans.first) ans = cur;
    return ans;
}

void modify(int p) {
    if(!p) return;
    push_up(p); 
    // cout << p << " " << tr[p].mn[0] << " " << tr[p].mx[0] << endl;
    modify(tr[p].fa);
}

bool cmp(Plane x, Plane y) {
    return x.z < y.z;
}

signed main() {
    int n, q;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d%d%d%d%d", &a[i].x[0][0], &a[i].x[0][1], &a[i].x[1][0], &a[i].x[1][1], &a[i].z), a[i].id = i;
    sort(a + 1, a + 1 + n, cmp);
    scanf("%d", &q);
    for(int i = 1; i <= q; i++) {
        scanf("%d%d", &sq[i].x[0], &sq[i].x[1]);
        sq[i].w = i;
    }
    int rt = 0;
    build(rt, 1, q, 0, 0);
    // cout << rt << endl;
    // puts("------");
    // cout << lson(2) << " " << rson(2) << endl;
    for(int i = 1; i <= n; i++) {
        for(int a1 = 0; a1 < K; a1++) {
            for(int a2 = 0; a2 < K; a2++) {
                qs[a1][a2] = a[i].x[a1][a2];
            }
        }
        pair<int, int> cur = query(rt);
        // cout << tr[cur.second].pt.x[0] << " " << tr[cur.second].pt.x[1] << endl;
        ans[tr[cur.second].pt.w] = a[i].id;
        tr[cur.second].f = false, modify(cur.second);
        // puts("---");cout << tr[2].f << endl;
    }
    for(int i = 1; i <= q; i++) printf("%d\n", ans[i]);
    return 0;
}

}

signed main() {
    return FakeWilson::main();
}