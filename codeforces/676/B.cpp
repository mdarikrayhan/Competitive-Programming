#include <bits/stdc++.h>

typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
const ll modular = 1e9 + 7;
const double pi = acos(-1.0);

double glass[11][11];

void find_ans(ll row, ll col, ll maxi)
{
    if (row > maxi || col > maxi)
        return;

    if (glass[row][col] >= 1.0000)
    {
        double extra = glass[row][col];
        glass[row][col] = 1.00000000;
        extra -= glass[row][col];
        extra /= 2.00;
        glass[row + 1][col] += extra;
        glass[row + 1][col + 1] += extra;
        find_ans(row + 1, col, maxi), find_ans(row + 1, col + 1, maxi);
    }
    return;
}

void solve()
{
    ll num, time;
    cin >> num >> time;

    glass[1][1] = time;
    find_ans(1, 1, num);

    ll ans = 0;
    for (ll i = 1; i <= num; i++)
    {
        for (ll j = 1; j <= i; j++)
            if (glass[i][j] >= 1.000000)
                ans++; // cout<<glass[i][j]<<" ";
        // cout<<endl;
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    n = 1;
    // cin >> n;
    for (ll i = 1; i <= n; ++i)
    {
        // cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}