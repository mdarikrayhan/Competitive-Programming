#include <bits/stdc++.h>

using namespace std;

#define dbg(v) cerr << "L: " << __LINE__ << " " << #v << " -> " << (v) << endl;
#define all(v) (begin(v)), (end(v))
#define ral(v) (rbegin(v)), (rend(v))
#define lso(x) ((x) & -(x))
#define sz(vc) (int)(size(vc))

using ll = long long;
using ii = pair<int, int>;

int n, m, q;
string s;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  cin >> n >> m >> q >> s;

  int priority = 1;
  map<int, int> mp;
  set<int> candidates;
  vector<int> priorities(n, INT_MAX);

  for (int i = 0; i < n; i++) candidates.insert(i);

  while (m--) {
    int l, r;
    cin >> l >> r, l--, r--;
    auto node = candidates.lower_bound(l);
    while (node != end(candidates) && *node <= r) {
      mp[priority] = *node;
      priorities[*node] = priority;
      candidates.erase(node++);
      priority++;
    }
  }
  priority--;
  int one_cnt = count(all(s), '1'), to_fill = min(priority, one_cnt);
  int gd_cnt = 0;
  for (int i = 0; i < n; i++) if (priorities[i] <= to_fill) {
    if (s[i] == '1') gd_cnt++;
  }
  while (q--) {
    int x;
    cin >> x, x--;
    if (priorities[x] == INT_MAX) {
      if (s[x] == '0') {
        one_cnt++;
        if (min(priority, one_cnt) > to_fill) {
          to_fill = min(priority, one_cnt);
          if (s[mp[to_fill]] == '1') gd_cnt++;
        }
      } else {
        one_cnt--;
        if (min(priority, one_cnt) < to_fill) {
          if (s[mp[to_fill]] == '1') gd_cnt--;
          to_fill = min(priority, one_cnt);
        }
      }
    } else {
      if (s[x] == '0') {
        one_cnt++;
        if (min(priority, one_cnt) > to_fill) {
          to_fill = min(priority, one_cnt);
          if (s[mp[to_fill]] == '1' || to_fill == priorities[x]) gd_cnt++;
          if (priorities[x] < to_fill) gd_cnt++;
        } else {
          if (priorities[x] <= to_fill) gd_cnt++;
        }
      } else {
        one_cnt--;
        if (min(priority, one_cnt) < to_fill) {
          if (s[mp[to_fill]] == '1' || to_fill == priorities[x]) gd_cnt--;
          if (priorities[x] < to_fill) gd_cnt--;
          to_fill = min(priority, one_cnt);
        } else {
          if (priorities[x] <= to_fill) gd_cnt--;
        }
      }
    }
    cout << to_fill - gd_cnt << '\n';
    s[x] = s[x] == '1' ? '0' : '1';
  }

  return 0;
}
