#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long int
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define forx(x, start, stop) for (long long x = start; x < (long long)(stop); x++)
#define forr(x, start, stop) for (long long x = start; x >= (long long)(stop); x--)

mt19937 mt(time(0));
vector<ll> arr;
vector<ll> factors;
ll n, res = -1;

void getFactors(ll num) {
    factors.clear();
    for (ll i = 1; i * i <= num; i++) {
        if (num % i == 0) {
            factors.push_back(i);
            if (num / i != i) factors.push_back(num / i);
        }
    }
    sort(factors.begin(), factors.end());
}

ll findGCD(ll num) {
    int sz = factors.size();
    vector<int> count(sz, 0);

    for (ll i = 0; i < n; i++) {
        ll gcd_val = __gcd(arr[i], num);
        auto it = lower_bound(factors.begin(), factors.end(), gcd_val);
        if (it != factors.end()) {
            int pos = it - factors.begin();
            count[pos]++;
        }
    }

    for (int i = 0; i < sz; i++) {
        for (int j = i + 1; j < sz; j++) {
            if (factors[j] % factors[i] == 0) {
                count[i] += count[j];
            }
        }
    }

    for (int i = sz - 1; i >= 0; i--) {
        if (count[i] * 2 >= n) return factors[i];
    }
    return -1;
}

void solve() {
    cin >> n;
    arr.resize(n);
    for (ll i = 0; i < n; i++) cin >> arr[i];

    uniform_int_distribution<int> dist(0, n - 1);

    for (int i = 0; i < 12; i++) {
        ll idx = dist(mt);
        getFactors(arr[idx]);
        res = max(res, findGCD(arr[idx]));
    }

    cout << res << "\n";
}

int main() {
    IOS
    solve();
    return 0;
}
