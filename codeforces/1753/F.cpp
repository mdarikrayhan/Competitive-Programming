// LUOGU_RID: 159857785
#include<algorithm>
#include<iostream>
#include<vector>

char bf[30000000], *bp = bf;
void inline rd(int&x) {
    for (x=0; !isdigit(*bp); bp++);
    for (; isdigit(*bp); bp++)
        x = x * 10 + (*bp ^ 48);
}
void inline ird(int&x) { bool f = 0;
    for (x=0; isspace(*bp); bp++);
    bp += f = *bp == '-';
    for (; isdigit(*bp); bp++)
        x = x * 10 + (*bp ^ 48);
    x = f ? -x : x;
}
const int N = 1e6, T = 4e4, B = 1e3;
int n, m, t, p[N], v[N], ct[T];
long long ans;
std::vector<int>w[T];
struct Block {
    int ct[N], bl[B];
    void md(int x, int k) {
        bl[x/B] -= !!ct[x];
        bl[x/B] += !!(ct[x] += k);
    }
    int qr() { int k = 0;
        for (; bl[k]==B; k++);
        for (k*=B; ct[k]; k++);
        return k;
    }
} a, b;
void inline md(int i, int j, int k) {
    for (int x : w[i*m+j])
        if (x > 0) a.md(x-1, k);
        else b.md(-x-1, k);
}
void sv(int x, int y) { int l = 0, r = 0;
    for (int i, j; x+r<n && y+r<m; ans+=l) {
        for (i=x+l; i<=x+r; i++) md(i, y+r, 1);
        for (i=y+l; i<y+r; i++) md(x+r, i, 1);
        for (r++; a.qr()+b.qr()>=t; l++) {
            for (i=x+l; i<x+r; i++) md(i, y+l, -1);
            for (i=y+l+1; i<y+r; i++) md(x+l, i, -1);
        }
    }
    for (int i=x+l, j; i<x+r; i++)
        for (j=y+l; j<y+r; j++) md(i, j, -1);
}
int main() {
    fread(bf, 1, sizeof bf, stdin);
    int k, tt = 0; rd(n), rd(m), rd(k), rd(t);
    if (!--t) { if (n > m) std::swap(n, m);
        return std::cout << (3*m-n+1)*(n+1ll)*n/6, 0; }
    for (int x, y; k--;) if (rd(x), rd(y), ird(v[tt]),
        abs(v[tt]) <= t) ct[p[tt++]=--x*m+--y]++;
    for (int i=0; i<n*m; i++) w[i].resize(ct[i]);
    for (int i=0, t; i<tt; i++) w[p[i]][--ct[p[i]]] = v[i];
    for (int i=0; i<n*m; i++) std::sort(w[i].begin(), w[i].end());
    for (int i=0; i<n; i++) sv(i, 0);
    for (int i=1; i<m; i++) sv(0, i);
    std::cout << ans;
}