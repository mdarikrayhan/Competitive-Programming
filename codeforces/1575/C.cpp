// LUOGU_RID: 158251951
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 8e5 + 5, mod = 1e9 + 7;
const double pi = acos(-1.0);

int n, m, k;
int a[MAXN], sum[MAXN];
int cnt[MAXN], cnt2[MAXN];

typedef long long ll;

struct Complex {
    double real, imag;
    Complex() {}
    Complex(double real, double imag): real(real), imag(imag) {}
} A[MAXN], B[MAXN];

Complex operator +(Complex x, Complex y) {
    return {x.real + y.real, x.imag + y.imag};
}

Complex operator -(Complex x, Complex y) {
    return {x.real - y.real, x.imag - y.imag};
}

Complex operator *(Complex x, Complex y) {
    return {x.real * y.real - x.imag * y.imag, x.imag * y.real + x.real * y.imag};
}

int lim, ans, rev[MAXN];

void FFT(Complex a[], int sgn) {
    for (int i = 0; i < lim; i++) {
        if (i < rev[i])
            swap(a[i], a[rev[i]]);
    }
    for (int i = 1; i < lim; i <<= 1) {
        Complex w = {cos(pi / i), sgn * sin(pi / i)};
        for (int j = 0; j < lim; j += (i << 1)) {
            Complex cur = {1, 0};
            for (int k = 0; k < i; k++) {
                Complex x = a[j + k];
                Complex y = cur * a[i + j + k];
                a[j + k] = x + y;
                a[i + j + k] = x - y;
                cur = cur * w;
            }
        }
    }
    if (sgn == -1) {
        for (int i = 0; i < lim; i++) {
            a[i].real /= lim;
            a[i].imag /= lim;
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        sum[i] = (sum[i - 1] + a[i]) % k;
    }
    for (int i = 1; i <= n; i++) {
        A[sum[i]].real++;
    }
    for (int i = 1; i < m; i++) {
        int u = (ll)i * sum[n] % k;
        B[u].real++;
    }
    lim = 1;
    while (lim <= 2 * k) lim *= 2;
    for (int i = 0; i < lim; i++) {
        rev[i] = rev[i >> 1] >> 1;
        if (i & 1) rev[i] |= (lim >> 1);
    }
    FFT(A, 1);
    FFT(B, 1);
    for (int i = 0; i < lim; i++) {
        A[i] = A[i] * B[i];
    }
    FFT(A, -1);
    for (int i = 1; i <= n; i++) {
        ll coef = ((ll)(A[sum[i - 1]].real + 0.5) + (ll)(A[sum[i - 1] + k].real + 0.5)) % mod;
        ans = (ans + coef) % mod;
    }
    for (int i = 0; i <= n; i++) {
        cnt[sum[i]]++;
    }
    for (int i = 0; i < k; i++) {
        if (!cnt[i]) continue;
        ll x = (ll)cnt[i] * (cnt[i] - 1) / 2;
        ans = (ans + x) % mod;
    }
    int S = (ll)m * sum[n] % k;
    for (int i = 1; i <= n; i++) {
        ans = (ans + cnt2[(sum[i - 1] - S + k) % k]) % mod;
        if (i > 1) cnt2[sum[i - 1]]++;
    }
    ans = (ll)ans * m % mod;
    if (!S) ans = (ans - (m - 1) + mod) % mod;
    printf("%d\n", ans);
}