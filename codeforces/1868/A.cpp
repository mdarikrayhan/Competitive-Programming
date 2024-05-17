#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define forn(i, n) for (int i = 0; i < n; i++)
#define forr(i, n) for (int i = n - 1; i >= 0; i--)
#define all(s) (s).begin(), (s).end()
#define rall(s) (s).rbegin(), (s).rend()

void solve(int nigga)
{
    // Your code goes here
    int n, m;
    cin >> n >> m;

    if (m == 1)
        cout << 0 << endl;
    else if (n >= m)
        cout << m << endl;
    else
        cout << n + 1 << endl;

    for (int i = 0; i < min(m - 1, n); i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << (i + j) % m << " ";
        }
        cout << endl;
    }

    for (int i = min(m - 1, n); i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << j << " ";
            }
            cout << endl;
        }
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

#endif

    int t;
    cin >> t;
    while (t--)
    {
        solve(t);
    }

    return 0;
}