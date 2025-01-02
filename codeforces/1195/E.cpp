#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3001;
int n, m, a, b;
ll h[N][N], ans, g[N * N], x, y, z, c[N][N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> a >> b >> g[0] >> x >> y >> z;
    for (int i = 1; i < n * m; i++) {
        g[i] = (g[i - 1] * x + y) % z;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            h[i][j] = g[(i - 1) * m + j - 1];
        }
        deque<ll> q;
        for (int j = 1; j < b; j++) {
            while (q.size() > 0 && q.back() > h[i][j]) {
                q.pop_back();
            }
            q.push_back(h[i][j]);
        }
        for (int j = b; j <= m; j++) {
             while (q.size() > 0 && q.back() > h[i][j]) {
                q.pop_back();
            }
            q.push_back(h[i][j]);
            c[i][j - b + 1] = q.front();
            if (h[i][j - b + 1] == q.front()) {
                q.pop_front();
            }
        }
    }
    for (int i = 1; i <= m - b + 1; i++) {
        deque<ll> q;
        for (int j = 1; j < a; j++) {
            while (q.size() > 0 && q.back() > c[j][i]) {
                q.pop_back();
            }
            q.push_back(c[j][i]);
        }
        for (int j = a; j <= n; j++) {
            while (q.size() > 0 && q.back() > c[j][i]) {
                q.pop_back();
            }
            q.push_back(c[j][i]);
            ans += q.front();
            if (c[j - a + 1][i] == q.front()) {
                q.pop_front();
            }
        }
    }
    cout << ans;
}