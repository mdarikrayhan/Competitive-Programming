#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;

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
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a=b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a=b, true : false; }

int n, k, l;
vi a;

int work(int flag) {
    auto calc = [&](int lmb) {
        V<array<int, 2>> dp(n+1, {inf, inf});
        dp[0] = {0, 0};
        for (int i = 0; i < n; i++) {
            ckmin(dp[i+1], {dp[i][0]+(a[i]^flag), dp[i][1]});
            if (i+l <= n) ckmin(dp[i+l], {dp[i][0]+lmb, dp[i][1]+1});
        }
        return dp[n];
    };

    int lo = 0, hi = n;
    while (hi-lo > 1) {
        int lmb = (lo+hi)/2;
        calc(lmb)[1] > k ? lo = lmb : hi = lmb;
    }
    if (calc(lo)[1] <= k) return 0;
    return calc(hi)[0] - k*hi;
}

void solve() {
    cin >> n >> k >> l;    
    a.resize(n);
    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        a[i] = c >= 'a';
    } 
    int ans = min(work(0), work(1));
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
