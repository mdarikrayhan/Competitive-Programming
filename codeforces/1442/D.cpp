#include <bits/stdc++.h>
using namespace std;
#define int int64_t

#ifdef LOCAL
#include "algo/debug.h"
#endif

#define f first
#define s second
template<class T> using V = vector<T>; 
using vi = V<int>;
using vb = V<bool>;
using vs = V<string>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x) 
#define pb push_back
#define lb lower_bound
#define ub upper_bound
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-begin(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-begin(a); }

const int max_n = 3000;
int n, k, sum[max_n], ans;
vi inp[max_n], dp;

void dnc(int l, int r) {
    if (l == r-1) {
        int cur = 0, cnt = 0;
        for (int i = 0; i <= inp[l].size(); i++) {
            if (cnt > k) break;
            if (dp[k-cnt] != -1) ans = max(ans, dp[k-cnt]+cur);
            if (i < inp[l].size()) cur += inp[l][i], cnt++;
        }
        return;
    }

    auto add_to_knapsack = [&](int L, int R) {
        for (int i = L; i < R; i++) {
            for (int j = max_n-inp[i].size(); j >= 0; j--) {
                dp[j+inp[i].size()] = max(dp[j+inp[i].size()], dp[j]+sum[i]);
            }
        }
    };

    auto rollback = dp;
    int m = (l+r)/2;

    add_to_knapsack(m, r);
    dnc(l, m);
    dp = rollback;

    add_to_knapsack(l, m);
    dnc(m, r);
    dp = rollback;
}

void solve() {
    dp.assign(max_n+1, -1);
    dp[0] = 0;

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int sz; cin >> sz; inp[i].resize(sz);
        for (auto& x : inp[i]) cin >> x, sum[i] += x;
    }
    dnc(0, n);
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
