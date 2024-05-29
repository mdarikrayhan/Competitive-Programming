#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 998244353;
const int Maxb = 31;
const int Maxn = 200005;

int xr[Maxb];
int l;
int a[Maxn];
int pw2[Maxn];

void Insert(int x)
{
    for (int i = Maxb - 1; i >= 0; i--)
        if (x & 1 << i)
            if (xr[i]) x ^= xr[i];
            else {
                xr[i] = x;
                break;
            }
}

int Get()
{
    int res = 0;
    for (int i = 0; i < Maxb; i++)
        res += xr[i] > 0;
    return res;
}

int main()
{
    pw2[0] = 1;
    for (int i = 1; i < Maxn; i++)
        pw2[i] = 2ll * pw2[i - 1] % mod;
    scanf("%d", &l);
    set <int> S;
    for (int i = 0; i < l; i++)
        scanf("%d", &a[i]);
    for (int i = l - 1; i >= 0; i--) {
        a[i] ^= a[0];
        Insert(a[i]);
        S.insert(a[i]);
    }
    int d = S.size();
    int g = Get();
    int res = 1;
    for (int j = 2; j <= d; j++)
        if (g >= j - 1)
            res = ll(res) * pw2[l - j + 1] % mod;
    printf("%d\n", res);
    return 0;
}
