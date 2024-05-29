// LUOGU_RID: 160599386
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
using uint = unsigned int;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using vi = vector<int>;
template<typename T>
using V = vector<T>;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 1e5 + 7;
int n, a[N], f[1 << 11], pre[1 << 11];
bool vis[1 << 11];
vi G[1 << 11];
void bfs() {
  queue<int> q;
  f[0] = 0, vis[0] = true, q.push(0);
  while (q.size()) {
    int u = q.front(); q.pop();
    for (int v : G[u]) {
      if (!vis[v]) q.push(v), vis[v] = true, pre[v] = u, f[v] = f[u] + 1;
    }
  }
}
void init(int n) {
  For(S, 0, (1 << n) - 1) {
    For(x, 1, n) For(y, x + 1, n) {
      int z = y * 2 - x;
      if (z > n) break;
      int T = S ^ 1 << x - 1 ^ 1 << y - 1 ^ 1 << z - 1;
      G[S].pb(T);
    }
  }
  bfs();
}
V<tuple<int, int, int>> get_path(int S, int n) {
  vi path;
  for (int T = S; T; T = pre[T]) {
    path.pb(T);
  }
  path.pb(0);
  V<tuple<int, int, int>> ans;
  For(i, 1, f[S]) {
    int T = path[i - 1] ^ path[i];
    vi t;
    For(u, 1, n) if (T >> u - 1 & 1) t.pb(u);
    ans.eb(t[0], t[1], t[2]);
  }
  return ans;
}
void print(const V<tuple<int, int, int>> ans) {
  assert(ans.size() <= n / 3 + 12);
  cout << ans.size() << '\n';
  for (auto [x, y, z] : ans) cout << x << ' ' << y << ' ' << z << '\n';
}
int best[1 << 11];
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  For(i, 1, n) cin >> a[i];
  if (n <= 11) {
    init(n);
    int S = 0;
    For(i, 1, n) S ^= a[i] << i - 1;
    if (!vis[S] || f[S] > n / 3 + 12) cout << "NO";
    else {
      cout << "YES\n";
      print(get_path(S, n));
    }
    return 0;
  }
  cout << "YES\n";
  V<tuple<int, int, int>> ans;
  auto push = [&] (int x, int y, int z) -> void {
    ans.eb(x, y, z);
    a[x] ^= 1, a[y] ^= 1, a[z] ^= 1;
  };
  init(11);
  For(S, 0, (1 << 11) - 1) {
    int mi = numeric_limits<int>::max();
    For(T, 0, (1 << 5) - 1) {
      int res = f[S ^ T << 6];
      if (res < mi) mi = res, best[S] = T;
    }
  }
  int p = 1;
  while (p + 10 < n) {
    int S = 0;
    For(i, p, p + 10) S ^= a[i] << i - p;
    S ^= best[S] << 6;
    V<tuple<int, int, int>> nxt = get_path(S, 11);
    for (auto [x, y, z] : nxt) {
      push(x + p - 1, y + p - 1, z + p - 1);
    }
    p += 6;
  }
  int S = 0;
  For(i, p, n) S ^= a[i] << i - (n - 10);
  V<tuple<int, int, int>> operate = get_path(S, 11);
  for (auto [x, y, z] : operate) {
    push(x + n - 11, y + n - 11, z + n - 11);
  }
  For(i, 1, n) assert(!a[i]);
  print(ans);
  return 0;
}