#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n; cin >> n;
    int ans = 0;
    map<int, int> m;
    for (int i = 0; i < n; ++i){
        int x; cin >> x;
        ans += m[log2(x)];
        ++m[log2(x)];
    }
    cout << ans << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(12) << fixed;

    int t = 1; cin >> t;
    while(t--) solve();
    
    return 0;
}