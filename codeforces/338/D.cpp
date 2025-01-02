// LUOGU_RID: 160377973
#include <bits/stdc++.h>
using namespace std;
int k;
long long n, m, z[10010];
long long gcd(long long a, long long b)
{
    if (!b)
        return a;
    else
        return gcd(b, a % b);
}
int main()
{
    cin >> n >> m >> k;
    for (int a = 1; a <= k; a++)
        cin >> z[a];
    long long v = z[1];
    for (int a = 2; a <= k; a++)
        if (v > n)
            break;
        else
            v = v / gcd(v, z[a]) * z[a];
    if (v > n)
    {
        printf("NO\n");
        return 0;
    }
    long long v1 = z[1];
    long long mo1 = z[1];
    if (v1 + k - 1 > m)
    {
        printf("NO\n");
        return 0;
    }
    for (int a = 2; a <= k; a++)
    {
        v1 %= mo1;
        long long v2 = ((-(a - 1)) % z[a] + z[a]) % z[a];
        long long mo2 = z[a];
        long long cnt = 0;
        if (mo1 > mo2)
        {
            while (cnt <= mo2 && v1 + k - 1 <= m && v1 % mo2 != v2)
                v1 += mo1, cnt++;
        }
        else
        {
            while (cnt <= mo1 && v2 + k - 1 <= m && v2 % mo1 != v1)
                v2 += mo2, cnt++;
            v1 = v2;
        }
        v2 %= mo2;
        if (v1 % mo2 != v2 || v1 + k - 1 > m)
        {
            printf("NO\n");
            return 0;
        }
        mo1 = mo1 / gcd(mo1, mo2) * mo2;
    }
    if (!v1)
        v1 = mo1;
    for (long long a = 1; a <= k; a++)
        if (gcd(v1 + a - 1, v) != z[a])
        {
            printf("NO\n");
            return 0;
        }
    printf("YES\n");
}