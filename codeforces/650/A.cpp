#include <bits/stdc++.h>
#ifdef MYDEBUG
#include "debug.h"
#else
#define debug(x...)
#endif
using namespace std;

#define t      \
    int t = 1; \
    cin >> t;  \
    while (t--)
#define run ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pb(x) emplace_back(x)
#define pp pop_back
#define fib(n) (int)(pow(((1 + sqrt(5)) / 2), n) - pow((((1 - sqrt(5)) / 2)), n)) / sqrt(5)
#define ROTaTE(v, i) rotate(v.begin(), v.begin() + i, v.end())
#define isPerfect(i) (pow((int)sqrt(i), 2) == i)
#define isFib(n) (isPerfect(5 * n * n + 4) || isPerfect(5 * n * n - 4))
#define input(v)      \
    for (auto &i : v) \
        cin >> i;
#define output(v)    \
    for (auto i : v) \
        cout << i << " ";

#define inputP(v)       \
    for (auto &i : (v)) \
        cin >> i.first >> i.second;
#define yes          \
    cout << "YES\n"; \
    cout.flush();
#define no          \
    cout << "nO\n"; \
    cout.flush();
#define all(i) i.begin(), i.end()
#define rall(i) i.rbegin(), i.rend()
#define int long long
#define MOd 1000000007
#define format(n) setprecision(n)
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
/****************************************
      solution by TheOnlyOne
 ****************************************/

void solve()
{
    int n;
    cin >> n;
    pair<int, int> a[n];
    unordered_map<int, int> Xmp, Ymp, XYmp; 
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
        Xmp[a[i].first]++;
        Ymp[a[i].second]++;
        XYmp[a[i].first * 1000000000LL + a[i].second]++;  
    }
    int  res = 0;
    for (auto i : Xmp)
    {
        int x = i.second;
        res += (x * (x - 1) / 2);
    }
    for (auto i : Ymp)
    {
        int x = i.second;
        res += (x * (x - 1) / 2);
    }
    for (auto i : XYmp)  
    {
        int x = i.second;
        res -= (x * (x - 1) / 2); 
    }
    cout << res;
}

signed main()
{
    run
    solve();
}