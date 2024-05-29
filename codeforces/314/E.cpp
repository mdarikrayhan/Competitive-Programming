// LUOGU_RID: 158358266
#include <bits/stdc++.h>

#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#define F(i, a, b)  for (int i = a; i <= b; i++)
#define F2(i, a, b) for (int i = a; i < b; i++)
#define dF(i, a, b) for (int i = a; i >= b; i--)

typedef long long LL;

#define N   200005
#define mod 4294967296

/*
 1. 小写字母和大写字母为一对括号
 2. 正方形没有交点 => 不会出现 ([)]
 3. 没有 x
 */

int dp[N]; // dp[i][j] 表示处理到第 i 个，第 j 个字母为左括号
char s[N];
int n;

signed main() {
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    
    scanf("%d", &n);
    if (n & 1) return std::cout << 0 << '\n', 0;
    scanf("%s", s + 1);
    dp[0] = 1;
    F(i, 1, n) {
        if (s[i] == '?') {
            dF(j, i / 2, 1) {
                dp[j] = (dp[j] * 25 + dp[j - 1]) % mod;
            }
            dp[0] = (dp[0] * 25) % mod;
        }
    }
    printf("%lld\n", dp[n / 2]);
    
    return 0;
}
