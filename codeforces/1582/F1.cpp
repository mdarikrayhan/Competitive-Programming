// LUOGU_RID: 160209491
#include <bits/stdc++.h>
#include <climits>
#define lowbit(x) ((x) & -(x))
#define endl "\n"
#define dbg(a) cout << #a << ": " << a << "\n";

using std::cin, std::cout, std::string;
using pii = std::pair<int, int>;
using PII = std::pair<int, int>;
using Pll = std::pair<long long,long long>;
using ull = unsigned long long;
using ll = long long;
const int N = 5e5 + 10;
const int M = 1e5 + 10;
const int inf = INT_MAX;
const ll INF = LONG_LONG_MAX;
const int mod = 998244353;

void solve() {
    int n;
    cin >> n;

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    std::vector<int> dp(513, inf);
    dp[0] = 0;

    std::vector<int> ans(513, 0);
    ans[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 512; j++) {
            if (a[i] >= dp[j]) {
                dp[j ^ a[i]] = std::min(dp[j ^ a[i]], a[i]);
                ans[j ^ a[i]] = 1;
            }
        }
    }

    int res = 0;
    for (int i = 0; i <= 512; i++) if (ans[i]) res++;

    cout << res << endl;
    for (int i = 0; i <= 512; i++) {
        if (ans[i]) cout << i << " ";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}