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
        int n;
        cin >> n;
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            sum += x;
        }
        cout << "Case " << i << ": " << sum / n << "\n";
    }
    return 0;
}