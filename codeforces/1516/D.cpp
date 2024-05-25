// LUOGU_RID: 160240080
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10, inf = 0x3f3f3f3f;
typedef long long ll;
typedef pair<int, int> pii;
template <class T>
T read() {
    char c = getchar();
    bool flag = (c == '-');
    T num = 0;
    while (c < '0' || c > '9') c = getchar(), flag |= (c == '-');
    while (c >= '0' && c <= '9') num = (num << 1) + (num << 3) + (c ^ 48), c = getchar();
    return flag ? -num : num;
}
int n, Q, a[N], c[N], nxt[N], f[21][N];
vector<int>p[N];
bool b[N];
int main() {
    memset(nxt, 0x3f, sizeof nxt);
    for (int i = 2; i <= 100000; i++) {
        if (!b[i]) {
            p[i].push_back(i);
            for (int j = i + i; j <= 100000; j += i) {
                b[j] = true;
                p[j].push_back(i);
            }
        }
    }
    n = read<int>(); Q = read<int>();
    for (int i = 1; i <= n; i++) a[i] = read<int>();
    f[0][n + 1] = n + 1;
    for (int i = n; i; --i) {
        f[0][i] = f[0][i + 1];
        for (auto x : p[a[i]]) {
            f[0][i] = min(f[0][i], nxt[x]);
            nxt[x] = i;
        }
    }
    for (int d = 1; d < 20; d++) {
        for (int i = 1; i <= n; i++) {
            if (f[d - 1][i] <= n) {
                f[d][i] = f[d - 1][f[d - 1][i]];
            } else f[d][i] = n + 1;
        }
    }
    while (Q--) {
        int l = read<int>(), r = read<int>();
        int ans = 0;
        for (int d = 19; d >= 0; d--) {
            if (f[d][l] <= r) {
                ans += (1 << d);
                l = f[d][l];
            }
        }
        printf("%d\n", ans + 1);
    }
    return 0;
}