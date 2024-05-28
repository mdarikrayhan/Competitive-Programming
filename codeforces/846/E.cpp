// LUOGU_RID: 160473211
#include <bits/stdc++.h>
using namespace std;
using i64 = long double;
constexpr int maxn = 100000 + 10;
i64 a[maxn], b[maxn];
int x[maxn];
i64 k[maxn];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i=1;i<=n;++i) cin >> b[i];
    for (int i=1;i<=n;++i) cin >> a[i];
    for (int i=2;i<=n;++i) cin >> x[i] >> k[i];
    for (int i=n;i>=2;--i)
    {
        if (b[i] <= a[i])
        {
            i64 d = a[i] - b[i];
            b[i] += d;
            b[x[i]] -= d * k[i];
        }
        if (b[i] >= a[i])
        {
            i64 d = b[i] - a[i];
            b[i] -= d;
            b[x[i]] += d;
        }
    }
    int o = 1;
    for (int i=1;i<=n;++i) o &= b[i] >= a[i];
    cout << (o ? "YES" : "NO") << '\n';
    return 0;
}