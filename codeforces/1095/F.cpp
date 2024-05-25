#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using vp = vector <pair <ll, ll>>;
using vll = vector<ll>;
using vb = vector <bool>;
using vi = vector<ll>;

ll INF1 = 1e9;
ll n, m, u, q, p, t, k, a, b, c, d, l, r, x, y, z, k1, w, h, v1, add;
ll ans = 0;

vll link1(200000, -1);
vll size_set(200000, 1);

ll find1(ll v) {
  if (link1[v] == -1) {
    return v;
  }
  return find1(link1[v]);
}

void unite(ll u, ll v) {
  u = find1(u);
  v = find1(v);
  if (u == v) {
    return;
  }
  if (size_set[u] > size_set[v]) {
    link1[v] = u;
    size_set[u] += size_set[v];
  } else {
    link1[u] = v;
    size_set[v] += size_set[u];
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n >> m;
  if(m == 0 && n == 1){
    cout << 0;
    exit(0);
  }
  vector < pair < ll, pair < ll, ll >>> v(n + m);
  vp v1(n);
  for (int i = 0; i < n; i++) {
    cin >> v1[i].first;
    v1[i].second = i;
  }
  sort(v1.begin(), v1.end());
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      v[i] = {
        v1[1].first + v1[i].first,
        {
          v1[1].second,
          v1[0].second
        }
      };
    } else {
      v[i] = {
        v1[i].first + v1[0].first,
        {
          v1[i].second,
          v1[0].second
        }
      };
    }
  }
  for (int i = 0; i < m; i++) {
    cin >> x >> y >> w;
    x--;
    y--;
    v[i + n] = {
      w,
      {
        x,
        y
      }
    };
  }
  ans = 0;
  sort(v.begin(), v.end());
  m += n;
  for (int i = 0; i < m; i++) {
    a = v[i].first;
    b = v[i].second.first;
    c = v[i].second.second;
    if (find1(b) != find1(c)) {
      unite(b, c);
      ans += a;
    }
  }
  cout << ans;
}
