#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, m, r;
    cin >> a >> b >> m >> r;
    int ans = 1;
    int st = (a * r + b) % m;
    map<int, int> mp;
    mp[r] = 0;
    while (!mp.count(st))
    {
        mp[st] = ans;
        st = (a * st + b) % m;
        ans += 1;
    }
    cout << ans - mp[st] << "\n";
 return 0;
}
