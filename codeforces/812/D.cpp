#include <iostream>
#include <vector> 
#include <algorithm> 
#include <string> 
#include <cassert> 
#include <algorithm> 
#include <set> 
#include <iomanip> 
#include <queue> 
#include <deque> 
#include <unordered_set> 
#include <unordered_map> 
#include <functional> 
#include <cmath> 
#include <map> 
#include <random> 
#include <chrono> 

bool home = true;

using namespace std;
typedef long long ll;

const int N = (int)1e5 + 7;
int n, m, k, q, last[N], wait[N], tin[N], tout[N], down_under[N], tt = 0;
vector<int> g[N];

void dfs(int a) {
  tin[a] = tout[a] = ++tt;
  down_under[a] = 1;

  for (auto& b : g[a]) {
    dfs(b);
    down_under[a] += down_under[b];
    tout[a] = ++tt;
  }
}

bool is_ancestor(int a, int ancestor) {

  return tin[ancestor] <= tin[a] && tout[a] <= tout[ancestor];
}

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    FILE* stream;
    freopen_s(&stream, "iron_man.txt", "r", stdin);
  }
  else {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  cin >> n >> m >> k >> q;

  for (int i = 1; i <= k; i++) {
    int a, toy;
    cin >> a >> toy;
    if (last[toy]) {
      assert(!wait[a]);
      wait[a] = last[toy];
    }
    last[toy] = a;
  }


  for (int i = 1; i <= n; i++) {
    g[wait[i]].push_back(i);
  }

  dfs(0);

  while (q--) {
    int a, toy;
    cin >> a >> toy;
    if (int b = last[toy]) {

      if (is_ancestor(b, a)) {
        cout << down_under[a] << "\n";
        continue;
      }
    }
    cout << "0\n";

  }

}