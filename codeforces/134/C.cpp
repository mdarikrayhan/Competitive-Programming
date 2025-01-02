#include <bits/stdc++.h>
#define CNO cout << "No\n"
#define CYES cout << "Yes\n"
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef __int128 i128;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int n, s;
ll ans = 0;
string str;
struct Node {
  int val, id;
  bool operator<(Node x) const { return val < x.val; }
} arr[200010];
vector<pii> v;
priority_queue<Node> q;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) {
    cin >> n >> s;
    // int sum = 0;
    for (int i = 1; i <= n; ++i) {
      cin >> arr[i].val;
      // sum += arr[i].val;
      arr[i].id = i;
      q.push(arr[i]);
    }
    if (s % 2) {
      CNO;
      continue;
    }
    while (!q.empty()) {
      Node u1 = q.top();
      if (u1.val >= q.size()) break;
      q.pop();
      vector<Node> tmp;
      while (u1.val) {
        Node u2 = q.top();
        q.pop();
        v.push_back({u1.id, u2.id});
        tmp.push_back({u2.val - 1, u2.id});
        u1.val--;
      }
      for (Node i : tmp) q.push(i);
    }
    if (v.size() != s / 2) {
      CNO;
      continue;
    } else
      CYES;
    cout << v.size() << endl;
    for (auto i : v) cout << i.first << ' ' << i.second << endl;
  }
  return 0;
}