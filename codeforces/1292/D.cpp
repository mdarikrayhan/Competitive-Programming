#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr i64 inf = (i64) 1e12;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  const int mx = 5001;
  vector<int> lp(mx);
  iota(lp.begin(), lp.end(), 0);
  for (int i = 2; i < mx; i++) {
    if (lp[i] != i) {
      continue;
    }
    for (int j = 2 * i; j < mx; j += i) {
      if (lp[j] == j) {
        lp[j] = i;
      }
    }
  }
  int n;
  cin >> n;
  vector<int> k(n);
  for (int i = 0; i < n; i++) {
    cin >> k[i];
    if (k[i] == 0) {
      k[i] = 1;
    }
  }
  vector<int> fk(mx);
  for (int i = 0; i < n; i++) {
    ++fk[k[i]];
  }
  vector<pair<int, int>> ind;
  for (int i = 0; i < mx; i++) {
    if (fk[i]) {
      ind.emplace_back(i, fk[i]);
    }
  }
  int sz = ind.size();
  vector<vector<int>> dat(sz, vector<int>(mx));
  for (int i = 0; i < sz; i++) {
    int cur = ind[i].first;
    for (int j = 2; j <= cur; j++) {
      int nj = j;
      while (nj != 1) {
        ++dat[i][lp[nj]];
        nj /= lp[nj];
      }
    }
    reverse(dat[i].begin(), dat[i].end());
    for (int j = 1; j < mx; j++) {
      if (dat[i][j] != 0) {
      }
      dat[i][j] += dat[i][j - 1];
    }
    cout << endl;
  }
  vector<int> del(sz);
  for (int i = 0; i + 1 < sz; i++) {
    for (int j = 0; j < mx; j++) {
      if (dat[i][j] != dat[i + 1][j]) {
        assert(dat[i + 1][j] > dat[i][j]);
        del[i] = dat[i][j];
        break;
      }
    }
  }
  i64 base = 0;
  i64 ans = 0;
  for (int i = 0; i < sz; i++) {
    int lim = dat[i].back() + 1;
    base += (i64) dat[i].back() * ind[i].second;
    vector<int> dp(lim);
    dp[dat[i].back()] += ind[i].second;
    int sofar = dat[i].back();
    for (int j = i + 1; j < sz; j++) {
      int com = del[j - 1];
      sofar = min(sofar, com);
      dp[sofar] += ind[j].second;
    }
    sofar = dat[i].back();
    for (int j = i - 1; j >= 0; j--) {
      int com = del[j];
      sofar = min(sofar, com);
      dp[sofar] += ind[j].second;
    }
    i64 lft_sum = 0;
    i64 lft_cnt = 0;
    for (int j = 0; j < lim; j++) {
      lft_sum += (i64) dp[j] * j;
      lft_cnt += dp[j];
      i64 r_cnt = n - lft_cnt;
      ans = min(ans, (i64) n * j - lft_sum * 2 - r_cnt * j * 2);
    }
  }
  cout << ans + base << '\n';
  return 0;
}