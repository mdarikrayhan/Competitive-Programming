#include <bits/stdc++.h>
#define CNO cout << "NO\n"
#define CYES cout << "YES\n"
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef __int128 i128;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int n, k, arr[30010], d;
bool vis[30010];
ll ans = 0;
string str;
vector<int> v1, v2;

bool solve(int l, int r) {
  v1.clear(), v2.clear();
  memset(vis, 0, sizeof vis);
  d = arr[r] - arr[l];
  int p = r;
  vis[l] = 1, vis[r] = 1;
  v1.push_back(arr[l]);
  v1.push_back(arr[r]);
  for (int i = r + 1; i <= n; ++i) {
    if (arr[i] - arr[p] == d) {
      v1.push_back(arr[i]);
      vis[i] = 1;
      p = i;
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (vis[i]) continue;
    v2.push_back(arr[i]);
  }
  /*for (int i : v1) cerr << i << ' ';
  cerr << endl;
  for (int i : v2) cerr << i << ' ';
  cerr << endl;*/
  if (v2.size() <= 2) {
    if (v2.empty()) v2.push_back(v1.back()), v1.pop_back();
    if (v2.size() == 2) d = v2[1] - v2[0];
    return true;
  } else {
    bool b = true;
    if (1ll * (v2[2] - v2[1]) * (v2[1] - v2[0]) < 0) return false;
    if (v2[2] - v2[1] > 0)
      d = min(v2[2] - v2[1], v2[1] - v2[0]);
    else
      d = max(v2[2] - v2[1], v2[1] - v2[0]);
    for (int i = 1; i < v2.size(); ++i) {
      if (v2[i] - v2[i - 1] != d) b = false;
      if (i == v2.size() - 1 && b) {
        return true;
      } else {
        for (int i = v2.size() - 1; i > 0; --i) {
          // cerr << i << endl;
          if (v2[i] - v2[i - 1] == d) continue;
          if (abs(v2[i] - v2[i - 1]) % abs(d) != 0)
            return false;
          else {
            for (int j = 1; j < (v2[i] - v2[i - 1]) / d; ++j) {
              // cerr << j << v2[i] << v1.back() << endl;
              if (v1.size() < 2) return false;
              if (v2[i] - v1.back() == j * d) {
                v1.pop_back();
              } else
                return false;
            }
            // cerr << '!' << endl;
          }
        }
        return true;
      }
    }
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) {
    ans = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      cin >> arr[i];
    }
    if (n <= 4) {
      for (int i = 1; i <= n / 2; ++i) {
        cout << arr[i] << ' ';
      }
      cout << endl;
      for (int i = n / 2 + 1; i <= n; ++i) {
        cout << arr[i] << ' ';
      }
      cout << endl;
      continue;
    }
    if (solve(1, 2)) {
      for (int i : v1) cout << i << ' ';
      cout << endl;
      for (int i = v2[0]; i != v2[v2.size() - 1]; i += d) cout << i << ' ';
      cout << v2[v2.size() - 1] << endl;
    } else if (solve(1, 3)) {
      for (int i : v1) cout << i << ' ';
      cout << endl;
      for (int i = v2[0]; i != v2[v2.size() - 1]; i += d) cout << i << ' ';
      cout << v2[v2.size() - 1] << endl;
    } else if (solve(2, 3)) {
      for (int i : v1) cout << i << ' ';
      cout << endl;
      for (int i = v2[0]; i != v2[v2.size() - 1]; i += d) cout << i << ' ';
      cout << v2[v2.size() - 1] << endl;
    } else
      cout << "No solution" << endl;
  }
}