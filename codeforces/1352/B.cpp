#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(a) a.begin(),a.end()


void _()
{ll n, k, i;
        cin >> n >> k;
        if(n - k + 1 > 0 && (n - k + 1) % 2)
        {
            cout << "YES\n";
            for(i = 0; i < k - 1; i++)
                cout << 1 << ' ';
            cout << n - k + 1 << "\n";
        }
        else    if(n + 2 - 2 * k > 0 && (n + 2 - 2 * k) % 2 == 0)
        {
            cout << "YES\n";
            for(i = 0; i < k - 1; i++)
                cout << 2 << ' ';
            cout << n + 2 - 2 * k << "\n";
        }
        else
            cout << "NO\n";
}


signed main()
{
    int tc;
    cin >> tc;
    while(tc--)
        _();
}