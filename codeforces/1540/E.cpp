// LUOGU_RID: 149593249
#include <bits/stdc++.h>
#define IL inline
#define LL long long
#define eb emplace_back
#define L(i, j, k) for (int i = (j); i <= (k); ++i)
#define R(i, j, k) for (int i = (j); i >= (k); --i)
using namespace std;

using vi = vector<int>;

constexpr int mod = 1e9 + 7;
// Helps 
using uLL = unsigned long long;

IL int ksm (int b, int k = mod - 2) {
  int r = 1;
  for (; k; k >>= 1, b = (uLL)b * b % mod) if (k & 1) r = (uLL)r * b % mod;
  return r;
}

template<class T>
IL void qm (T &x) {
  x += (x >> 31) & mod;
}
template<class T>
IL T nor (const T &x) {
  return x + ((x >> 31) & mod);
}
//

constexpr int N = 3e2 + 9;
constexpr int INF = 1e9 + 11;
int n, m, a[N], d[N], v[N][N], tv[N][N], c[N][N], ipw[N][N];
vi g1[N], g2[N];

struct BIT {
  int t[N];

  void clr () {
    memset(t, 0, (n + 2) << 2);
  }

  void mdy (int x, int v) {
    ++x;
    for (; x <= n + 1; x += x & (-x)) {
      qm(t[x] += v - mod);
    }
  }

  int qry (int x) {
    if (x > n) {
      x = n;
    }
    ++x;
    int r = 0;
    for (; x; x &= (x - 1)) {
      qm(r += t[x] - mod);
    }
    return r;
  }
} t[N];

IL void Do () {
  L (i, 1, n) {
    if (a[i] > 0) {
      d[i] = 0;
    } else {
      d[i] = INF;
    }
  }
  R (i, n, 1) {
    for (int j : g2[i]) {
      d[j] = min(d[j], d[i] + 1);
    }
  }
  L (i, 1, n) {
    t[i].clr();
  }
  L (i, 1, n) {
    if (d[i] <= n) {
      L (j, 1, n) {
        t[j].mdy(d[i], (uLL)nor(a[i]) * c[i][j] % mod * ipw[j][d[i]] % mod);
      }
    }
  }
}

void init () {
  ipw[0][0] = 1;
  L (i, 1, n) {
    ipw[i][0] = 1;
    int iv = ksm(i);
    L (j, 1, n) {
      ipw[i][j] = (uLL)ipw[i][j - 1] * iv % mod;
    }
  }
  L (i, 1, n) {
    v[i][i] = 1;
    R (j, i - 1, 1) {
      int s = 0;
      for (int k : g1[j]) {
        s = (s + (uLL)k * v[i][k]) % mod;
      }
      v[i][j] = (uLL)s * ksm(i - j) % mod;
    }
  }
  L (i, 1, n) {
    L (j, 1, n) {
      tv[i][j] = v[i][j];
      qm(v[i][j] += v[i][j - 1] - mod);
    }
  }
  L (i, 1, n) {
    c[i][i] = 1;
  }
  L (i, 1, n) {
    uLL iv = ksm(tv[i][i]);
    L (j, 1, n) {
      c[i][j] = c[i][j] * iv % mod;
    }
    L (j, 1, n) {
      if (i ^ j) {
        uLL cf = nor(-tv[j][i]);
        L (k, 1, n) {
          c[j][k] = (c[j][k] + cf * c[i][k]) % mod;
        }
      }
    }
  }
}

int main () {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  L (i, 1, n) {
    cin >> a[i];
  }
  L (i, 1, n) {
    int k;
    cin >> k;
    while (k--) {
      int j;
      cin >> j;
      g1[i].eb(j);
      g2[j].eb(i);
    }
  }
  init();
  Do();
  L (i, 1, n) {
    L (j, 1, n) {
      int q = 0;
      L (k, 1, n) {
        q = (q + (uLL)c[i][k] * v[k][j]) % mod;
      }
    }
  }
  cin >> m;
  while (m--) {
    int o;
    cin >> o;
    if (o == 1) {
      int k, l, r;
      cin >> k >> l >> r;
      int s = 0;
      L (i, 1, n) {
        s = (s + (uLL)nor(v[i][r] - v[i][l - 1]) * t[i].qry(k) % mod * ksm(i, k)) % mod;
      }
      LL q = 0;
      L (i, l, r) {
        if (d[i] > k) {
          q += a[i];
        }
      }
      qm(s += nor(q % mod) - mod);
      cout << s << '\n';
    } 
    else {
      int x, y;
      cin >> x >> y;
      a[x] += y;
      if (a[x] > 0 && a[x] <= y) {
        Do();
      } else if (d[x] <= n) {
        L (i, 1, n) {
          t[i].mdy(d[x], (uLL)y * c[x][i] % mod * ipw[i][d[x]] % mod);
        }
      }
    }
  }
}
// I love WHQ!