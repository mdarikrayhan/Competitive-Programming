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

umap<int, pairii> db;
string ar[30];
void setup() {
  int n = 30;
  int sz[n];
  for (int i = 0; i < n; i++) {
    ar[i] = "O";
    int y = (i * (i + 1)) >> 1;
    for (int j = 0; j <= y; j++) {
      ar[i] += 'X';
    }
    for (int j = 0; j <= y; j++) {
      ar[i] += 'O';
    }
    sz[i] = y + 1;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int x = 0;
      int s = sz[i], t = sz[j];
      int m = max(s, t);
      x += m * m + (m << 2);
      x += (s + s + 1) * (t + t);
      x += (s < t ? s + 1 : s > t ? t : 0);
      x += (s >= t ? s + 2 : 0);
      db[x] = {i, j};
    }
  }
}

void solveMain() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cout << ar[i] << endl;
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
  setup();
  while (t--) {
    solveMain();
  }
#ifndef ONLINE_JUDGE
  printf("Time taken: %.3fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
#endif
  return 0;
}
