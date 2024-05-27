#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1 << 18;

int fen[N + 1], c = 0;

void upd(int i, int k) {
    for (; i <= N; i += (i & -i)) fen[i] += k;
}

int query(int i) {
    int res = 0;
    for (; i; i -= (i & -i)) res += fen[i];
    return res;
}

int amogus(int ql, int qr, int l, int r) {
    if (ql <= l && r <= qr) {
        int x = l ^ c;
        // cout << x << ' ' << l << ' ' << r << ' ' << c << '\n';
        x &= (~(r - l));
        // cout << x + 1 << ' ' << x + r - l + 1 << '\n';
        return query(x + r - l + 1) - query(x);
    }
    if (qr < l || r < ql) return 0;
    int mid = (l + r) / 2;
    return amogus(ql, qr, l, mid) + amogus(ql, qr, mid + 1, r);
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q;
    cin >> n >> q; 
    vector<int> a((1 << n) + 1);
    for (int i = 1; i <= (1 << n); i++) {
        cin >> a[i];
        upd(i, a[i]);
    }
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int x, k;
            cin >> x >> k;
            int idx = ((x - 1) ^ c) + 1;
            upd(idx, k - a[idx]);
            a[idx] = k;
        } else if (type == 2) {
            int k;
            cin >> k;
            for (int i = 0; i < k; i++) c ^= (1 << i);
        } else if (type == 3) {
            int k;
            cin >> k;
            c ^= (1 << k);
        } else {
            int l, r;
            cin >> l >> r;
            l--, r--;
            cout << amogus(l, r, 0, (1 << n) - 1) << '\n';
        }
    }
}