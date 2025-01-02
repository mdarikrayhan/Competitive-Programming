#include <bits/stdc++.h>
using namespace std;

struct fenwick_tree {
    vector<int> bit;
    int n;

    fenwick_tree(int n) : n(n), bit(n + 1, 0) {}

    void update(int u, int v) {
        for (++u; u <= n; u += u & -u) {
            bit[u] += v;
        }
    }

    int pref_sum(int u) {
        int ans = 0;
        for (++u; u > 0; u -= u & -u) {
            ans += bit[u];
        }
        return ans;
    }

    int upper_bound(int u) {
        int ans = 0;
        for (int i = __lg(n); i >= 0; i--) {
            if (ans + (1 << i) <= n && bit[ans + (1 << i)] <= u) {
                u -= bit[ans += (1 << i)];
            }
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> b(n);
    fenwick_tree fen(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i]; b[i] = i - b[i];
        fen.update(i, 1);
    }
    int d = 200;
    vector<int> p_block(n), val(n);
    auto get_value = [&](int x, int low, int high) {
        int le = -1, ri = high - low;
        while (le + 1 < ri) {
            int mi = (le + ri) / 2;
            (x + mi >= val[mi + low] ? le : ri) = mi;
        }
        return x + ri;
    };
    auto generate_block = [&](int id) {
        int low = id * d, high = min((id + 1) * d, n);
        for (int i = high - 1; i >= low; i--) {
            val[i] = p_block[i] = fen.upper_bound(b[i]);
            fen.update(p_block[i], -1);
        }
        sort(val.begin() + low, val.begin() + high);
        for (int i = high - 1; i >= low; i--) {
            fen.update(p_block[i], 1);
        }
    };
    for (int i = 0; i < n; i += d) {
        generate_block(i / d);
    }
    int q; cin >> q;
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int i, x; cin >> i >> x; i--;
            b[i] = i - x;
            generate_block(i / d);
        } else {
            int i; cin >> i; i--;
            int ans = p_block[i];
            for (int j = i / d + 1; j * d < n; j++) {
                ans = get_value(ans, j * d, min((j + 1) * d, n));
            }
            cout << ans + 1 << '\n';
        }
    }
}