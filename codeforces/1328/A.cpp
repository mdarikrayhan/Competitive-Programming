#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        long long int a, b;
        cin >> a >> b;
        if (a % b == 0)
        {
            cout << 0 << nl;
        }
        else
        {
            cout << b - (a % b) << nl;
        }
    }
    return 0;
}