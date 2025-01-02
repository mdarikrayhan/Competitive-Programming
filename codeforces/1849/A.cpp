#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, a, b, c, t;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c;
        if (a <= b + c)
        {
            cout << a * 2 - 1 << '\n';
        }
        else
        {
            cout << (b + c) * 2 + 1 << '\n';
        }
    }
    return 0;
}
