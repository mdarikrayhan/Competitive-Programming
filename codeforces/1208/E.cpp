#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = l; i <= r; i++)
#define rep2(i, l, r) for(int i = l; i >= r; i--)
#define fi first
#define se second
#define bit(i, x) (x >> i & 1)
using namespace std;
const int N = 1e6 + 3;

int n, w;
int k, a[N];
long long b[N];
deque<pair<int, int>> q;

void update(int u, int v, int x) {
 if (u > v) return;
 if (v > w) return;
// cout << u << " " << v << " " << x << "\n";
 b[u] += x;
 b[v + 1] -= x;
}

void add(int x, int i) {
 while(!q.empty() && x > q.back().fi) q.pop_back();
 q.push_back({x, i});
}

void calc() {
 if (k != w) {
  int d = w - k;
  q.push_back({0, 0});
  rep(i, 1, k) {
   add(a[i], i);
   while(!q.empty() && i - q.front().se > d) q.pop_front();
   update(i, i, q.front().fi);
//   cout << q.front().fi << " ";
  }
  int p = k + 1;
  add(0, k + 1);
  while(!q.empty()) {
   update(p, q.front().se + d, q.front().fi);
   p = max(p, q.front().se + d + 1);
   q.pop_front();
  }
 }
 else {
  rep(i, 1, k) update(i, i, a[i]);
 }
}

int main()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);

 cin >> n >> w;
 rep(i, 1, n) {
  cin >> k;
  rep(j, 1, k) cin >> a[j];
  calc();
 }
 rep(i, 1, w) {
  b[i] += b[i - 1];
  cout << b[i] << " ";
 }



 return 0 ^ 0;
}
