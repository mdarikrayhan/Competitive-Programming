#include <bits/stdc++.h>
using namespace std;

const int N = 200010, M = N * 50, L = 200000;
using ll = long long;

ll A[M], B[M];
int root[75005], ls[M], rs[M], tot;

void modify (int u, int& v, int l, int r, int x, int y, int a, int b) {
    v = ++ tot;
    A[v] = A[u];
    B[v] = B[u];
    ls[v] = ls[u];
    rs[v] = rs[u];
    if (x <= l && r <= y) {
        A[v] += a;
        B[v] += b;
        return;
    }
    int mid = l + r >> 1;
    if (x <= mid) modify(ls[u], ls[v], l, mid, x, y, a, b);
    if (y > mid) modify(rs[u], rs[v], mid + 1, r, x, y, a, b);
}

ll query (int u, int v, int l, int r, int x) {
    if (v == 0) return 0;
    ll sa = A[v] - A[u], sb = B[v] - B[u], res = sa * x + sb; 
    if (l == r) return res;
    int mid = l + r >> 1;
    if (x <= mid) res += query(ls[u], ls[v], l, mid, x);
    else res += query(rs[u], rs[v], mid + 1, r, x);
    return res;
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i ++) {
        int x1, x2, y1, a, b, y2;
        cin >> x1 >> x2 >> y1 >> a >> b >> y2;
        modify (root[i - 1], root[i], 0, L + 1, 0, x1, 0, y1);
        modify (root[i], root[i], 0, L + 1, x1 + 1, x2, a, b);
        modify (root[i], root[i], 0, L + 1, x2 + 1, L + 1, 0, y2);
    }
    
    ll last = 0;
    int m, mod = 1e9;
    cin >> m;
    while (m --) {
        int l, r, x;
        cin >> l >> r >> x;
        x = (last + x) % mod;
        cout << (last = query(root[l - 1], root[r], 0, L + 1, min(L + 1, x))) << '\n';
    }
    
    return 0;
}