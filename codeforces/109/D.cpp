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
int n, pos[100010];
struct Node {
  int val, id, r;
} arr[100010], a[100010];
ll ans = 0;
string str;
vector<pii> v;

bool cmp(Node x, Node y) { return x.val < y.val; }

void dbg() {
  for (int i = 1; i <= n; ++i) cerr << a[i].r << ' ';
  cerr << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) {
    cin >> n;
    bool b = true;
    int p = 0;
    for (int i = 1; i <= n; ++i) {
      cin >> arr[i].val;
      arr[i].id = i;
      a[i] = arr[i];
      if (i > 1)
        if (a[i].val < a[i - 1].val) b = false;
      if (!p) {
        int tmp = a[i].val;
        bool B = false;
        while (tmp > 0) {
          if (tmp % 10 != 4 && tmp % 10 != 7) {
            break;
          }
          tmp /= 10;
          if (tmp == 0) B = true;
        }
        if (B) p = i;
      }
    }
    if (b) {
      cout << 0 << endl;
      continue;
    }
    if (p == 0) {
      cout << -1 << endl;
      continue;
    }
    sort(arr + 1, arr + 1 + n, cmp);
    for (int i = 1; i <= n; ++i) {
      a[arr[i].id].r = i;
      pos[i] = arr[i].id;
    }
    // dbg();
    for (int i = 1; i <= n; ++i) {
      if (a[i].r == i) continue;
      if (i == p) {
        if (i != pos[i]) v.push_back({i, pos[i]});
        swap(a[i], a[pos[i]]);
        pos[a[i].r] = pos[i];
        p = pos[a[i].r];
        pos[i] = i;
      } else {
        if (i != p) v.push_back({i, p});
        pos[a[p].r] = i;
        pos[a[i].r] = p;
        swap(a[i], a[p]);
        // dbg();
        // cerr << i << ' ' << pos[i] << endl;
        if (i != pos[i]) v.push_back({i, pos[i]});
        swap(a[i], a[pos[i]]);
        pos[a[i].r] = pos[i];
        p = pos[a[i].r];
        pos[i] = i;
      }
      // dbg();
    }
    cout << v.size() << endl;
    for (auto i : v) cout << i.first << ' ' << i.second << endl;
  }
  return 0;
}