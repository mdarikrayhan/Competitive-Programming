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
    int n, k;
    std::cin >> n >> k;
    std::vector<std::pair<int, ll>> cond(k);
    for(auto &i : cond) {
        std::cin >> i.first;
        i.first--;
    }
    for(auto &i : cond) std::cin >> i.second;
    std::sort(cond.begin(), cond.end());
    std::vector<ll> a(n, 1e12);
    ll min = 1e12, pos = 0;
    for(int i = 0; i < n; i++) {
        if(pos < k && cond[pos].first == i) {
            min = std::min(min, cond[pos].second);
            pos++;
        }
        a[i] = std::min(a[i], min);
        min++;
    }
    pos = k - 1; min = 1e12;
    for(int i = n - 1; i >= 0; i--) {
        if(pos >= 0 && cond[pos].first == i) {
            min = std::min(min, cond[pos].second);
            pos--;
        }
        a[i] = std::min(a[i], min);
        min++;
    }
    for(auto &i : a) std::cout << i << ' ';
    std::cout << '\n';
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