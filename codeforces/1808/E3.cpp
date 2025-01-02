// LUOGU_RID: 160587671
#include <iostream>
using namespace std;

using ll = long long;

ll pow(ll b, ll p, ll m)
{
    ll r = 1;
    while (p)
    {
        if (p & 1)
        {
            r = r * b % m;
        }
        b = b * b % m;
        p >>= 1;
    }
    return r;
}

ll gg(ll a, ll b)
{
    return b == 0 ? a : gg(b, a % b);
}

ll n, k, m;

int main()
{
    cin >> n >> k >> m;
    if (k % 2)
    {
        cout << (((pow(k, n, m) - pow(k - 1, n, m) + m) % m + pow(m - 1, n, m)) % m + pow(m - 1, n - 1, m) * gg(k, abs(n - 2)) % m) % m << endl;
    }
    else
    {
        cout << (pow(2, m - 2, m) * (pow(k, n, m) - pow(k - 2, n, m) + pow(m - 2, n, m) + m) % m + pow(m - 1, n - 1, m) * pow(2, n - 1, m) % m * gg(k / 2, abs(n - 2)) % m) % m << endl;
    }
    return 0;
}
