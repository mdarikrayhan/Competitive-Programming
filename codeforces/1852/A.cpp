#include <bits/stdc++.h>
#include <bitset>
#include <iostream>
#define lana_del_rey                    \
      ios_base::sync_with_stdio(false); \
      cin.tie(NULL)
#define ll long long int
#define clr(v, d) memset(v, d, sizeof(v))
#define deb(x) cout << #x << "=" << x << endl
#define comma(ans, n) setprecision(n) << fixed << ans << endl;
using namespace std;
const ll Mod = 1e9 + 7;
const ll N = 2002000;
void files()
{
      freopen("input.in", "r", stdin);
      freopen("output.out", "w", stdout);
}

bool check(ll x, vector<ll> &v, ll k)
{
      while (k--)
      {
            auto it = lower_bound(v.begin(), v.end(), x);

            x -= it - v.begin();

            if (x < 1)
                  return false;
      }

      return x == 1;
}
void solve()
{
      ll n, k;

      cin >> n >> k;

      vector<ll> v(n);

      for (int i = 0; i < n; i++)
      {
            cin >> v[i];
      }

      if (v[0] != 1)
      {
            cout << 1 << "\n";
            return;
      }

      ll l = 1, r = 1e14;

      while (l <= r)
      {

            ll mid = (l + r) / 2;

            if (check(mid, v, k))
            {
                  l = mid + 1;
            }
            else
                  r = mid - 1;
      }

      cout << l - 1 << "\n";
}

int main()
{
      lana_del_rey;
      int t = 1;
      cin >> t;
      while (t--)
      {
            solve();
      }

      return 0;
}