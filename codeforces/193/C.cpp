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
const ll mod = 998244353;
ll n, var, a, b, c, arr[10];
ll ans = -1;
string str[4];
ll mat[10][10] = {0};
vector<int> v(10);

ll gauss() {
  ll mxr, col = 0;
  ll k;
  for (k = 0; k < var; ++k) {
    if (col >= n) break;
    mxr = k;
    for (int i = k + 1; i < var; ++i) {
      if (abs(mat[i][col]) > abs(mat[mxr][col])) mxr = i;
    }
    if (mat[mxr][col] == 0) {
      k--;
      col++;
      continue;
    }
    if (mxr != k) {
      for (int j = col; j <= n; ++j) {
        swap(mat[k][j], mat[mxr][j]);
      }
    }
    for (int i = k + 1; i < var; ++i) {
      if (mat[i][col]) {
        ll l = lcm(abs(mat[i][col]), abs(mat[k][col]));
        ll tmp1 = l / abs(mat[i][col]), tmp2 = l / abs(mat[k][col]);
        if (mat[i][col] * mat[k][col] < 0) tmp2 = -tmp2;
        for (int j = col; j <= n; ++j) {
          mat[i][j] = mat[i][j] * tmp1 - mat[k][j] * tmp2;
        }
      }
    }
    col++;
  }
  /*cerr << endl;
  for (int i = 0; i < var; ++i) {
    for (int j = 0; j <= n; ++j) {
      cerr << mat[i][j] << ' ';
    }
    cerr << endl;
  }*/

  for (int i = k; i < var; ++i) {
    if (mat[i][col] != 0) return -1;
  }
  for (int i = var - 1; i >= 0; --i) {
    ll tmp = mat[i][n];
    for (int j = i + 1; j < n; ++j) {
      if (mat[i][j]) {
        tmp -= mat[i][j] * v[j];
      }
    }
    v[i] = (ll)((long double)tmp / mat[i][i]);
  }
  return 0;
}

bool check() {
  bool b = true;
  if (v[3] + v[4] + v[5] + v[6] != arr[0]) b = false;
  if (v[1] + v[2] + v[5] + v[6] != arr[1]) b = false;
  if (v[0] + v[2] + v[4] + v[6] != arr[2]) b = false;
  if (v[1] + v[2] + v[3] + v[4] != arr[3]) b = false;
  if (v[0] + v[2] + v[3] + v[5] != arr[4]) b = false;
  if (v[0] + v[1] + v[4] + v[5] != arr[5]) b = false;
  return b;
}

void init() {
  for (int i = 0; i < 6; ++i) {
    switch (i) {
      case 0:
        mat[i][3] = 1, mat[i][4] = 1, mat[i][5] = 1, mat[i][6] = 1;
        break;
      case 1:
        mat[i][1] = 1, mat[i][2] = 1, mat[i][5] = 1, mat[i][6] = 1;
        break;
      case 2:
        mat[i][0] = 1, mat[i][2] = 1, mat[i][4] = 1, mat[i][6] = 1;
        break;
      case 3:
        mat[i][1] = 1, mat[i][2] = 1, mat[i][3] = 1, mat[i][4] = 1;
        break;
      case 4:
        mat[i][0] = 1, mat[i][2] = 1, mat[i][3] = 1, mat[i][5] = 1;
        break;
      case 5:
        mat[i][0] = 1, mat[i][1] = 1, mat[i][4] = 1, mat[i][5] = 1;
        break;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) {
    n = 7, var = 6;
    for (int i = 0; i < 6; ++i) {
      cin >> mat[i][n];
      arr[i] = mat[i][n];
    }
    init();
    for (int l = 0; l <= 100000; ++l) {
      ll tmp = 0;
      v[6] = l;
      memset(mat, 0, sizeof mat);
      for (int i = 0; i < 6; ++i) {
        mat[i][n] = arr[i];
      }
      init();
      gauss();
      for (int i = 0; i < 7; ++i) {
        // cerr << v[i] << ' ';
        if (v[i] < 0) {
          tmp = -1;
          break;
        } else {
          tmp += v[i];
        }
      }
      // if (tmp > 100000) continue;
      if (!check()) continue;
      if (tmp != -1) {
        if (tmp < ans || ans == -1) {
          for (int i = 0; i < 4; ++i) str[i] = "";
          for (int i = 0; i < 7; ++i) {
            for (int j = 0; j < v[i]; ++j) switch (i) {
                case 0:
                  str[0] += "a", str[1] += "a", str[2] += "a", str[3] += "b";
                  break;
                case 1:
                  str[0] += "a", str[1] += "a", str[2] += "b", str[3] += "a";
                  break;
                case 2:
                  str[0] += "a", str[1] += "a", str[2] += "b", str[3] += "b";
                  break;
                case 3:
                  str[0] += "a", str[1] += "b", str[2] += "a", str[3] += "a";
                  break;
                case 4:
                  str[0] += "a", str[1] += "b", str[2] += "a", str[3] += "b";
                  break;
                case 5:
                  str[0] += "a", str[1] += "b", str[2] += "b", str[3] += "a";
                  break;
                case 6:
                  str[0] += "a", str[1] += "b", str[2] += "b", str[3] += "b";
                  break;
              }
          }
        }
        ans = ans == -1 ? tmp : min(tmp, ans);
      }
    }
    cout << ans << endl;
    if (ans != -1) {
      for (int i = 0; i < 4; ++i) cout << str[i] << endl;
    }
  }
  return 0;
}