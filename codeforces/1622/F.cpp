// LUOGU_RID: 158620127
#include <bits/stdc++.h>
constexpr int N = 1e6 + 10;
using LL = long long;
std::mt19937_64 rnd(std::chrono::_V2::high_resolution_clock().now().time_since_epoch().count());
LL hs[N], npr[N];
LL fac[N];
std::vector<int> pr;
void sieve (int m) {
    for (int i = 2; i <= m; ++i) {
        if (!npr[i]) pr.push_back(i), hs[i] = rnd();
        for (int j : pr) {
            if (i * j > m) break;
            npr[i * j] = 1;
            hs[i * j] = hs[i] ^ hs[j];
            if (i % j == 0) break;
        }
    }
}
int main () {
    int n;
    scanf("%d", &n);
    sieve(n);
    for (int i = 1; i <= n; ++i) fac[i] = hs[i] ^ fac[i - 1];
    LL x = 0;
    for (int i = 1; i <= n; ++i) x ^= fac[i];
    if (!x) {
        printf("%d\n", n);
        for (int i = 1; i <= n; ++i) printf("%d ", i);
        puts("");
        return 0;
    }
    for (int i = 1; i <= n; ++i)
        if (fac[i] == x) {
            printf("%d\n", n - 1);
            for (int j = 1; j <= n; ++j)
                if (i != j) printf("%d ", j);
            puts("");
            return 0;
        }
    std::unordered_map<LL, int> mp;
    mp.reserve(n);
    for (int i = 1; i <= n; ++i) mp.insert({fac[i], i});
    for (int i = 1; i <= n; ++i) {
        if (mp.find(x ^ fac[i]) != mp.end()) {
            printf("%d\n", n - 2);
            int k = mp[x ^ fac[i]];
            for (int j = 1; j <= n; ++j)
                if (j != i && j != k) printf("%d ", j);
            puts("");
            return 0;
        }
    }
    printf("%d\n", n - 3);
    for (int i = 1; i < n; ++i) if (i != 2 && i != n / 2) printf("%d ", i);
    puts("");
}
