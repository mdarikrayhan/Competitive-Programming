#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
constexpr int V = 1E7;

void solve() {
    int a, b;
    cin >> a >> b;
    a = abs(a); b = abs(b);
    int x = min(a, b);
    int ans = max(a - x, b - x) * 2;
    if (ans)
        ans--;
    ans += 2 * x;
    cout << ans << endl;
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}