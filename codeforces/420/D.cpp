// LUOGU_RID: 160501482
#include <chrono>
#include <iostream>
#include <random>
#include <utility>
using namespace std;
const int N = 1e6 + 5;
int n, m, rt, cnt, a[N];
bool vis[N];
struct node {
    int l, r, id, siz;
    mt19937::result_type key;
} t[N];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int newnode(int x) { return t[++cnt] = {0, 0, x, 1, rng()}, cnt; }
void pushup(int rt) { t[rt].siz = t[t[rt].l].siz + t[t[rt].r].siz + 1; }
void split(int rt, int x, int &l, int &r) {
    if (!rt) return void(l = r = 0);
    if (t[t[rt].l].siz >= x) split(t[r = rt].l, x, l, t[rt].l);
    else split(t[l = rt].r, x - t[t[rt].l].siz - 1, t[rt].r, r);
    pushup(rt);
}
int merge(int lt, int rt) {
    if (!lt || !rt) return lt + rt;
    if (t[lt].key < t[rt].key) t[lt].r = merge(t[lt].r, rt);
    else t[rt].l = merge(lt, t[rt].l), lt = rt;
    return pushup(lt), lt;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) rt = merge(rt, newnode(i));
    for (int i = 1, x, y; i <= m; i++) {
        cin >> x >> y;
        int l, m, r;
        split(rt, y - 1, l, r), split(r, 1, m, r);
        if (a[t[m].id]) {
            if (a[t[m].id] != x) return cout << -1, 0;
        } else if (vis[x]) return cout << -1, 0;
        else vis[a[t[m].id] = x] = true;
        rt = merge(m, merge(l, r));
    }
    for (int i = 1, j = 0; i <= n; i++)
        if (!a[i]) do a[i] = ++j; while (vis[j]);
    for (int i = 1; i <= n; i++) cout << a[i] << ' ';
}