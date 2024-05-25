#include <iostream>
#include <string>
#include <math.h>
#include <cmath>
using namespace std;
int main()
{
    float x, y;
    cin >> x >> y;
    float n;
    n = x * x + y * y;
    n = sqrt(n);
    int p = n;
    if (p - n == 0)

        cout << "black";

    else if (x * y > 0)
    {
        if (p % 2 == 0)
            cout << "black";
        else
            cout << "white";
    }
    else
    {
        if (p % 2 == 1)
            cout << "black";
        else
            cout << "white";
    }
}