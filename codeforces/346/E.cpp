#include <bits/stdc++.h>

using namespace std;

int firstLargeMultiple(int mult, int modulo, int atleast);
int firstSmallMultiple(int mult, int modulo, int upto);

int firstLargeMultiple(int mult, int modulo, int atleast) {
    mult %= modulo;
    if (atleast == 0) throw runtime_error("atleast cannot be 0");
    if (mult == 0)
        return modulo;
    if ((atleast + mult - 1) / mult * mult <= modulo)
        return (atleast + mult - 1) / mult;
    return (firstSmallMultiple(modulo, mult, modulo - atleast) * (long long) modulo + atleast - modulo + mult - 1) / mult;
}

int firstSmallMultiple(int mult, int modulo, int upto) {
    mult %= modulo;
    if (mult <= upto)
        return 1;
    if (upto == 0)
        return modulo;
    return (firstLargeMultiple(modulo, mult, mult - upto) * (long long) modulo + mult - 1) / mult;
}

int modInverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0)
        x1 += m0;

    return x1;
}

void solve() {
    int a, n, p, h;
    cin >> a >> n >> p >> h;
    a %= p;
    int left = firstSmallMultiple(a, p, h);
    int right = firstSmallMultiple(p - a, p, h);
    int atleast = max(0, n - left + 1);
    int atmost = min(n, right - 1);
    if (atleast < atmost) {
        cout << "NO" << endl;
        return;
    }
    if (atleast > atmost) {
        cout << "YES" << endl;
        return;
    }
    int max = p - firstSmallMultiple(modInverse(p - a, p), p, n);
    if ((atleast * (long long)a) % p == max) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
