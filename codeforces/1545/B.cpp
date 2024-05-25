// LUOGU_RID: 160144448
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 100'005
#define endl '\n'
#define mod 998'244'353
int n, a, b;
string s;
int jc[N];
void init()
{
    jc[0] = 1;
    for (int i = 1; i <= N; i++)
        jc[i] = (jc[i - 1] * i) % mod;
}
int ksm(int n, int k)
{
    int ret = 1;
    while (k)
    {
        if (k & 1)
            ret = (ret * n) % mod;
        n = (n * n) % mod;
        k >>= 1;
    }
    return ret;
}
void solve()
{
    a = 0, b = 0; // a表示11整体的个数,b表示单个1的个数
    cin >> n;
    cin >> s;
    for (int i = 0; s[i]; i++)
        if (s[i] == '1' && s[i + 1] == '1')
        {
            a++;
            i++;
        }
        else if (s[i] == '1')
            b++;
    // cout << a << ' ' << b << endl;
    int ans = 0; // c(n-a-b,a)
    ans = jc[n - a - b] % mod * ksm(jc[n - a - b - a], mod - 2) % mod * ksm(jc[a], mod - 2) % mod;
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}