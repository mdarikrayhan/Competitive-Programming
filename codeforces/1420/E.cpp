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
    int n;
    cin >> n;
    vector<int> a;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(x) a.pb(i + 1);
    }
    int up = n * (n - 1) / 2;
    if(a.empty()) {
        for(int i = 0; i <= up; i++) cout << "0 "; cout << '\n';
        return;
    }
    int m = sz(a);
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(up + 1, inf)));
    dp[0][0][0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m && j <= i; j++) {
            for(int p = 0; p < i; p++) {
                int sub = abs(a[j - 1] - i);
                int len = i - p - 1;
                int add = len * (len - 1) / 2;
                for(int k = sub; k <= up; k++) {
                    umin(dp[i][j][k], dp[p][j - 1][k - sub] + add);
                }
            }
        }
    }
    vector<int> ans(up + 1, inf);
    for(int k = 0; k <= up; k++) {
        for(int i = 1; i <= n; i++) {
            int len = n - i;
            umin(ans[k], dp[i][m][k] + len * (len - 1) / 2);
        }
    }
    for(int i = 1; i <= up; i++) umin(ans[i], ans[i - 1]);
    for(int i = 0; i <= up; i++) {
        ans[i] = n * (n - 1) / 2 - m * (m - 1) / 2 - m * (n - m) - ans[i];
    }
    for(auto i : ans) cout << i << " "; cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ttt = 1;
//    cin >> ttt;
    while(ttt--) {
        solve();
    }
}
