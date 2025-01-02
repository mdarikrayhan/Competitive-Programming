#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using i128 = __int128_t;
using uint = unsigned;
using ull = unsigned long long;
using u128 = __uint128_t;
using pii = pair<int, int>;

int sz(auto&& x) { return int(size(x)); }

const auto& range = views::iota;

// End template

struct Truck {
    int x, c, l, r;
};

struct Key {
    int s, t;

    friend auto operator<=>(Key, Key) = default;
};

struct Value {
    int x, i;

    friend auto operator<=>(Value, Value) = default;
};

void solve() {
    int n;
    cin >> n;
    vector<Truck> a(n);
    for (auto& [x, c, l, r] : a) cin >> x >> c >> l >> r;

    map<Key, Value> dp;
    vector par(n, -1);
    for (int i = 0; auto [x, c, l, r] : a) {
        Value val = {-1, -1};
        if (l == 0) {
            par[i] = -1;
            val = {x, i};
        } else {
            auto it = dp.find({l, r + c});
            if (it != end(dp)) {
                auto [d, p] = it->second;
                par[i] = p;
                val = {d + x, i};
            }
        }

        if (val.x != -1) {
            auto it = dp.find({l + c, r});
            if (it == end(dp)) {
                dp[{l + c, r}] = val;
            } else {
                it->second = max(it->second, val);
            }
        }

        i++;
    }

    Key best = {-1, -1};
    for (auto& [k, v] : dp) {
        if (k.t == 0 && (best.s == -1 || v > dp[best])) {
            best = k;
        }
    }

    if (best.s == -1) {
        cout << "0\n";
    } else {
        vector<int> ans;
        for (auto i = dp[best].i; i != -1; i = par[i]) {
            ans.push_back(i);
        }

        cout << sz(ans) << '\n';
        for (auto i : range(0, sz(ans)) | views::reverse) {
            cout << ans[i] + 1 << " \n"[i == 0];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}

 				 	   	    	 	    	   	  	