#include <bits/stdc++.h>

using namespace std;
#define fr first
#define sc second
#define ll long long
const int B1 = 311, B2 = 131, M = 1e5 + 5;
const int MOD1 = 2e9 + 11, MOD2 = 1e9 + 7;
const int N = 3e2 + 2;
int p1[M], p2[M];
int n;
map<int, map<pair<int, int>, vector<pair<int, int>>>> mp[N];

vector<pair<int, int>> prefix;

void hash_prefix(const string &str) {
  ll h1 = 0, h2 = 0;
  if (prefix.size())
    tie(h1, h2) = prefix.back();
  for (char i: str) {
    h1 = (h1 * B1) % MOD1;
    h2 = (h2 + i) % MOD2;
    h1 = (h1 + i) % MOD1;
    h2 = (h2 * B2) % MOD2;
    prefix.emplace_back(h1, h2);
  }
}

pair<int, int> getPrefix(int l, int r) {
  auto ret = prefix[r];
  int sz = r - l + 1;
  l--;
  if (l >= 0) {
    ret.fr -= 1LL * prefix[l].fr * p1[sz] % MOD1;
    if (ret.fr < 0)ret.fr += MOD1;
    ret.sc -= 1LL * prefix[l].sc * p2[sz] % MOD2;
    if (ret.sc < 0)ret.sc += MOD2;
  }
  return ret;
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  p1[0] = p2[0] = 1;
  for (int i = 1; i < M; ++i) {
    p1[i] = 1LL * p1[i - 1] * B1 % MOD1;
    p2[i] = 1LL * p2[i - 1] * B2 % MOD2;
  }

  cin >> n;
  vector<pair<int, int>> range(n);
  int cur = 0;
  string s;

  for (int i = 0; i < n; ++i) {
    cin >> s;
    range[i] = {cur, cur + s.size() - 1};
    cur += s.size() + 1;
    hash_prefix(s);
    hash_prefix("@");
  }
  assert(prefix.size() == cur);
  --cur;

  for (int sz = 1; sz < n; ++sz) {
    for (int i = 0; i + sz <= n; ++i) {
      int l = range[i].first;
      int r = range[i + sz - 1].second;
      int x = (r - l - sz + 1);
      if (x)mp[sz][x][{getPrefix(l, r)}].emplace_back(l, r);
    }
  }

  auto solve = [](vector<pair<int, int>> &arr) -> int {
    sort(arr.begin(), arr.end(), [&](pair<int, int> &lf, pair<int, int> &rt) {
      return lf.second < rt.second;
    });
    int res = 1, cur = arr[0].second;
    for (auto &[l, r]: arr) {
      if (l > cur)++res, cur = r;
    }
    if (res == 1)return 0;
    return res;
  };

  int mx = 0;

  for (auto &list: mp)
    for (auto &[sz, same_size]: list) {
      for (auto &[hash_code, a]: same_size) {
        mx = max(solve(a) * sz, mx);
      }
    }
  cout << cur - mx;
}