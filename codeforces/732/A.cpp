#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long int k, r;
    cin >> k >> r;
    for (int i = 1;; i++)
    {
        if ((k * i) % 10 == 0)
        {
            cout << i << nl;
            break;
        }
        if (((k * i) - r) % 10 == 0)
        {
            cout << i << nl;
            break;
        }
    }
    return 0;
}