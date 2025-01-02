#include <bits/stdc++.h>
using namespace std;
typedef long long li;
const li mod = 1000000007;

inline void normal(li &a)
{
    a %= mod;
    (a < 0) && (a += mod);
}

inline li mul(li a, li b)
{
    a %= mod, b %= mod;
    normal(a), normal(b);
    return (a * b) % mod;
}

inline li add(li a, li b)
{
    a %= mod, b %= mod;
    normal(a), normal(b);
    return (a + b) % mod;
}

inline li sub(li a, li b)
{
    a %= mod, b %= mod;
    normal(a), normal(b);
    a -= b;
    normal(a);
    return a;
}

inline li sum(li n) { return mul(mul(n, n + 1), (mod + 1) / 2); }
inline li sum(li lf, li rg) { return sub(sum(rg), sum(lf - 1)); }

inline li calcDiv(li n, li m)
{
    m = min(m, n);

    li ans = 0;
    li minVal = m;
    for (li i = 1; i * i <= n; i++)
    {
        li lf = n / (i + 1), rg = n / i;
        rg = min(rg, m);
        if (lf >= rg)
            continue;
        minVal = lf; // interval (lf, rg]
        ans = add(ans, mul(i, sum(lf + 1, rg)));
    }

    for (int i = 1; i <= minVal; i++)
    {
        ans = add(ans, mul(n / i, i));
    }
    return ans;
}

inline li calcMod(li n, li m)
{
    li ans = mul(n, m);
    ans = sub(ans, calcDiv(n, m));
    return ans;
}

int main()
{
    long long n, m;
    cin >> n >> m;
    cout << calcMod(n, m) << endl;
    return 0;
}