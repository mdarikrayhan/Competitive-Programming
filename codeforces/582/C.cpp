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

using ll = long long;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;

    map<int, vector<int>> mp;
    for (int i = 1; i < n; i++) mp[gcd(i, n)].emplace_back(i);
    ll ans = 0;
    vector<bool> ok(n);
    for (auto [g, v] : mp) {
        vector<int> maxi(g, 0);
        for (int i = 0; i < n; i++) chmax(maxi[i % g], a[i]);
        for (int i = 0; i < n; i++) ok[i] = (a[i] == maxi[i % g]);
        if (ranges::all_of(ok, [](bool x) { return x; })) {
            ans += 1LL * n * int(v.size());
            continue;
        }
        vector<ll> sum;
        sum.emplace_back(0);
        for (int val : v) sum.emplace_back(sum.back() + val);
        for (int i = 0; i < n;) {
            while (i < n and not ok[i]) i++;
            if (i == n) break;
            int j = i;
            while (ok[j % n]) j++;
            int len = j - i;
            int r = distance(v.begin(), ranges::upper_bound(v, len));
            int l = distance(v.begin(), ranges::lower_bound(v, len - (n - i) + 1));
            ans += 1LL * (n - i) * l + 1LL * (len + 1) * (r - l) - (sum[r] - sum[l]);
            i = j;
        }
    }

    cout << ans << '\n';
    return 0;
}
