#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

auto read(int n) {
    vector<int64_t> x(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    return x;
}

void setmin(int64_t& a, int64_t b) { a = min(a, b); }
static const int64_t inf = INT64_MAX / 5;
using vi = vector<int64_t>;

auto solve_dp() {
    int N, s, e;
    cin >> N >> s >> e;
    auto x = read(N);
    auto a = read(N); // lin
    auto b = read(N); // rin
    auto c = read(N); // lout
    auto d = read(N); // rout

    vector<int64_t> lin(N + 1), rin(N + 1), lout(N + 1), rout(N + 1);
    for (int i = 1; i <= N; i++) {
        lin[i] = a[i] + x[i];
        rin[i] = b[i] - x[i];
        lout[i] = c[i] + x[i];
        rout[i] = d[i] - x[i];
    }
    lin[s] = rin[s] = lout[e] = rout[e] = inf + inf;

    vector<int64_t> dp(N + 2, inf);
    if (s == 1) {
        dp[1] = rout[1];
    } else if (e == 1) {
        dp[0] = rin[1];
    } else {
        dp[1] = rin[1] + rout[1];
    }

    // If we start and end here, or neither, #out=#in
    // If we start but don't end here, #out=#in+1
    // If we end but don't start here, #out=#in-1
    // ! We track #out. At the end we have #out=#in=0.

    auto in = [&](int k, int i) { return k - (i >= s) + (i >= e); };

    for (int i = 2; i <= N; i++) {
        vector<int64_t> dn(N + 2, inf);
        for (int k = 0; k <= i; k++) {
            if (in(k, i) < 0) {
                continue;
            }
            // We go to the right
            if (i == s && k > 0) {
                setmin(dn[k], rout[i] + dp[k - 1]);
            }
            // We go to the left
            if (i == s && in(k, i - 1) > 0) {
                setmin(dn[k], lout[i] + dp[k]);
            }
            // We come from the left
            if (i == e) {
                setmin(dn[k], lin[i] + dp[k + 1]);
            }
            // We come from the right
            if (i == e && in(k, i) > 0) {
                setmin(dn[k], rin[i] + dp[k]);
            }
            // We come from the right and then go to the right
            if (k > 0 && in(k, i) > 0) {
                setmin(dn[k], rin[i] + rout[i] + dp[k - 1]);
            }
            // We come from the right and then go to the left
            if (in(k, i) > 0 && in(k, i - 1) > 0) {
                setmin(dn[k], rin[i] + lout[i] + dp[k]);
            }
            // We come from the left and then go to the right
            if (k > 0) {
                setmin(dn[k], lin[i] + rout[i] + dp[k]);
            }
            // We come from the left and then go back to the left
            if (in(k + 1, i - 1) > 0) {
                setmin(dn[k], lin[i] + lout[i] + dp[k + 1]);
            }
        }
        swap(dn, dp);
    }

    cout << dp[0] << '\n';
}

auto solve_pq() {
    int N, s, e;
    cin >> N >> s >> e;
    auto x = read(N);
    auto a = read(N); // lin
    auto b = read(N); // rin
    auto c = read(N); // lout
    auto d = read(N); // rout

    vector<int64_t> lin(N + 1), rin(N + 1), lout(N + 1), rout(N + 1);
    for (int i = 1; i <= N; i++) {
        lin[i] = a[i] + x[i];
        rin[i] = b[i] - x[i];
        lout[i] = c[i] + x[i];
        rout[i] = d[i] - x[i];
    }
    lin[s] = rin[s] = lout[e] = rout[e] = inf + inf;

    auto cost = [&](int i, int j) {
        return i == j ? 0 : i < j ? rout[i] + lin[j] : lout[i] + rin[j];
    };

    priority_queue<int64_t, vector<int64_t>, greater<int64_t>> pq;

    // j i s -> lout[i]+lin[i] + rin[i]-lin[i]
    // j s i -> lout[i]+lin[i] + rout[s]-lout[s]
    // s j i -> lout[i]+lin[i] + rin[j]-lin[j]
    // j i e -> lout[i]+lin[i] + rout[i]-lout[i]
    // j e i -> lout[i]+lin[i] + rin[e]-lin[e]
    // e j i -> lout[i]+lin[i] + rout[j]-lout[j]

    int64_t ans = cost(s, 1) + cost(1, e);

    for (int i = 2; i <= N; i++) {
        if (i == s) {
            pq.push(rout[i] - lout[i]);
            continue;
        }
        if (i == e) {
            pq.push(rin[i] - lin[i]);
            continue;
        }
        if (i < s) {
            pq.push(rin[i] - lin[i]);
        }
        if (i < e) {
            pq.push(rout[i] - lout[i]);
        }
        int64_t add = pq.top();
        ans += add + lout[i] + lin[i];
        pq.pop();
        if (i > s) {
            pq.push(rin[i] - lin[i]);
        }
        if (i > e) {
            pq.push(rout[i] - lout[i]);
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cout << solve_pq() << '\n';
    return 0;
}