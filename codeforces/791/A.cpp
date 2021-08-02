#include <iostream>
using namespace std;
int main()
{
    int a, b,n=0;
    cin >> a >> b;
    while (a <= b)
    {
        a = 3 * a;
        b = 2 * b;
        n++;
    }
    cout<<n;
}