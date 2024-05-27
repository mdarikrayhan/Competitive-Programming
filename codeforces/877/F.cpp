#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6+5, block = 1000;

int n, k, t[N], a[N], q, ans[N], B[N], C[N], D[N];
vector<int> rar;

struct query {
  int l, r, id;
  bool operator<(const query &o) const {
    if (l / block != o.l / block)
      return l/block < o.l/block;
    if (l / block & 1)  return r < o.r;
    else  return r > o.r;
  }
} qu[N];

void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> t[i];
  int c = 0, d = 0;
  rar.emplace_back(-k); 
  rar.emplace_back(k); 
  rar.emplace_back(0);
  for (int i = 1; i <= n; ++i) {
    int x; cin >> x;
    if (t[i] == 1) c += x;
    else d += x;
    a[i] = c - d;
    rar.emplace_back(a[i]-k); 
    rar.emplace_back(a[i]+k);
    rar.emplace_back(a[i]);
  }
  
  sort(rar.begin(), rar.end());
  rar.resize(unique(rar.begin(), rar.end()) - rar.begin());
  
  auto zip = [&](int num) -> int {
    return upper_bound(rar.begin(), rar.end(), num) - rar.begin();
  };
  
  B[0] = zip(-k); C[0] = zip(k);
  for (int i = 1; i <= n; ++i) {
    B[i] = zip(a[i]-k);
    C[i] = zip(a[i]+k);
    D[i] = zip(a[i]);
  }
  
  cin >> q;
  for (int i = 1; i <= q; ++i) {
    cin >> qu[i].l >> qu[i].r;
    qu[i].id = i;
  }
  
  vector<int> cnt(4*n, 0);
  int cur_ans = 0;
  
  auto add = [&](int p, bool dir) -> void {
    if (p < 1 || p > n) return;
    // dir = 1 -> add right
    // dir = 0 -> add left
    if (dir) {
      cur_ans += cnt[B[p]];
      cnt[D[p]]++;
    } else {
      cur_ans += cnt[C[p]];
      cnt[D[p]]++;
    }
  };
  
  auto dec = [&](int p, bool dir) -> void {
    if (p < 1 || p > n) return;
    // dir = 1 -> dec right
    // dir = 0 -> dec left
    if (dir) {
      cnt[D[p]]--; // can I swap this line?
      cur_ans -= cnt[B[p]];
    } else {
      cnt[D[p]]--;
      cur_ans -= cnt[C[p]];
    }
  };
  
  sort(qu+1, qu+q+1);
  int l = 0, r = 0;
  for (int i = 1; i <= q; ++i) {
    while (r < qu[i].r) add(++r, 1);
    while (l > qu[i].l) add(--l, 0);
    while (r > qu[i].r) dec(r--, 1);
    while (l < qu[i].l) dec(l++, 0);
    ans[qu[i].id] = cur_ans + cnt[C[l-1]];
  }
  for (int i = 1; i <= q; ++i)
    cout << ans[i] << ' ';
}

signed main() {
  cin.tie(0) -> sync_with_stdio(0);
  int tc = 1; // cin >> tc;
  while(tc--) solve();
}