#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define what(x) cout << (#x) << " -> " << x << '\n';
#define cno cout << "NO" \
                 << "\n"
#define cy cout << "YES" \
                << "\n"
#define c1 cout << "-1" << '\n'
#define pb push_back
#define ff first
#define ss second
#define sz size()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

const ll N = 1000005;
const ll mod = 1000000007;
ll n, m, x, y, z, l, r, d, q, mx, mn, sum, temp;
ll a[N];

void solve()
{
    cin >> n;
    l = 0, r = 0;
    for (int i = 1; i <= n; i++)
    {
        char op;
        cin >> op >> x >> y;
        if (x > y)
            swap(x, y);
        if (op == '+')
        {
            l = max(x, l);
            r = max(r, y);
        }
        else
        {
            if (l <= x && r <= y)
                cy;
            else
                cno;
        }
    }
}
int main()
{
    IOS int testcases = 1;

    // cin >> testcases;
    while (testcases--)
    {

        solve();
    }
}
