// LUOGU_RID: 160225162
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

#define MAXN 300005
#define MAXL 25
#define INF 0x3ffff3fff3fff3ffll

using ll = long long;

int n;

ll val[MAXN];

ll sl[MAXN];

ll d[MAXN][MAXL];

ll dp(int i, int j)
{
    if (d[i][j] != -1)
    {
        return d[i][j];
    }
    if (val[i] == -1)
    {
        return d[i][j] = 0;
    }
    d[i][j] = INF;
    if (j < MAXL - 1)
    {
        d[i][j] = dp(i + 1, j + 1) + val[i];
    }
    if (sl[j] > i - 1)
    {
        d[i][j] = min(d[i][j], dp(i + 1, j));
    }
    return d[i][j];
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> val[i];
    }
    for (int i = 1, x = (n >> 1); i < MAXL + 10; i++)
    {
        sl[i] = sl[i - 1] + x;
        x >>= 1;
    }
    reverse(val + 1, val + n + 1);
    memset(d, -1, sizeof(d));
    cout << dp(1, 0) << endl;
    return 0;
}
