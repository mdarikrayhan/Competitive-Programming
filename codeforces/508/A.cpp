#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define pi 3.141592653589793238462643383279502884197
#define all(ar) ar.begin(), ar.end()
#define rall(ar) ar.rbegin(), ar.rend()
typedef long long ll;
#define S second
#define F first
#define MAX(x) *max_element(all(x));
#define MIN(x) *min_element(all(x));
bool arr[1001][1001];
bool square(ll i, ll j)
{
    if (arr[i][j] && arr[i + 1][j] && arr[i][j + 1] && arr[i + 1][j + 1])

    {
        return true;
    }
    if (arr[i][j] && arr[i - 1][j] && arr[i][j - 1] && arr[i - 1][j - 1])
    {
        return true;
    }
    if (arr[i][j] && arr[i + 1][j] && arr[i][j - 1] && arr[i + 1][j - 1])
    {
        return true;
    }
    if (arr[i][j] && arr[i - 1][j] && arr[i][j + 1] && arr[i - 1][j + 1])
    {
        return true;
    }

    return false;
}
void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;
    for (ll i = 0; i < k; i++)
    {
        ll a, b;
        cin >> a >> b;

        arr[a][b] = true;
        if (square(a, b))
        {
            cout << i+1 << "\n";
            return;
        }
    }
    cout << 0 << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
}
