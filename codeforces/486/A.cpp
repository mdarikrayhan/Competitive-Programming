#include <iostream>
using namespace std;
int main()
{
    long long int n = 0;
    cin >> n;

    if (n % 2 == 0)
    {
        cout << n / 2;
    }
    else
    {
        n++;
        cout << "-" << n / 2;
    }
}