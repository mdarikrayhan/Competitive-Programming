// LUOGU_RID: 160227234
#include <bits/stdc++.h>
#include <unordered_map>
#define LL long long
#define ll long long
#define double long double
#define pii pair<int, int>
#define pll pair<LL, LL>
#define pdd pair<double, double>

using namespace std;

pll a[200005];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    LL x, w;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> w;
        a[i] = { x + w, x - w };    
    }
    sort(a + 1, a + n + 1);

    LL ans = 0, r = -1e18;
    for (int i = 1; i <= n; i++)
        if (a[i].second >= r)
        {
            ans++;
            r = a[i].first;
        }

    cout << ans << "\n";
}