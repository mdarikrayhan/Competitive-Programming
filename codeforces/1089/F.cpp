#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define eb emplace_back
#define MP make_pair
#define MT make_tuple
#define IT iterator
#define fi first
#define se second
#define For(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define Rep(i, a, b) for (int i = (int)(a); i >= (int)(b); --i)
#define CLR(a, v) memset(a, v, sizeof(a))
#define CPY(a, b) memcpy(a, b, sizeof(a))
#define debug cerr << "ztxakking\n"
#define y0 ztxaknoi
#define y1 ztxakioi
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using uint = unsigned;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using vi = vector<int>;
template<typename T>
using V = vector<T>;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
int n;
V<pii> fac;
void init(int n) {
  int p = 2;
  while (p * p <= n) {
    if (n % p == 0) {
      int e = 0;
      while (n % p == 0) ++e, n /= p;
      fac.eb(p, e);
    }
    ++p;
  }
  if (n > 1) fac.eb(n, 1);
}
void exgcd(int a, int b, int c, ll &x, ll &y) {
  if (!b) return x = c, y = 0, void();
  exgcd(b, a % b, c, y, x), y -= a / b * x;
}
void print(int x) {
  int d = __gcd(x, n);
  cout << x / d << ' ' << n / d << '\n';
}
void slv() {
  if (fac.size() <= 1) return cout << "NO", void();
  cout << "YES\n";
  int a = fac[0].fi, b = fac[1].fi;
  ll x, y;
  exgcd(a, b, n - 1, x, y);
  x = (x % b + b) % b, y = (n - 1 - x * a) / b;
  cout << "2\n";
  print(x * a), print(y * b);
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  init(n);
  slv();
  return 0;
}