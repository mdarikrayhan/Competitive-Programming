#include "bits/stdc++.h"

using namespace std;

#define int long long

const int sz = 2e5 + 5;

void solve()
{
    int n, k;
    cin >> n >> k;
    multiset<int> s;
    for(int i = 1; i <= k; i++) s.insert(0);
    for(int i = 1; i <= n; i++) 
    {
        int t, m;
        cin >> t >> m;
        cout << max(t, *s.begin()) + m << endl;
        s.insert(max(t, *s.begin()) + m);
        s.erase(s.begin());
    }
}

signed main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++) solve();
}
