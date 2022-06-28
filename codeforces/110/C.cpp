#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, n7 = 0, n4 = 0, mod7, mod4;
    cin >> n;
    if (n < 4 || n == 5 || n == 6 || n == 9 || n == 10)
    {
        cout << "-1";
        return 0;
    }
    mod7 = n % 7;
    n7 = n / 7;
    mod4 = (mod7 % 4);
    n4 = mod7 / 4;

    for (int i = 0; i < n4; i++)
    {
        cout << "4";
    }
    for (int i = 0; i < mod4 * 2; i++)
    {
        cout << "4";
    }
    for (int i = 0; i < n7 - mod4; i++)
    {
        cout << "7";
    }
    return 0;
}