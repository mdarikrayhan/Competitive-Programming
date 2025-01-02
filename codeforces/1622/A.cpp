#include <iostream>

using namespace std;

int main()
{   
    int t;
    cin >> t;

    while(t--)
    {
        int a, b ,c;
        cin >> a >> b >> c;

        if( (a + b + c ) % 2 != 0)
        cout << "NO\n";

        else if( (a + b == c) || (a + c == b) || (b + c == a))
        cout << "YES\n";

        else if( (a == b && c % 2 == 0) || (a == c && b % 2 == 0) || (c == b && a % 2 == 0))
        {
            cout << "YES\n";
        }

        else cout << "NO\n";
    }

    return 0;
}