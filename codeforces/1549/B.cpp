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
    int t;
    cin >> t;
    while (t--)
    {
        int m;
        cin >> m;
        string s1, s2;
        cin >> s1 >> s2;
        int maxi = 0;
        for (int i = 0; i < m; i++)
        {
            if (s2[i] == '1')
            {
                if (s1[i] == '0')
                {
                    maxi++;
                }
                else if (s1[i - 1] == '1')
                {
                    maxi++;
                    s1[i - 1] = '3';
                }
                else if (s1[i + 1] == '1')
                {
                    maxi++;
                    s1[i + 1] = '3';
                }
            }
        }
        cout << maxi << nl;
    }
    return 0;
}