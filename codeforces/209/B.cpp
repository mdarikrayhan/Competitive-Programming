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
ll n, a, b, c;
ll ans = 1e18;
string str;

void is_even(ll a, ll b) {
  if ((a + b) % 2 == 0) ans = min(ans, max(a, b));
}

/*ll euclid(ll a, ll b) {
  if (a < b) swap(a, b);
  if (b == 0) return 0;
  if (a % b == 0) return a;
  return b + euclid(b, a % b);
}*/

ll calc(ll a, ll b, ll c) {
  return min(a, b) + max(max(a, b) - min(a, b), c + min(a, b));
  // return min(a, b) + euclid(max(a, b) - min(a, b), c + min(a, b));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) {
    cin >> a >> b >> c;
    is_even(a, b), is_even(a, c), is_even(b, c);
    ll ans1 = calc(a, b, c), ans2 = calc(a, c, b), ans3 = calc(b, c, a);
    // cerr << ans1 << ", " << ans2 << ", " << ans3 << ", " << endl;
    ans = min(min(ans, ans1), min(ans2, ans3));
    cout << ans << endl;
  }
  return 0;
}