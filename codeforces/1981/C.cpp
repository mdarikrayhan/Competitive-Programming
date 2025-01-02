#include <bits/stdc++.h>

using ll = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<ll> a(n);
  std::vector<ll> b(n), c;
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    if (a[i] != -1) {
      c.push_back(i);
      b[i] = a[i];
    }
  }

  if (c.empty()) {
    for (int i = 0; i < n; i++) {
      std::cout << (i % 2 ? 1 : 2) << " \n"[i == n - 1];
    }
    return;
  }

  for (int i = 1; i < c.size(); i++) {
    int x = c[i - 1], y = c[i];
    ll mn = std::min(a[x], a[y]), mx = std::max(a[x], a[y]);
    ll st = mn;
    ll l = st, r = st;
    ll cnt = c[i] - c[i - 1] - 1;
    ll now = 0;
    ll tmp = 0;
    while (true) {
      if (st == 0) {
        std::cout << -1 << "\n";
        return;
      }
      now = tmp;
      while (!(l <= mx && mx <= r)) {
        if (l > mx) {
          break;
        }
        // std::cout << l << " " << r << std::endl;
        l = l * 2;
        r = r * 2 + 1;
        now++;
      }
      if (l <= mx && mx <= r) break;
      else {
        tmp++;
        st /= 2;
        l = st, r = st;
      }
    }
    
    if (cnt + 1 < now || (now - cnt) % 2 == 0) {
      std::cout << -1 << "\n";
      return;
    }
    // std::cout << now << "\n";

    if (a[x] <= a[y]) {
      ll v = a[y];
      for (int i = now; i; i--) {
        b[x + i] = v;
        if (v == st) {
          v = a[x] / 2;
          for (int j = x + 1; j < x + i; j++) {
            b[j] = v;
            v /= 2;
          }
          break;
        }
        v /= 2;
      }
      v = a[y];
      for (int i = 1; x + now + i < y; i++) {
        b[x + now + i] = (i % 2 ? (v * 2) : v);
      }
    } else {
      ll v = a[x];
      for (int i = now; i; i--) {
        b[y - i] = v;
        if (v == st) {
          v = a[y] / 2;
          for (int j = y - 1; j > y - i; j--) {
            b[j] = v;
            v /= 2;
          }
          break;
        }
        v /= 2;
      }
      v = a[x];
      for (int i = 1; y - now - i > x; i++) {
        b[y - now - i] = (i % 2 ? (v * 2) : v);
      }
    }
  }

  ll v = a[c[0]];
  for (int i = 1; c[0] - i >= 0; i++) {
    b[c[0] - i] = (i % 2 ? v * 2 : v);
  }
  v = a[c.back()];
  for (int i = 1; c.back() + i < n; i++) {
    b[c.back() + i] = (i % 2 ? v * 2 : v);
  }

  for (int i = 0; i < n; i++) {
    std::cout << b[i] << " \n"[i == n - 1];
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }    
  return 0;
}