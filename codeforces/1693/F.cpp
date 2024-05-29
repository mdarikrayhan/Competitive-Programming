// LUOGU_RID: 158578792
#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  int c0 = count(s.begin(), s.end(), '0');
  int c1 = s.size() - c0;
  if (c0 < c1) {
    for (auto &c : s) c = '1' + '0' - c;
    reverse(s.begin(), s.end());
    swap(c0, c1);
  }
  if (is_sorted(s.begin(), s.end()))
    return cout << 0 << "\n", void();
  int cur = 0, ans = 0;
  vector<int> mx(s.size() + 1, -1);
  mx[0] = n;
  for (int i = int(s.size()) - 1, r = 0; i >= 0; --i) {
    r += s[i] == '0' ? 1 : -1;
    if (r >= 0 && mx[r] == -1) mx[r] = i;
  }
  while (s[cur] == '0') ++cur, --c0;
  while (1) {
    if (c0 < c1) {++ans; break;}
    int nxt = mx[c0 - c1], len = nxt - cur;
    ++ans;
    for (int i = cur; i < cur + len / 2; ++i) s[i] = '0';
    for (int i = cur + len / 2; i < nxt; ++i) s[i] = '1';
    c0 -= len / 2;
    cur = nxt - len / 2;
    if (!c0) break;
    while (s[cur] == '0') ++cur, --c0;
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}