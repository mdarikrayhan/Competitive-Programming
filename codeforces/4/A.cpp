#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n;
    cin >> n;
    if (n == 2)
    {
        cout << "NO" << nl;
    }
    else if (n % 2 == 0)
    {
        cout << "YES" << nl;
    }
    else
    {
        cout << "NO" << nl;
    }
    return 0;
}