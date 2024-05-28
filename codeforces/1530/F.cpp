// LUOGU_RID: 159517800
#include <bits/stdc++.h>
// #define int int64_t
#define ALL(x) begin(x), end(x)
#define All(x, l, r) &x[l], &x[(r) + 1]
using namespace std;
void file () {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);
}
using ui = unsigned int;
using ll = long long;
using ull = unsigned long long;
using db = long double;
using Li = __int128_t;
template <typename T> using vec = vector<T>;

const int mod = 31607;
void Add(int &x, int y) { if((x += y) >= mod) x -= mod; }
void Sub(int &x, int y) { if((x -= y) < 0) x += mod; }
int Sum(int x, int y) { return Add(x, y), x; } 
int Dif(int x, int y) { return Sub(x, y), x; }
int qpow(int x, int y) {
  int b = x, r = 1;
  for(; y; b = (ll)b * b % mod, y /= 2) if(y & 1) r = (ll)r * b % mod;
  return r;
}
int Inv(int x) { return qpow(x, mod - 2); }

int32_t main () {
//  file();
  ios::sync_with_stdio(0); cin.tie(0);
  const int inv10000 = Inv(10000);
  int n;
  cin >> n;
  vec<vec<int>> P(n, vec<int> (n)), iP(n, vec<int> (n));
  vec<int> Mul(n, 1);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> P[i][j];
      P[i][j] = inv10000 * P[i][j] % mod;
      iP[i][j] = Inv(P[i][j]);
      Mul[i] = Mul[i] * P[i][j] % mod;
    }
  }
  
  vec<int> ban(n, 0);
  
  function <int()> solve = [&]() {
    vec<int> f(1 << n, 1), g(1 << n);
    for(int i = 0; i < n; i++) {
      fill(ALL(g), 0);
      g[0] = Mul[i];
      for(int S = 1; S < (1 << n); S++) {
        if(!(S & ban[i])) {
          int lb = __lg(S & -S);
          g[S] = g[S ^ (1 << lb)] * iP[i][lb] % mod;
        }
      }
      for(int S = 0; S < (1 << n); S++) {
        if(S & ban[i]) g[S] = g[S ^ (S & ban[i])];
      }
      for(int S = 0; S < (1 << n); S++) Sub(g[S], Mul[i]);
      for(int S = 0; S < (1 << n); S++) f[S] = g[S] * f[S] % mod;
    }
    for(int i = 0; i < n; i++) {
      for(int S = (1 << n) - 1; ~S; S--) {
        if((S >> i) & 1) Sub(f[S], f[S ^ (1 << i)]);
      }
    }
    return f.back();
  };
  
  int res = 0;
  Add(res, solve());
  for(int i = 0; i < n; i++) ban[i] |= (1 << i);
  Sub(res, solve());
  fill(ALL(ban), 0);
  for(int i = 0; i < n; i++) ban[n - i - 1] |= (1 << i);
  Sub(res, solve());
  for(int i = 0; i < n; i++) ban[i] |= (1 << i);
  Add(res, solve());
  cout << (mod + 1 - res) % mod << "\n";
  return 0;
}