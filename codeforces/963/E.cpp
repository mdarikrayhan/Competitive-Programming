#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int o = 1;

int qpow(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (int)(1LL * ans * a % mod);
        a = (int)(1LL * a * a % mod);
        b >>= 1;
    }
    return ans;
}
int bi[105][105];
int ii[8005], jj[8005];
int a[7846][7846];
int f[7846];

signed main()
{
    int r, a1, a2, a3, a4;
    scanf("%d", &r);
    scanf("%d", &a1);
    scanf("%d", &a2);
    scanf("%d", &a3);
    scanf("%d", &a4);
    int x = a1 + a2 + a3 + a4;
    x = qpow(x, mod - 2);
    a1 = (int)(1LL * a1 * x % mod);
    a2 = (int)(1LL * a2 * x % mod);
    a3 = (int)(1LL * a3 * x % mod);
    a4 = (int)(1LL * a4 * x % mod);
    int tot = 0;
    for (int i = -r; i <= r; i++)
    {
        for (int j = -r; j <= r; j++)
        {
            if (i * i + j * j <= r * r)
            {
                bi[i + r][j + r] = ++tot;
                ii[tot] = i, jj[tot] = j;
            }
        }
    }
    // tot最大7845
    for (int i = 1; i <= tot; i++)
    {
        a[i][i] = 1;
        a[i][0] = 1;
        int ni = ii[i], nj = jj[i];
        if (bi[ni - 1 + r][nj + r])
            a[i][bi[ni - 1 + r][nj + r]] = ((-a1) % mod + mod) % mod;
        if (bi[ni + r][nj - 1 + r])
            a[i][bi[ni + r][nj - 1 + r]] = ((-a2) % mod + mod) % mod;
        if (bi[ni + 1 + r][nj + r])
            a[i][bi[ni + 1 + r][nj + r]] = ((-a3) % mod + mod) % mod;
        if (bi[ni + r][nj + 1 + r])
            a[i][bi[ni + r][nj + 1 + r]] = ((-a4) % mod + mod) % mod;
    }
    for (int i = 1; i <= tot; i++)
    {
        int tmp = qpow(a[i][i], mod - 2);
        for (int j = i + 1; j <= min(tot, i + 2 * r); j++)
        {
            int x = (int)(1LL * a[j][i] * tmp % mod);
            for (int k = max(o, j - 2 * r); k <= min(tot, j + 2 * r); k++)
            {
                a[j][k] = (a[j][k] - 1LL * x * a[i][k]) % mod;
                if (a[j][k] < 0)
                    a[j][k] += mod;
            }
            a[j][0] = (a[j][0] - 1LL * x * a[i][0]) % mod;
            if (a[j][0] < 0)
                a[j][0] += mod;
        }
    }
    for (int i = tot; i >= 1; i--)
    {
        for (int j = i + 1; j <= tot; j++)
            a[i][0] = (a[i][0] - 1LL * a[i][j] * f[j]) % mod;
        f[i] = (int)(1LL * a[i][0] * qpow(a[i][i], mod - 2) % mod);
        if (f[i] < 0)
            f[i] += mod;
    }
    cout << f[bi[r][r]];
}
