// LUOGU_RID: 160097892
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
const int N = 4e5 + 7;
int n;
string s;
ll r[N], b[N], ans;
struct node {
  int l, r, key, sz, tag;
  ll val;
} t[N];
int rt, cnt;
int nwnode(ll w) {
  ++cnt;
  t[cnt].l = t[cnt].r = 0;
  t[cnt].key = rnd();
  t[cnt].sz = 1, t[cnt].tag = 0;
  t[cnt].val = w;
  return cnt;
}
void pushup(int p) {
  t[p].sz = t[t[p].l].sz + t[t[p].r].sz + 1;
}
void pushdown(int p) {
  if (t[p].tag) {
    if (t[p].l) t[t[p].l].tag += t[p].tag, t[t[p].l].val += t[p].tag;
    if (t[p].r) t[t[p].r].tag += t[p].tag, t[t[p].r].val += t[p].tag;
    t[p].tag = 0;
  }
}
void split1(int p, ll k, int &x, int &y) {
  if (!p) x = y = 0;
  else {
    pushdown(p);
    if (t[p].val <= k) x = p, split1(t[p].r, k, t[x].r, y);
    else y = p, split1(t[p].l, k, x, t[y].l);
    pushup(p);
  }
}
void split2(int p, ll k, int &x, int &y) {
  if (!p) x = y = 0;
  else {
    pushdown(p);
    if (t[t[p].l].sz + 1 <= k) x = p, split2(t[p].r, k - t[t[p].l].sz - 1, t[x].r, y);
    else y = p, split2(t[p].l, k, x, t[y].l);
    pushup(p);
  }
}
int mrg(int x, int y) {
  if (!x || !y) return x + y;
  else {
    pushdown(x), pushdown(y);
    if (t[x].key > t[y].key) return t[x].r = mrg(t[x].r, y), pushup(x), x;
    else return t[y].l = mrg(x, t[y].l), pushup(y), y;
  }
}
void slv() {
  cin >> n >> s, s = '#' + s, rt = cnt = ans = 0;
  For(i, 1, n) cin >> r[i];
  For(i, 1, n) cin >> b[i];
  For(i, 1, n) ans += min(r[i], b[i]);
  For(i, 1, n) {
    if (r[i] <= b[i]) continue;
    if (s[i] == '1') {
      ll k = r[i] - b[i];
      int x, y;
      split1(rt, k, x, y);
      rt = mrg(mrg(x, nwnode(k)), y);
    } else {
      ll k = r[i] - b[i];
      if (k > t[rt].sz) {
        ans += t[rt].sz;
        --t[rt].val, --t[rt].tag;
      } else {
        ans += k;
        int x, y;
        split2(rt, t[rt].sz - k, x, y);
        int p = y;
        while (t[p].l) p = t[p].l;
        ll mi = t[p].val;
        --t[y].val, --t[y].tag;
        int u, v;
        split1(y, mi - 1, u, v);
        int q, w;
        split1(x, mi - 1, q, w);
        rt = mrg(mrg(mrg(q, u), w), v);
      }
      int x, y;
      split1(rt, 0, x, y);
      rt = y;
    }
  }
  ans = -ans;
  For(i, 1, n) ans += r[i] + b[i];
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int t; cin >> t;
  while (t--) slv();
  return 0;
}