#include <iostream>
using namespace std;
const char nl = '\n';

int main()
{
    int n;
    scanf("%d",&n);
    switch (n)
    {
    case 1:
        cout << 'a' << nl;
        break;
    case 2:
        cout << "ab" << nl;
        break;
    case 3:
        cout << "abc" << nl;
        break;

    default:
        for (int i = 0; i < n / 4; i++)
        {
            cout << "abcd";
        }

        int t = n % 4;
        switch (t)
        {
        case 1:
            cout << 'a' << nl;
            break;
        case 2:
            cout << "ab" << nl;
            break;
        case 3:
            cout << "abc" << nl;
            break;
        }
        break;
    }

    return 0;
}