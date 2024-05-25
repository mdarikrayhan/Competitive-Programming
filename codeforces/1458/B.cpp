// LUOGU_RID: 160122332
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <utility>
#include <array>
#include <algorithm>
#include <string>
#include <functional>
#include <numeric>
#include <queue>
// below is c standard library
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;
constexpr char E = '\n', B = ' ', Q[] = "? ", AS[] = "! ";
using LL = long long;
using VI = std::vector<int>;
using VVI = std::vector<std::vector<int>>;
using A2 = std::array<int, 2>;
double gt(int a, int b, int s) {
    double l = (s - a) * 0.5;
    return min<double>(b, l + a);
}
int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n, k;
    cin >> n;
    vector<A2> a(n);
    int  l = 0;
    for (auto & i : a) {
        cin >> i[0] >> i[1];
        l += i[1];
    }
    VVI dp(n + 1, VI(l + 1, -1));
    dp[0][0] = 0;
    int x, y, s = 0;
    for (int i = 0; i < n; i++) {
        x = a[i][0], y = a[i][1];
        s += y;
        for (int j = i + 1; j > 0; j--) {
            for (int t = y; t <= s; t++) {
                if (dp[j - 1][t - y] == -1) continue;
                dp[j][t] = max(dp[j][t], dp[j - 1][t - y] + x);
            }
        }
    }
    double res;
    // for (auto & i : dp) {for (int j : i) cout << j << B; cout << E;}
    for (int i = 1; i <= n; i++) {
        res = 0.0;
        for (int j = 0; j <= l; j++) {
            res = max(res, gt(j, dp[i][j], l));
        }
        printf("%f ", res);
    }
    cout << E;
    return 0;
}






