#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1;
int n, q;
int a[N], nxt[N], seg[N * 4];
vector<pair<int, int>> qs[N];
unordered_map<int, int> pos;
int ans[N];
void insert(int x, int st, int ed, int ind, int val) {
    if (st > ind || ed < ind) {
        return;
    }
    if (st == ed) {
        seg[x] = val;
        return;
    }
    insert(x * 2 + 1, st, (st + ed) / 2, ind, val);
    insert(x * 2 + 2, (st + ed) / 2 + 1, ed, ind, val);
    seg[x] = seg[x * 2 + 1] ^ seg[x * 2 + 2];
}
int get(int x, int st, int ed, int l, int r) {
    if (st > r || ed < l) {
        return 0;
    }
    if (l <= st && ed <= r) {
        return seg[x];
    }
    return get(x * 2 + 1, st, (st + ed) / 2, l, r) ^ get(x * 2 + 2, (st + ed) / 2 + 1, ed, l, r);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        insert(0, 1, n, i, a[i]);
    }
    for (int i = n; i > 0; i--) {
        if (pos.find(a[i]) != end(pos)) {
            nxt[i] = pos[a[i]];
        }
        pos[a[i]] = i;
    }
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;
        qs[l].push_back({r, i});
    }
    for (auto i: pos) {
        insert(0, 1, n, i.second, 0);
    }
    for (int i = 1; i <= n; i++) {
        for (pair<int, int> j: qs[i]) {
            ans[j.second] = get(0, 1, n, i, j.first);
        }
        if (nxt[i] != 0) {
            insert(0, 1, n, nxt[i], 0);
        }
    }
    for (int i = 1; i <= q; i++) {
        cout << ans[i] << '\n';
    }
}