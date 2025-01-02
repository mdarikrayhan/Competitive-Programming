// LUOGU_RID: 160388854
#include <bits/stdc++.h>
using namespace std;

char *p1, *p2, buf[1048577];
#define gc (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 20, stdin), p1 == p2) ? EOF : *p1++)
template <typename T>
inline void Read(T &x)
{
    x = 0; char ch = gc;
    while (!isdigit(ch)) ch = gc;
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = gc;
}

typedef long long ll;
typedef pair<int, int> pii;
const ll mod = 998244353;
const int maxn = 2e6 + 5;

ll fpow(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

int n, m;
ll pre1[2100], pre2[2100], fac[4500], inv[4500];
ll F(int a, int b) { return fac[a + b - 1] * inv[a] % mod * inv[b - 1] % mod; }

void work()
{
    cin >> n >> m;
    ll ans = 0;
    for (int i = 1; i < n; i++)
        for (int j = 1; j <= m; j++)
        {
            pre1[j] = (pre1[j - 1] + F(i, j) * F(i - 1, m - j + 1)) % mod;
            pre2[j] = (pre2[j - 1] + F(n - i, j) * F(n - i - 1, m - j + 1)) % mod;
            if (j < m)
            {
                (ans += pre1[j] * F(n - i - 1, j + 1) % mod * F(n - i, m - j)) %= mod;
                (ans += pre2[j] * F(i - 1, j + 1) % mod * F(i, m - j)) %= mod;
            }
        }
    
    for (int i = 1; i < m; i++)
        for (int j = 1; j <= n; j++)
        {
            pre1[j] = (pre1[j - 1] + F(i, j) * F(i - 1, n - j + 1)) % mod;
            pre2[j] = (pre2[j - 1] + F(m - i, j) * F(m - i - 1, n - j + 1)) % mod;
            if (j < n)
            {
                (ans += pre1[j - 1] * F(m - i - 1, j + 1) % mod * F(m - i, n - j)) %= mod;
                (ans += pre2[j - 1] * F(i - 1, j + 1) % mod * F(i, n - j)) %= mod;
            }
        }
    cout << ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

    fac[0] = fac[1] = inv[0] = inv[1] = 1;
    for (int i = 2; i <= 4499; i++)
    {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = inv[mod % i] * (mod - mod / i) % mod;
    }
    for (int i = 2; i <= 4499; i++) inv[i] = inv[i] * inv[i - 1] % mod;

    int T;
    // cin >> T;
    T = 1;
    while (T--) work();
	return 0;
}