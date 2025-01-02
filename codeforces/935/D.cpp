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

long long mod = 1e9 + 7;

long long expo (long long x, long long n, long long m) {
    if (n == 0) {
        return 1;
    } else {
        long long z = expo(x, n / 2, m) % m;
        z = (z * z) % m;
        if (n % 2 == 1) {
            z = (x * z) % m;
        }
        return z % m;
    }
}

long long inverse(long long x, long long m) {
    return expo(x, m - 2, m);
}


int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    int n; long long m;
    std::cin >> n >> m;
    std::vector<long long> first (n);
    std::vector<long long> second (n);
    for (int i = 0; i < n; i++) {
        std::cin >> first[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> second[i];
    }
    long long sum = 0;
    long long mult = 1;
    for (int i = 0; i < n; i++) {
        if (first[i] == 0 && second[i] == 0) {
            long long div = inverse(((((mult * m) % mod) * 2) % mod), mod);
            sum += (((m - 1) % m) * div) % mod;
            mult *= m;
            mult %= mod;
        } else if (first[i] == 0) {
            long long div = inverse(((mult * m) % mod), mod);
            sum += (((m - second[i]) * div) % mod);
            mult *= m;
            mult %= mod;
        } else if (second[i] == 0) {
            long long div = inverse(((mult * m) % mod), mod);
            sum += (((first[i] - 1) * div) % mod);
            mult *= m;
            mult %= mod;
        } else if (first[i] == second[i]) {
            continue;
        } else if (first[i] > second[i]) {
            sum += inverse(mult, mod);
            break;
        } else {
            break;
        }
        sum %= mod;
    }
    std::cout << sum % mod << "\n";
}


