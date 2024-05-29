#pragma GCC optimize("O3")
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define IOS ios::sync_with_stdio(false); cin.tie(0)
#define ll long long
#define ld long double
#define mp(a, b) make_pair(a, b)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pil pair<int, ll>
#define pli pair<ll, int>
#define fi first
#define se second
 
 
const int MOD = 1e9+7; // 998244353; // = (119<<23)+1
const int MX = 2e5+5;
const ll INF = 1e18;
const ld PI = 4*atan((ld)1);
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
 
 
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
 
int main() {
    IOS;
    int n;
    cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    int mx = *max_element(b.begin(), b.end());
    int ind = -1;
    for (int i = 0; i < n; ++i) {
        if (b[i] == mx && b[(i - 1 + n) % n] != mx) {
            ind = i;
        }
    }
    if (ind == -1) {
        if (mx == 0) {
            cout << "YES\n";
            for (int i = 0; i < n; ++i) {
                cout << 1 << ' ';
            }
            cout << '\n';
        }
        else {
            cout << "NO\n";
        }
        return 0;
    }
    cout << "YES\n";
    vector<ll>a(n);

    a[ind] = 2 * b[ind];
    for (int i = 1; i < n; ++i) {
        int cur = (ind - i + n) % n;
        a[cur] = a[(cur + 1) % n] + b[cur];
    }
    a[ind] = b[ind];

    for (auto x : a) {
        cout << x << ' ';
    }
    cout << '\n';
}
