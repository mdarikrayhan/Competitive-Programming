#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3000 + 10;
int n, m, L[MAXN][MAXN], R[MAXN][MAXN], LD[MAXN][MAXN];
char mat[MAXN][MAXN];
vector<pair<int, int> > segs[MAXN];
void pre() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) if (mat[i][j] == 'z') L[i][j] = L[i][j - 1] + 1;
        for (int j = m; j >= 1; --j) if (mat[i][j] == 'z') R[i][j] = R[i][j + 1] + 1;
    }
    for (int i = n; i >= 1; --i) 
        for (int j = 1; j <= m; j++) 
            if (mat[i][j] == 'z')
                LD[i][j] = LD[i + 1][j - 1] + 1;
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++) {
            int r = j + R[i][j] - 1;
            if (j <= r) segs[r].push_back({ i, j });
        }
}
struct BIT {
    long long seq[MAXN];
    void mo(int x) {
        for (; x <= m; x += x & -x) ++seq[x];
    }
    long long qr(int x) {
        int r = 0; for (; x; x -= x & -x) r += seq[x]; return r;
    }
} cnt[MAXN << 1];
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) scanf("%s", mat[i] + 1);
    pre();
    long long ans = 0;
    for (int j = m; j >= 1; --j) {
        for (auto [x, y] : segs[j])
            cnt[x + y].mo(y);
        for (int i = 1; i <= n; ++i) {
            if (mat[i][j] != 'z') continue;
            int maxlen = min(L[i][j], LD[i][j]);
            int ql = j - maxlen + 1, qr = j;
            ans += cnt[i + j].qr(qr) - cnt[i + j].qr(ql - 1);
        }
    }
    cout << ans;
}