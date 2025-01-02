// LUOGU_RID: 159160581
#include <bits/stdc++.h>
// #define int int64_t
#define ALL(x) begin(x), end(x)
#define All(x, l, r) &x[l], &x[(r) + 1]
using namespace std;
void file () {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);
}
using ll = long long;
using ull = unsigned long long;
using db = long double;
using Li = __int128_t;
template <typename T> using vec = vector<T>;
/*
int mod;
void Add(int &x, int y) { if((x += y) >= mod) x -= mod; }
void Sub(int &x, int y) { if((x -= y) < 0) x += mod; }
int Sum(int x, int y) { return Add(x, y), x; } 
int Dif(int x, int y) { return Sub(x, y), x; }
int qpow(int x, int y) {
  int b = x, r = 1;
  for(; y; b = (ll)b * b % mod, y /= 2) if(y & 1) r = (ll)r * b % mod;
  return r;
}
int Inv(int x) { return qpow(x, mod - 2); } */

const int nLim = 2e5 + 5;
const ll inf = 1e12;
int n, m;
array<ll, nLim> pos, c;
array<array<ll, 2>, nLim> f;

struct SEG {
  ll l, r;
  SEG() {  }
  SEG(ll _l, ll _r) { l = _l; r = _r; }
};
array<SEG, nLim> seg, tseg;

void solve(int TT) {
  cin >> n >> m;
  fill(All(c, 1, n), 0);
  
  pos[0] = -inf; pos[n + 1] = inf;
  for(int i = 1; i <= n; i++) cin >> pos[i];
  sort(All(pos, 1, n));
  for(int i = 1; i <= m; i++) {
    cin >> tseg[i].l >> tseg[i].r;
  }
  sort(All(tseg, 1, m), [&](SEG x, SEG y) {
    return (x.l ^ y.l) ? (x.l < y.l) : (x.r > y.r);
  });
  int sz = 0;
  for(int i = 1; i <= m; i++) {
    int p = lower_bound(All(pos, 1, n), tseg[i].l) - &pos[0];
    if((p <= n) && (pos[p] <= tseg[i].r)) continue;
    while(sz && (seg[sz].r >= tseg[i].r)) sz--;
    seg[++sz] = tseg[i];
  }
  seg[0].l = -inf;
  seg[sz + 1].r = inf;
  
  for(int i = 0; i <= n + 1; i++) {
    int l = 0, r = sz + 1;
    while(l + 1 < r) {
      int mi = (l + r) >> 1;
      (seg[mi].r < pos[i]) ? (l = mi) : (r = mi);
    }
    c[i] = l;
  }
  
  f[0][0] = f[0][1] = 0;
  for(int i = 1; i <= n + 1; i++) {
    f[i].fill(inf);
    
    auto calc = [&](int x, int y, int px, int py) -> ll {
      auto val = [&](int p) -> ll {
        return (x + 1) * max(0ll, seg[p].l - pos[px]) + (y + 1) * max(0ll, pos[py] - seg[p + 1].r);
      };
      
      ll mn = inf;
      if(c[px] == c[py]) return 0;
      for(int i = c[px]; i <= c[py]; i++) mn = min(mn, val(i));
      return mn;
    };
    
    for(int x = 0; x < 2; x++) {
      for(int y = 0; y < 2; y++) {
        f[i][y] = min(f[i][y], f[i - 1][x] + calc(x, y ^ 1, i - 1, i));
      }
    }
  }
  cout << f[n + 1][0] << "\n";
}

int32_t main () {
//  file();
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  cin >> T;
  for (int i = 1; i <= T; i++) solve(i);
  return 0;
}