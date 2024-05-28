// LUOGU_RID: 158624936
#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f
using namespace std;
const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;
int inv[maxn], fac[maxn];
int a[maxn], sum[maxn];
int pw10[maxn];
int fpow(int x, int p)
{
    int ans = 1;
    x %= mod;
    while (p)
    {
        if (p & 1)
            ans = (ans * x) % mod;
        x = (x * x) % mod;
        p >>= 1;
    }
    return ans;
}
void init()
{
    fac[0] = pw10[0] = 1;
    for (int i = 1; i < maxn; i++)
    {
        fac[i] = fac[i - 1] * i % mod;
        pw10[i] = pw10[i - 1] * 10 % mod;
    }
    inv[maxn - 1] = fpow(fac[maxn - 1], mod - 2);
    for (int i = maxn - 2; i >= 0; i--)
    {
        inv[i] = inv[i + 1] * (i + 1) % mod;
    }
}
int C(int n, int m)
{
    if (n < m)
        return 0;
    return fac[n] * inv[n - m] % mod * inv[m] % mod;
}
signed main()
{
    cin.tie(0), cout.tie(0);
    init();
    // cout << C(4, 2);
    int n, k;
    cin >> n >> k;
    pw10[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        char c;
        cin >> c;
        a[i] = c - '0';
        sum[i] = sum[i - 1] + a[i];
    }
    int ans = 0;
    for (int i = 0; i <= n - k - 1; i++)
    {
        int tmp = C(n - i - 2, k - 1) % mod * pw10[i] % mod * sum[n - i - 1] % mod;
        ans += tmp;
        ans %=mod;
    }
    for (int i = k; i <= n; i++)
    {
        ans += C(i - 1, k) % mod * pw10[n - i] % mod * a[i] % mod;
        ans %= mod;
    }
    cout << ans;
}
