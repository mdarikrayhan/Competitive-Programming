#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
void solve()
{
    string s;
    cin >> s;
    set<char> ch;
    int days = 0, n = s.size();
    for(int i=0;i<n;i++)
    {
        
        ch.insert(s[i]);
        if (ch.size() == 4)
        {
            ch.clear();
            days++;
            i--;
        }
    }

    cout << days+1 << nl;
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