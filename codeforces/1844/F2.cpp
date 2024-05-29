#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")

#define f first
#define s second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int) (x).size())
#define pb push_back
#define mp make_pair
#define int long long

using namespace std;
using namespace __gnu_pbds;

template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> inline bool umin(T &a, const T &b) { if(a > b) { a = b; return 1; } return 0; }
template <typename T> inline bool umax(T &a, const T &b) { if(a < b) { a = b; return 1; } return 0; }

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9 + 7;
const ll base = 1e6 + 9;
const ll inf = 1e9;
const int MAX = 2e5 + 42;
const int LG = 20;

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<ll> dis(1, inf);

void solve() {
    int n, c;
    cin >> n >> c;
    vector<int> a(n);
    for(auto &i : a) {
        cin >> i;
    }
    if(n == 1 || c >= 0) {
        sort(all(a));
        for(auto i : a) cout << i << " "; cout << '\n';
        return;
    }
    sort(rall(a));
    vector<int> ans;
    for(int j = n - 1; j > 0; j--) {
        int delta = (j + 1 < n? abs(a[j + 1] - a[j - 1] - c) - abs(a[j + 1] - a[j] - c) : 0) - abs(a[j] - a[j - 1] - c) + abs(a[0] - a[j] - c);
        if(delta == 0) {
            for(int k = j - 1; k >= 0; k--) swap(a[k + 1], a[k]);
            break;
        }
    }
    ans.pb(a[0]);
    set<pii> good;
    set<pii> left;
    for(int i = 1; i < n; i++) {
        if(i != 1 && i + 1 < n && (a[i + 1] - a[i - 1] - c >= 0 || a[i] == a[i - 1] || a[i + 1] == a[i])) good.insert({a[i], i});
        left.insert({i, a[i]});
    }
    auto check = [&](int x, int i) {
        auto it = left.lower_bound({i, x});
        if(it == left.begin()) return;
        ++it;
        if(it == left.end()) return;
        auto [useless_r, r] = *it;
        --it; --it;
        auto [useless_l, l] = *it;
        if(l == x || r == x || r - l - c >= 0) {
            good.insert({x, i});
            return;
        }
    };
    auto change = [&](int j) {
        auto r = left.lower_bound({j, 0}); assert(r != left.end());
        auto [useless_j, y] = *r;
        if(useless_j != j) {
            for(auto i : a) cout << i << ","; cout << c << endl;
            exit(0);
        }
        ans.pb(y);
        if(good.count({y, j})) good.erase({y, j});
        int r_val = 0, r_idx = -1;
        int l_val = 0, l_idx = -1;
        if(r != left.begin()) {
            --r;
            auto [idx, val] = *r;
            if(good.count({val, idx})) good.erase({val, idx});
            r_val = val, r_idx = idx;
            ++r;
        }
        ++r;
        if(r != left.end()) {
            auto [idx, val] = *r;
            if(good.count({val, idx})) good.erase({val, idx});
            l_val = val, l_idx = idx;
        }
        --r;
        left.erase(r);
        if(~r_idx) check(r_val, r_idx);
        if(~l_idx) check(l_val, l_idx);
    };
    for(int i = 1; i + 1 < n; i++) {
        auto it = --left.end();
        auto [useless_r, r] = *it; --it;
        auto [useless_l, l] = *it;
        auto [useless_i, val] = *left.begin();
        int delta = abs(r - l - c) + abs(r - ans.back() - c) - abs(val - ans.back() - c) + abs(val - r - c);
        if(delta == 0) {
            change(n - 1);
            continue;
        }
        ///a[j] >= a[i - 1] + c
        it = good.lower_bound({ans.back() + c, 0});
        if(it != good.end()) {
            auto [x, j] = *it;
            if(x != val) change(j);
            else change(useless_i);
        }
        else change(useless_i);
    }
    assert(sz(left) == 1);
    auto [i, x] = *left.begin();
    ans.pb(x);
    for(auto i : ans) cout << i << " "; cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ttt = 1;
    cin >> ttt;
    while(ttt--) {
        solve();
    }
}
