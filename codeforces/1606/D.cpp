// LUOGU_RID: 158908213
#include <bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("avx2")
// #pragma GCC optimize(3, "inline")
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> s;
using i64 = long long;
// using u32 = unsigned int;
// using u64 = unsigned long long;
// using i128 = __int128_t;
using namespace std;
// const int N = 3e5 + 5;
// const int B = 3e6;
// const int M = 2e6 + 5;
// const int base = 16;
// const int base = 17171;
// const int mod = 998244353;
// const int mod = 1e9 + 7;
// const i64 mod = 1000000000000000003LL;
// const double pi = acos(-1);
// mt19937_64 rnd(chrono::duration_cast<chrono::nanoseconds>(chrono::system_clock::now().time_since_epoch()).count());

template <int mod>
unsigned int down(unsigned int x)
{
    return x >= mod ? x - mod : x;
}
template <int mod>
struct Modint
{
    unsigned int x;
    Modint() = default;
    Modint(unsigned int x) : x(x) {}
    friend istream &operator>>(istream &in, Modint &a) { return in >> a.x; }
    friend ostream &operator<<(ostream &out, Modint a) { return out << a.x; }
    friend Modint operator+(Modint a, Modint b) { return down<mod>(a.x + b.x); }
    friend Modint operator-(Modint a, Modint b) { return down<mod>(a.x - b.x + mod); }
    friend Modint operator*(Modint a, Modint b) { return 1ULL * a.x * b.x % mod; }
    friend Modint operator/(Modint a, Modint b) { return a * ~b; }
    friend Modint operator^(Modint a, int b)
    {
        Modint ans = 1;
        for (; b; b >>= 1, a *= a)
            if (b & 1)
                ans *= a;
        return ans;
    }
    friend Modint operator~(Modint a) { return a ^ (mod - 2); }
    friend Modint operator-(Modint a) { return down<mod>(mod - a.x); }
    friend Modint &operator+=(Modint &a, Modint b) { return a = a + b; }
    friend Modint &operator-=(Modint &a, Modint b) { return a = a - b; }
    friend Modint &operator*=(Modint &a, Modint b) { return a = a * b; }
    friend Modint &operator/=(Modint &a, Modint b) { return a = a / b; }
    friend Modint &operator^=(Modint &a, int b) { return a = a ^ b; }
    friend Modint &operator++(Modint &a) { return a += 1; }
    friend Modint operator++(Modint &a, int)
    {
        Modint x = a;
        a += 1;
        return x;
    }
    friend Modint &operator--(Modint &a) { return a -= 1; }
    friend Modint operator--(Modint &a, int)
    {
        Modint x = a;
        a -= 1;
        return x;
    }
    friend bool operator==(Modint a, Modint b) { return a.x == b.x; }
    friend bool operator!=(Modint a, Modint b) { return !(a == b); }
};
typedef Modint<998244353> mint;
// typedef Modint<1000000007> mint;

template <typename T>
struct Fenwick
{
    int n;
    vector<T> a;
    Fenwick(int n = 0) { init(n); }
    void init(int n)
    {
        this->n = n;
        a.assign(n + 1, T());
    }
    void add(int x, T v)
    {
        for (int i = x; i <= n; i += i & -i)
            a[i] += v;
    }
    T sum(int x)
    {
        auto ans = T();
        for (int i = x; i; i -= i & -i)
            ans += a[i];
        return ans;
    }
    T rangeSum(int l, int r) { return sum(r) - sum(l - 1); }
    int kth(T k)
    {
        int x = 0;
        for (int i = 1 << std::__lg(n); i; i >>= 1)
        {
            if (x + i <= n && k >= a[x + i])
            {
                x += i;
                k -= a[x];
            }
        }
        return x;
    }
};

const int N = 3e5 + 5, P = 998244353;
using i64 = long long;
using Poly = vector<int>;
/*---------------------------------------------------------------------------*/
#define MUL(a, b) (i64(a) * (b) % P)
#define ADD(a, b) (((a) += (b)) >= P ? (a) -= P : 0) // (a += b) %= P
#define SUB(a, b) (((a) -= (b)) < 0 ? (a) += P : 0)  // ((a -= b) += P) %= P
Poly getInv(int L)
{
    Poly inv(L);
    inv[1] = 1;
    for (int i = 2; i < L; i++)
        inv[i] = MUL((P - P / i), inv[P % i]);
    return inv;
}
int POW(i64 a, int b = P - 2, i64 x = 1)
{
    for (; b; b >>= 1, a = a * a % P)
        if (b & 1)
            x = x * a % P;
    return x;
}
auto inv = getInv(N);

namespace NTT
{
    const int g = 3;
    Poly Omega(int L)
    {
        int wn = POW(g, P / L);
        Poly w(L);
        w[L >> 1] = 1;
        for (int i = L / 2 + 1; i < L; i++)
            w[i] = MUL(w[i - 1], wn);
        for (int i = L / 2 - 1; i >= 1; i--)
            w[i] = w[i << 1];
        return w;
    }
    auto W = Omega(1 << 20); // Length
    void DIF(int *a, int n)
    {
        for (int k = n >> 1; k; k >>= 1)
            for (int i = 0, y; i < n; i += k << 1)
                for (int j = 0; j < k; ++j)
                    y = a[i + j + k], a[i + j + k] = MUL(a[i + j] - y + P, W[k + j]), ADD(a[i + j], y);
    }
    void IDIT(int *a, int n)
    {
        for (int k = 1; k < n; k <<= 1)
            for (int i = 0, x, y; i < n; i += k << 1)
                for (int j = 0; j < k; ++j)
                    x = a[i + j], y = MUL(a[i + j + k], W[k + j]),
                    a[i + j + k] = x - y < 0 ? x - y + P : x - y, ADD(a[i + j], y);
        int Inv = P - (P - 1) / n;
        for (int i = 0; i < n; i++)
            a[i] = MUL(a[i], Inv);
        reverse(a + 1, a + n);
    }
}
/*---------------------------------------------------------------------------*/
namespace Polynomial
{
    // basic operator
    int norm(int n) { return 1 << (__lg(n - 1) + 1); }
    void norm(Poly &a)
    {
        if (!a.empty())
            a.resize(norm(a.size()), 0);
        else
            a = {0};
    }
    void DFT(Poly &a) { NTT::DIF(a.data(), a.size()); }
    void IDFT(Poly &a) { NTT::IDIT(a.data(), a.size()); }
    Poly &dot(Poly &a, Poly &b)
    {
        for (int i = 0; i < a.size(); i++)
            a[i] = MUL(a[i], b[i]);
        return a;
    }

    // mul / div int
    Poly &operator*=(Poly &a, int b)
    {
        for (auto &x : a)
            x = MUL(x, b);
        return a;
    }
    Poly operator*(Poly a, int b) { return a *= b; }
    Poly operator*(int a, Poly b) { return b * a; }
    Poly &operator/=(Poly &a, int b) { return a *= POW(b); }
    Poly operator/(Poly a, int b) { return a /= b; }

    // Poly add / sub
    Poly &operator+=(Poly &a, Poly b)
    {
        a.resize(max(a.size(), b.size()));
        for (int i = 0; i < b.size(); i++)
            ADD(a[i], b[i]);
        return a;
    }
    Poly operator+(Poly a, Poly b) { return a += b; }
    Poly &operator-=(Poly &a, Poly b)
    {
        a.resize(max(a.size(), b.size()));
        for (int i = 0; i < b.size(); i++)
            SUB(a[i], b[i]);
        return a;
    }
    Poly operator-(Poly a, Poly b) { return a -= b; }

    // Poly mul
    Poly operator*(Poly a, Poly b)
    {
        int n = a.size() + b.size() - 1, L = norm(n);
        if (a.size() <= 8 || b.size() <= 8)
        {
            Poly c(n);
            for (int i = 0; i < a.size(); i++)
                for (int j = 0; j < b.size(); j++)
                    c[i + j] = (c[i + j] + (i64)a[i] * b[j]) % P;
            return c;
        }
        a.resize(L), b.resize(L);
        DFT(a), DFT(b), dot(a, b), IDFT(a);
        return a.resize(n), a;
    }

    // Poly inv
    Poly Inv2k(Poly a)
    { // |a| = 2 ^ k
        int n = a.size(), m = n >> 1;
        if (n == 1)
            return {POW(a[0])};
        Poly b = Inv2k(Poly(a.begin(), a.begin() + m)), c = b;
        b.resize(n), DFT(a), DFT(b), dot(a, b), IDFT(a);
        for (int i = 0; i < n; i++)
            a[i] = i < m ? 0 : P - a[i];
        DFT(a), dot(a, b), IDFT(a);
        return move(c.begin(), c.end(), a.begin()), a;
    }
    Poly Inv(Poly a)
    {
        int n = a.size();
        norm(a), a = Inv2k(a);
        return a.resize(n), a;
    }

    // Poly calculus
    Poly deriv(Poly a)
    {
        for (int i = 1; i < a.size(); i++)
            a[i - 1] = MUL(i, a[i]);
        return a.pop_back(), a;
    }
    Poly integ(Poly a)
    {
        a.push_back(0);
        for (int i = a.size() - 1; i >= 1; i--)
            a[i] = MUL(inv[i], a[i - 1]);
        return a[0] = 0, a;
    }

    // Poly ln
    Poly Ln(Poly a)
    {
        int n = a.size();
        a = deriv(a) * Inv(a);
        return a.resize(n - 1), integ(a);
    }

    // Poly exp
    Poly Exp(Poly a)
    {
        int n = a.size(), k = norm(n);
        Poly b = {1}, c, d;
        a.resize(k);
        for (int L = 2; L <= k; L <<= 1)
        {
            d = b, b.resize(L), c = Ln(b), c.resize(L);
            for (int i = 0; i < L; i++)
                c[i] = a[i] - c[i] + (a[i] < c[i] ? P : 0);
            ADD(c[0], 1), DFT(b), DFT(c), dot(b, c), IDFT(b);
            move(d.begin(), d.end(), b.begin());
        }
        return b.resize(n), b;
    }

    // Poly pow
    Poly Pow(Poly &a, int b) { return Exp(Ln(a) * b); } // a[0] = 1
    Poly Pow(Poly a, int b1, int b2)
    { // b1 = b % P, b2 = b % phi(P) and b >= n iff a[0] > 0
        /*
        a0 > 1 : f^k(x) = (f(x) * inv(a0))^k * a0^k
        a0 = 0 : 右移至第一个系数不为0的项，设为x^d，则f(x) / x^d，转化为问题一，然后乘上(x^d)^k
        */
        int n = a.size(), d = 0, k, a0;
        while (d < n && !a[d])
            ++d;
        if ((i64)d * b1 >= n)
            return Poly(n);
        a.erase(a.begin(), a.begin() + d); // f(x) / x^d
        a0 = a[0];
        k = POW(a0), norm(a *= k); // f(x) * inv(a0)
        a = Pow(a, b1) * POW(a0, b2);
        a.resize(n), d *= b1;
        for (int i = n - 1; i >= 0; i--)
            a[i] = i >= d ? a[i - d] : 0; // 乘上(x^d)^k
        return a;
    }
    Poly Pow(Poly a, string str)
    {
        const int Phi = P - 1;
        i64 k = 0, ol = 0, t = 0;
        for (int i = 0; i < str.size(); i++)
        {
            k = (k * 10 + str[i] - '0') % P, ol = (ol * 10 + str[i] - '0') % Phi;
            if (t <= P)
                t = (t * 10 + str[i] - '0');
        }
        if (k < P && t >= P)
            k += P;
        return Pow(a, k, ol);
    }
}
using namespace Polynomial;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    vector<vector<int>> pre1(n + 1, vector<int>(m + 1));
    vector<vector<int>> suf1(n + 1, vector<int>(m + 2));
    vector<vector<int>> pre2(n + 1, vector<int>(m + 1));
    vector<vector<int>> suf2(n + 1, vector<int>(m + 2));
    for (int i = 1; i <= n; i++)
    {
        pre2[i][0] = suf2[i][m + 1] = 1e9;
        for (int j = 1; j <= m; j++)
            pre1[i][j] = max(pre1[i][j - 1], a[i][j]),
            pre2[i][j] = min(pre2[i][j - 1], a[i][j]);
        for (int j = m; j >= 1; j--)
            suf1[i][j] = max(suf1[i][j + 1], a[i][j]),
            suf2[i][j] = min(suf2[i][j + 1], a[i][j]);
    }
    for (int k = 1; k < m; k++)
    {
        set<pair<int, int>> l, r;
        for (int j = 1; j <= n; j++)
        {
            l.insert({pre1[j][k], j});
            r.insert({suf2[j][k + 1], j});
        }
        int p = 1;
        for (int j = 2; j <= n; j++)
            if (pre1[j][k] > pre1[p][k])
                p = j;
        string ans(n, 'B');
        ans[p - 1] = 'R';
        int mi_l = pre2[p][k], mx_r = suf1[p][k + 1];
        while (1)
        {
            bool done = false;
            while (!l.empty() && l.rbegin()->first >= mi_l)
            {
                auto [x, y] = *l.rbegin();
                l.erase({x, y});
                mx_r = max(mx_r, suf1[y][k + 1]);
                mi_l = min(mi_l, pre2[y][k]);
                ans[y - 1] = 'R';
                done = true;
            }
            while (!r.empty() && r.begin()->first <= mx_r)
            {
                auto [x, y] = *r.begin();
                r.erase({x, y});
                mx_r = max(mx_r, suf1[y][k + 1]);
                mi_l = min(mi_l, pre2[y][k]);
                ans[y - 1] = 'R';
                done = true;
            }
            if (!done)
                break;
        }
        if (count(ans.begin(), ans.end(), 'B'))
        {
            cout << "YES\n";
            cout << ans << ' ' << k << '\n';
            return;
        }
    }
    cout << "NO\n";
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    cout << fixed << setprecision(15);
    while (t--)
        solve();
}