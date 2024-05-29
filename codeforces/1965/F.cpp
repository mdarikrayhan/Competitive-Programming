#include <bits/stdc++.h>
 
using namespace std;
 
const long long inf = (long long) 1e18;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> l(n), r(n);
  for (int i = 0; i < n; i++) {
    cin >> l[i] >> r[i];
  }
  int original_n = n;

  for (int rot = 0; rot < 2; rot++) {
    // make all left ends distinct
    map<long long, vector<long long>> mp;
    for (int i = 0; i < n; i++) {
      mp[l[i]].push_back(r[i]);
    }

    vector<long long> new_l, new_r;
    auto it = mp.begin();
    multiset<long long> s;
    long long T = -inf;
    
    while (true) {
      if (s.empty()) {
        if (it == mp.end()) {
          break;
        }
        T = it->first;
      }
      while (it != mp.end() && T == it->first) {
        s.insert(it->second.begin(), it->second.end());
        ++it;
      }
      assert(!s.empty());
      new_l.push_back(T);
      new_r.push_back(*s.begin());
      s.erase(s.begin());
      T += 1;
      while (!s.empty() && *s.begin() < T) {
        s.erase(s.begin());
      }
    }
    swap(l, new_l);
    swap(r, new_r);
    n = (int) l.size();
    for (int i = 0; i < n; i++) {
      l[i] *= -1;
      r[i] *= -1;
      swap(l[i], r[i]);
    }
  }
  
  sort(l.begin(), l.end());
  sort(r.begin(), r.end());
  vector<long long> ans(original_n + 1);
  long long lx = -inf, rx = -inf;
  int pl = 0, pr = 0;
  int k = 0;
  while (pl < n || pr < n) {
    long long wait = min(pl < n ? l[pl] - lx : inf, pr < n ? r[pr] - rx : inf);
    ans[k] += wait;
    lx += wait;
    rx += wait;
    while (pl < n && l[pl] == lx) {
      k += 1;
      lx += 1;
      pl += 1;
    }
    while (pr < n && r[pr] == rx) {
      ans[k] += 1;
      k -= 1;
      rx += 1;
      pr += 1;
    }
  }
  for (int i = n; i > 1; i--) {
    ans[i - 1] += ans[i];
  }
  for (int i = 1; i <= original_n; i++) {
    cout << ans[i] << '\n';
  }
  return 0;
}