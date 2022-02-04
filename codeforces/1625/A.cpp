/***************************************************/
/*https://codeforces.com/problemset/problem/1625/A */
/*            Author : Md. Arik Rayhan             */
/*        Github : github.com/mdarikrayhan         */
/***************************************************/

#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, l;
    cin >> n >> l;
    int a[n];
    int c1[l] = {0};
    int c2[l] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        for (int j = 0; j < l; j++)
        {
            if (a[i] & (1 << j))
            {
                c1[j]++;
            }
            else
            {
                c2[j]++;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < l; i++)
    {
        if (c1[i] > c2[i])
        {
            ans = ans + pow(2, i);
        }
    }
    cout << ans << endl;
    return;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}