#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long
#define ld long double
using namespace std;
using namespace __gnu_pbds;
typedef pair<int, int> node;
typedef tree<node, null_type, less<node>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int N = 5e5 + 5;
const ll MOD = 1e9 + 7, MAX = 1e18;
const double ep = 1e-6, pi = atan(1.0) * 4;
long long inv(long long a, long long b = MOD)
{
  return 1 < a ? b - inv(b % a, a) * b / a : 1;
}
int dx[8] = {1, 0, -1, 0, -1, 1, -1, 1};
int dy[8] = {0, 1, 0, -1, -1, 1, 1, -1};
ll n, m = 0, k;
void fastio()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int comp(ld x, ld y)
{
  // return 1 if x<=y
  if (abs(x - y) <= 1e-9)
    return 1;
  if (x < y)
    return 1;
  return 0;
}
ll fact[N];
ll pw2[N];
void precalc()
{
  fact[0] = 1;
  pw2[0] = 1;
  for (int i = 1; i < N; i++)
  {
    fact[i] = fact[i - 1] * i % MOD;
    pw2[i] = pw2[i - 1] * 2 % MOD;
  }
}
ll arr[N];
void fn()
{
  cin >> n >> m;
  ll ans = fact[n - m];
  for (int i = 1; i <= m; i++)
  {
    cin >> arr[i];
  }
  sort(arr + 1, arr + 1 + m);
  arr[0] = 0;
  arr[m + 1] = n + 1;
  // cout << ans << '\n';
  for (int i = 1; i <= m + 1; i++)
  {
    // cout << arr[i] - arr[i - 1] - 1 << '\n';
    ans *= inv(fact[arr[i] - arr[i - 1] - 1]);
    ans %= MOD;
    if (i != m + 1 && i != 1 && arr[i] - arr[i - 1] - 1 > 0)
    {
      ans *= pw2[arr[i] - arr[i - 1] - 2];
      ans %= MOD;
    }
  }
  cout << ans << '\n';
}
int main()
{
  precalc();
  fastio();
  int t = 1;
  // cin>>t;
  while (t--)
    fn();
  return 0;
}