#include <iostream>
using namespace std;
int main()
{
    int m, n, x;
    cin >> m >> n;
    if (1 <= m && m <= n && n <= 16)
    {
        cout << (m * n) / 2;
    }
}