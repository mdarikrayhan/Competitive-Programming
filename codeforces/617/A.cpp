#include <iostream>
using namespace std;
int main()
{
    int x, s = 0;
    cin >> x;
    while (x)
    {
        if (x >= 5)
        {
            x = x - 5;
            s++;
        }
        else if (x >= 4)
        {
            x = x - 4;
            s++;
        }
        else if (x >= 3)
        {
            x = x - 3;
            s++;
        }
        else if (x >= 2)
        {
            x = x - 2;
            s++;
        }
        else if (x >= 1)
        {
            x = x - 1;
            s++;
        }
    }

    cout << s;
}