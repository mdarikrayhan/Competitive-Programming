#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long int
#define pb push_back
#define pi pair<int, int>
#define pii pair<int, pi>
#define fir first
#define sec second
#define MAXN 300005
#define mod 998244353

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int q;
  cin >> q;
  while (q--)
  {
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    vector<int> cr(n, m);
    vector<int> cc(m, n);
    for (int i = 0; i < n; i++)
    {
      cin >> v[i];
      for (int j = 0; j < m; j++)
      {
        if (v[i][j] == '*')
        {
          cr[i]--;
          cc[j]--;
        }
      }
    }
    int ans = 1e18;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        int curr = cr[i] + cc[j];
        if (v[i][j] == '.')
          curr--;
        ans = min(ans, curr);
      }
    }
    cout << ans << endl;
  }
}