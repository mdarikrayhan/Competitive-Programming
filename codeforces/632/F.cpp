// LUOGU_RID: 160411265
#include<bits/stdc++.h>
using namespace std;
const int N = 2505;
int n;
struct node {
    int x, y, val;
    bool operator < (const node& x) const {
        return val < x.val;
    }
}a[N * N];
int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
    while (isdigit(ch)) { x = x * 10 + (ch ^ 48); ch = getchar(); }
    return x * f;
}
int fa[N];
int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void kruskal() {
    sort(a + 1, a + n * n + 1);
    a[n * n + 1].val = -1;
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int l = 1, r = 0; l <= n * n; l = r + 1) {
        while (a[r + 1].val == a[l].val) ++r;
        if (a[l].val != 0)
            for (int i = l; i <= r; i++)
                if (find(a[i].x) == find(a[i].y)) {
                    puts("NOT MAGIC");
                    return;
                }
        for (int i = l; i <= r; i++)
            fa[find(a[i].x)] = find(a[i].y);
    }
    puts("MAGIC");
}
int id(int x, int y) {
    return (x - 1) * n + y;
}
int main() {
    n = read();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            a[id(i, j)].val = read();
            a[id(i, j)].x = i; a[id(i, j)].y = j;
            if (i == j && a[id(i, j)].val) {
                puts("NOT MAGIC");
                return 0;
            }
        }
    kruskal();
}