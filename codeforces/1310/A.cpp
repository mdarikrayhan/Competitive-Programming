#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> t(n);
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }
  a.push_back((int) 1.01e9);
  t.push_back(0);
  ++n;
  vector<int> order(n);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int i, int j) {
    return a[i] < a[j];
  });
  unsigned long long ans = 0;
  int last = 0;
  multiset<int> s;
  long long sum = 0;
  for (int i : order) {
    while (a[i] > last && !s.empty()) {
      ++last;
      auto it = prev(s.end());
      sum -= *it;
      s.erase(it);
      ans += sum;
    }
    last = a[i];
    s.insert(t[i]);
    sum += t[i];
  }
  cout << ans << '\n';
  return 0;
}