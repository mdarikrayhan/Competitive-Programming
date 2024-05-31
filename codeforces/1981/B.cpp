#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
constexpr int mod = 998244353;
constexpr int N = 2e5 + 10;

int calc(int l, int r) {
    if (l > r) return 0;
    int ans = 0;
    for (int i = 30; i >= 0; i--) {
        int x = l >> i & 1;
        int y = r >> i & 1;
        if (x != y) {
            ans |= (1 << i + 1) - 1;
            break;
        } else if (x) {
            ans |= (1 << i);
        }
    }
    return ans;
}
void solve() {
    int n, m;
    cin >> n >> m;
    cout << calc(max(0, n - m), n + m) << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}