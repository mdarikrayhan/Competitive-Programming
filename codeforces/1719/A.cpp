#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        long long n, m;
        cin >> n >> m;
        if (abs(n - m) & 1)
        {
            cout << "Burenka" << nl;
        }
        else
        {
            cout << "Tonya" << nl;
        }
    }

    return 0;
}