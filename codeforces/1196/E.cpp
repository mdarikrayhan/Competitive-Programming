#include <iostream>
using namespace std;
typedef long long ll;
void solve() {
    int b, w; cin >> b >> w;
    int ans = 1;
    if (b < w) swap(b, w);
    else ans++;
    if (b > 3 * w + 1) return cout << "NO\n", void();
    cout << "YES\n";
    for (int i = 0; i < w * 2; i++) cout << i + ans + 1 << ' ' << 3 << '\n';
    if (b != w) {
        cout << ans << ' ' << 3 << '\n';
        int x = min(b - w - 1, w) * 2;
        for (int i = 1; i < x; i += 2) cout << i + ans << ' ' << 2 << '\n';
        if (b - w - 1 > w) {
            x = (b - w * 2 - 1) * 2;
            for (int i = 1; i < x; i += 2) cout << i + ans << ' ' << 4 << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1; cin >> t;
    while (t--) solve();
}
