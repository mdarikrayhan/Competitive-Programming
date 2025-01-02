#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;

// Function to perform modular exponentiation
long long modExp(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) { // If exp is odd, multiply base with result
            result = (result * base) % mod;
        }
        exp = exp >> 1; // Divide exp by 2
        base = (base * base) % mod; // Square the base
    }
    return result;
}

// Function to precompute binomial coefficients modulo MOD
vector<vector<long long>> precomputeBinomial(int n) {
    vector<vector<long long>> nCr(n + 1, vector<long long>(n + 1, 0));
    nCr[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        nCr[i][0] = nCr[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            nCr[i][j] = (nCr[i-1][j-1] + nCr[i-1][j]) % MOD;
        }
    }
    return nCr;
}

// Function to precompute powers modulo MOD
vector<long long> precomputePowers(int base, int n) {
    vector<long long> powers(n + 1, 1);
    for (int i = 1; i <= n; ++i) {
        powers[i] = (powers[i-1] * base) % MOD;
    }
    return powers;
}

int main() {
    int n, k;
    cin >> n >> k;

    if (k == 1) {
        cout << 1 << endl;
        return 0;
    }

    vector<vector<long long>> f(n + 1, vector<long long>(n + 1, 0));
    auto nCr = precomputeBinomial(n);
    auto kpower = precomputePowers(k, n);
    auto k1power = precomputePowers(k - 1, n);

    // Edge DP
    for (int r = 1; r <= n; ++r) {
        f[r][0] = modExp((kpower[n] - k1power[n] + MOD) % MOD, r, MOD);
    }
    for (int c = 1; c <= n; ++c) {
        f[1][c] = kpower[n - c];
    }

    // DP
    for (int r = 2; r <= n; ++r) {
        for (int c = 1; c <= n; ++c) {
            long long sum = 0;
            for (int c0 = 1; c0 <= c; ++c0) {
                sum = (sum + k1power[c - c0] * nCr[c][c0] % MOD * f[r - 1][c - c0] % MOD) % MOD;
            }
            f[r][c] = (((kpower[n - c] - k1power[n - c] + MOD) % MOD) * k1power[c] % MOD * f[r - 1][c] % MOD + kpower[n - c] * sum % MOD) % MOD;
        }
    }

    cout << f[n][n] << endl;
    return 0;
}
