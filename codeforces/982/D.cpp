#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include "./algo/debug.h"
#endif

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<array<int, 2>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i][0];
    a[i][1] = i + 1;
  }
  sort(a.begin(), a.end());
  vector<int> left(n + 3), b(n + 3), size(n + 3);
  iota(left.begin(), left.end(), 0);
  auto find = [&](auto find, int i) -> int {
    return left[i] == i ? i : left[i] = find(find, left[i]);
  };
  int c = 0, mx = 0, mxc = 0, ans = 0;
  int j = 0;
  for (auto& [val, index] : a) {
    b[index] = 1;
    int li = find(find, index - 1), ri = find(find, index + 1);
    if (b[index - 1] && b[index + 1]) {
      c--;
      left[index] = li, left[ri] = li;
      size[li] += size[ri] + 1;
      mx = max(mx, size[li]);
    } else if (!b[index - 1] && !b[index + 1]) {
      size[index] = 1;
      c++;
      mx = max(mx, size[index]);
    } else if (b[index - 1]) {
      left[index] = li;
      size[li]++;
      mx = max(mx, size[li]);
    } else {
      left[ri] = index;
      size[index] = 1 + size[ri];
      mx = max(mx, size[index]);
    }
    if (c * mx == j + 1 && c > mxc) {
      mxc = c;
      ans = val + 1;
    }
    j++;
  }
  cout << ans;
  return 0;
}