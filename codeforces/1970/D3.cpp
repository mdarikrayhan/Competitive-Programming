#ifdef ONLINE_JUDGE
#include <bits/stdc++.h>
#else
#include "./stdc++.h"
#endif
#define fastio                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(nullptr)
#define i64 long long
#define ld long double
#define F first
#define S second
#define MOD 998244353
#define pairii pair<int, int>
#define pb push_back
#ifdef ONLINE_JUDGE
// #define endl '\n'
#endif
#define matrix(type) vector<vector<type>>
#define vi vector<int>
#define vi64 vector<i64>
#define uset unordered_set
#define umap unordered_map
#define mpr make_pair
#define ALL(x) x.begin(), x.end()
#define RALL(data) data.rbegin(), data.rend()
#define TYPEMAX(type) std::numeric_limits<type>::max()
#define TYPEMIN(type) std::numeric_limits<type>::min()
#define null nullptr
#define fr(i, a, b) for (int i = a; i < b; i++)
using namespace std;

#ifdef ONLINE_JUDGE
class NullBuffer : public std::streambuf {
public:
  int overflow(int c) { return c; }
};
ostream logger(new NullBuffer());
#else
ostream &logger = cout;
#endif

int calc(string &s) {
  uset<string> st;
  for (int i = 0; i < s.size(); i++) {
    string t;
    for (int j = i; j < s.size(); j++) {
      t += s[j];
      st.insert(t);
    }
  }
  return st.size();
}

string str(int a) {
  string s = "XO";
  for (int i = 0; i < a; i++) {
    s += 'X';
  }
  return s;
}

i64 calc(int s, int t) {
  i64 x = 0;
  int m = max(s, t);
  x += (m ? m * 3 : 1) + 2;
  x += (s + 2) * (t + 1) + (s >= t ? (2 + (s != 0)) : 0);
  return x;
}

int sz[1000];
umap<i64, pairii> db;
void setup(int n) {
  int mx = 0;
  for (int i = 0; i < n; i++) {
    for (int j = (i ? sz[i - 1] + 1 : 0);; j++) {
      int cj = calc(j, j);
      bool ok = !db.count(cj);
      uset<int> sj;
      sj.insert(cj);
      for (int k = 0; k < i and ok; k++) {
        int d1 = calc(j, sz[k]), d2 = calc(sz[k], j);
        if (d1 == d2 or db.count(d1) or db.count(d2) or sj.count(d1) or
            sj.count(d2)) {
          ok = 0;
        } else {
          sj.insert(d1);
          sj.insert(d2);
        }
      }
      if (!ok) {
        continue;
      }
      sz[i] = j;
      db[cj] = {i, i};
      for (int k = 0; k < i and ok; k++) {
        db[calc(sz[i], sz[k])] = {i, k};
        db[calc(sz[k], sz[i])] = {k, i};
      }
      break;
    }
  }
  // for (int i = 0; i < n; i++) {
  //   mx = max(mx, 2 + sz[i]);
  // }
  // logger << "Result: " << n * n << " == " << db.size() << endl;
  // logger << "Max: " << mx << endl;
}

void solveMain() {
  int n;
  cin >> n;
  setup(n);
  for (int i = 0; i < n; i++) {
    cout << "OX";
    for (int j = 0; j < sz[i]; j++) {
      cout << 'O';
    }
    cout << endl;
  }
  int q;
  cin >> q;
  while (q--) {
    int p;
    cin >> p;
    pairii &ans = db[p];
    cout << ans.F + 1 << " " << ans.S + 1 << endl;
  }
}

int main() {
#ifndef ONLINE_JUDGE
  clock_t tStart = clock();
#endif
  fastio;
  int t = 1;
  // cin >> t;
  while (t--) {
    solveMain();
  }
#ifndef ONLINE_JUDGE
  printf("Time taken: %.3fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
#endif
  return 0;
}
