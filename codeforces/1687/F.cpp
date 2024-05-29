#include <bits/stdc++.h>
 
#define LOG(FMT...) fprintf(stderr, FMT)
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
const int P = 998244353, R = 3;
const int BRUTE_N2_LIMIT = 50;
 
int mpow(int x, int k, int p = P) {
  int ret = 1;
  while (k) {
    if (k & 1)
      ret = ret * (ll) x % p;
    x = x * (ll) x % p;
    k >>= 1;
  }
  return ret;
}
 
int norm(int x) { return x >= P ? x - P : x; }
 
int reduce(int x) {
  return x < 0 ? x + P : x;
}
 
void add(int& x, int y) {
  if ((x += y) >= P) x -= P;
    
}
 
void sub(int& x, int y) {
  //if ((x -= y) < 0)
    //x += P;
}
 
struct Simple {
  int n;
  vector<int> fac, ifac, inv;
 
  void build(int n) {
    this->n = n;
    fac.resize(n + 1);
    ifac.resize(n + 1);
    inv.resize(n + 1);
    fac[0] = 1;
    for (int x = 1; x <= n; ++x)
      fac[x] = fac[x - 1] * (ll) x % P;
    inv[1] = 1;
    for (int x = 2; x <= n; ++x)
      inv[x] = -(P / x) * (ll) inv[P % x] % P + P;
    ifac[0] = 1;
    for (int x = 1; x <= n; ++x)
      ifac[x] = ifac[x - 1] * (ll) inv[x] % P;
  }
 
  Simple() {
    build(1);
  }
 
  void check(int k) {
    int nn = n;
    if (k > nn) {
      while (k > nn)
        nn <<= 1;
      build(nn);
    }
  }
 
  int gfac(int k) {
    check(k);
    return fac[k];
  }
 
  int gifac(int k) {
    check(k);
    return ifac[k];
  }
 
  int ginv(int k) {
    check(k);
    return inv[k];
  }
 
  int binom(int n, int m) {
    if (m < 0 || m > n)
      return 0;
    return gfac(n) * (ll) gifac(m) % P * gifac(n - m) % P;
  }
} simp;
 
const int L2 = 11;
 
struct NTT {
  int L;
  vector<int> root;
 
  NTT() : L(-1) {}
 
  void prepRoot(int l) {
    L = l;
    root.resize((1 << L) + 1);
    int i, n = 1 << L;
    int *w2 = root.data();
    *w2 = 1;
    w2[1 << l] = mpow(31, 1 << (21 - l));
 
    for (i = l; i; --i)
      w2[1 << (i - 1)] = (ull) w2[1 << i] * w2[1 << i] % P;
 
    for (i = 1; i < n; ++i)
      w2[i] = (ull) w2[i & (i - 1)] * w2[i & -i] % P;
  }
 
  void DIF(int *a, int l) {
    int *j, *k, n = 1 << l, len = n >> 1, r, *o;
 
    for (; len; len >>= 1)
      for (j = a, o = root.data(); j != a + n; j += len << 1, ++o)
        for (k = j; k != j + len; ++k) {
          r = (ull) *o * k[len] % P;
          k[len] = reduce(*k - r);
          add(*k, r);
        }
  }
 
  void DIT(int *a, int l) {
    int *j, *k, n = 1 << l, len = 1, r, *o;
 
    for (; len != n; len <<= 1)
      for (j = a, o = root.data(); j != a + n; j += len << 1, ++o)
        for (k = j; k != j + len; ++k) {
          r = reduce(*k + k[len] - P);
          k[len] = ull(*k - k[len] + P) * *o % P;
          *k = r;
        }
  }
 
  void fft(int *a, int lgn, int d = 1) {
    if (L < lgn) prepRoot(lgn);
    int n = 1 << lgn;
    if (d == 1) DIF(a, lgn);
    else {
      DIT(a, lgn);
      reverse(a + 1, a + n);
      ull nv = P - (P - 1) / n;
      for (int i = 0; i < n; ++i) a[i] = a[i] * nv % P;
    }
  }
} ntt;
 
struct Poly {
  vector<int> a;
 
  Poly(int v = 0) : a(1) {
    if ((v %= P) < 0)
      v += P;
    a[0] = v;
  }
 
  Poly(const vector<int> &a) : a(a) {}
 
  Poly(initializer_list<int> init) : a(init) {}
 
  // Helps
  int operator[](int k) const { return k < a.size() ? a[k] : 0; }
 
  int &operator[](int k) {
    if (k >= a.size())
      a.resize(k + 1);
    return a[k];
  }
 
  int deg() const { return a.size() - 1; }
 
  void redeg(int d) { a.resize(d + 1); }
 
  Poly monic() const;
 
  Poly sunic() const;
 
  Poly slice(int d) const {
    if (d < a.size())
      return vector<int>(a.begin(), a.begin() + d + 1);
    vector<int> res(a);
    res.resize(d + 1);
    return res;
  }
 
  int *base() { return a.data(); }
 
  const int *base() const { return a.data(); }
 
  Poly println(FILE *fp) const {
    fprintf(fp, "%d", a[0]);
    for (int i = 1; i < a.size(); ++i)
      fprintf(fp, " %d", a[i]);
    fputc('\n', fp);
    return *this;
  }
 
  // Calculations
  Poly operator+(const Poly &rhs) const {
    vector<int> res(max(a.size(), rhs.a.size()));
    for (int i = 0; i < res.size(); ++i)
      if ((res[i] = operator[](i) + rhs[i]) >= P)
        res[i] -= P;
    return res;
  }
 
  Poly operator-() const {
    Poly ret(a);
    for (int i = 0; i < a.size(); ++i)
      if (ret[i])
        ret[i] = P - ret[i];
    return ret;
  }
 
  Poly operator-(const Poly &rhs) const { return operator+(-rhs); }
 
  Poly operator*(const Poly &rhs) const;
 
  Poly taylor(int k) const;
};
 
Poly zeroes(int deg) { return vector<int>(deg + 1); }
 
Poly operator "" _z(unsigned long long a) { return {0, (int) a}; }
 
Poly operator+(int v, const Poly &rhs) { return Poly(v) + rhs; }
 
Poly Poly::operator*(const Poly &rhs) const {
  int n = deg(), m = rhs.deg();
  if (n <= 10 || m <= 10 || n + m <= BRUTE_N2_LIMIT) {
    Poly ret = zeroes(n + m);
    for (int i = 0; i <= n; ++i)
      for (int j = 0; j <= m; ++j)
        ret[i + j] = (ret[i + j] + a[i] * (ll) rhs[j]) % P;
    return ret;
  }
  n += m;
  int l = 0;
  while ((1 << l) <= n)
    ++l;
  vector<int> res(1 << l), tmp(1 << l);
  memcpy(res.data(), base(), a.size() * sizeof(int));
  ntt.fft(res.data(), l, 1);
  memcpy(tmp.data(), rhs.base(), rhs.a.size() * sizeof(int));
  ntt.fft(tmp.data(), l, 1);
  for (int i = 0; i < (1 << l); ++i)
    res[i] = res[i] * (ll) tmp[i] % P;
  ntt.fft(res.data(), l, -1);
  res.resize(n + 1);
  return res;
}
 
Poly Poly::taylor(int k) const {
  int n = deg();
  Poly t = zeroes(n);
  simp.check(n);
  for (int i = 0; i <= n; ++i)
    t[n - i] = a[i] * (ll) simp.fac[i] % P;
  int pw = 1;
  Poly help = vector<int>(simp.ifac.begin(), simp.ifac.begin() + n + 1);
  for (int i = 0; i <= n; ++i) {
    help[i] = help[i] * (ll) pw % P;
    pw = pw * (ll) k % P;
  }
  t = t * help;
  for (int i = 0; i <= n; ++i)
    help[i] = t[n - i] * (ll) simp.ifac[i] % P;
  return help;
}
 
Poly stirling2(int n) {
  Poly p = zeroes(n), ne = zeroes(n);
  for (int i = 0; i <= n; ++i) p[i] = mpow(i, n) * (ll)simp.gifac(i) % P;
  for (int i = 0; i <= n; ++i) ne[i] = simp.gifac(i);
  for (int i = 1; i <= n; i += 2) ne[i] = P - ne[i];
  p = p * ne;
  vector<int> ans(n + 1);
  for (int i = 0; i <= n; ++i) ans[i] = p[i] * (ll)simp.gfac(i) % P;
  return ans;
}
 
namespace DC {
 
int N;
vector<Poly> prd, sum;
 
Poly lift(Poly a, int k) {
  a.a.insert(a.a.begin(), k, 0);
  return a;
}
 
void build(int o, int l, int r) {
  if (l == r - 1) {
    prd[o].redeg(1);
    prd[o][1] = P - simp.ginv(r);
    prd[o][0] = (P - l) * (ll)simp.ginv(r) % P;
    sum[o] = prd[o];
    return;
  }
  int mid = (l + r + 1) / 2;
  build(o << 1, l, mid);
  build(o << 1 | 1, mid, r);
  prd[o] = prd[o << 1] * prd[o << 1 | 1];
  sum[o] = prd[o << 1] * sum[o << 1 | 1] + lift(sum[o << 1], r - mid);
}
 
void pre(int n) {
  N = n;
  sum.resize(n * 4); prd.resize(n * 4);
  build(1, 0, n);
}
 
Poly input;
 
pair<Poly, Poly> solve(int o, int l, int r) {
  if (l == r - 1) {
    Poly r1 = input[r];
    return make_pair(r1 * prd[o], lift(r1, 1));
  }
  int mid = (l + r + 1) / 2;
  auto ls = solve(o << 1, l, mid), rs = solve(o << 1 | 1, mid, r);
  ls.first = ls.first + prd[o << 1] * rs.first + sum[o << 1] * rs.second;
  ls.second = ls.second + lift(rs.second, mid - l);
  return ls;
}
 
Poly solve(Poly in) {
  input = in; input.redeg(N);
  auto pr = solve(1, 0, N);
  auto ret = pr.first + pr.second;
  ret[0] = (ret[0] + input[0]) % P;
  return ret;
}
 
}
 
Poly compute(Poly coeff) {
  int n = coeff.deg();
  Poly ret = DC::solve(coeff);
  ret.redeg(n);
  reverse(ret.a.begin(), ret.a.end());
  ret = ret.taylor(P - 1);
  reverse(ret.a.begin(), ret.a.end());
  return ret;
}
 
Poly solve(int n) {
  DC::pre(n);
  auto v0 = stirling2(n), v1 = stirling2(n - 1);
  return compute(v0) + compute(v1);
}
 
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
 
  int n, s; cin >> n >> s;
  auto ans = solve(n - s);
  for (int i = 0; i < s; ++i) cout << "0 ";
  for (int i = n - s - 1; i >= 0; --i)
    cout << ans[i] * (ll)simp.binom(n - 1, s) % P
         << " \n"[i == 0];
 
  return 0;
}