#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define int long long
using ll = long long;
const int inf = (int)(1e9 + 8);

template <typename T>
class fenwick {
public:
    std::vector<T> fenw;
    int n;
 
    fenwick(int _n) : n(_n) {
        fenw.resize(n);
    }
 
    void modify(int x, T v) {
        while (x < n) {
            fenw[x] += v;
            x |= (x + 1);
        }
    }
 
    T get(int x) {
        T v{};
        while (x >= 0) {
            v += fenw[x];
            x = (x & (x + 1)) - 1;
        }
        return v;
    }
};
struct Node {
    int x, v;
    Node(int x = 0, int v = 0) { x = x; v = v; }
    bool operator<(const Node & b) const {
        return v != b.v ? v > b.v : x > b.x;
    }
};
struct cmp {
    bool operator()(const Node & a, const Node & b) {
        return a.v != b.v ? a.v > b.v : a.x > b.x;
    }
};
void solve() {
    int n;
    std::cin >> n;
    std::vector<int> x(n);
    std::vector<Node> a(n);
    for (int i = 0; i < n; ++ i) { 
        std::cin >> a[i].x; 
        x[i] = a[i].x;
    }
    for (int i = 0; i < n; ++ i) { 
        std::cin >> a[i].v; 
    }
    std::sort(x.begin(), x.end());
    for (int i = 0; i < n; ++ i) {
        a[i].x = std::lower_bound(x.begin(), x.end(), a[i].x) - x.begin();
    }
    std::sort(a.begin(), a.end());
    fenwick<int> fen1(n + 10), fen2(n + 10);
    int ans = 0;
    for (int i = 0; i < n; ++ i) {
        int sum = fen1.get(n) - fen1.get(a[i].x - 1);
        int cnt = fen2.get(n) - fen2.get(a[i].x - 1);
        ans += sum - cnt * x[a[i].x];
        fen1.modify(a[i].x, x[a[i].x]);
        fen2.modify(a[i].x, 1);
    }
    std::cout << ans << "\n";
}
signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    // std::cin >> T;
    while ( T -- ) {
        solve();
    }
    return 0;
}  