//بسم الله الرحمن الرحيم
#include <bits/stdc++.h>
using namespace std;
void IO();
const int N = 2e2 + 1;
int R, G, B;
int a[N], b[N], c[N];
int DP[N][N][N];
int cal(int i, int j, int k) {
    int &ret = DP[i][j][k];
    if (~ret) return ret;
    ret = 0;
    if (i < R && j < G) {
        ret = max(ret, cal(i + 1, j + 1, k) + a[i] * b[j]);
    }
    if (i < R && k < B) {
        ret = max(ret, cal(i + 1, j, k + 1) + a[i] * c[k]);
    }
    if (j < G && k < B) {
        ret = max(ret, cal(i, j + 1, k + 1) + b[j] * c[k]);
    }
    return ret;
}
void solution() {
    cin >> R >> G >> B;
    for (int i = 0; i < R; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < G; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < B; ++i) {
        cin >> c[i];
    }
    sort(a, a + R, greater<>());
    sort(b, b + G, greater<>());
    sort(c, c + B, greater<>());
    memset(DP, -1, sizeof DP);
    cout << cal(0, 0, 0);
}
signed main(){
    IO();
    int t = 1;
//    cin >> t;
    while (t--) {
        solution();
    }
}
void IO() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#endif
}