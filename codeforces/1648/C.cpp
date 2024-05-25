// LUOGU_RID: 159988511
#include <bits/stdc++.h>

using namespace std;
#define IOS ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
#define int long long

# ifdef LOCAL

# include "C:\Program Files\DEBUG\debug.h"

# else
# define debug(...) 114514
# define ps 114514
# endif

using i64 = long long;

template<class T>
constexpr T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}

constexpr i64 mul(i64 a, i64 b, i64 p) {
    i64 res = a * b - i64(1.L * a * b / p) * p;
    res %= p;
    if (res < 0) {
        res += p;
    }
    return res;
}

template<i64 P>
struct MLong {
    i64 x;

    constexpr MLong() : x{} {}

    constexpr MLong(i64 x) : x{norm(x % getMod())} {}

    static i64 Mod;

    constexpr static i64 getMod() {
        if (P > 0) {
            return P;
        } else {
            return Mod;
        }
    }

    constexpr static void setMod(i64 Mod_) {
        Mod = Mod_;
    }

    constexpr i64 norm(i64 x) const {
        if (x < 0) {
            x += getMod();
        }
        if (x >= getMod()) {
            x -= getMod();
        }
        return x;
    }

    constexpr i64 val() const {
        return x;
    }

    explicit constexpr operator i64() const {
        return x;
    }

    constexpr MLong operator-() const {
        MLong res;
        res.x = norm(getMod() - x);
        return res;
    }

    constexpr MLong inv() const {
        assert(x != 0);
        return power(*this, getMod() - 2);
    }

    constexpr MLong &operator*=(MLong rhs) &{
        x = mul(x, rhs.x, getMod());
        return *this;
    }

    constexpr MLong &operator+=(MLong rhs) &{
        x = norm(x + rhs.x);
        return *this;
    }

    constexpr MLong &operator-=(MLong rhs) &{
        x = norm(x - rhs.x);
        return *this;
    }

    constexpr MLong &operator/=(MLong rhs) &{
        return *this *= rhs.inv();
    }

    friend constexpr MLong operator*(MLong lhs, MLong rhs) {
        MLong res = lhs;
        res *= rhs;
        return res;
    }

    friend constexpr MLong operator+(MLong lhs, MLong rhs) {
        MLong res = lhs;
        res += rhs;
        return res;
    }

    friend constexpr MLong operator-(MLong lhs, MLong rhs) {
        MLong res = lhs;
        res -= rhs;
        return res;
    }

    friend constexpr MLong operator/(MLong lhs, MLong rhs) {
        MLong res = lhs;
        res /= rhs;
        return res;
    }

    friend constexpr std::istream &operator>>(std::istream &is, MLong &a) {
        i64 v;
        is >> v;
        a = MLong(v);
        return is;
    }

    friend constexpr std::ostream &operator<<(std::ostream &os, const MLong &a) {
        return os << a.val();
    }

    friend constexpr bool operator==(MLong lhs, MLong rhs) {
        return lhs.val() == rhs.val();
    }

    friend constexpr bool operator!=(MLong lhs, MLong rhs) {
        return lhs.val() != rhs.val();
    }
};

template<>
i64 MLong<0LL>::Mod = i64(1E18) + 9;

template<int P>
struct MInt {
    int x;

    constexpr MInt() : x{} {}

    constexpr MInt(i64 x) : x{norm(x % getMod())} {}

    static int Mod;

    constexpr static int getMod() {
        if (P > 0) {
            return P;
        } else {
            return Mod;
        }
    }

    constexpr static void setMod(int Mod_) {
        Mod = Mod_;
    }

    constexpr int norm(int x) const {
        if (x < 0) {
            x += getMod();
        }
        if (x >= getMod()) {
            x -= getMod();
        }
        return x;
    }

    constexpr int val() const {
        return x;
    }

    explicit constexpr operator int() const {
        return x;
    }

    constexpr MInt operator-() const {
        MInt res;
        res.x = norm(getMod() - x);
        return res;
    }

    constexpr MInt inv() const {
        assert(x != 0);
        return power(*this, getMod() - 2);
    }

    constexpr MInt &operator*=(MInt rhs) &{
        x = 1LL * x * rhs.x % getMod();
        return *this;
    }

    constexpr MInt &operator+=(MInt rhs) &{
        x = norm(x + rhs.x);
        return *this;
    }

    constexpr MInt &operator-=(MInt rhs) &{
        x = norm(x - rhs.x);
        return *this;
    }

    constexpr MInt &operator/=(MInt rhs) &{
        return *this *= rhs.inv();
    }

    friend constexpr MInt operator*(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res *= rhs;
        return res;
    }

    friend constexpr MInt operator+(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res += rhs;
        return res;
    }

    friend constexpr MInt operator-(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res -= rhs;
        return res;
    }

    friend constexpr MInt operator/(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res /= rhs;
        return res;
    }

    friend constexpr std::istream &operator>>(std::istream &is, MInt &a) {
        i64 v;
        is >> v;
        a = MInt(v);
        return is;
    }

    friend constexpr std::ostream &operator<<(std::ostream &os, const MInt &a) {
        return os << a.val();
    }

    friend constexpr bool operator==(MInt lhs, MInt rhs) {
        return lhs.val() == rhs.val();
    }

    friend constexpr bool operator!=(MInt lhs, MInt rhs) {
        return lhs.val() != rhs.val();
    }
};

template<>
int MInt<0>::Mod = 998244353;

template<int V, int P>
constexpr MInt<P> CInv = MInt<P>(V).inv();

constexpr int P = 998244353;
using Z = MInt<P>;

template<typename T>
class BIT {
public:
    std::vector<T> c;
    int sz;

    BIT(int n) : c(n + 1) { sz = n; }

    int lowbit(int x) {
        return (x & (-x));
    }


    void resize(int n) {
        c.resize(n + 1);
        sz = n;
    }


    void add(int pos, T k) {
        while (pos <= sz) {
            c[pos] += k;
            pos += lowbit(pos);
        }
    }

    void add(int l, int r, T k) {
        BIT::add(l, k);
        BIT::add(r + 1, -k);
    }

    T query(int i) {
        T res = 0;
        while (i > 0) {
            res += c[i];
            i -= lowbit(i);
        }
        return res;
    }

    void modify(int pos, int k) {
        int t = BIT::query(pos) - BIT::query(pos - 1);
        add(pos, k - t);
    }
};

struct Comb {
    int n;
    std::vector<Z> _fac;
    std::vector<Z> _invfac;
    std::vector<Z> _inv;

    Comb() : n{0}, _fac{1}, _invfac{1}, _inv{0} {}

    Comb(int n) : Comb() {
        init(n);
    }

    void init(int m) {
        m = std::min(m, Z::getMod() - 1);
        if (m <= n) return;
        _fac.resize(m + 1);
        _invfac.resize(m + 1);
        _inv.resize(m + 1);

        for (int i = n + 1; i <= m; i++) {
            _fac[i] = _fac[i - 1] * i;
        }
        _invfac[m] = _fac[m].inv();
        for (int i = m; i > n; i--) {
            _invfac[i - 1] = _invfac[i] * i;
            _inv[i] = _invfac[i] * _fac[i - 1];
        }
        n = m;
    }

    Z fac(int m) {
        if (m > n) init(2 * m);
        return _fac[m];
    }

    Z invfac(int m) {
        if (m > n) init(2 * m);
        return _invfac[m];
    }

    Z inv(int m) {
        if (m > n) init(2 * m);
        return _inv[m];
    }

    Z binom(int n, int m) {
        if (n < m || m < 0) return 0;
        return fac(n) * invfac(m) * invfac(n - m);
    }
} comb;

int cnt[200200];

signed main() {
    IOS
    int n, m;
    cin >> n >> m;
    BIT<int> bit(200200);
    vector<int> a(n + 1), b(m + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= 200000; i++) {
        bit.add(i, cnt[i]);
    }
    Z ans = 0;
    Z now = comb.fac(n);
    for (int i = 1; i <= 200000; i++) {
        now *= comb.invfac(cnt[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (i > m) {
            break;
        }
        if (m > n && i == n && cnt[b[i]]) {
            ans += 1;
        }
        debug(i);
        Z val = bit.query(b[i] - 1);
        val *= now;
        val /= (n - i + 1);
        ans += val;
        if (cnt[b[i]]) {
            now /= (n - i + 1);
            now *= cnt[b[i]];
            cnt[b[i]]--;
            bit.add(b[i], -1);
        } else {
            break;
        }
    }
    cout << ans << endl;
    return 0;
}