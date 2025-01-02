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
 
 
const int MOD = 998244353; // = (119<<23)+1
const int N = 1e6 + 3;
const ll INF = 1e18;
const ld PI = 4*atan((ld)1);
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};

inline int pr(int a, int b) {
    return 1ll * a * b % MOD;
}
 
 
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
 
int a[N];

int main() {
    IOS;
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int res = 1;
        for (int i = n - k; i < n; ++i) {
            if (a[i] > 0) {
                res = 0;
            }
        }

        for (int i = n - 1; i >= 0; --i) {
            if (i - k >= 0) {
                if (a[i - k] == -1) 
                    res = pr(res, i + 1);
                else if (a[i - k] == 0) 
                    res = pr(res, min(i + 1, k + 1));
            }
            else {
                res = pr(res, i + 1);
            }
        }
        cout << res << '\n';
    }
}
