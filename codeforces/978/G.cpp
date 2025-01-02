#include <bits/stdc++.h>
#define fastIO                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(nullptr)
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
#define ll long long
#define ld long double
#define pii pair<ll, ll>
#define mp make_pair
#define f first
#define s second
#define pb push_back
#define rep(i, a, b) for (int i = a; i < b; i++)
const ll INF = 1000000000000000000;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
string stepDir = "URDL";

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  os << '{';
  string sep;
  for (const auto &x : v) os << sep << x, sep = ", ";
  return os << '}';
}
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  return os << '(' << p.first << ", " << p.second << ')';
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}
#ifdef DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
#define MOD 1000000007

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template <class T>
using Tree =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using max_pq = priority_queue<T>;

int main() {
  fastIO;
  cout << fixed << setprecision(10);
  int n, m;
  cin >> n >> m;
  vector<ll> ans(n), S(m), C(m);
  vector<pii> b;
  bool failed = false;
  for (int i = 0; i < m; i++) {
    ll s, d, c;
    cin >> s >> d >> c;
    --s;
    --d;
    if (ans[d] != 0) failed = true;
    ans[d] = m + 1;
    b.pb({d, i});
    S[i] = s;
    C[i] = c;
  }
  if (failed) {
    cout << -1 << endl;
    return 0;
  }
  sort(b.begin(), b.end());
  dbg(b);
  dbg(ans, S, C);
  for (auto &[d, i] : b) {
    for (int j = S[i]; j < d; j++) {
      if (ans[j] == 0) {
        ans[j] = i + 1;
        C[i]--;
        if (C[i] == 0) break;
      }
    }
    if (C[i] != 0) {
      cout << -1 << endl;
      return 0;
    }
  }
  for (auto &x : ans) cout << x << ' ';
}
