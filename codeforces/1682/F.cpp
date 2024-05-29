// LUOGU_RID: 159724752
// LUOGU_RID: 159724496
#include <bits/stdc++.h>
#define int long long

#define F(i, a, b) for (int i = (a); i <= (b); i++)
#define dF(i, a, b) for (int i = (a); i >= (b); i--)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 200005, M = (N << 1), inf = 1e16, mod = 1e9 + 7;
int n, m, a[N], b[N], c[N], s[N], an[N], d[N], e[N];
struct node {
    int x, y, z;
    node (int a = 0, int b = 0, int c = 0) {
        x = a, y = b, z = c;
    }
} ;
vector<node> q[N];
struct SGT {
    int t[N << 2], g[N << 2];
    void change(int p, int x, int v, int l, int r, int op) {
        if (l == r) {
            op ? (t[p] += v) %= mod : (g[p] += v) %= mod;
            return ;
        }
        int mid = (l + r) / 2;
        if (x <= mid) change(p * 2, x, v, l, mid, op);
        else change(p * 2 + 1, x, v, mid + 1, r, op);
        t[p] = (t[p * 2] + t[p * 2 + 1]) % mod;
        g[p] = (g[p * 2] + g[p * 2 + 1]) % mod;
    }
    int query(int p, int x, int y, int l, int r, int op) {
        if (x <= l && r <= y) return op ? t[p] : g[p];
        int mid = l + r >> 1, res = 0;
        if (x <= mid) res += query(p * 2, x, y, l, mid, op);
        if (y > mid) res += query(p * 2 + 1, x, y, mid + 1, r, op);
        return res % mod;
    }
} tr;
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    F(i, 1, n) cin >> a[i];
    vector<int> ve;
    F(i, 1, n) {
        cin >> b[i];
        c[i] = a[i + 1] - a[i];
        s[i] = s[i - 1] + b[i];
        d[i] = (d[i - 1] + c[i] * s[i] % mod) % mod;
        e[i] = (e[i - 1] + c[i]) % mod;
        ve.push_back(s[i]);
    }
    sort(ve.begin(), ve.end());
    ve.erase(unique(ve.begin(), ve.end()), ve.end());
    F(i, 1, n - 1) {
        int pos = lower_bound(ve.begin(), ve.end(), s[i]) - ve.begin();
        q[pos].emplace_back(i, i, 0);
    }
    F(i, 1, m) {
        int l, r, pos;
        cin >> l >> r;
        pos = lower_bound(ve.begin(), ve.end(), s[l - 1]) - ve.begin();
        q[pos].emplace_back(l, r, i);
    }
    for (int i = 0; i < ve.size(); i ++) {
        for (auto [l, r, id] : q[i]) {
            if (id == 0) {
                tr.change(1, l, c[l], 1, n, 0);
                tr.change(1, l, s[l] * c[l] % mod, 1, n, 1);
            } else {
                int C = tr.query(1, l, r - 1, 1, n, 0),
                    S = tr.query(1, l, r - 1, 1, n, 1);
                an[id] += C * (s[l - 1] % mod) % mod - S + mod;
                C = e[r - 1] - e[l - 1] - C;
                S = d[r - 1] - d[l - 1] - S;
                an[id] += S - s[l - 1] % mod * C % mod + mod;
                an[id] = (an[id] % mod + mod) % mod;
            }
        }
    }
    F(i, 1, m) cout << an[i] << endl;
    return 0;
}
