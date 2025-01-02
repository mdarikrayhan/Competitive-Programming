#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){

    int n; cin >> n;
    int l , r;
    cin >> l >> r;

    vector < int > v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    sort(v.begin(), v.end());
    int ans = 0;

    for(int i = 0; i < n; i++){
        int x = l-v[i];
        int y = r-v[i];

        //if(x <= v[0] && y >= v[n-1]) ans--;

         ans += (upper_bound(v.begin(), v.end(), y) - lower_bound(v.begin(), v.end(), x));

         if (l <= 2 * v[i] && 2 * v[i] <= r) ans--;

        //cout << m << p << 'a';
        // if(m < n && p < n) ans++;
    }

    cout << ans/2 << '\n';

}

int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        solve();
    }
}