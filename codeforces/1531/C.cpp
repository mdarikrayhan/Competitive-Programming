// LUOGU_RID: 156865213
#include <iostream>
using namespace std;
bool mp[101][101];
int main()
{
    int n;
    cin >> n;
    int q = 1;
    int f = 0x7fffffff;
    while (q * q <= n)
    {
        if ((n - q * q) % 2 == 0)
        {
            f = q;
        }
        q++;
    }
    if (f == 0x7fffffff)
    {
        cout << -1;
        return 0;
    }
    for (int i = 1; i <= f; i++)
    {
        for (int j = 1; j <= f; j++)
        {
            mp[i][j] = true;
        }
    }
    n -= f * f;
    int f2 = f;
    while (n > 0)
    {
        for (int i = 1; i <= f && n > 0; i++)
        {
            mp[i][f2 + 1] = mp[f2 + 1][i] = true;
            n -= 2;
        }
        f2++;
    }
    cout << f2 << endl;
    for (int i = 1; i <= f2; i++)
    {
        for (int j = 1; j <= f2; j++)
        {
            cout << (mp[f2 - i + 1][j] ? 'o' : '.');
        }
        cout << endl;
    }
    return 0;
}



