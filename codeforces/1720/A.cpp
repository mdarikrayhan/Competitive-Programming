#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while(T--)
    {
        long long a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a == 0 && c == 0)
        {
            cout << 0 << nl;
            continue;
        }
        while(gcd(a, b) != 1)
        {
            int x=gcd(a, b);
            a=a/x;
            b=b/x;
        }
        while(gcd(c, d) != 1)
        {
            int x=gcd(c, d);
            c=c/x;
            d=d/x;
        }
        while (gcd(a, c) != 1)
        {
            int x=gcd(a, c);
            a=a/x;
            c=c/x;
        }
        while (gcd(b, d) != 1)
        {
           int x=gcd(b, d);
            b=b/x;
            d=d/x;
        }

        int x = b * c;
        int y = a * d;
        if (x == y)
        {
            cout << 0 << nl;
        }
        else if (x == 1 || y == 1 )
        {
            cout << 1 << nl;
        }
        else
        {
            cout << 2 << nl;
        }
    }

    return 0;
}