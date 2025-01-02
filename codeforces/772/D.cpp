#include <bits/stdc++.h>
using namespace std;

#define int long long
// Z_P (Modular Arithmetic) {{{
template <unsigned P>
struct Z {
  unsigned value;

  constexpr Z() : value(0) {}

  template<typename T, typename = enable_if_t<std::is_integral<T>::value>>
  constexpr Z(T a) : value((((long long)a % P) + P) % P) {}

  Z& operator+=(Z rhs) {
    value += rhs.value;
    if (value >= P) value -= P;
    return *this;
  }

  Z& operator-=(Z rhs) {
    value += P - rhs.value;
    if (value >= P) value -= P;
    return *this;
  }

  Z& operator*=(Z rhs) {
    value = (unsigned long long)value * rhs.value % P;
    return *this;
  }

  Z& operator/=(Z rhs) { return *this *= pow(rhs, -1); }

  Z operator+() const { return *this; }

  Z operator-() const { return Z() - *this; }

  bool operator==(Z rhs) const { return value == rhs.value; }

  bool operator!=(Z rhs) const { return value != rhs.value; }

  friend Z operator+(Z lhs, Z rhs) { return lhs += rhs; }

  friend Z operator-(Z lhs, Z rhs) { return lhs -= rhs; }

  friend Z operator*(Z lhs, Z rhs) { return lhs *= rhs; }

  friend Z operator/(Z lhs, Z rhs) { return lhs /= rhs; }

  friend ostream& operator<<(ostream& out, Z a) { return out << a.value; }

  friend istream& operator>>(istream& in, Z& a) {
    long long x;
    in >> x;
    a = Z(x);
    return in;
  }
};

template<unsigned P>
Z<P> pow(Z<P> x, long long p) {
  if (x == 0) {
    return p == 0 ? 1 : 0;
  }
  p %= P -1;
  if (p < 0) p += P-1;
  Z<P> res = 1;
  while (p) {
    if (p & 1) {
      res *= x;
    }
    x *= x;
    p >>= 1;
  }
  return res;
}
//}}}

const int MOD = 1e9+7;
using mint = Z<MOD>;

const int MAXA = 1e6;

// Debug {{{
#define var(x) "[", #x, " ", x, "] "
template<typename ...A> void db(A const&... a) { ((cout << (a)), ...); cout << endl; }
//}}}

const vector P10{1, 10, 100, 1'000, 10'000, 100'000, 1'000'000};

template<typename T>
void sos(vector<T> &A) {
  for (int d = 0; d < 6; d++) {
    for (int i = 0; i < 1e6; i++) {
      int dig = (i/P10[d])%10;
      for (int j = 1; j <= dig; j++) {
        int ni = i - j*P10[d];
        A[ni] += A[i];
      }
    }
  }
}

template<typename T>
void sos_minus(vector<T> &A) {
  for (int d = 0; d < 6; d++) {
    for (int i = 1e6-1; i >= 0; i--) {
      int dig = (i/P10[d])%10;
      for (int j = 1; j < 10-dig; j++) {
        int ni = i + j*P10[d];
        A[i] -= A[ni];
      }
    }
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);

  int N;
  cin >> N;

  vector<int> cnt(MAXA);
  vector<mint> ssq(MAXA), sum(MAXA);

  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    cnt[x] += 1;
    ssq[x] += x*x;
    sum[x] += x;
  }

  sos(cnt);
  sos(sum);
  sos(ssq);

  vector<mint> GS(MAXA);
  for (int i = 0; i < 1e6; i++) {
    if (cnt[i] == 0) continue;
    GS[i] = pow(mint(2), cnt[i]-2) * (sum[i] * sum[i] + ssq[i]);
  }
  sos_minus(GS);

  long long ans = 0;
  for (int i = 0; i < 1e6; i++) {
    auto g = GS[i];
    ans ^= (long long)i * g.value;
  }

  cout << ans << endl;
}

/* Solution Notes {{{

GS[s] =
  x y z w

  8x^2 + 8xy + 8xz + 8xw

  (x+y+z+w)^2
  x^2 + 2xy + 2xz + 2yz
}}} */
