#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
long long pow(int base, int power)
{
    long long result = base;
    for (int i = 1; i <= power; i++)
    {
        result = base * result;
    }
    return result;
}
void solve()
{
    long long m, min = INT_MAX;
    cin >> m;
    if (m == 1)
    {
        cout << 0 << nl;
        return;
    }
    if (m < 10)
    {
        cout << m - 1 << nl;
        return;
    }
    for (int i = 0; i < 10; i++)
    {
        long long result = m - (pow(10, i));
        if (result < 0)
        {
            break;
        }
        min = result;
    }
    cout << min << nl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}