#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <set>
#include <array>
#include <cstdio>
#include <vector>
#include <string>
#include <fstream>
#include <tuple>
#include <numeric>
#include <map>
#include <iomanip>
#include <math.h>
#include <queue>
#include <sstream>
#include <stack>
#include <initializer_list>
#include <functional>
#include <cstring>

long long mod = 998244353;

long long expo (long long x, long long n) {
    if (n == 0) {
        return 1;
    } else {
        long long z = expo(x, n / 2) % mod;
        z = (z * z) % mod;
        if (n % 2 == 1) {
            z = (x * z) % mod;
        }
        return z % mod;
    }
}

long long inverse(long long x) {
    return expo(x, mod - 2);
}

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    long long n;
    std::vector<long long> present_count (1e6 + 1);
    std::vector<std::vector<long long>> presents;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int k;
        std::cin >> k;
        std::vector<long long> vec(k + 1);
        vec[0] = k;
        for (int j = 1; j <= k; j++) {
            std::cin >> vec[j];
            present_count[vec[j]]++;
        }
        presents.push_back(vec);
    }
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        long long inv = (((n * n) % mod) * presents[i][0]) % mod;
        inv = inverse(inv);
        for (int j = 1; j < presents[i].size(); j++) {
            sum += (inv * present_count[presents[i][j]]) % mod;
            sum %= mod;
        }
    }
    std::cout << sum << "\n";
}


