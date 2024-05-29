#include <bits/stdc++.h>
#define CNO cout << "NO\n"
#define CYES cout << "YES\n"
#define endl '\n'
#define PI 3.1415926535
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;
typedef __int128 i128;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
const int pos[5] = {1, 4, 2, 5, 3};
int n, arr[200010];
ll ans = 0;
ld x = 20.0 * cosl(36.0 * PI / 180.0);
ld X = x - (x - 10.0) / 2.0, Y = sqrtl(100.0 - powl((x - 10.0) / 2.0, 2));
string str;
pld pt[10010];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) {
    cin >> n;
    cout << 4 * n + 1 << endl;
    pt[0] = {0.0, 0.0};
    pt[1] = {x, 0.0};
    pt[2] = {(x - 10.0) / 2.0, sqrtl(100.0 - powl((x - 10.0) / 2.0, 2))};
    pt[3] = {x / 2.0, -10.0 * cosl(54.0 * PI / 180.0)};
    for (int i = 0; i <= 4 * n; ++i) {
      if (i > 3) pt[i] = {pt[i - 4].first + X, pt[i - 4].second + Y};
      cout << fixed << setprecision(10) << pt[i].first << ' ' << pt[i].second
           << endl;
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < 5; ++j) {
        cout << i * 4 + pos[j] << ' ';
      }
      cout << endl;
    }
    for (int i = 0; i <= 4 * n; ++i) {
      cout << i + 1 << ' ';
    }
    for (int i = 4 * (n - 1); i >= 0; i -= 4) {
      cout << i + 1 << ' ';
    }
  }
  return 0;
}
