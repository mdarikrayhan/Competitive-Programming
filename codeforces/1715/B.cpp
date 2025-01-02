#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        ll k, b, s;
        cin >> n >> k >> b >> s;

        ll min_sum = k * b;  
        ll max_sum = min_sum + (k - 1) * n;  

        if (s < min_sum || s > max_sum) {
            cout << -1 << endl;
            continue;
        }

        vector<ll> a(n, 0);

        
        a[0] = min_sum;
        s -= min_sum;

       
        for (int i = 0; i < n && s > 0; ++i) {
            ll add = min(s, k - 1);
            a[i] += add;
            s -= add;
        }

        for (const auto& x : a) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
