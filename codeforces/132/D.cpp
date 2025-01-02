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
int n, arr[200010];
ll ans = 0;
string str;
bitset<1000010> s;
vector<pii> v, w;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) {
    cin >> s;
    int cnt = s.count(), p = 0;
    while (cnt) {
      if (s[p] == 1) cnt--;
      p++;
    }
    p--;
    cnt = 0;
    bool bit = 1;
    for (int i = p; i >= 0; --i) {
      if (s[i] == bit)
        cnt++;
      else {
        if (bit) {
          if (cnt > 1) {
            if (i == 0) {
              v.push_back({0, 1});
              break;
            } else if (s[i - 1] == 1) {
              cnt++;
              v.push_back({0, i});
              continue;
            }
            v.push_back({1, p + 1});
            v.push_back({0, i + 1});
          } else {
            v.push_back({1, p});
          }
        }
        cnt = 1;
        bit = !bit;
        p = i;
      }
    }
    if (bit) {
      // cerr << cnt << endl;
      if (cnt > 1) {
        v.push_back({1, p + 1});
        if (s[0]) v.push_back({0, 0});
      } else {
        v.push_back({1, p});
      }
    }
    cout << v.size() << endl;
    for (auto i : v) {
      if (i.first) {
        cout << "+2^" << i.second << endl;
      } else {
        cout << "-2^" << i.second << endl;
      }
    }
    /*if (s.count() < p - s.count() + s[0] + 1) {
      cout << s.count() << endl;
      for (int i : v[1]) cout << "+2^" << i << endl;
    } else {
      cout << p - s.count() + s[0] + 1 << endl;
      cout << "+2^" << p << endl;
      if (s[0]) cout << "-2^0" << endl;
      for (int i : v[0]) {
        if (i == v[0][0] && !s[0])
          cout << "-2^" << i + 1 << endl;
        else
          cout << "-2^" << i << endl;
      }
    }*/
  }
  return 0;
}