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
        int n, c[101] = {0}, tmp;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            c[tmp]++;
        }
        int h = 0, m;
        for (int i = 0; i <= 100; i++)
        {
            if (c[i] >= h)
            {
                h = c[i];
                m = i;
            }
        }
        cout << "Case " << i << ": " << m << " " << h << nl;
    }
    return 0;
}