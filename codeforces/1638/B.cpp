#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
void solve()
{
    int n;
    cin >> n;
    vector<int> even, odd, sorteven, sortodd;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (a&1)
        {
            odd.push_back(a);
            sortodd.push_back(a);
        }
        else
        {
            even.push_back(a);
            sorteven.push_back(a);
        }
    }
    sort(sorteven.begin(), sorteven.end());
    sort(sortodd.begin(), sortodd.end());
    if (even == sorteven && odd == sortodd)
    {
        cout << "Yes" << nl;
    }
    else
    {
        cout << "No" << nl;
    }
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