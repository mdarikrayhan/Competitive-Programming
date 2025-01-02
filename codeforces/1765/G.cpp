// LUOGU_RID: 159724898
#include <bits/stdc++.h>
typedef long long ll;
using std::max; using std::min;
#define INF 1e18
#define rd() read<ll>()
#define lowbit(x) -x & x
#define E(i, l, r) for (int i = l; i <= r; ++ i)
#define FILE(filename) { \
  freopen(#filename ".in", "r", stdin); \
  freopen(#filename ".out", "w", stdout); \
}
template <typename T> inline T read() {
  T x = 0; char c = getchar(); bool f = 0;
  while (c < '0' || c > '9') {if (c == '-') f = 1; c = getchar();}
  while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  return f ? -x : x;
}
template <typename T> void write(T x) {
  if (x < 0) {putchar('-'); x = -x;}
  if (x / 10) write(x / 10);
  putchar((x % 10) ^ 48);
}
namespace pigeon {
  const int N = 1005;
  char c[N];
  int n, p[N], q[N];
  std::mt19937 gen(20221027);
  void ans() {
    std::cout << 0 << ' ';
    E(i, 1, n) putchar(c[i]);
    std::cout << std::endl;
    int x; x = rd();
  }
  int query_p(int x) {
    std::cout << "1 " << x << std::endl;
    int res; res = rd(); return res;
  }
  int query_q(int x) {
    std::cout << "2 " << x << std::endl;
    int res; res = rd(); return res;
  }
  int getf(char c) {return '0' + '1' - c;}
  bool get(int opt, int x, int y) {
    if (opt == 0 && y > 1) {c[x - 1] = c[y - 1], c[x] = c[y]; return 1;}
    if (opt == 0 && !y && c[2] == '1') {c[x - 1] = c[x] = '1'; return 1;}
    if (opt == 0 && y && c[2] == '0') {c[x - 1] = '1', c[x] = '0'; return 1;}
    if (opt == 1 && y > 1 ) {c[x - 1] = getf(c[y - 1]), c[x] = getf(c[y]); return 1;}
    if (opt == 1 && !y && c[2] == '1') {c[x - 1] = c[x] = '0'; return 1;}
    if (opt == 1 && y && c[2] == '0') {c[x - 1] = '0', c[x] = '1'; return 1;}
    return 0;
  }
  void Main() {
    n = rd();
    memset(p, -1, sizeof p);
    memset(q, -1, sizeof q);
    c[n + 1] = '\0';
    c[1] = '0'; c[2] = query_p(2) ? '0' : '1';
    for (int i = 3; i <= n; i += 2) {
      int opt = gen() % 2;
      int pos = i + (i + 1 <= n);
      int x = opt ? query_q(pos) : query_p(pos);
      if (get(opt, pos, x)) continue;
      opt = !opt; get(opt, pos, opt ? query_q(pos) : query_p(pos));
    } ans();
  }
}
int main() {
  int T = rd();
  while (T --) pigeon::Main();
  return 0;
}