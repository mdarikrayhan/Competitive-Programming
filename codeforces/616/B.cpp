/***************************************************/
/*            Author : Md. Arik Rayhan             */
/*        Github : github.com/mdarikrayhan         */
/***************************************************/
#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    int maxi = INT_MIN, index;
    long long a[100][100];
    for (int i = 0; i < n; i++)
    {
        long long mini = INT_MAX;
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            mini = min(mini, a[i][j]);
        }
        if (mini > maxi)
        {
            maxi = mini;
            index = i;
        }
    }
    long long mini = INT_MAX;
    for (int j = 0; j < m; j++)
    {
        mini = min(mini, a[index][j]);
    }
    cout << mini << nl;

    return 0;
}