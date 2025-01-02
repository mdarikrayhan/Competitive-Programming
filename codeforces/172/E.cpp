#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;

// loal is the cutest girl

#define ll long long
#define ld long double
#define pow2(x) (x)*(x)
#define le left
#define ri right
#define fi first
#define se second
#define pb push_back
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define pll pair<long long, long long>
#define isvowel(x) (x) == 'a' || (x) == 'i' || (x) == 'u' || (x) == 'e' || (x) == 'o'
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 

const ld EPS = 1e-9;
const ld PI = 3.141592653589793238462643383279502884197169399375105820974944;

vector<pair<string, vector<int>>> adj;
vector<int> roots;
vector<string> q;

int dfs(int idx, int loc) {
  int ret = 0;
  if (adj[idx].fi == q[loc]) {
    if (loc != q.size()-1) loc++;
    else ret++;
  }
  for (auto i : adj[idx].se) {
    ret += dfs(i, loc);
  }
  return ret;
}

signed main() {
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  
  string ins;
  cin >> ins;
  vector<int> st;
  for (int i = 0; i < ins.size(); i++) {
    int close = ins.find('>', i);
    if (ins[i+1] == '/') {
      st.pop_back();
    } else {
      if (ins[close-1] == '/') {
        adj.pb({ins.substr(i+1, close-i-2), {}});
        if (st.size() > 0)
          adj[st.back()].se.pb(adj.size()-1);
        else roots.pb(adj.size()-1);
      } else {
        adj.pb({ins.substr(i+1, close-i-1), {}});
        if (st.size() > 0)
          adj[st.back()].se.pb(adj.size()-1);
        else roots.pb(adj.size()-1);
        st.pb(adj.size()-1);
      }
    }
    i = close;
  }

  int n;
  cin >> n;
  
  string s;
  getline(cin, s);

  while (n--) {
    getline(cin, s);
		stringstream in(s);
    string str;
    q.clear();
    while (in >> str) {
      q.pb(str);
    }
    int res = 0;
    for (auto j : roots) res += dfs(j, 0);
    cout << res << '\n';
  }
  
  return 0;
}