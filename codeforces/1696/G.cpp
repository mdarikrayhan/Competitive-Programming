// LUOGU_RID: 156892993
#include <bits/stdc++.h>
using namespace std;

#define debug(...) fprintf(stderr, __VA_ARGS__)

using db = long double;
const int N = 2e5 + 5;
const int M = 3;
const db Infdb = 1e18;

struct Mat {
  db x[M][M];
  Mat() {
    for (int i = 0; i < M; ++i)
      for (int j = 0; j < M; ++j) x[i][j] = -Infdb;
  }
  Mat operator*(const Mat &b) {
    Mat c;
    for (int i = 0; i < M; ++i)
      for (int j = 0; j < M; ++j)
        for (int k = 0; k < M; ++k)
          if (x[i][k] != -Infdb && b.x[k][j] != -Infdb)
            c.x[i][j] = max(c.x[i][j], x[i][k] + b.x[k][j]);
    return c;
  }
};

int X, Y, a[N];
Mat t[4 * N];
#define LS (2 * i)
#define RS (2 * i + 1)
#define LP LS, l, mid
#define RP RS, mid + 1, r
void modify(int i, int l, int r, int x) {
  if (l == r) {
    auto &p = t[i].x;
    p[0][0] = p[1][0] = p[2][0] = 0;
    p[0][1] = db(a[l]) / Y;
    p[0][2] = p[2][2] = db(a[l]) / (X + Y);
    p[1][1] = p[2][1] = p[1][2] = -Infdb;
    return;
  }
  int mid = (l + r) / 2;
  if (x <= mid) modify(LP, x);
  else modify(RP, x);
  t[i] = t[LS] * t[RS];
}
Mat query(int i, int l, int r, int ql, int qr) {
  if (ql <= l && qr >= r) return t[i];
  int mid = (l + r) / 2;
  if (qr <= mid) return query(LP, ql, qr);
  else if (ql > mid) return query(RP, ql, qr);
  else return query(LP, ql, qr) * query(RP, ql, qr);
}

int main() {
  int n, q;
  scanf("%d%d%d%d", &n, &q, &X, &Y);
  if (X > Y) swap(X, Y);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    modify(1, 0, n - 1, i);
  }
  while (q--) {
    int op, x, y;
    scanf("%d%d%d", &op, &x, &y);
    if (op == 1) a[--x] = y, modify(1, 0, n - 1, x);
    else {
      --x, --y;
      Mat f;
      f.x[0][0] = 0;
      f = f * query(1, 0, n - 1, x, y);
      printf("%.10Lf\n", max({f.x[0][0], f.x[0][1], f.x[0][2]}));
    }
  }
  return 0;
}