#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
 
using namespace std;
template<typename T1, typename T2> inline void chkmin(T1 &a, T2 b) {if (a > b) a = b;}
template<typename T1, typename T2> inline void chkmax(T1 &a, T2 b) {if (a < b) a = b;}
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()
#define left left228
#define right right228
#define y1 y1228
#define mp make_pair
#define pb push_back
#define y2 y2228
#define rank rank228
using ll = long long;
using ld = long double; 
const string FILENAME = "input";
const int MAXN = 200228;
const int Mod = 1e9 + 7;

int n;
int f[MAXN], rf[MAXN];
int a[MAXN], coef[MAXN];

int add(int a, int b) {
    a += b;
    if (a >= Mod) {
        return a - Mod;
    }
    if (a < 0) {
        return a + Mod;
    }
    return a;
}

int mul(int a, int b) {
    return 1LL * a * b % Mod;
}

int powm(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

int dv(int a, int b) {
    return mul(a, powm(b, Mod - 2));
}

void precalc() {
    f[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        f[i] = mul(f[i - 1], i);
    }
    rf[MAXN - 1] = dv(1, f[MAXN - 1]);
    for (int i = MAXN - 2; i >= 0; i--) {
        rf[i] = mul(rf[i + 1], i + 1);
    }
}

int binom(int n, int k) {
    return mul(f[n], mul(rf[k], rf[n - k]));
}

int getcatalan(int n, int k) {
    return mul(binom(n, k), dv(n - 2 * k + 1, n - k + 1)); 
}

void smart(int n) {
    if (n % 4 == 1) { 
        for (int i = 1; i <= n; i += 2) {
            coef[i] = binom(n / 2, i / 2);
        }
    }
    if (n % 4 == 2) {
        for (int i = 1; i <= n; i += 2) {
            coef[i] = binom(n / 2 - 1, i / 2);
        }
        for (int i = 2; i <= n; i += 2) {
            coef[i] = coef[i - 1];
        }
    }
    if (n % 4 == 3) {
        smart(n - 1);
        for (int i = 2; i <= n; i += 2) {
            coef[i] *= 2;
        }
        for (int i = 1; i <= n; i += 2) {
            coef[i] = getcatalan(n / 2 - 1, i / 2);
        }
        for (int i = (n + 1) / 2 + 1; i <= n; i += 2) {
            coef[i] = -coef[n - i + 1];
        }
    }
    if (n % 4 == 0) { 
        for (int i = 1; i <= n; i += 2) {
            coef[i] = binom(n / 2 - 1, i / 2);
        }
        for (int i = 2; i <= n; i += 2) {
            coef[i] = -coef[i - 1];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    precalc();
    smart(n);
    int res = 0;
    for (int i = 1; i <= n; i++) {
        res = add(res, mul(a[i], coef[i]));
    }
    cout << res << '\n';
    return 0;
}
