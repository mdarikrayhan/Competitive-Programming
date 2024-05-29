#include <bits/stdc++.h>
using namespace std;

typedef vector<int> poly;
const int maxn = 30010;
inline void init(int);
inline poly add(const poly&, const poly&);
inline poly sub(const poly&, const poly&);
inline poly mul(const poly&, const poly&);
int q;

int main() {
    int n, a, lg = 0;
    scanf("%d %d %d", &n, &a, &q);
    n -= !(n & 1), init(n + 5);
    while (a >> lg) lg++;
    long long ans = 0;
    poly f = { 1 }, f1 = { 0 };
    while (--lg) {
        poly F = mul(f, f);
        poly F1 = (a >> (lg + 1)) & 1 ? sub(sub(f, f1), { 1 }) : f1;
        F1 = add(mul(F1, f), f1), F1.resize(F.size());
        if (F.size() > n)
            F.resize(n + 1), F1.resize(n + 1);
        if ((a >> lg) & 1) {
            F1.push_back(F.back()), F.push_back(F.back());
            for (int i = F.size() - 2; i; i--) (F1[i] += F[i - 1]) %= q, (F[i] += F[i - 1]) %= q;
            if (F.size() > n)
                F.resize(n + 1), F1.resize(n + 1);
        }
        f = F, f1 = F1;
        for (int i = 1; i < f1.size(); i += 2) ans += f1[i];
    }
    printf("%lld\n", (ans % q + q) % q);
    return 0;
}

struct comp {
    long double r, i;
    inline comp operator+(const comp rhs) const { return { r + rhs.r, i + rhs.i }; }
    inline comp operator-(const comp rhs) const { return { r - rhs.r, i - rhs.i }; }
    inline comp operator*(const comp rhs) const { return { r * rhs.r - i * rhs.i, r * rhs.i + rhs.r * i }; }
};

comp w[maxn << 1];
inline void init(const int n) {
    static const long double pi = acosl(-1);
    int l = 1;
    while (l <= n) l <<= 1;
    w[0] = { 1, 0 }, w[l] = { cosl(2 * pi / (l << 2)), sinl(2 * pi / (l << 2)) };
    for (int i = l >> 1; i; i >>= 1) w[i] = w[i << 1] * w[i << 1];
    for (int i = 1; i < l; i++) w[i] = w[i & (i - 1)] * w[i & (-i)];
    return;
}

inline void dft(const int l, vector<comp>& a) {
    a.resize(l);
    for (int i = l >> 1; i; i >>= 1)
        for (int j = 0, p = 0; j < l; j += i << 1, p++)
            for (int k = j; k < j + i; k++) {
                comp x = a[k + i] * w[p];
                a[k + i] = a[k] - x, a[k] = a[k] + x;
            }
    return;
}

inline void idft(const int l, vector<comp>& a) {
    a.resize(l);
    for (int i = 1; i < l; i <<= 1)
        for (int j = 0, p = 0; j < l; j += i << 1, p++)
            for (int k = j; k < j + i; k++) {
                comp x = a[k] + a[k + i];
                a[k + i] = (a[k] - a[k + i]) * w[p], a[k] = x;
            }
    reverse(a.begin() + 1, a.end());
    for (auto& x : a) x.r /= l, x.i /= l;
    return;
}

inline poly add(const poly& a, const poly& b) {
    poly ret = a;
    if (a.size() < b.size())
        ret.resize(b.size());
    for (int i = 0; i < b.size(); i++) (ret[i] += b[i]) %= q;
    return ret;
}

inline poly sub(const poly& a, const poly& b) {
    poly ret = a;
    if (a.size() < b.size())
        ret.resize(b.size());
    for (int i = 0; i < b.size(); i++) (ret[i] += q - b[i]) %= q;
    return ret;
}

inline poly mul(const poly& a, const poly& b) {
    static const int B = 8;
    int len = a.size() + b.size() - 1, l = 1;
    while (l < len) l <<= 1;
    poly a0(l), a1(l), b0(l), b1(l);
    for (int i = 0; i < a.size(); i++) a1[i] = a[i] >> B, a0[i] = a[i] - (a1[i] << B);
    for (int i = 0; i < b.size(); i++) b1[i] = b[i] >> B, b0[i] = b[i] - (b1[i] << B);
    vector<comp> f0(l), f1(l), f2(l);
    for (int i = 0; i < l; i++) {
        f0[i] = { (long double)a1[i], (long double)a0[i] };
        f1[i] = { (long double)b1[i], (long double)b0[i] };
        f2[i] = { (long double)b1[i], (long double)-b0[i] };
    }
    dft(l, f0), dft(l, f1), dft(l, f2);
    for (int i = 0; i < l; i++) f1[i] = f1[i] * f0[i], f2[i] = f2[i] * f0[i];
    idft(l, f1), idft(l, f2);
    poly ret(len);
    for (int i = 0; i < ret.size(); i++) {
        long long x = roundl((f1[i].r + f2[i].r) / 2);
        x <<= B, (x += roundl(f1[i].i)) %= q, x <<= B;
        (x += roundl((f2[i].r - f1[i].r) / 2)) %= q;
        ret[i] = x;
    }
    return ret;
}

		 	 				  	 		  				  			 	  	