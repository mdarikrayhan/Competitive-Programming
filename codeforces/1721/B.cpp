#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int n, m, sx, sy, d;
        cin >> n >> m >> sx >> sy >> d;
        if (((sy - d > 1) && (d + sx < n)) || ((sx - d > 1) && (d + sy < m)))
        {
            cout << m + n - 2 << '\n';
        }
        else
        {
            cout << -1 << '\n';
        }
    }
    return 0;
}