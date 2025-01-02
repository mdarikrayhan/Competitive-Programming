#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> a(n), b(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int i = 0; i < n; i++){
            cin >> b[i];
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        ll ans = 0;
        for(int i = 0; i < n; i++){
            ll cans = 1e9;
            for(int j = 0; j < n; j++){
                cans = min(cans, abs(a[j] - b[(j + i) % n]));
            }
            ans = max(ans, cans);
        }
        cout << ans << "\n";
    }
    
    return 0;
}