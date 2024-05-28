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

const int MAX_N = 100010;
ll dp[MAX_N][2][2][2];  // LCS[i][i - 1 / i / i + 1] の値がそれぞれ i - 1 / i / i + {-1, 0}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int n, m;
    string S;
    cin >> n >> m >> S;

    vector<int> v;
    for (char c : S) v.emplace_back(c - 'a');
    for (int c = 0; c < m; c++) {
        if (c == v[0]) {
            dp[1][1][1][1]++;
        } else if (n > 1 and c == v[1]) {
            dp[1][1][0][1]++;
        } else {
            dp[1][1][0][0]++;
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                for (int l = 0; l < 2; l++) {
                    ll& val = dp[i][j][k][l];
                    if (val == 0) continue;
                    int x = (i - 1) - 1 + j, y = i - 1 + k, z = i - 1 + l;
                    for (int c = 0; c < m; c++) {
                        int nx = 0, ny = 0, nz = 0;
                        chmax(nx, y);
                        chmax(nx, x + (i - 1 >= 0 and c == v[i - 1]));
                        chmax(ny, z);
                        chmax(ny, nx);
                        chmax(ny, y + (c == v[i]));
                        chmax(nz, ny);
                        chmax(nz, z + (i + 1 < n and c == v[i + 1]));
                        int nj = nx - (i - 1), nk = ny - i, nl = nz - i;
                        if (nj < 0 or nk < 0 or nl < 0) continue;
                        dp[i + 1][nj][nk][nl] += val;
                    }
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < 2; i++) {
        for (int k = 0; k < 2; k++) {
            ans += dp[n][i][0][k];
        }
    }
    cout << ans << '\n';
    return 0;
}
