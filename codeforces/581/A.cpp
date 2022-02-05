#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int r = 0, b = 0, f = 0, w = 0;
    cin >> r >> b;
    if (r == b)
    {
        f = r;
        w = 0;
    }
    else if (r < b)
    {
        f = r;
        w = (b - r) / 2;
    }
    else if (r > b)
    {
        f = b;
        w = (r - b) / 2;
    }
    cout << f << " " << w;
    return 0;
}