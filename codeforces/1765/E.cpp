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
    int t, n, a, b;
    cin >> t;
    while (t--)
    {
        cin >> n >> a >> b;
        if (a > b)
        {
            cout << 1 << nl;
        }
        else
        {
            if (n % a == 0)
            {
                cout << n / a << nl;
            }
            else
            {
                cout << n / a + 1 << nl;
            }
        }
    }
    return 0;
}