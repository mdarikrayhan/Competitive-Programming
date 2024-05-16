#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define endl "\n"
#define mod 1000000007 // 1e9+7

bool solve(int hc, int dc, int hm, int dm, int k, int w, int a)
{
    for (int j = 0; j <= k; j++)
    {
        int i = k - j;
        int chH = hc + i * a; // new health
        int chD = dc + j * w; // new damage

        int n1 = ceil(static_cast<double>(chH) / dm);
        int n2 = ceil(static_cast<double>(hm) / chD);
        if (n1 >= n2)
            return true;
    }
    return false;
}

void Vatsh()
{
    // Your logic goes here
    int hc, dc, hm, dm, k, w, a;
    cin >> hc >> dc >> hm >> dm >> k >> w >> a;

    if (solve(hc, dc, hm, dm, k, w, a))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt = 1;
    cin >> tt;
    while (tt--)
        Vatsh();

    return 0;
}