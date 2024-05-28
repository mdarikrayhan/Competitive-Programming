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
int n, arr[200010], h[200010] = {0};
ll ans = 0;
string str;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) {
    bool b = true;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
    }
    sort(arr, arr + n);
    int cnt = 0;
    h[0] = 1;
    for (int i = 1; i < n; ++i) {
      if (arr[i] == arr[i - 1]) {
        h[cnt]++;
      } else if (arr[i] == arr[i - 1] + 1) {
        cnt++;
        h[cnt]++;
      } else {
        b = false;
        break;
      }
    }
    h[0]--, h[cnt]--;
    for (int i = 1; i < cnt; ++i) {
      h[i] -= 2;
      if (h[i] < 0) b = false;
    }
    for (int i = 1; i <= cnt; ++i) {
      if (h[i] < h[i - 1]) {
        b = false;
        break;
      } else {
        h[i] -= h[i - 1];
        h[i - 1] = 0;
        if (!h[i]) {
          i++;
        }
      }
    }
    if (h[cnt]) b = false;
    if (b)
      CYES;
    else
      CNO;
  }
  return 0;
}