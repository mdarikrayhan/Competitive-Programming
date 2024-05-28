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

const ll mod = 998244353;
const ll base = 1e6 + 9;
const ll inf = 1e18;
const int MAX = 2e5 + 42;
const int LG = 20;

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<ll> dis(1, inf);

void solve() {
    int n, m, k;
    cin >> n >> m >> k; k--;
    vector<int> a(n);
    for(auto &i : a) {
        cin >> i;
    }
    sort(all(a));
    int ans_cnt = -1;
    int ans_x = -1;
    auto calc = [&](int x) {
        int ans = 0;
        int i = lower_bound(all(a), x) - a.begin();
        if(i + k >= n) ans += m - x + 1;
        else {
            int lst = a[i + k] - 1;
            ///2 * m - x <= lst
            ///x <= m <= (lst + x) / 2;
            ans += (lst + x) / 2 - x + 1;
        }
        i = upper_bound(all(a), x) - a.begin() - 1;
        if(i - k < 0) ans += x;
        else {
            int lst = a[i - k] + 1;
            ///2 * m - x >= lst
            ///x >= m >= (lst + x) / 2;
            ans += x - (lst + x + 1) / 2;
        }
        if(umax(ans_cnt, ans)) ans_x = x;
        else if(ans_cnt == ans) umin(ans_x, x);
    };
    for(auto p : a) {
        for(int d = -3; d <= 3; d++) {
            int x = p + d;
            if(x < 0 || x > m) continue;
            calc(x);
        }
    }
    for(int d = -3; d <= 3; d++) {
        int x = d;
        if(x < 0 || x > m) continue;
        calc(x);
    }
    cout << ans_cnt << " " << ans_x << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ttt = 1;
//    cin >> ttt;
    while(ttt--) {
        solve();
    }
}