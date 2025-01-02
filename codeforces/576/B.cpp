#include <bits/stdc++.h>
#ifdef LOCAL
#include <debug.hpp>
#else
#define debug(...) void(0)
#endif

template <class T> std::istream& operator>>(std::istream& is, std::vector<T>& v) {
    for (auto& e : v) {
        is >> e;
    }
    return is;
}

template <class T> std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
    for (std::string_view sep = ""; const auto& e : v) {
        os << std::exchange(sep, " ") << e;
    }
    return os;
}

template <class T, class U = T> bool chmin(T& x, U&& y) {
    return y < x and (x = std::forward<U>(y), true);
}

template <class T, class U = T> bool chmax(T& x, U&& y) {
    return x < y and (x = std::forward<U>(y), true);
}

template <class T> void mkuni(std::vector<T>& v) {
    std::ranges::sort(v);
    auto result = std::ranges::unique(v);
    v.erase(result.begin(), result.end());
}

template <class T> int lwb(const std::vector<T>& v, const T& x) {
    return std::distance(v.begin(), std::ranges::lower_bound(v, x));
}

namespace atcoder {

// Implement (union by size) + (path compression)
// Reference:
// Zvi Galil and Giuseppe F. Italiano,
// Data structures and algorithms for disjoint set union problems
struct dsu {
  public:
    dsu() : _n(0) {}
    explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    // root node: -1 * component size
    // otherwise: parent
    std::vector<int> parent_or_size;
};

}  // namespace atcoder

using ll = long long;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int n;
    cin >> n;
    vector<int> p(n);
    for (int& val : p) {
        cin >> val;
        val--;
    }

    atcoder::dsu dsu(n);
    for (int i = 0; i < n; i++) dsu.merge(i, p[i]);
    int r = -1, mini = n + 1;
    for (int i = 0; i < n; i++) {
        if (dsu.leader(i) != i) continue;
        if (dsu.size(i) < mini) {
            r = i;
            mini = dsu.size(i);
        }
    }
    for (int i = 0; i < n; i++) {
        if (dsu.size(i) % mini != 0) {
            cout << "NO\n";
            return 0;
        }
    }
    if (mini >= 3) {
        cout << "NO\n";
        return 0;
    }

    vector<pair<int, int>> ans;
    vector<bool> seen(n, false);
    for (int i = 0; i < n; i++) {
        if (dsu.same(r, i)) {
            if (i != r) ans.emplace_back(i, r);
            continue;
        }
        if (seen[i]) continue;
        for (int j = i, k = r; not seen[j]; j = p[j], k = p[k]) {
            ans.emplace_back(j, k);
            seen[j] = true;
        }
    }

    cout << "YES\n";
    for (auto [a, b] : ans) cout << a + 1 << ' ' << b + 1 << '\n';
    return 0;
}
