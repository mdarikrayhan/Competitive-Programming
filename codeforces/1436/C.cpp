#include <bits/stdc++.h>
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define int long long
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define fori(a, b, c) for (ll a = b; a < ll(c); a++)
using namespace std;
const int MOD = 1e9 + 7;

int lcount(int n, int k) {
    int l = 0, h = n;
    int lc = 0, hc = 0;
    while (l < h) {
        int m = (l + h) / 2;
        if (m <= k) {
            if(m!=k)
            lc++;
            l = m + 1;
        } else {
            hc++;
            h = m;
        }
    }
    return lc;
}

int hcount(int n, int k) {
    int l = 0, h = n;
    int lc = 0, hc = 0;
    while (l < h) {
        int m = (l + h) / 2;
        
        if (m <= k) {
            if(m!=k)
            lc++;
            l = m + 1;
        } else {
            hc++;
            h = m;
        }
    }
    return hc;
}

// Function to calculate the factorial of a number modulo MOD
long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    int result = 1;
    for (int i = 2; i <= n; i++) {
        result = (result * i) % MOD;
    }
    return result;
}

// Function to calculate nCr modulo MOD
long long ncr(int n, int r) {
    if (r > n) {
        return 0; // Invalid input
    }
    long long numerator = factorial(n) % MOD;
    long long denominator = (factorial(r) * factorial(n - r)) % MOD;

    // Calculate denominator inverse using modular exponentiation
    long long denominator_inverse = 1;
    long long base = denominator;
    int exponent = MOD - 2; // Using Fermat's Little Theorem
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            denominator_inverse = (denominator_inverse * base) % MOD;
        }
        base = (base * base) % MOD;
        exponent /= 2;
    }

    return (numerator * denominator_inverse) % MOD;
}

signed main() {
    int n, k, p;
    cin >> n >> k >> p;
    int lc = lcount(n, p);
    int hc = hcount(n, p);
    if(lc==-1){cout<<"0"<<endl;return 0;}
    //cout<<lc<<" "<<hc<<endl;
    int a = ((ncr(k - 1, lc) % MOD) * (ncr(n - k, hc) % MOD)) % MOD;
    a = ((factorial(n - 1 - lc - hc) % MOD) * a) % MOD;
    a=(a*factorial(lc))%MOD;
    a=(a*factorial(hc))%MOD;
    cout << a << endl;
    return 0;
}
