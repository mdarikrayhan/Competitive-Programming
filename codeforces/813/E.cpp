// LUOGU_RID: 159848979
#include<bits/stdc++.h>
#define int long long
#define said(...)
#define pb push_back
#define em emplace_back
#define F(i,x,y) for(int i=x;i<=y;++i)
#define G(i,x,y) for(int i=x;i>=y;--i)
#define W(G,i,x) for(auto&i:G[x])
#define W_(G,i,j,x) for(auto&[i,j]:G[x])
#define add(x,y) z[x].em(y)
#define add_(x,y) add(x,y),add(y,x)
#define Add(x,y,d) z[x].em(y,d)
#define Add_(x,y,z) Add(x,y,z),Add(y,x,z);
#ifdef int
#define inf (761125761137835809/2)
#else
#define inf 1011011011
#endif
using namespace std;
const int N = 100100;
const int mod = 998244353;

namespace yhb {

int a[N], la[N], rt[N], idx;
vector<int> scc[N], lask[N];
struct Node {
    int l, r, sum;
} z[N << 5];
void pushup(int rt) {
    z[rt].sum = z[z[rt].l].sum + z[z[rt].r].sum;
}
void flower() {
}
int build(int l, int r) {
    int p = ++idx;
    if (l == r) {
        z[p].sum = 0;
    } else {
        int mid = l + r >> 1;
        z[p].l = build(l, mid);
        z[p].r = build(mid + 1, r);
        pushup(p);
    }
    return p;
}
int modify(int rt, int x, int l, int r) {
    int p = ++idx;
    z[p] = z[rt];
    z[p].sum++;
    if (l != r) {
        int mid = l + r >> 1;
        if (x <= mid) {
            z[p].l = modify(z[p].l, x, l, mid);
        } else {
            z[p].r = modify(z[p].r, x, mid + 1, r);
        }
        pushup(p);
    }
    return p;
}
int query(int rt, int l, int r, int ll, int rr) {
    // cout << rt << ' ' << l << ' ' << r << ' ' << ll << ' ' << rr << '\n';
    // _sleep(233);
    int mid = l + r >> 1;
    if (ll == l && r == rr) {
        return z[rt].sum;
    } else {
        int s = 0;
        if (rr <= mid) {
            s = query(z[rt].l, l, mid, ll, rr);
        } else if (mid < ll) {
            s = query(z[rt].r, mid + 1, r, ll, rr);
        } else {
            s = query(z[rt].l, l, mid, ll, mid) + query(z[rt].r, mid + 1, r, mid + 1, rr);
        }
        return s;
    }
}
void rua() {
    int n, k, mx = 0;
    cin >> n >> k;
    F(i, 1, n) {
        cin >> a[i];
        scc[a[i]].pb(i);
        mx = max(mx, a[i]);
    }
    F(i, 1, mx) {
        F(j, k, (int)scc[i].size() - 1) {
            la[scc[i][j]] = scc[i][j - k];
        }
    }
    F(i, 1, n) {
        lask[la[i]].pb(i);
    }
    rt[0] = build(1, n);
    F(i, 0, n) {
        F(j, 0, (int)lask[i].size() - 1) {
            rt[i] = modify(rt[i], lask[i][j], 1, n);
        }
        rt[i + 1] = rt[i];
    }
    int q, la = 0;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        x = (x + la) % n + 1, y = (y + la) % n + 1;
        if (x > y) {
            swap(x, y);
        }
        cout << (la = query(rt[x - 1], 1, n, x, y)) << '\n';
    }
}
}
auto main() [[O3]] -> signed {
    int T;
    // cin >> T;
    T = 1;
    yhb::flower();
    while (T--) {
        yhb::rua();
    }
}