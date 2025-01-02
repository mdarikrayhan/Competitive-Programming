#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;
const int inf = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    auto dfs = [&](auto dfs, int index, bool empty, int sum) -> bool {
        if (index >= n) {
            return sum == 0 && !empty;
        }
        int op1 = dfs(dfs, index + 1, false, sum - a[index]);
        int op2 = dfs(dfs, index + 1, false, sum + a[index]);
        int op3 = dfs(dfs, index + 1, empty, sum);
        return op1 || op2 || op3;
    };
    bool ans = dfs(dfs, 0, true, 0);
    cout << (ans ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}