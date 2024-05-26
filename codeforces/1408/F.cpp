// LUOGU_RID: 160363169
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 5;

int n, cnt;
pair<int, int> p[MAXN];

void solve(int l, int r) {
    if (l == r) return;
    int mid = (l + r) >> 1;
    solve(l, mid);
    solve(mid + 1, r);
    for (int i = l; i <= mid; i++)
        p[++cnt] = {i, i + mid - l + 1};
}

int main() {
    // freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    int k = __lg(n);
    solve(1, 1 << k);
    solve(n - (1 << k) + 1, n);
    printf("%d\n", cnt);
    for (int i = 1; i <= cnt; i++) {
        auto [x, y] = p[i];
        printf("%d %d\n", x, y);
    }
}