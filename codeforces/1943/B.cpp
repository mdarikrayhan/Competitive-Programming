// LUOGU_RID: 160154984
#include <bits/stdc++.h>

using i64 = long long;

std::vector<int> manacher(std::string s) {
    std::string t = "#";
    for (auto c : s) {
        t += c;
        t += '#';
    }
    int n = t.size();
    std::vector<int> r(n);
    for (int i = 0, j = 0; i < n; i ++ ) {
        if (2 * j - i >= 0 && j + r[j] > i) {
            r[i] = std::min(r[2 * j - i], j + r[j] - i);
        }
        while (i - r[i] >= 0 && i + r[i] < n && t[i - r[i]] == t[i + r[i]]) {
            r[i] += 1;
        }
        if (i + r[i] > j + r[j]) {
            j = i;
        }
    }
    return r;
}

void solve() {
    int n, q;
    std::cin >> n >> q;
    
    std::string s;
    std::cin >> s;
    
    std::vector<int> f1(n), f2(n);
    for (int i = n - 1; i >= 0; i -- ) {
        f1[i] = i + 1 < n && s[i] == s[i + 1] ? f1[i + 1] : i + 1;
        f2[i] = i + 2 < n && s[i] == s[i + 2] ? f2[i + 2] : i + 2;
    }
    
    auto f = manacher(s);
    
    while (q -- ) {
        int l, r;
        std::cin >> l >> r;
        l--;
        
        i64 ans = 0;
        int len = r - l;
        if (f1[l] < r) {
            int mx = (len - 1) - (len - 1) % 2;
            ans += 1LL * (mx / 2) * (mx + 2) / 2;
        }
        if (f2[l] < r || f2[l + 1] < r) {
            int mx = len - 1 - len % 2;
            ans += 1LL * ((mx - 1) / 2) * (mx + 3) / 2;
        }
        if (f[l + r] <= len) {
            ans += len;
        }
        std::cout << ans << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t -- ) {
        solve();
    }
    
    return 0;
}
