#include <bits/stdc++.h>
using namespace std;
#ifdef SERT
#include "kek.h"
#endif
 
constexpr int getId(char ch) { return ch - 'A'; }
constexpr char getCh(int id) { return char('A' + id); }
 
constexpr int INF = 100500;
constexpr int UNUSED = getId('_');
#ifdef SERT
constexpr int M = 26;
constexpr char REP = '_';
#else
constexpr int M = 26;
constexpr char REP = 'S';
#endif
 
int getMin(const array<int, 3> &arr) {
  return *min_element(arr.begin(), arr.end());
}
 
void dec(array<int, 3> &arr, int val = 1) {
  for (int &x : arr) x -= val;
}
 
void forEachLetter(const std::function<void(int)> &callback) {
  for (int i = 0; i < M; i++) {
    callback(i);
  }
}
 
void updAns(vector<pair<int, int>> &ans, vector<array<int, 3>> cnt, int numAllEqual, int curMxSize) {
  vector<pair<int, int>> cur;
  cur.reserve(curMxSize);
  forEachLetter([&](int c) {
    if (numAllEqual && getMin(cnt[c]) == 1) {
      dec(cnt[c]);
      cur.emplace_back(c, UNUSED);
      numAllEqual--;
    }
  });
  forEachLetter([&](int c) {
    if (numAllEqual && getMin(cnt[c]) % 2) {
      dec(cnt[c]);
      cur.emplace_back(c, UNUSED);
      numAllEqual--;
    }
  });
  forEachLetter([&](int c) {
    int num = min(numAllEqual, getMin(cnt[c]));
    numAllEqual -= num;
    dec(cnt[c], num);
    while (num--) cur.emplace_back(c, UNUSED);
  });
  int freeNum = 0;
  vector<int> qq;
 
  /*forEachLetter([&](int c) {
    int num = getMin(cnt[c]);
    for (int i = 0; i + 2 < num; i += 2) {
      qq.push_back(c);
      qq.push_back(c);
      qq.push_back(c);
      freeNum += 3;
      dec(cnt[c], 2);
    }
  });*/
 
  array<vector<int>, 3> uniq;
  forEachLetter([&](int c) {
    int mx = 0, sum = 0;
    for (int i = 0; i < 3; i++) {
      sum += cnt[c][i];
      if (cnt[c][i] > cnt[c][mx]) mx = i;
    }
    int num = max(0, cnt[c][mx] - cnt[c][(mx + 1) % 3] - cnt[c][(mx + 2) % 3]);
    while (num--) {
      uniq[mx].push_back(c);
      cnt[c][mx]--;
    }
    if (accumulate(cnt[c].begin(), cnt[c].end(), 0) % 2) {
      uniq[mx].push_back(c);
      cnt[c][mx]--;
    }
  });
 
  auto getUniq = [&](int i) {
    if (uniq[i].empty()) return UNUSED;
    int res = uniq[i].back();
    uniq[i].pop_back();
    return res;
  };
 
  array<vector<int>, 3> fix;
 
  for (int i = 0; i < 3; i++) {
    int p1 = (i + 1) % 3;
    int p2 = (i + 2) % 3;
    forEachLetter([&](int c) {
      int num = max(0, accumulate(cnt[c].begin(), cnt[c].end(), 0) / 2 - cnt[c][i]);
      if (num == 0) return;
      cnt[c][p1] -= num;
      cnt[c][p2] -= num;
      //cout << getCh(c) << " " << p1 << " " << p2 << " " << num << "\n";
      while (num--) {
        int x = getUniq(i);
        if (x == UNUSED) {
          fix[i].push_back(c);
        } else {
          cur.emplace_back(c, x);
        }
      }
    });
  }
 
  for (int i = 0; i < 3; i++) {
    for (int j = i; j < freeNum; j += 3) {
      int x = getUniq(i);
      if (x == UNUSED) {
        fix[i].push_back(qq[j]);
      } else {
        cur.emplace_back(qq[j], x);
      }
    }
  }
 
  while (!fix[0].empty() && !fix[1].empty() && !fix[2].empty()) {
    int a = fix[0].back();
    int b = fix[1].back();
    int c = fix[2].back();
    for (int i = 0; i < 3; i++) fix[i].pop_back();
    cur.emplace_back(a, b);
    cur.emplace_back(a, c);
  }
 
  for (int i = 0; i < 3; i++) {
    for (int x : fix[i]) {
      cur.emplace_back(x, UNUSED);
    }
  }
 
  while (true) {
    int p1 = 0, p2 = 1;
    if (uniq[p1].size() < uniq[p2].size()) swap(p1, p2);
    if (uniq[2].size() > uniq[p2].size()) p2 = 2;
    if (uniq[p1].size() < uniq[p2].size()) swap(p1, p2);
    if (uniq[p1].empty()) break;
    if (p2 == 0) swap(p1, p2);
    cur.emplace_back(getUniq(p1), getUniq(p2));
  }
 
  forEachLetter([&](int c) {
    for (int i = 0; i < 3; i++) {
      if (cnt[c][i]) {
        cout << "Fail " << getCh(c) << " " << i << " not empty\n";
        exit(11);
      }
    }
  });
 
  if (cur.size() < ans.size()) {
    ans = cur;
  }
}
 
vector<pair<char, char>> solve(string a = "", string b = "", string c = "", bool test = false) {
  array<string *, 3> v{&a, &b, &c};
  vector<array<int, 3>> cnt(M);
  int it = 0;
  for (auto *s : v) {
    if (s->empty()) {
      cin >> *s;
    }
    sort(s->begin(), s->end());
    for (char ch : *s) {
      cnt[getId(ch)][it]++;
    }
    it++;
  }
  vector<pair<int, int>> ans(INF);
  int curMxSize = static_cast<int>(max({a.length(), b.length(), c.length()})) + 5;
 
  /*auto totEqual = accumulate(cnt.begin(), cnt.end(), 0,
                             [](int sum, const array<int, 3> &arr) { return sum + getMin(arr); });
  for (int numAllEqual = 0; numAllEqual <= totEqual; numAllEqual++) {
    updAns(ans, cnt, numAllEqual, curMxSize);
  }*/
 
  updAns(ans, cnt, 0, curMxSize);
 
  vector<pair<char, char>> ret;
  if (!test) cout << ans.size() << "\n";
  for (const auto &[x, y] : ans) {
    if (test) ret.emplace_back((x == UNUSED ? REP : getCh(x)), (y == UNUSED ? REP : getCh(y)));
    else cout << (x == UNUSED ? REP : getCh(x)) << (y == UNUSED ? REP : getCh(y)) << "\n";
  }
  return ret;
}
 
#ifdef SERT
 
void go(const string &a, const string &b, const string &c, int it) {
  auto res = solve(a, b, c, true);
  if (res.size() == max({a.length(), b.length(), c.length()})) return;
  long uniq = 0;
  for (char ch = 'A'; ch <= 'Z'; ch++) {
    uniq += max({count(a.begin(), a.end(), ch), count(b.begin(), b.end(), ch), count(c.begin(), c.end(), ch)});
  }
  if (static_cast<long>(res.size()) == (uniq + 1) / 2) return;
  int check = stress(a, b, c);
  if (static_cast<int>(res.size()) != check) {
    cout << "it = " << it << ", Stress = " << check << ", Solve = " << res.size() << "\n";
    cout << "a: " << a << "\n";
    cout << "b: " << b << "\n";
    cout << "c: " << c << "\n";
    for (auto &[x, y] : res) {
      cout << x << y << "\n";
    }
    exit(2);
  }
}
 
void test2() {
  int E = 4;
  int L = 15;
  int mx = 1;
  for (int i = 0; i < L; i++) mx *= E;
  set<string> u;
  for (int msk = 0; msk < mx; msk++) {
    if (msk % max(1, mx / 20) == 0) {
      cout << "Finished " << msk / max(1, mx / 20) * 5 << "%" << endl;
    }
    string a, b, c, s;
    int kk = msk;
    for (int i = 0; i < L; i++) {
      s.push_back(char('A' + kk % E));
      kk /= E;
    }
    int l1 = (L + 2) / 3;
    int l2 = (L - l1 + 1) / 2;
    a = s.substr(0, l1);
    b = s.substr(l1, l2);
    c = s.substr(l1 + l2);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
 
    if (a == b || b == c || a == c) continue;
 
    string xx = a;
    xx.append("_").append(b).append("_").append(c);
    if (u.count(xx)) continue;
    u.insert(xx);
 
    vector<int> cnt(E, 0);
    for (int i = 0; i < E; i++) cnt[i] = static_cast<int>(count(a.begin(), a.end(), char('A' + i)));
    if (!is_sorted(cnt.begin(), cnt.end())) continue;
 
    go(a, b, c, msk);
  }
  cout << "Completed in " << static_cast<double>(clock()) / CLOCKS_PER_SEC << " sec\n";
}
 
void test() {
  string a, b, c;
  int it = 0;
  while (static_cast<double>(clock()) / 13.4 < CLOCKS_PER_SEC) {
    it++;
    gen(a, b, c, it);
    go(a, b, c, it);
  }
  cout << "All " << it << " iterations are ok in " << static_cast<double>(clock()) / CLOCKS_PER_SEC << " sec!\n";
}
#endif
 
int main() {
  cout.precision(3);
  cout << fixed;
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#ifdef SERT
  freopen("../a.in", "r", stdin);
  //solve();
  test();
  //cout << solve("ACCCD", "ABCCC", "BCCC", true).size() << "\n";
  //cout << stress("CD", "AB", "C");
//  solve();
//  solve();
//  solve();
//  solve();
#else
  solve();
#endif
}
 