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
    long long ans = 0;
    for (int i = 1; i <= T; i++)
    {
        string s;
        cin >> s;
        if (s == "++X" || s == "X++")
        {
            ans++;
        }
        else
        {
            ans--;
        }
    }
    cout << ans << nl;
    return 0;
}