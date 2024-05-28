// LUOGU_RID: 159906960
#include <bits/stdc++.h>
using namespace std;
#define N 110
#define V 100010
#define M 5210
int n, k;
int first[V], cur[V], nxt[M], to[M], f[M], et = 1;
int e1;
int add(int u, int v, int w) {
  nxt[++et] = first[u]; first[u] = et; to[et] = v; f[et] = w;
  nxt[++et] = first[v]; first[v] = et; to[et] = u; f[et] = 0;
  return et - 1;
}
int s = 0, t = 1e5 + 1;
struct card {
  int p, c, l;
  bool operator< (const card& tmp) const {
    return l < tmp.l;
  }
}a[N];
bool not_prime[V * 2];
vector<int> prime;
void ini() {
  not_prime[1] = 1;
  for (int i = 2; i <= 2e5; ++i) {
    if (!not_prime[i]) {
      prime.emplace_back(i);
    }
    for (int j = 0; j < (int)prime.size() && prime[j] * i <= 2e5; ++j) {
      not_prime[i * prime[j]] = 1;
      if (i % prime[j] == 0) continue;
    }
  }
}
#define inf 0x3f3f3f3f
int d[V];
bool bfs() {
  queue<int> q;
  d[s] = d[t] = 0;
  for (int i = 1; i <= n; ++i) d[a[i].c] = 0;
  d[s] = 1;
  q.emplace(s);
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int i = first[u]; i; i = nxt[i]) {
      if (!d[to[i]] && f[i]) {
        d[to[i]] = d[u] + 1;
        q.emplace(to[i]);
      }
    }
  }
  cur[s] = first[s], cur[t] = first[t];
  for (int i = 1; i <= n; ++i) cur[a[i].c] = first[a[i].c];
  return d[t];
}
int dinic(int u, int flow) {
  if (u == t || !flow) return flow;
  int rest = flow;
  for (int& i = cur[u]; i; i = nxt[i]) {
    if (d[to[i]] == d[u] + 1 && f[i]) {
      int k = dinic(to[i], min(rest, f[i]));
      if (k) {
        f[i] -= k, f[i ^ 1] += k;
        rest -= k;
        if (!rest) break;
      }
    }
  }
  return flow - rest;
}
int main() {
  ini();
  cin.tie(nullptr) -> sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].p >> a[i].c >> a[i].l;
  }
  int res = -1;
  sort(a + 1, a + n + 1);
  int tot = 0, mfl = 0;
  for (int i = 1; i <= n; ++i) {
    if (a[i].c != 1 || !e1) {
      tot += a[i].p;
      if (a[i].c & 1) {
        int tt = add(s, a[i].c, a[i].p);
        if (a[i].c == 1) e1 = tt;
        for (int j = 1; j < i; ++j) {
          if (!not_prime[a[i].c + a[j].c]) add(a[i].c, a[j].c, inf);
        }
      } else {
        add(a[i].c, t, a[i].p);
        for (int j = 1; j < i; ++j) {
          if (!not_prime[a[i].c + a[j].c]) add(a[j].c, a[i].c, inf);
        }
      }
    } else {
      if (a[i].p > f[e1] + f[e1 ^ 1]) {
        tot += a[i].p - f[e1] - f[e1 ^ 1];
        f[e1] += a[i].p - f[e1] - f[e1 ^ 1];
      }
    }
    while (bfs()) mfl += dinic(s, inf);
    if (tot - mfl >= k) {res = a[i].l; break;}
  }
  cout << res;
  return 0;
}