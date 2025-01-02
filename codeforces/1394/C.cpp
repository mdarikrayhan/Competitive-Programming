// LUOGU_RID: 159981251
/**
 * @author : cyb1010
 * @date   : 2024-05-23 18:34:53
 * @file   : Boboniu_and_String.cpp
 */
#include <bits/stdc++.h>
using namespace std;
#define fo(s) freopen(s ".in", "r", stdin), freopen(s ".out", "w", stdout)
#define fi first
#define se second
typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
int __, n, t[300010][3], f[2];
string s;
bool chk(int x) {
    int mx[3] = {500010, 500010, 500010}, mn[3] = {0, 0, -500010};
    for (int i = 1; i <= n; i++) {
        mn[0] = max(mn[0], t[i][0] - x), mx[0] = min(mx[0], t[i][0] + x);
        mn[1] = max(mn[1], t[i][1] - x), mx[1] = min(mx[1], t[i][1] + x);
        mn[2] = max(mn[2], t[i][2] - x), mx[2] = min(mx[2], t[i][2] + x);
    }
    if (mn[0] > mx[0] || mn[1] > mx[1] || mn[2] > mx[2] || mx[1] - mn[0] < mn[2]
        || mn[1] - mx[0] > mx[2])
        return false;
    f[0] = mx[0], f[1] = mn[1];
    while (f[1] - f[0] < mn[2] && f[1] < mx[1]) f[1]++;
    while (f[1] - f[0] < mn[2] && f[0] > mn[0]) f[0]--;
    return true;
}
int main() {
    // fo("Boboniu_and_String");
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int _ = 1; _ <= n; _++) {
        cin >> s;
        for (auto i : s) t[_][i == 'B']++;
        t[_][2] = t[_][1] - t[_][0];
    }
    int l = 0, r = 500000, mid, ans;
    while (l <= r) {
        if (chk(mid = l + r >> 1))
            ans = mid, r = mid - 1;
        else
            l = mid + 1;
    }
    cout << ans << '\n';
    while (f[1]--) cout << 'B';
    while (f[0]--) cout << 'N';
    return 0 ^ __ ^ 0;
}