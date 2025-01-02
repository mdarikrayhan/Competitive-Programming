#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

int ceilLog(int x) {
    int y = 0;
    while((1 << y) < x)
        y++;
    return y;
}

void solve() {
    int n, k;
    std::cin >> n >> k;

    std::string t;
    std::cin >> t;

    int m = std::min(k, ceilLog(n - k + 2));
    std::vector<int> used(1 << m, 0);
    std::vector<int> next0(n, int(1e9));

    if (t[n - 1] == '0')
        next0[n - 1] = n - 1;
    for (int j = n - 2; j >= 0; j--)
        if (t[j] == '0')
            next0[j] = j;
        else
            next0[j] = next0[j + 1];

    int d = k - m;
    for (int j = 0; j < n - k + 1; j++) {
        if (next0[j] - j < d)
            continue;
        int cur = 0;
        for (int x = j + d; x < j + k; x++)
            cur = cur * 2 + (t[x] - '0');
        used[((1 << m) - 1) ^ cur] = 1;
    }

    int ans = -1;
    for (int j = 0; j < (1 << m); j++) {
        if (used[j] == 0) {
            ans = j;
            break;
        }
    }

    if (ans == -1) {
        std::cout << "NO\n";
    } else {
        std::cout << "YES\n";
        std::string res(d, '0');
        std::string res2;
        for (int j = 0; j < m; j++) {
            res2.push_back('0' + (ans % 2));
            ans /= 2;
        }
        std::reverse(res2.begin(), res2.end());
        res += res2;
        std::cout << res << '\n';
    }
}

int main() {
    int q;
    std::cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}
