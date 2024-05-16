//#pragma comment(linker, "/STACK:100000000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2")
// If you only do what you can do, you’ll never be more than you are now
#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
#define cin(v)         \
  for (auto& el : v) { \
    cin >> el;         \
  }
#define cout(v)        \
  for (auto& el : v) { \
    cout << el << " "; \
  }                    \
  cout << "\n";

using namespace std;
using ll = long long;
using ldb = long double;
using db = double;
const ll LINF = 1e15 + 1;
const double EPS = 1e-9;
const ll MOD = 1e9 + 7;
const ll MOD2 = 1072005019;

void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> vec;
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    vec.push_back({l, r});
  }
  int k;
  cin >> k;
  for (int i = 0; i < n; i++) {
    if (vec[i].second >= k) {
      cout << n - i << endl;
      return;
    }
  }
  cout << 0 << endl;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  solve();
  return 0;
}