// LUOGU_RID: 160311389
#include <bits/stdc++.h>
#define int long long

#define F(i, a, b) for (int i = (a); i <= (b); i++)
#define dF(i, a, b) for (int i = (a); i >= (b); i--)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 405, M = (N << 1), inf = 1e16;
int mod, n, m, A[N], I[N], fac[N], B[N][N];
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> mod;
    fac[0] = 1;
    F(i, 1, 400) I[i] = fac[i] = fac[i - 1] * i % mod;
    F(i, 2, 400)
        F(j, 1, i - 1) 
            I[i] = (I[i] - I[j] * fac[i - j] % mod + mod) % mod;
    B[0][0] = 1;
    F(i, 1, 400) F(j, 1, i) F(k, 1, i)
        B[i][j] = (B[i][j] + B[i - k][j - 1] * fac[k] % mod) % mod;
    A[1] = 1, A[2] = 2, A[3] = 0;
    F(i, 4, 400) {
        A[i] = fac[i];
        F(j, 1, i - 1)
            A[i] = (A[i] - 2 * I[j] * fac[i - j] % mod + mod) % mod;
        F(j, 4, i - 1)
            A[i] = (A[i] - B[i][j] * A[j] % mod + mod) % mod;
    }
    F(i, 1, n) {
        int x;
        cin >> x;
        cout << A[x] << '\n';
    }
    return 0;
}
