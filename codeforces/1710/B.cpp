#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<ll> l(n), r(n);
        map<ll, ll> jmen;
        for (int i = 0; i < n; ++i) {
            ll c, p;
            cin >> c >> p;
            l[i] = c - p;
            r[i] = c + p;
            jmen[l[i]]++;
            jmen[c] -= 2;
            jmen[r[i]]++;
        }
        ll h = -m;
        ll pref = 0, prev = -2e9;
        ll st = 1e18, dr = -1e18;
        for (auto it : jmen) {
            h += pref * (it.first - prev);
            pref += it.second;
            prev = it.first;
            if (h > 0) {
                st = min(st, it.first - h);
                dr = max(dr, it.first + h);
            }
        }
        for (int i = 0; i < n; ++i) {
            cout << (l[i] <= st && dr <= r[i] ? 1 : 0);
        }
        cout << "\n";
    }
    return 0;
}

