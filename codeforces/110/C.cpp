#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    if (n == 0 || n == 1 || n == 2 || n == 3 || n == 5 || n == 6 || n == 9 || n == 10)
    {
        cout << "-1";
        return 0;
    }
    for (int i = 0; i < (n % 7) / 4; i++)
    {
        cout << "4";
    }
    for (int i = 0; i < ((n % 7) % 4) * 2; i++)
    {
        cout << "4";
    }
    for (int i = 0; i < ((n / 7) - ((n % 7) % 4)); i++)
    {
        cout << "7";
    }
    return 0;
}