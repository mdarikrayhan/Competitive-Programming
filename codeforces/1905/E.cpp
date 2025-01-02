#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

long long binpow(long long a, long long b) {
    if (b == 0) {
        return 1;
    }
    long long c = binpow(a, b / 2);
    if (b % 2 == 0) {
        return c * c % MOD;
    } else {
        return c * c % MOD * a % MOD;
    }
}

void solve() {
    long long n;
    cin >> n;

    long long res = 0;
    // {cnt (# nodes with this amount of leaves), sum (sum of nodes with this amount of leaves), leaves}
    deque<tuple<long long, long long, long long>> dq;
    dq.emplace_back(1, 1, n);
    while (!dq.empty()) {
        auto [cnt, sum, leaves] = dq.front();
        dq.pop_front();

        long long half1 = (leaves + 1) / 2;
        long long half2 = leaves - half1;

        if (leaves == 1) {
            res += sum;
            res %= MOD;
            break;
        } else {
            res += (binpow(2, leaves) - binpow(2, half1) - binpow(2, half2) + 1) % MOD * sum % MOD + MOD;
            res %= MOD;
        }

        if (!dq.empty() && half1 == get<2>(dq.back())) {
            get<0>(dq.back()) = (get<0>(dq.back()) + cnt) % MOD;
            get<1>(dq.back()) = (get<1>(dq.back()) + sum * 2) % MOD;
        } else {
            dq.emplace_back(cnt, 2 * sum % MOD, half1);
        }
        
        if (!dq.empty() && half2 == get<2>(dq.back())) {
            get<0>(dq.back()) = (get<0>(dq.back()) + cnt) % MOD;
            get<1>(dq.back()) = (get<1>(dq.back()) + sum * 2 + cnt) % MOD;
        } else {
            dq.emplace_back(cnt, (2 * sum + cnt) % MOD, half2);
        }
    }
    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}