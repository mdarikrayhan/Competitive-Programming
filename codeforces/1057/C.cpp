#include <bits/stdc++.h>

using namespace std;
#define all(v) v.begin(), v.end()
#define ll long long
#define en cout << endl;
#define dpp(arr, val) memset(arr, val, sizeof(arr))
#define int long long
#define f first
#define s second
#define sz(s) (int)(s).size()
#define forn for (int i = 0; i < n; i++)
#define fornn for (int i = n - 1; i >= 0; i--)

void Sh3lan() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}

int mod = 1e9 + 7;

int mul(int a, int b) { return ((a % mod) * (b % mod)) % mod; }

int add(int a, int b) { return ((a % mod) + (b % mod)) % mod; }

int sub(int a, int b) { return ((a % mod) - (b % mod) + mod) % mod; }

int GCD(int a, int b) { return b == 0 ? a : GCD(b, a % b); }

int LCM(int a, int b) { return a / GCD(a, b) * b; }

int fast(int a, int m) {
  if (m == 0) return 1;
  int x = fast(a, m / 2);
  x = mul(x, x);
  if (m & 1) x = mul(x, a);
  return x % mod;
}
int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};
const int N = 2e3 + 5;
int vis[N];
int dp[55][55][N];
int a[N];
int n, st, k;
int inf = 1e18;
vector<pair<int, int>> v;
string s;
int calc(int i, int last, int sum) {
  if (sum >= k) return 0;

  int &ret = dp[i][last][sum];
  if (~ret) return ret;
  ret = inf;
  if (i + 1 < n && s[i + 1] != s[last] && a[i + 1] > a[last])
    ret = min(ret, calc(i + 1, i + 1, sum + a[i + 1]) + 1);
  if (i - 1 >= 0 && s[i - 1] != s[last] && a[i - 1] > a[last])
    ret = min(ret, calc(i - 1, i - 1, sum + a[i - 1]) + 1);
  if (i + 1 < n) ret = min(ret, calc(i + 1, last, sum) + 1);
  if (i - 1 >= 0) ret = min(ret, calc(i - 1, last, sum) + 1);
  return ret;
}
void solve() {
  dpp(dp, -1);
  cin >> n >> st >> k;
  st--;
  for (int i = 0; i < n; i++) cin >> a[i];
  cin >> s;
  int ans = inf;
  for (int i = 0; i < n; i++) {
    ans = min(ans, calc(i, i, a[i]) + abs(st - i));
  }
  if (ans == inf)
    cout << -1 << endl;
  else
    cout << ans << endl;
}
signed main() {
  Sh3lan();
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}