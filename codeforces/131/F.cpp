// LUOGU_RID: 158212170
#include <bits/stdc++.h>
using namespace std;
#define il inline
#define ptc putchar
#define pb push_back
#define R(i, l, r) for (int i = l; i <= r; ++i)
#define debug puts("--------------------------------------------")
typedef long long ll;
typedef pair<int, int> PII;
namespace ZeroTwo
{
    template <typename T>
    il void read(T &x) 
    { 
        x = 0; T f = 1; char ch;
        while (!isdigit(ch = getchar())) f -= (ch == '-') << 1;
        while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch & 15), ch = getchar();
        x *= f;
    }
    template <typename T, typename ...L>
    il void read(T &x, L &...y) {read(x); read(y...);}
    template <typename T>
    il void write(T x) 
    {
        if (x < 0) ptc('-'), x = -x;
        if (x > 9) write(x / 10);
        ptc(x % 10 + '0');
    }
    template <typename T, typename ...L>
    il void write(T &x, L &...y) {write(x), ptc(' '); write(y...);}
}
using namespace ZeroTwo;
const int N = 505;
int n, m, k, a[N][N], s[N][N];
ll ans;
int sum(int X1, int Y1, int X2, int Y2)
{
    ++X1, ++Y1, --X2, --Y2;
    return s[X2][Y2] - s[X1 - 1][Y2] - s[X2][Y1 - 1] + s[X1 - 1][Y1 - 1];
}
signed main() 
{
    cin >> n >> m >> k;
    R(i, 1, n) R(j, 1, m) scanf("%1d", &a[i][j]);
    R(i, 1, n)
    {
        R(j, 1, m)
        {
            if (a[i][j] && a[i - 1][j] && a[i + 1][j] && a[i][j - 1] && a[i][j + 1]) s[i][j] = 1;
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + s[i][j];
        }
    }
    // cout << sum(7, 1, 9, 4) << endl;
    R(i, 1, n)
    {
        R(j, 1, m)
        {
            for (int len1 = 3, len2 = m + 1 - j; i + len1 - 1 <= n; ++len1)
            {
                while (len2 > 2 && sum(i, j, i + len1 - 1, j + len2 - 1) >= k) --len2;
                // cout << i << ' ' << j << ' ' << len1 << ' ' << len2 << ' ' << sum(i, j, i + len1 - 1, j + len2 - 1) << endl;
                ans += m - j - len2 + 1;
            }
        }
    }
    cout << ans << endl;
    return 0;
}