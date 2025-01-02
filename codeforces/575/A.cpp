// LUOGU_RID: 159675017
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/hash_policy.hpp>
#include <ext/rope>

bool Mbe;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

std :: mt19937 rnd (std :: chrono :: steady_clock :: now ().time_since_epoch ().count ());
template < typename T > T gen (const T l, const T r) {
  return rnd () % (r - l + 1) + l;
}
const double pi = std :: acos (-1);

template < typename T > inline void read (T &val) {
  T x = 0;
  bool f = false;
  char c = std :: getchar ();
  for ( ; c < '0' || c > '9' ; c = std :: getchar ()) {
    f |= (c == '-');
  }
  for ( ; c >= '0' && c <= '9' ; c = std :: getchar ()) {
    x = (x << 1) + (x << 3) + (c & 15);
  }
  val = (!f) ? (x) : (-x);
  return ;
}

#define debug(fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)
const i64 hashmod1 = 2147483579, hashmod2 = 1610612741, hashmod3 = 805306457;

template < typename T, typename I > void chkmin (T &p, I q) {
  T q_ = q; 
  p = std :: min (p, q_); 
  return ;
}
template < typename T, typename I > void chkmax (T &p, I q) {
  T q_ = q; 
  p = std :: max (p, q_); 
  return ;
}

const int N = static_cast < int > (5e4) + 25;

std :: map < i64, i64 > s;
int n, m;
i64 mod;

std :: set < i64 > st;
std :: set < i64 > may_affect;

struct Matrix {
  int n, m;
  i64 a[2][2];
};

Matrix operator * (Matrix lhs, Matrix rhs) {
  Matrix res;
  res = (Matrix) {
    .n = lhs.n,
    .m = rhs.m,
    .a = {
      {0, 0},
      {0, 0}
    }
  };

  for (int i = 0;i < res.n; ++ i) {
    for (int j = 0;j < res.m; ++ j) {
      for (int k = 0;k < lhs.m; ++ k) {
        res.a[i][j] = (res.a[i][j] + lhs.a[i][k] * rhs.a[k][j] % mod) % mod;
      }
    }
  }

  return res;
}
void operator *= (Matrix &lhs, Matrix rhs) {lhs = (lhs * rhs); return ;}

Matrix operator ^ (Matrix lhs, i64 rhs) {
  assert (rhs >= 0);
  assert (lhs.n == lhs.m);
  Matrix res;
  res = (Matrix) {
    .n = lhs.n,
    .m = lhs.n,
    .a = {
      {1, 0},
      {0, 1}
    }
  };

  for (; rhs > 0; rhs >>= 1, lhs *= lhs) {
    if (rhs & 1) res *= lhs;
  }

  return res;
}
void operator ^= (Matrix &lhs, i64 rhs) {lhs = (lhs ^ rhs); return ;}

i64 query_s (i64 x) {
  if (x >= 0 && s.count (x)) {
    return s[x];
  }
  else {
    if (x < 0) {
      x = -x;
      x %= n;
      x = (n - x) % n;
    }
    else x %= n;
    return s[x];
  }
}

Matrix query_matrix (i64 x) {
  return (Matrix) {
    .n = 2, 
    .m = 2, 
    .a = {
      {query_s (x - 1), 1},
      {query_s (x - 2), 0}
    }
  };
}

i64 query_first (i64 l, i64 r) {
  if (may_affect.empty ()) return -1;
  else if (*may_affect.rbegin () < l) return -1;
  else if (may_affect.count (l)) return l;
  else {
    may_affect.insert (l);
    auto it = may_affect.find (l);
    it ++;
    i64 ans = *it;
    may_affect.erase (l);
    return (ans <= r) ? ans : -1;
  }
}

namespace SegmentTree {
  Matrix info[N << 2];

  void push_up (int u) {
    info[u] = info[u << 1] * info[u << 1 | 1];
    return ;
  }

  void build (int u, int l, int r) {
    if (l == r) {
      info[u] = query_matrix (1ll * l);
      return ;
    }
    int mid = (l + r) >> 1;
    build (u << 1, l, mid);
    build (u << 1 | 1, mid + 1, r);
    push_up (u);
    return ;
  }

  Matrix query (int u, int l, int r, int x, int y) {
    if (x <= l && r <= y) {
      return info[u];
    }
    int mid = (l + r) >> 1;
    if (x <= mid && y > mid) return query (u << 1, l, mid, x, y) * query (u << 1 | 1, mid + 1, r, x, y);
    else if (x <= mid) return query (u << 1, l, mid, x, y);
    else if (y > mid) return query (u << 1 | 1, mid + 1, r, x, y);
    else return (Matrix) {
      .n = 2,
      .m = 2,
      .a = {
        {1, 0},
        {0, 1}
      }
    };
  }
}

Matrix solve (i64 l, i64 r) {
  if (l > r) {
    return (Matrix) {
      .n = 2,
      .m = 2,
      .a = {
        {1, 0},
        {0, 1}
      }
    };
  }

  auto mid = query_first (l, r);
  
  if (mid == -1) {
    auto res = solve (1, 0);
    auto suf = solve (1, 0);

    if (l % n && l <= r) {
      i64 x = l + (n - 1) - (l % n);
      chkmin (x, r);
      res *= SegmentTree :: query (1, 0, n - 1, l % n, x % n);
      l = x + 1;
    }

    if (r % n != n - 1 && l <= r) {
      i64 x = r - (r % n);
      chkmax (x, l);
      suf = SegmentTree :: query (1, 0, n - 1, x % n, r % n);
      r = x - 1;
    }

    if (l <= r) {
      i64 t = (r - l + 1) / n;
      res *= ((SegmentTree :: info[1]) ^ t);
    }

    return res * suf;
  }
  else {
    return solve (l, mid - 1) * query_matrix (mid) * solve (mid + 1, r);
  }
}

bool Med;
signed main () {
  debug ("%.8lf MB\n", (&Mbe - &Med) / 1048576.0);

  s.clear ();
  i64 k;
  read (k), read (mod);
  read (n);
  for (i64 i = 0;i < n; ++ i) {
    i64 w;
    read (w);
    w %= mod;
    s[i] = w;
  }

  read (m);
  while (m --) {
    i64 i, w;
    read (i), read (w);
    w %= mod;
    s[i] = w;
    st.insert (i);
    may_affect.insert (i + 1);
    may_affect.insert (i + 2);
  }

  SegmentTree :: build (1, 0, n - 1);

  if (mod == 1) printf ("0\n");
  else {
    if (!k) printf ("0\n");
    else if (k == 1) printf ("1\n");
    else {
      Matrix init = (Matrix) {
        .n = 1,
        .m = 2,
        .a = {
          {1, 0},
          {0, 0}
        }
      };

      printf ("%lld\n", (init * solve (2, k)).a[0][0]);
    }
  }

  debug ("%.8lf ms\n", 1e3 * clock () / CLOCKS_PER_SEC);
  return 0;
}
// g++ "CF575A Fibonotci.cpp" -o CF575A -std=c++14 -O2 -Wall -Wextra -Wshadow
// check! no inline! (except fastIO)