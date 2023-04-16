/***************************************************/
/*                  Md. HAFIZ AHMED                */
/*               DEPARTMENT OF CSE,BAUET           */
/***************************************************/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define nl '\n'
#define successfull return 0

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    string s, t;
    cin >> s >> t;
    int n = s.size();
    for (int i = 0; i < n; ++i)
    {

        if (s.back() == t.back())
        {
            s.pop_back();
            t.pop_back();
        }
        else
        {
            break;
        }
    }

    cout << s.size() + t.size() << nl;

    successfull;
}