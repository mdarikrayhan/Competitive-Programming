#include <bits/stdc++.h>
using namespace std;
#pragma G++ optimize(2)
#define debug(x) cout << "[debug] " #x << " = " << x << '\n';
#define ull unsigned long long
#define double long double
#define int long long
#define xiaowen ac
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f3f3f3f3f;
const int N = 2e6 + 7;
const int P = 131;

int n, m;
int a[N];
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        mp[a[i] % m]++;
    }
    int res = 0;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        int x = it->first;
        int y = (m - x) % m;
        if (x == 0)
        {
            res++;
        }
        else
        {
            int k1 = mp[x], k2 = mp[y];
            if (k1 != 0 || k2 != 0)
            {
                if (k1 == k2)
                {
                    res++;
                    mp[x] = mp[y] = 0;
                }
                else
                {
                    if (k1 > k2)
                    {
                        res++;
                        mp[x] -= k2 + 1;
                        mp[y] = 0;
                        res += mp[x];
                        mp[x] = 0;
                    }
                    else
                    {
                        res++;
                        mp[y] -= k1 + 1;
                        mp[x] = 0;
                        res += mp[y];
                        mp[y] = 0;
                    }
                }
            }
        }
    }
    cout << res << '\n';
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int T;
    // T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}