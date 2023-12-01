/***************************************************/
/*            Author : Md. Arik Rayhan             */
/*        Github : github.com/mdarikrayhan         */
/***************************************************/
#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';

typedef long long ll;

#define rep(i, a, b) for (int i = a; i < (b); i++)

ll n, matrix[1005][1005], ans[1005];

void input()
{
    cin >> n;
    rep(i, 0, n)
    {
        int val = INT_MAX;
        rep(j, 0, n)
        {
            cin >> matrix[i][j];
            if (i != j)
            {
                val &= matrix[i][j];
            }
        }
        ans[i] = val;
    }
}
bool solve()
{
    rep(i, 0, n)
    {
        rep(j, 0, n)
        {
            if (i != j && (ans[i] | ans[j]) != matrix[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        input();
        if (solve())
        {
            cout << "YES" << nl;
            rep(i, 0, n)
            {
                if (ans[i] == INT_MAX)
                {
                    ans[i] = 7;
                }
                cout << ans[i] << " ";
            }
            cout << nl;
        }
        else
        {
            cout << "NO" << nl;
        }
    }
    return 0;
}