#include<bits/stdc++.h>

using namespace std;

int const maxn = 2e5 + 5;
int a[maxn], nxt[maxn], lst[maxn];
unordered_map < int, int > dp[maxn];

int solve(int l, int r) {
    if (l > r) return 0;
    if (dp[l].find(r) != dp[l].end()) return dp[l][r];
    int lst_v = max(a[l - 1], a[r + 1]);
    if (a[l] > lst_v) {
        if (a[r] <= lst_v) {
            int cnt = min(r, nxt[l]) - l + 1;
            if (cnt % 2 == 0) {
                dp[l][r] = 0;
                return 0;
            } else {
                dp[l][r] = 1;
                return 1;
            }
        }
        if (!solve(l + 1, r)) {
            dp[l][r] = 1;
            return 1;
        }
    }
    if (a[r] > lst_v) {
        if (a[l] <= lst_v) {
            int cnt = r - max(l, lst[r]) + 1;
            if (cnt % 2 == 0) {
                dp[l][r] = 0;
                return 0;
            } else {
                dp[l][r] = 1;
                return 1;
            }
        }
        if (!solve(l, r - 1)) {
            dp[l][r] = 1;
            return 1;
        }
    }
    dp[l][r] = 0;
    return 0;
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    nxt[n] = n;
    for (int i = n - 1; i >= 1; i--) {
        if (a[i] < a[i + 1]) nxt[i] = nxt[i + 1];
        else nxt[i] = i;
    }
    lst[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (a[i - 1] > a[i]) lst[i] = lst[i - 1];
        else lst[i] = i;
    }
    a[0] = -1, a[n + 1] = -1;
    int res = solve(1, n);
    if (res) cout << "Alice\n";
    else cout << "Bob\n";
    return 0;
}

