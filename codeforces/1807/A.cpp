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
        long long c, d, e;
        cin >> c >> d >> e;
        if ((c + d) == e)
        {
            cout << "+" << endl;
        }
        else
        {
            cout << "-" << endl;
        }
    }
    return 0;
}