#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;
typedef long long ll;
 
int ans = 1e9;
ll a, b;
set<pair<int,int>> visited;
void rec(ll h, ll w, vector<ll>&arr, int i) {
  if (h > w) swap(w,h);
  if (h>=a && w >= b) {
    ans = min(ans, i);
    return;
  }
  if (i == arr.size()) return;
  if (visited.count({h,w})) return;
  visited.insert({h,w});
  rec(h*arr[i], w, arr, i+1);
  rec(h, w*arr[i], arr, i+1);
}
 
int main() {
  ll h, w, n;
  cin >> a >> b >> h >> w >> n;
  if (a > b) swap(a,b);
  vector<ll> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i];
  sort(arr.rbegin(), arr.rend());
  rec(h, w, arr, 0);
  cout << (ans == 1e9 ? -1 : ans) << endl;
}