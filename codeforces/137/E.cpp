#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct segtree {
    vector<int> tree;
    int size = 1;

    void init(int n) {
        while (size < n) {
            size *= 2;
        }
        tree.assign(2 * size - 1, INT_MAX);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if (lx + 1 == rx) {
            tree[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m) {
            set(i, v, 2 * x + 1, lx, m);
        } else {
            set(i, v, 2 * x + 2, m, rx);
        }
        tree[x] = min(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    int getmin(int l, int r, int x, int lx, int rx) {
        if (r <= lx || rx <= l) {
            return INT_MAX;
        }
        if (l <= lx && r >= rx) {
            return tree[x];
        }
        int m = (lx + rx) / 2;
        return min(getmin(l, r, 2 * x + 1, lx, m), getmin(l, r, 2 * x + 2, m, rx));
    }

    int getmin(int l, int r) {
        return getmin(l, r, 0, 0, size);
    }
};


void solve() {
    string s;
    cin >> s;
    int n = s.size();
    string b = "aeiouAEIOU";
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < b.size(); ++j) {
            a[i] += (int) (s[i] == b[j]);
        }
    }
    int c = 0, v = 0;
    vector<pair<int, int>> d;
    d.push_back({0, 0});
    for (int i = 0; i < n; ++i) {
        v += (a[i] == 1);
        c += (a[i] == 0);
        d.push_back({2 * c - v, i + 1});
    }
    sort(d.begin(), d.end());
    map<pair<int, int>, int> m;
    for (int i = 0; i < d.size(); ++i) {
        m[d[i]] = i;
    }
    c = 0, v = 0;
    segtree st;
    st.init(n + 1);
    st.set(m[{0, 0}], 0);
    int len = 0;
    for (int i = 0; i < n; ++i) {
        v += (a[i] == 1);
        c += (a[i] == 0);
        int j = m[{2 * c - v, i + 1}];
        st.set(j, c + v);
        int mn = st.getmin(0, j + 1);
        len = max(len, c + v - mn);
    }

    if (len == 0) {
        cout << "No solution\n";
        return;
    }

    int ans = 0;
    vector<int> pv(n + 1), pc(n + 1);
    for (int i = 0; i < n; ++i) {
        pc[i + 1] = pc[i] + (a[i] == 0);
        pv[i + 1] = pv[i] + (a[i] == 1);
        if (i + 1 >= len && 2 * (pc[i + 1] - pc[i + 1 - len]) >= pv[i + 1] - pv[i + 1 - len]) {
            ++ans;
        }
    }


    cout << len << " " << ans;

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}