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
int n, m, a, b, c, arr[200010];
ll ans = 0;
string str = "IMPOSSIBLE";
char ch[110][110];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) {
    cin >> n >> m >> a >> b >> c;
    if ((n * m) % 2) {
      cout << str << endl;
      continue;
    }
    if (n % 2) {
      a -= m / 2;
      if (a < 0) {
        cout << str << endl;
        continue;
      }
      for (int i = 1; i <= m; i += 2) {
        ch[n][i] = 'y' + (i / 2) % 2;
        ch[n][i + 1] = 'y' + (i / 2) % 2;
      }
    } else if (m % 2) {
      b -= n / 2;
      if (b < 0) {
        cout << str << endl;
        continue;
      }
      for (int i = 1; i <= n; i += 2) {
        ch[i][m] = 'y' + (i / 2) % 2;
        ch[i + 1][m] = 'y' + (i / 2) % 2;
      }
    }
    for (int i = 1; i < n; i += 2) {
      for (int j = 1; j < m; j += 2) {
        if (c > 0) {
          ch[i][j] = 'a' + (i / 2 + j / 2) % 2;
          ch[i][j + 1] = 'a' + (i / 2 + j / 2) % 2;
          ch[i + 1][j] = 'a' + (i / 2 + j / 2) % 2;
          ch[i + 1][j + 1] = 'a' + (i / 2 + j / 2) % 2;
          c -= 1;
        } else if (a > 1) {
          ch[i][j] = 'c' + (i / 2 + j / 2) % 2;
          ch[i][j + 1] = 'c' + (i / 2 + j / 2) % 2;
          ch[i + 1][j] = 'e' + (i / 2 + j / 2) % 2;
          ch[i + 1][j + 1] = 'e' + (i / 2 + j / 2) % 2;
          a -= 2;
        } else if (b > 1) {
          ch[i][j] = 'h' + (i / 2 + j / 2) % 2;
          ch[i][j + 1] = 'j' + (i / 2 + j / 2) % 2;
          ch[i + 1][j] = 'h' + (i / 2 + j / 2) % 2;
          ch[i + 1][j + 1] = 'j' + (i / 2 + j / 2) % 2;
          b -= 2;
        } else {
          cout << str << endl;
          return 0;
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cout << ch[i][j];
      }
      cout << endl;
    }
  }
  return 0;
}