#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr i64 inf = (i64) 1e12;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  int tt;
  cin >> tt;
  while (tt--) {
    int n, x, y;
    cin >> n >> x >> y;
    int need = y - x;
    vector<int> b(n);
    vector<vector<int>> at(n + 2);
    for (int i = 0; i < n; i++) {
      cin >> b[i];
      at[b[i]].push_back(i);
    }
    set<pair<int, int>, greater<>> st;
    for (int i = 1; i <= n + 1; i++) {
      if (!at[i].empty()) {
        st.insert({at[i].size(), i});
      }
    }
    vector<int> vis(n);
    vector<int> ans = b;
    while (x > 0) {
      auto it = st.begin();
      int ind = at[it->second].back();
      at[it->second].pop_back();
      vis[ind] = 1;
      pair<int, int> nval = {at[it->second].size(), it->second};
      st.erase(it);
      if (nval.first > 0) {
        st.insert(nval);
      }
      --x;
    }
    auto verify = [&]() -> int {
      vector<int> siz;
      for (auto& arr : at) {
        if (arr.empty()) {
          continue;
        }
        siz.push_back(arr.size());
      }
      if (siz.size() <= 1) {
        return 0;
      }
      sort(siz.begin(), siz.end());
      int tsum = 0;
      for (int i = 0; i + 1 < siz.size(); i++) {
        tsum += siz[i];
      }
      if (tsum < siz.back()) {
        return tsum * 2;
      }
      return tsum + siz.back();
    };
    if (verify() < need) {
      cout << "NO\n";
      continue;
    }
    while (need > 1) {
      if (need == 3) {
        if (st.size() >= 3) {
          auto it1 = st.begin();
          auto it2 = next(it1);
          auto it3 = next(it2);
          int l1 = at[it1->second].back();
          int l2 = at[it2->second].back();
          int l3 = at[it3->second].back();
          swap(ans[l1], ans[l2]);
          swap(ans[l2], ans[l3]);
          vis[l1] = vis[l2] = vis[l3] = 1;
          need = 0;
          break;
        }
      }
      auto it = st.begin();
      auto it2 = next(it);
      int lind = at[it->second].back();
      at[it->second].pop_back();
      int rind = at[it2->second].back();
      at[it2->second].pop_back();
      swap(ans[lind], ans[rind]);
      vis[lind] = 1;
      vis[rind] = 1;
      pair<int, int> nwl = {it->first - 1, it->second};
      pair<int, int> nwr = {it2->first - 1, it2->second};
      st.erase(it);
      st.erase(it2);
      if (nwl.first > 0) {
        st.insert(nwl);
      }
      if (nwr.first > 0) {
        st.insert(nwr);
      }
      need -= 2;
    }
    vector<int> extra;
    if (need == 1) {
      assert(st.size() >= 2);
      auto it = st.begin();
      auto it2 = next(it);
      int lind = at[it->second].back();
      at[it->second].pop_back();
      int rind = at[it2->second].back();
      at[it2->second].pop_back();
      swap(ans[lind], ans[rind]);
      vis[lind] = 1;
      extra.push_back(b[lind]);
    }
    for (int i = 0; i < n; i++) {
      if (!vis[i]) {
        extra.push_back(b[i]);
      }
    }
    if (!extra.empty()) {
      int spec = -1;
      sort(extra.begin(), extra.end());
      if (extra[0] > 1) {
        spec = 1;
      } else if (extra.back() < n + 1) {
        spec = n + 1;
      }
      if (spec == -1) {
        for (int i = 0; i + 1 < extra.size(); i++) {
          if (extra[i + 1] > extra[i] + 1) {
            spec = extra[i] + 1;
            break;
          }
        }
      }
      for (int i = 0; i < n; i++) {
        if (!vis[i]) {
          ans[i] = spec;
          vis[i] = 1;
        }
      }
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
      cout << ans[i] << ' ';
    }
    cout << '\n';
  }
  return 0;
}