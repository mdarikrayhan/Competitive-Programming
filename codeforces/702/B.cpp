#include <bits/stdc++.h>
using namespace std;
map<int, int> f;
int i, n, x;
long long r;
int main()
{
    cin >> n;
    while (n--)
    {
        cin >> x;
        for (i = 0; i < 31; ++i)
        {
            r += f[(1 << i) - x];
        }
        f[x]++;
    }
    cout << r;
}