#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, m;
    cin >> n >> m;
    long long a;
    if (n == m)
    {
        a = n - 1;
        if (a == 0)
        {
            a++;
        }
    }
    else if (m > n / 2)
    {
        a = m - 1;
    }
    else
    {
        a = m + 1;
    }
    cout << a << endl;
}