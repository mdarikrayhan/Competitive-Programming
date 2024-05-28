#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define nl '\n'
#define ff first
#define ss second
#define pb push_back
#define sik(x) {cout << x << nl; return;}
const ll maxn = 3000+10, mod = 1e9 + 7, inf = 1e10;
typedef pair<ll, ll> pii;

struct edge {
  ll u, v, w;
  bool operator < (const edge &e) {
    return w < e.w;
  }
} E[maxn];

ll n, m, par[maxn], sz[maxn], x[maxn], cnt[maxn], S;

inline void add(ll v) {
  sz[v] = 1;
  par[v] = v;
  cnt[v] = x[v];
}

ll get(ll v) {
  if (par[v] == v) return v;
  return par[v] = get(par[v]);
}

inline ll merge(ll u, ll v) {
  u = get(u), v = get(v);
  if (u == v) return 0;
  if (sz[u] < sz[v]) swap(u, v);
  par[v] = u;
  sz[u] += sz[v];
  cnt[u] += cnt[v];
  return 1;
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for (int i = 1 ; i < n ; i ++) cin >> E[i].v >> E[i].u >> E[i].w;
  for (int i = 1 ; i <= n ; i ++) cin >> x[i], add(i), S += x[i];
  sort(E+1, E+n);
  for (int i = 1 ; i < n ; i ++) {
    ll u = get(E[i].u), v = get(E[i].v);
    merge(u, v);
    if (S - cnt[get(u)] < sz[get(u)]) return cout << E[i].w << nl, 0;
  }
  cout << "0\n";
  return 0;
}

// bool chk(ll mid) {
//   for (ll i = 1 ; i <= n ; i ++) add(i);
//   for (edge e : E) {
//     if (e.w < mid) merge(e.v, e.u);
//   }
//   bool f = 1;
//   for (ll i = 1 ; i <= n && f ; i ++) {
//     if (get(i) == i) f &= (sz[i] <= S - cnt[i]);
//   }
//   return f;
// }
//
// int32_t main() {
//   cin.tie(0)->sync_with_stdio(0); 
//   cin >> n;
//   for (ll i = 1 , u , v, w ; i < n ; i ++) cin >> u >> v >> w, E[i] = {u, v, w};
//   for (int i = 1 ; i <= n ; i ++) cin >> x[i], S += x[i];
//   ll l = 0, r = 1e4+10;
//   while (r - l > 1) {
//     ll mid = (l + r) >> 1;
//     if (chk(mid)) l = mid;
//     else r = mid;
//   }
//   cout << l << nl;
//   return 0;
// }
