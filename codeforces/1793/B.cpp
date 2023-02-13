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
        long long x, y, ans = 0;
        cin >> x >> y;
        ans = ((x - y) + (x - 1 - y) + 1);
        vector<long long> ansv;
        for (long long i = y + 1; i <= x; i++)
            ansv.push_back(i);
        for (long long i = x - 1; i >= y; i--)
            ansv.push_back(i);
        cout << ans << nl;
        for (auto it : ansv)
            cout << it << " ";
        cout << nl;
    }
    return 0;
}