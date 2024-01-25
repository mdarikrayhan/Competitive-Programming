#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, x, ans = 0;
    unordered_map<int, int> mp;
    vector<int> p2(31);
    for (int i = 0; i < 31; ++i)
    {
        p2[i] = 1 << i;
    }

    cin >> n;
    while (n--)
    {
        cin >> x;
        for (auto i : p2)
        {
            ans += mp[i - x];
        }
        mp[x]++;
    }
    cout << ans << nl;

    return 0;
}