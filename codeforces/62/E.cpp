// please be patient i have autism

#include <iostream>
#include<math.h>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <deque>
#include <memory>
#include <random>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <tuple>
#include <thread>
#include <chrono>
#include <iomanip>  

using namespace std;

const int64_t bound = 1e9 + 7;
const int64_t mod = 1e9 + 7;
const int64_t inf = 1e18;
 
int64_t gcd(int64_t a, int64_t b) {
    return b ? gcd(b, a % b) : a;
}
int64_t binexp(int64_t a, int64_t b) {
    if (!b) return 1;
    int64_t res = binexp(a, b / 2);
    res = (res * res) % mod;
    if (b % 2) res = (res * a) % mod;
    return res;
}
int64_t inv(int64_t x) {
    return binexp(x, mod - 2);
}
int64_t Cnk(int n, int k, vector<int64_t>& fact,
            vector<int64_t>& inv_fact) {
    return (((fact[n] * inv_fact[k]) % mod) * inv_fact[n - k]) % mod;
}

int64_t horizontal[6][100100];
int64_t vertical[6][100100];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            horizontal[i][j] = vertical[i][j] = 0;
        }
    }
    for (int i = 1; i <= m - 1; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> horizontal[j][i];
        }
    }
    for (int i = 1;  i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> vertical[j][i];
        }
    }
    vector<int64_t> dp(35, inf);
    /*
    dp[i][j][mask] -> dp[i][j + 1][mask ^ jjjj???]
    to get dp[i][1][mask] we should do transition from dp[i - 1][n][mask_1]
    but we don't need to save previous columns so we can use dp[j][mask]
    i guess we even can use just dp[mask] - chose horizontal edges or not
    */
    dp[0] = 0;
    for (int col = 2; col <= m; col++) {
        // m = 1 is inf
        for (int mask = 0; mask < (1 << n); mask++) {
            int64_t add = 0;
            for (int row = 1; row <= n; row++) {
                if ((mask & (1 << (row - 1))) == 0) {
                    // horizontal edge
                    dp[mask ^ (1 << (row - 1))] = min(dp[mask ^ (1 << (row - 1))], dp[mask] + horizontal[row][col - 1]);
                }
                int cur = mask & (1 << (row - 1));
                int nxt = (row < n ? row + 1 : 1);
                int nnxt = mask & (1 << (nxt - 1));
                if ((cur ^ nnxt) == 0) {
                    // vertical
                    add += vertical[row][col];
                }
            }
            for (int row = 1; row <= n; row++) {
                int rrow = row - 1;
                if (((mask >> rrow) ^ (mask >> ((rrow + 1) % n))) & 1) {
                    dp[mask] += vertical[row][col];
                }
            }
            // dp[mask] += add;/
            
        }
    }
    cout << dp[(1 << n) - 1] << endl;
}