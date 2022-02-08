#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
void solve()
{
    int n, k;
    cin >> n >> k;
    if (k >= 2 && n % 2)
        cout << "NO\n";
    else
    {
        cout << "YES\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < k; j++)
            {
                cout << j * n + i + 1 << ' ';
            }
            cout << endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}