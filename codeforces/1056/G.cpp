// Author: Klay Thompson
// Problem: Take Metro
// Memory Limit: 1000 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

#define rep(i, j, k) for (int i = (j); i <= (k); ++i)
#define per(i, j, k) for (int i = (j); i >= (k); --i)
#define SZ(v) int((v).size())
#define ALL(v) (v).begin(),(v).end()
#define fi first
#define se second
using ll = long long;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;

template<class T>inline void chkmn(T &x, T y) { if (y < x) x = y; }
template<class T>inline void chkmx(T &x, T y) { if (y > x) x = y; }

using namespace std;

const int maxn = 100010;

int n, m, s, mp[maxn];
ll t;

int main() {
  cin.tie(nullptr) -> ios::sync_with_stdio(false);
  cin >> n >> m >> s >> t, s--;
  memset(mp, -1, sizeof(mp));
  mp[s] = 0;
  int cur = 0, loop = -1, w = t % n;
  while (true) {
    cur++;
    if (s < m) s = (s + t) % n;
    else s = ((s - t) % n + n) % n;
    t--;
    if (!t) return cout << s + 1 << '\n', 0;
    if (t % n == w && mp[s] != -1) {
      loop = cur - mp[s];
      break;
    }
    if (t % n == w) mp[s] = cur;
  }
  t %= loop;
  while (t) {
    if (s < m) s = (s + t) % n;
    else s = ((s - t) % n + n) % n;
    t--;
  }
  cout << s + 1 << '\n';
}