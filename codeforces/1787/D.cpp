# include <bits/stdc++.h>

using namespace std;

namespace lyre {
  namespace test_case {
    constexpr int nmax = 200'100;
    constexpr auto inf = numeric_limits<long long>::max() / 2;
    int n, a[nmax], siz[nmax];
    bool vis[nmax];
    vector<int> ch[nmax];
    void search(int x) {
      siz[x] = 1;
      for (auto y : ch[x])
        search(y), siz[x] += siz[y];
    }
    void main() {
      cin >> n;
      fill(ch, ch + n + 1, vector<int>());
      fill(siz, siz + n + 1, 0);
      fill(vis, vis + n + 1, false);
      for (int i = 1; i <= n; ++i) {
        cin >> a[i], a[i] += i;
        if (a[i] < 1 || a[i] > n) a[i] = 0;
        ch[a[i]].push_back(i);
      }
      search(0);
      if (siz[1]) {
        auto ans = 1ll * n * (2 * n + 1);
        for (int i = 1; i; i = a[i])
          ans -= siz[i] + n + 1 - siz[0];
        cout << ans << '\n';
      } else {
        auto ans = 0ll;
        for (int i = 1; !vis[i]; i = a[i])
          vis[i] = true, ans += n + siz[0];
        cout << ans << '\n';
      }
    }
  }
  void main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    for (int i = 0; i < t; ++i)
      test_case::main();
  }
}

int main() { lyre::main(); }