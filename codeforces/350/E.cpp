#define _USE_MATH_DEFINES

#include <immintrin.h>
#include <math.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstring>
#include <chrono>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <ranges>

using namespace std;
namespace rng = ranges;
namespace viu = views;

namespace std {

template<typename Fun>
struct y_combinator {
    const Fun fun;

    explicit y_combinator(const Fun&& fun) : fun(std::forward<const Fun>(fun)) {}

    template<typename... Args>
    auto operator()(Args&&... args) const {
        return fun(std::ref(*this), std::forward<Args>(args)...);
    }
};

template <typename T> T& mineq(T& element, const T value) {
    return element = std::min<T>(element, value);
}

template <typename T> T& maxeq(T& element, const T value) {
    return element = std::max<T>(element, value);
}

} // namespace std

#define INF ((int)1e9 + 1329)
#define INF_LL ((int64_t)1e18)
#define filin(x) freopen(x, "r", stdin)
#define filout(x) freopen(x, "w", stdout)

typedef int64_t ll;
typedef uint64_t ul;
typedef long double ld;

//const ld PI = acos(-1.0);

#ifndef __APPLE__
mt19937 rnd((uint32_t)time(0));
#else
mt19937 rnd(57);
#endif

struct Solution {
    signed operator()() {
        int n, G, m; cin >> n >> m >> G;
        vector<bool> ban(n, false);
        for (int i = 0; i < G; ++i) {
            int v; cin >> v;
            ban[v - 1] = true;
        }
        vector<vector<int>> mat(n, vector<int>(n, INF));
        for (int i = 0; i < n; ++i)
            mat[i][i] = 0;
        vector<pair<int, int>> e;
        for (int i = 0; i < n && m; ++i) {
            if (ban[i])
                continue;
            for (int j = 0; j < n && m; ++j) {
                if (i == j)
                    continue;
                if (ban[j] && mat[i][j] == INF) {
                    mat[i][j] = mat[j][i] = 1;
                    e.emplace_back(i, j);
                    m--;
                }
            }
            break;
        }
        for (int i = 0; i < n && m; ++i) {
            if (!ban[i])
                continue;
            for (int j = 0; j < n && m; ++j) {
                if (i == j)
                    continue;
                if (!ban[j] && mat[i][j] == INF) {
                    mat[i][j] = mat[j][i] = 1;
                    e.emplace_back(i, j);
                    m--;
                }
            }
            break;
        }
        for (int i = 0; i < n && m; ++i) {
            for (int j = i + 1; j < n && m; ++j) {
                if (!ban[i] && !ban[j] && mat[i][j] == INF) {
                    mat[i][j] = mat[j][i] = 1;
                    e.emplace_back(i, j);
                    m--;
                }
            }
        }
        for (int i = 0; i < n && m; ++i) {
            for (int j = i + 1; j < n && m; ++j) {
                if ((ban[i] ^ ban[j]) && mat[i][j] == INF) {
                    mat[i][j] = mat[j][i] = 1;
                    e.emplace_back(i, j);
                    m--;
                }
            }
        }
        
        
        int bann = -1;
        for (int i = n - 1; i >= 0; --i) {
            if (ban[i]) {
                bann = i;
                break;
            }
        }
        
        for (int i = 0; i < n && m; ++i) {
            if (ban[i] && i != bann) {
                for (int j = i + 1; j < n && m; ++j) {
                    if (ban[j] && j != bann && mat[i][j] == INF) {
                        mat[i][j] = mat[j][i] = 1;
                        e.emplace_back(i, j);
                        m--;
                    }
                }
            }
        }
        
        for (int i = 0; i < n && m; ++i) {
            for (int j = i + 1; j < n && m; ++j) {
                if (mat[i][j] == INF) {
                    mat[i][j] = mat[j][i] = 1;
                    e.emplace_back(i, j);
                    m--;
                }
            }
        }
        
        for (int k = 0; k < n; ++k) {
            if (!ban[k])
                continue;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    mineq(mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
        }
        bool ok = false;
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n && !ok; ++i) {
                for (int j = 0; j < n && !ok; ++j) {
                    if (mat[i][j] > mat[i][k] + mat[k][j]) {
                        ok = true;
                    }
                }
            }
        }
        if (!ok) {
            cout << "-1\n";
            return 0;
        }
        for (auto& it : e) {
            cout << it.first + 1 << " " << it.second + 1 << "\n";
        }
        return 0;
        return 0;
    }
    
    Solution() {}
};

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
//    cin >> t;
    while (t--) {
        int exit_code = Solution()();
        if (exit_code)
            exit(exit_code);
        //        cout << "\n";
    }
    return 0;
}


