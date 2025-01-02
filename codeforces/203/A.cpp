#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int x, t, a, b, da, db;
    cin >> x >> t >> a >> b >> da >> db;
    multiset<int> v1, v2;
    int cnt = 0;
    for (int i = 0; i < t; i++)
    {
        v1.insert(max(a - (cnt * da), 0ll));
        v2.insert(max(b - (cnt * db), 0ll));
        cnt++;
    }
    v1.insert(0);
    v2.insert(0);
    for (auto i : v1)
    {
        if (x == i)
        {
            cout << "YES" << '\n';
            return 0;
        }
        int f = x - i;
        if (v2.find(f) != v2.end())
        {
            cout << "YES" << '\n';
            return 0;
        }
    }
    for (auto i : v2)
    {
        if (x == i)
        {
            cout << "YES" << '\n';
            return 0;
        }
        int f = x - i;
        if (v1.find(f) != v1.end())
        {
            cout << "YES" << '\n';
            return 0;
        }
    }
    cout << "NO" << '\n';
}