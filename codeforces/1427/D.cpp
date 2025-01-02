#include <bits/stdc++.h>
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define all(x) (x).begin(), (x).end()

template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order, order_of_key

void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (auto &i : v) cin >> i;
    auto isSorted = [&] (vector<ll> &z) {
        for (ll i = 0; i < z.size(); i++) {
            if (z[i] != i + 1) return false;
        }
        return true;
    };
    auto createV = [&] (vector<ll> &nw, ll l, ll r) {
        for (ll i = l; i < l + r; i++) {
            nw.push_back(v[i]);
        }
    };
    vector<vector<ll>> ans;
    while (!isSorted(v)) {
        map<ll, ll> mp;
        vector<ll> d, nw;
        for (ll i = 0; i < n; i++) {
            mp[v[i]] = i;
            if (mp.find(v[i] + 1) != mp.end()) {
                ll prev = mp[v[i] + 1];
                ll mid = i, val = v[i];
                while (mid - 1 >= 0 && v[mid - 1] == val - 1) {
                    mid--;
                    val--;
                }
                if (n - 1 - i > 0) {
                    d.push_back(n - 1 - i);
                    createV(nw, i + 1, n - 1 - i);
                }
                if (i - mid >= 0) {
                    d.push_back(i - mid + 1);
                    createV(nw, mid, i - mid + 1);
                }
                if (mid - prev > 0) {
                    d.push_back(mid - prev);
                    createV(nw, prev, mid - prev);
                }
                if (prev != 0) {
                    d.push_back(prev);
                    createV(nw, 0, prev);
                }
                reverse(all(d));
                ans.push_back(d);
                v = nw;
                break;
            }
        }
    }
    cout << ans.size() << '\n';
    for (auto &i : ans) {
        cout <<  i.size() << " ";
        for (auto &j : i) cout << j << " ";
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}