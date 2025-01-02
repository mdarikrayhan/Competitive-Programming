#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ll a, b, s, x, c;
    cin >> a >> b >> s;
    x = abs(a) + abs(b);
    if (x == s)
    {
        c = 1;
    }
    else if (x > s)
    {
        c = 0;
    }
    else
    {
        if (s % 2 == 0 && x % 2 == 0)
            c = 1;
        else if (s % 2 == 1 && x % 2 == 1)
            c = 1;
        else
            c = 0;
    }
    if (c == 1)
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}
