#include<bits/stdc++.h>
using namespace std;

using Complex = complex<double>;
void fft(vector<Complex>& a) {
  static vector<complex<long double>> R(2, 1); 
  static vector<Complex> rt(2, 1); // (^ 10% faster if double)
  int n = (int)a.size(), L = 31 - __builtin_clz(n);
  for(static int k = 2; k < n; k *= 2) {
    R.resize(n);
    rt.resize(n);
    auto x = polar(1.0L, acos(-1.0L) / k);
    for (int i = k; i < 2 * k; ++i) {
      rt[i] = R[i] = i & 1 ? R[i / 2] * x : R[i / 2];
    }
  }
  vector<int> rev(n);
  for(int i = 0; i < n; ++i) {
    rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
    if (i < rev[i]) swap(a[i], a[rev[i]]);
  }
  for (int k = 1; k < n; k *= 2)
    for (int i = 0; i < n; i += 2 * k)
      for (int j = 0; j < k; ++j) {
        // Complex z = rt[j+k] * a[i+j+k]; // (25% faster if hand-rolled)  /// include-line
        auto x = (double *)&rt[j+k], y = (double *)&a[i+j+k];              /// exclude-line
        Complex z(x[0]*y[0] - x[1]*y[1], x[0]*y[1] + x[1]*y[0]);           /// exclude-line
        a[i + j + k] = a[i + j] - z;
        a[i + j] += z;
      }
}

template<typename T = long long>
vector<T> convolution(const vector<T>& a, const vector<T>& b) {
  if (a.empty() || b.empty()) return {};
  vector<T> res((int)a.size() + (int)b.size() - 1);
  int L = 32 - __builtin_clz((int)res.size()), n = 1 << L;
  vector<Complex> in(n), out(n);
  copy(a.begin(), a.end(), in.begin());
  for (int i = 0; i < (int)b.size(); ++i) in[i].imag((double)b[i]);
  fft(in);
  for (Complex& x: in)  x *= x;
  for (int i = 0; i < n; ++i) out[i] = in[-i & (n - 1)] - conj(in[i]);
  fft(out);
  for (int i = 0; i < (int)res.size(); ++i) {
    res[i] = (T)llround(imag(out[i]) / (4 * n)); // remove rounding if the output is double
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, x;
  cin >> n >> x;
  vector<long long> cnt(n + 1);
  vector<int> pr(n + 1);
  cnt[0] = 1;
  for(int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    pr[i + 1] = pr[i] + (a < x);
    cnt[pr[i + 1]] += 1;
  }
  auto o = cnt;
  reverse(begin(o), end(o));
  auto c = convolution(cnt, o);
  c[n] -= (n + 1);
  c[n] /= 2;
  for(int i = n; i < (int)c.size(); ++i) {
    cout << c[i] << ' ';
  }
  cout << '\n';
  return 0;
} 