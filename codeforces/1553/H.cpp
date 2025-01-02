// LUOGU_RID: 159740415
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pr pair<int, int>
#define mid (l + r) / 2
#define ls num << 1
#define rs num << 1 | 1

inline int read() {
    int x = 0, mm = 1;
    char ch = getchar();

    while (!isdigit(ch)) {
        if (ch == '-') mm = -1;
        ch = getchar();
    }

    while (isdigit(ch)) {
        x = x * 10 + ch - 48;
        ch = getchar();
    }

    return x * mm;
}

inline void write(int x) {
    if (x < 0) {
        putchar('-');
        write(-x);
        return;
    }

    if (x >= 10) write(x / 10);
    putchar(x % 10 + '0');
}

const int N = (1 << 20) + 5, inf = 1e16;

struct node {
    int l, r, ans, siz;
    node(int l = 0, int r = 0, int ans = -1, int siz = 0) : l(l), r(r), ans(ans), siz(siz) {}
};

node merge(node x, node y) {
    if (x.ans == -1 && y.ans == -1) return node(0, 0, -1, x.siz + y.siz);
    if (x.ans == -1) {
        return node(y.l + x.siz, y.r + x.siz, y.ans, x.siz + y.siz);
    }
    if (y.ans == -1) {
        return node(x.l, x.r, x.ans, x.siz + y.siz);
    }
    return node(x.l, x.siz + y.r, min({x.ans, y.ans, y.l + x.siz - x.r}), x.siz + y.siz);
}

#define Poly vector<node>

int a[N];

Poly solve(int l, int r) {
    if (l == r) {
        Poly now;
        if (a[l]) {
            now.pb(node(0, 0, inf, 1));
        }
        else {
            now.pb(node(0, 0, -1, 1));
        }
        return now;
    }

    Poly L = solve(l, mid), R = solve(mid + 1, r), ans(r - l + 1);
    int len = (r - l + 1) / 2;
    for (int i = 0; i < len; i++) {
        ans[i] = merge(L[i], R[i]);
        ans[i + len] = merge(R[i], L[i]);
    }
    return ans;
}

signed main() {
    int n = read(), k = read();

    for (int i = 1; i <= n; i++) {
        int x = read();
        a[x] = 1;
    }

    int m = 1 << k;

    Poly ans = solve(0, m - 1);

    for (int i = 0; i < m; i++) {
        write(ans[i].ans);
        putchar(' ');
    }
    putchar('\n');
}