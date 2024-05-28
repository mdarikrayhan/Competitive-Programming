#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
// typedef __int128 lll;
// typedef __float128 lld;
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    cin >> n;
    vector<vector<int>> g(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> g[i][j];
        }
    }
    vector<pair<int, pair<int, int>>> o(0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            o.push_back({g[i][j], {i, j}});
        }
    }
    vector<int> r(n, 0), c(n, 0);
    ll ans = 0;
    sort(o.begin(), o.end());
    for(int i = 0; i < o.size(); i++){
        int _r = o[i].second.first;
        int _c = o[i].second.second;
        ll u = r[_r];
        ll v = c[_c];
        ans += u * (n - 1 - v) + v * (n - 1 - u);
        r[_r] ++;
        c[_c] ++;
    }
    ans /= 2;
    cout << ans << "\n";
    
    return 0;
}
