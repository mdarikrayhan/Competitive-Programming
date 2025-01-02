// LUOGU_RID: 160015590
// powered by c++11
// by Isaunoya
#include <bits/stdc++.h>

#define rep(i, x, y) for (register int i = (x); i <= (y); ++i)
#define Rep(i, x, y) for (register int i = (x); i >= (y); --i)

using namespace std;
using db = double;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

using pii = pair<int, int>;

#define fir first
#define sec second

template <class T>

void cmax(T& x, const T& y) {
  if (x < y) x = y;
}

template <class T>

void cmin(T& x, const T& y) {
  if (x > y) x = y;
}

#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define pb emplace_back

template <class T>

void sort(vector<T>& v) {
  sort(all(v));
}

template <class T>

void reverse(vector<T>& v) {
  reverse(all(v));
}

template <class T>

void unique(vector<T>& v) {
  sort(all(v)), v.erase(unique(all(v)), v.end());
}

void reverse(string& s) { reverse(s.begin(), s.end()); }

const int io_size = 1 << 23 | 233;
const int io_limit = 1 << 22;
struct io_in {
  char ch;
#ifndef __WIN64
  char getchar() {
    static char buf[io_size], *p1 = buf, *p2 = buf;

    return (p1 == p2) && (p2 = (p1 = buf) + fread(buf, 1, io_size, stdin), p1 == p2) ? EOF : *p1++;
  }
#endif
  io_in& operator>>(char& c) {
    for (c = getchar(); isspace(c); c = getchar())
      ;

    return *this;
  }
  io_in& operator>>(string& s) {
    for (s.clear(); isspace(ch = getchar());)
      ;

    if (!~ch) return *this;

    for (s = ch; !isspace(ch = getchar()) && ~ch; s += ch)
      ;

    return *this;
  }

  io_in& operator>>(char* str) {
    char* cur = str;
    while (*cur) *cur++ = 0;

    for (cur = str; isspace(ch = getchar());)
      ;
    if (!~ch) return *this;

    for (*cur = ch; !isspace(ch = getchar()) && ~ch; *++cur = ch)
      ;

    return *++cur = 0, *this;
  }

  template <class T>

  void read(T& x) {
    bool f = 0;
    while ((ch = getchar()) < 48 && ~ch) f ^= (ch == 45);

    x = ~ch ? (ch ^ 48) : 0;
    while ((ch = getchar()) > 47) x = x * 10 + (ch ^ 48);
    x = f ? -x : x;
  }

  io_in& operator>>(int& x) { return read(x), *this; }

  io_in& operator>>(ll& x) { return read(x), *this; }

  io_in& operator>>(uint& x) { return read(x), *this; }

  io_in& operator>>(ull& x) { return read(x), *this; }

  io_in& operator>>(db& x) {
    read(x);
    bool f = x < 0;
    x = f ? -x : x;
    if (ch ^ '.') return *this;

    double d = 0.1;
    while ((ch = getchar()) > 47) x += d * (ch ^ 48), d *= .1;
    return x = f ? -x : x, *this;
  }
} in;

struct io_out {
  char buf[io_size], *s = buf;
  int pw[233], st[233];

  io_out() {
    set(7);
    rep(i, pw[0] = 1, 9) pw[i] = pw[i - 1] * 10;
  }

  ~io_out() { flush(); }

  void io_chk() {
    if (s - buf > io_limit) flush();
  }

  void flush() { fwrite(buf, 1, s - buf, stdout), fflush(stdout), s = buf; }

  io_out& operator<<(char c) { return *s++ = c, *this; }

  io_out& operator<<(string str) {
    for (char c : str) *s++ = c;
    return io_chk(), *this;
  }

  io_out& operator<<(char* str) {
    char* cur = str;
    while (*cur) *s++ = *cur++;
    return io_chk(), *this;
  }

  template <class T>

  void write(T x) {
    if (x < 0) *s++ = '-', x = -x;

    do {
      st[++st[0]] = x % 10, x /= 10;
    } while (x);

    while (st[0]) *s++ = st[st[0]--] ^ 48;
  }

  io_out& operator<<(int x) { return write(x), io_chk(), *this; }

  io_out& operator<<(ll x) { return write(x), io_chk(), *this; }

  io_out& operator<<(uint x) { return write(x), io_chk(), *this; }

  io_out& operator<<(ull x) { return write(x), io_chk(), *this; }

  int len, lft, rig;

  void set(int _length) { len = _length; }

  io_out& operator<<(db x) {
    bool f = x < 0;
    x = f ? -x : x, lft = x, rig = 1. * (x - lft) * pw[len];
    return write(f ? -lft : lft), *s++ = '.', write(rig), io_chk(), *this;
  }
} out;
#define int long long

template <int sz, int mod>

struct math_t {
  math_t() {
    fac.resize(sz + 1), ifac.resize(sz + 1);
    rep(i, fac[0] = 1, sz) fac[i] = fac[i - 1] * i % mod;

    ifac[sz] = inv(fac[sz]);
    Rep(i, sz - 1, 0) ifac[i] = ifac[i + 1] * (i + 1) % mod;
  }

  vector<int> fac, ifac;

  int qpow(int x, int y) {
    int ans = 1;
    for (; y; y >>= 1, x = x * x % mod)
      if (y & 1) ans = ans * x % mod;
    return ans;
  }

  int inv(int x) { return qpow(x, mod - 2); }

  int C(int n, int m) {
    if (n < 0 || m < 0 || n < m) return 0;
    return fac[n] * ifac[m] % mod * ifac[n - m] % mod;
  }
};

int gcd(int x, int y) { return !y ? x : gcd(y, x % y); }
int lcm(int x, int y) { return x * y / gcd(x, y); }

const int maxn = 1e5 + 51;
const int S = 500;

int n, k, _;
struct qry {
  int l, r, id;
  bool operator<(const qry& other) const { return r < other.r; }
};

vector<qry> v[S];
bool L[maxn][6], R[maxn][6];

struct dsu {
  int fa[maxn], sz[maxn];
  int st[maxn], top = 0;

  void init() { rep(i, 1, maxn - 1) sz[fa[i] = i] = 1; }

  int find(int x) { return fa[x] == x ? x : find(fa[x]); }

  void clear() {
    while (top) {
      int x = st[top--];
      sz[fa[x]] -= sz[x];
      fa[x] = x;
    }
  }

  void merge(int x, int y, bool ins = 1) {
    if (sz[x] < sz[y]) x ^= y ^= x ^= y;
    sz[x] += sz[y];
    fa[y] = x;
    if (ins) st[++top] = y;
  }
} dsu;

int bel(int x) { return (x - 1) / S + 1; }

int ans[maxn];
void solve(const qry& now) {
  const int l = now.l;
  const int r = now.r;
  const int id = now.id;
  int cnt = r - l + 1;
  rep(i, l, r) {
    for (int j = 1; j <= k && i + j <= r; j++) {
      if (R[i][j]) {
        int x = dsu.find(i);
        int y = dsu.find(i + j);
        if (x ^ y) {
          cnt--;
          dsu.merge(x, y);
        }
      }
    }
  }
  ans[id] = cnt;
  dsu.clear();
}
signed main() {
  // code begin.
  in >> n >> k >> _;
  dsu.init();
  while (_--) {
    int u, v;
    in >> u >> v;
    if (u > v) u ^= v ^= u ^= v;
    L[v][v - u] = R[u][v - u] = 1;
  }
  in >> _;
  rep(i, 1, _) {
    qry now;
    in >> now.l >> now.r;
    now.id = i;
    if (now.r - now.l <= S)
      solve(now);
    else
      v[bel(now.l)].pb(now);
  }
  rep(i, 1, bel(n)) {
    if (!sz(v[i])) continue;
    sort(v[i]);
    dsu.init();
    int r = i * S, cnt = 0;
    for (auto x : v[i]) {
      const int ql = x.l;
      const int qr = x.r;
      const int id = x.id;
      while (r < qr) {
        ++r;
        for (int j = 1; j <= k && r - j >= i * S; j++) {
          if (L[r][j]) {
            int x = dsu.find(r);
            int y = dsu.find(r - j);
            if (x ^ y) {
              ++cnt;
              dsu.merge(x, y, 0);
            }
          }
        }
      }
      int now = cnt;
      for (int l = i * S - 1; l >= ql; l--) {
        rep(j, 1, k) {
          if (R[l][j]) {
            int x = dsu.find(l);
            int y = dsu.find(l + j);
            if (x ^ y) {
              ++cnt;
              dsu.merge(x, y);
            }
          }
        }
      }
      ans[id] = qr - ql + 1;
      ans[id] -= cnt;
      cnt = now;
      dsu.clear();
    }
  }
  rep(i, 1, _) out << ans[i] << '\n';
  return 0;
  // code end.
}
