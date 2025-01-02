#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        long long cx, cy, r, px, py;
        cin >> cx >> cy >> r >> px >> py;
        long long d = (cx - px) * (cx - px) + (cy - py) * (cy - py);
        if (d < r * r)
            cout << "Case " << i << ": "
                 << "yes" << nl;
        else
            cout << "Case " << i << ": "
                 << "no" << nl;
    }
    return 0;
}