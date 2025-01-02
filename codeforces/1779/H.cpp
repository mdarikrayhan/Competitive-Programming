// learned from https://www.luogu.com.cn/article/jaubwkuq
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 35;
int n;
int id[maxn], p[maxn];
bool vis[maxn];
ll sum, res, t;
ll a[maxn], rec[maxn];
mt19937 rng(time(0));

void dfs(int x, int rest, ll cur, ll s) {
  if (cur > sum || x + rest > n + 1) return;
  if (x == n + 1) {
    if (cur > res && (res == -1 || rng() % 8)) {
			res = cur;
			t = s;
		}
    return;
  }
  if (vis[p[x]] == 0 && rest > 0) {	
    vis[p[x]] = 1;
		dfs(x + 1, rest - 1, cur + a[p[x]], s | (1ll << (p[x] - 1)));
    vis[p[x]] = 0;
	}
  dfs(x + 1, rest, cur, s);
}

int check(int x) {
  int r = 0;
  for (int k = 1; k <= 30 && r == 0; k++) {
    for (int i = 1; i <= n; i++) {	
      vis[i] = 0;
			p[i] = i;
		}
		
    shuffle(p + 1, p + 1 + n, rng), sum = a[x], vis[x] = 1;
    bool flag = 0;
    for (int i = 1; (1 << i) <= n; i++) {
      res = -1;
			t = 0;
			dfs(1, 1 << (i - 1), 0, 0);
      if (res == -1) {
        flag = 1;
        break;
      }
      sum += res;
			rec[i] = t;
      for (int j = 1; j <= n; j++) if ((t >> (j - 1)) & 1) vis[j] = 1;
    }
    if (flag == 0) r = 1;
  }
  return r;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
		cin >> a[i];
		id[i] = i;
	}
	
  sort(id + 1, id + 1 + n, [&](int x, int y) {
		return a[x] < a[y];
	});
	
  int l = 0, r = n + 1;
  while (l + 1 < r) {
    int mid = (l + r >> 1);
    if (check(id[mid])) r = mid;
    else l = mid;
  }
  for (int i = 1; i <= n; i++) cout << (a[i] >= a[id[r]]);
}