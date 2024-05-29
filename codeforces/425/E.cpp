// LUOGU_RID: 160410476
#include <bits/stdc++.h>
#define int long long

#define F(i, a, b) for (int i = (a); i <= (b); i++)
#define dF(i, a, b) for (int i = (a); i >= (b); i--)
using namespace std;

const int N = 505, mod = 1e9 + 7;
int n, k, sum, f[N][N], pw[N * N];
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> k;
    f[0][0] = 1, pw[0] = 1;
    F(i, 1, n * n) 
        pw[i] = (pw[i - 1] + pw[i - 1]) % mod;
    F(i, 1, n) {
        f[i][0] = 1;
        F(j, 1, min(i, k)) F(p, j - 1, i)
            (f[i][j] += f[p][j - 1] * (pw[i - p] - 1) % mod * pw[p * (i - p)] % mod) %= mod;
    }
    cout << f[n][k];
    return 0;
}