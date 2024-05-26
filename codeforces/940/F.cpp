// LUOGU_RID: 160340134
#include <bits/stdc++.h>
#define int long long

#define F(i, a, b) for (int i = (a); i <= (b); i++)
#define dF(i, a, b) for (int i = (a); i >= (b); i--)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 200005, M = (N << 1), G = 400, B = 2000;
int n, m, a[N], an[N];
int qcnt;
struct QUERY {
    int l, r, t, id;
    bool operator<(QUERY x) const {
        if (l / B != x.l / B)
            return l < x.l;
        if (r / B != x.r / B)
            return r < x.r;
        return t < x.t;
    }
} q[N];
int mcnt;
struct MODIFY {
    int pos, v;
} mo[N];
int cnt[N], c[N];
void add(int x) {
    c[cnt[x]] --;
    c[++cnt[x]] ++;
}
void del(int x) {
    c[cnt[x]] --;
    c[--cnt[x]] ++;
}
void mod(int t, int i) {
    if (q[i].l <= mo[t].pos && mo[t].pos <= q[i].r)
        del(a[mo[t].pos]), add(mo[t].v);
    swap(mo[t].v, a[mo[t].pos]);
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    vector<int> ve;
    F(i, 1, n) {
        cin >> a[i];
        ve.push_back(a[i]);
    }
    F(i, 1, m) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1) {
            q[++qcnt] = {x, y, mcnt, qcnt};
        } else {
            mo[++mcnt] = {x, y};
            ve.push_back(y);
        }
    }
    sort(ve.begin(), ve.end());
    ve.erase(unique(ve.begin(), ve.end()), ve.end());
    F(i, 1, n) a[i] = lower_bound(ve.begin(), ve.end(), a[i]) - ve.begin();
    F(i, 1, mcnt) mo[i].v = lower_bound(ve.begin(), ve.end(), mo[i].v) - ve.begin();
    sort(q + 1, q + qcnt + 1);
    int l = 1, r = 0, t = 0;
    F(i, 1, qcnt) {
        int L = q[i].l, R = q[i].r, T = q[i].t;
        while (l > L) add(a[--l]);
        while (r < R) add(a[++r]);
        while (l < L) del(a[l++]);
        while (r > R) del(a[r--]);
        while (t < T) mod(++t, i);
        while (t > T) mod(t--, i);
        an[q[i].id] = 1;
        while (c[an[q[i].id]] > 0) 
            an[q[i].id] ++;
    }
    F(i, 1, qcnt) cout << an[i] << '\n';
    return 0;
}
