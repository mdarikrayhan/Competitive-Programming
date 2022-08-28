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
        int n, m, sx, sy, d, ans;
        cin >> n >> m >> sx >> sy >> d;
        ans=m+n-2;
        if ((sy - d > 1) && (d + sx < n))
        {
            cout<<ans<<'\n';
        }
        else if ((sx - d > 1) && (d + sy < m))
        {
            cout<<ans<<'\n';
        }
        else
        {
            cout << "-1" << '\n';
        }
    }
    return 0;
}