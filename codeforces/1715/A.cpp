#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        long long n, m;
        cin >> n >> m;
        if (n == 1 && m == 1)
        {
            cout << 0 << nl;
            continue;
        }
        cout << (min(n, m) + max(n, m) - 2 + min(n, m)) << nl;
    }
    return 0;
}