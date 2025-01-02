#define _USE_MATH_DEFINES

#include "iostream"
#include "vector"
#include "map"
#include "iomanip"
#include "set"
#include "queue"
#include "deque"
#include "algorithm"
#include "cmath"
#include "string"
#include "random"
#include "ctime"
#include "chrono"


using ll = long long;

int MOD = 1e9 + 7;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for(auto &i : a) std::cin >> i;
    int min = 1e9, max = -1e9;
    for(int i = 0; i < n; i++) {
        if(a[i] != -1) {
            if((i - 1 >= 0 && a[i - 1] == -1) || (i + 1 < n && a[i + 1] == -1)) {
                min = std::min(min, a[i]);
                max = std::max(max, a[i]);
            }
        }
    }
    if(max == -1e9) {
        std::cout << 0 << ' ' << 0 << '\n';
        return;
    }
    int k = (max + min) / 2;
    int m = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == -1) {
            a[i] = k;
        }
        if(i) {
            m = std::max(m, std::abs(a[i] - a[i - 1]));
        }
    }
    std::cout << m << ' ' << k << '\n';
}

signed main() {
#ifdef LOCAL
    freopen("../in.txt", "r", stdin);
    freopen("../out.txt", "w", stdout);
#endif
    int t;
    std::cin >> t;
//    t = 1;
    while(t--) {
        solve();
    }
}