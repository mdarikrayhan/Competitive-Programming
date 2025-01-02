#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

constexpr int mod = 998244353, N = 2000 + 5, M = 50 + 5;
namespace basic {
  inline int add(int x, int y) {return (x + y >= mod ? x + y - mod : x + y);}
  inline int dec(int x, int y) {return (x - y < 0 ? x - y + mod : x - y);}
  inline void ad(int &x, int y) {x = add(x, y);}
  inline void de(int &x, int y) {x = dec(x, y);}

  inline int qpow(int a, int b) {
    int r = 1;
    while(b) {
      if(b & 1) r = 1ll * r * a % mod;
      a = 1ll * a * a % mod; b >>= 1;
    }
    return r;
  }
  inline int inv(int x) {return qpow(x, mod - 2);}

  int fac[N], ifac[N];
  inline void fac_init(int n = N - 1) {
    fac[0] = 1;
    for(int i = 1; i <= n; i++)
      fac[i] = 1ll * fac[i - 1] * i % mod;
    ifac[n] = inv(fac[n]);
    for(int i = n - 1; i >= 0; i--)
      ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;
  }
  int invx[N];
  inline void inv_init(int n = N - 1) {
    invx[1] = 1;
    for(int i = 2; i <= n; i++)
      invx[i] = 1ll * (mod - mod / i) * invx[mod % i] % mod;
  }
  inline int binom(int n, int m) {
    if(n < m || m < 0) return 0;
    return 1ll * fac[n] * ifac[m] % mod * ifac[n - m] % mod;
  }
}
using namespace basic;

int n, k, a[M];
int F[M][N], G[M][N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  
  fac_init();

  cin >> n >> k;
  int S = 0;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    S += a[i];
  }
  int iS = inv(S);
  F[0][0] = 1;
  for(int j = 1; j <= n; j++) {
    memset(G, 0, sizeof(G));
    for(int t = 0; t * k < a[j]; t++) {
      int coef = 1ll * (t & 1 ? mod - 1 : 1) * ifac[t] % mod;
      int A = qpow(1ll * (a[j] - t * k) * iS % mod, t);
      int B = t ? qpow(1ll * (a[j] - t * k) * iS % mod, t - 1) : 0;
      for(int x = 0; x <= j - 1; x++) {
        for(int y = 0; y * k < S; y++) {
          if(!F[x][y]) {
            continue;
          }
          ad(G[x][y + t], 1ll * F[x][y] * coef % mod * A % mod);
          if(t) {
            ad(G[x + 1][y + t], 1ll * F[x][y] * coef % mod * t % mod * B % mod);
          }
        }
      }
    }
    for(int x = 0; x < M; x++) {
      for(int y = 0; y < N; y++) {
        swap(F[x][y], G[x][y]);
      }
    }
  }
  int ans = 0;
  for(int j = 1; j * k < S; j++) {
    for(int i = 0; i <= j && i <= n; i++) {
      int A = F[i][j], B = j - i, C = dec(1, 1ll * j * k * iS % mod);
      ad(ans, 1ll * A * fac[B] % mod * qpow(inv(dec(1, C)), B + 1) % mod);
    }
  }
  ans = dec(0, ans);
  cout << ans << "\n";
}
//
	 							  	  			  	  				   	