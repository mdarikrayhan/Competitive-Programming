// learned from the editorial
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 305;
const int inf = 0x3f3f3f3f;

bool contains(ll x, ll l, ll r) {
	return (x >= l) && (x <= r);
}

int lmin[maxn][maxn][maxn], lmax[maxn][maxn][maxn], rmin[maxn][maxn][maxn], rmax[maxn][maxn][maxn];
ll a[maxn];
pair<ll, int> b[maxn];
ll pr[maxn];
int next_left[maxn][maxn], next_right[maxn][maxn];
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  if (n == 1) {
    cout << "1\n";
    return;
  }
  memset(pr, 0, sizeof(int) * (n + 1));
  for (int i = 0; i < n; i++) pr[i + 1] = pr[i] + a[i + 1];
  for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			for (int k = 0; k <= n; k++) {
				lmin[i][j][k] = lmax[i][j][k] = rmin[i][j][k] = rmax[i][j][k] = -inf;
			}
		}
	}
  for (int i = 0; i <= n; i++) b[i] = make_pair(pr[i], i);
  sort(b, b + n + 1);
	
  for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			next_left[i][j] = next_right[i][j] = -1;
		}
	}
  for (int i = 0; i <= n; i++) {
    int prev = -1;
    for (int j = 0; j <= n; j++) {
      next_left[i][j] = prev;
      if (pr[j] == pr[i]) prev = j;
    }
    prev = n + 1;
    for (int j = n; j >= 0; j--) {
      next_right[i][j] = prev;
      if (pr[j] == pr[i]) prev = j;
    }
  }
	
  for (int len = 0; len <= n; len++) {
    for (int i = 0; i <= n && i + len <= n; i++) {
      int j = i + len;
      for (int k = 0; k <= n; k++) {
        if (contains(pr[i], pr[i], pr[k]) && contains(pr[j], pr[i], pr[k])) lmin[i][j][k] = min(len, 1);
        if (contains(pr[i], pr[k], pr[i]) && contains(pr[j], pr[k], pr[i])) lmax[i][j][k] = min(len, 1);
        if (contains(pr[i], pr[j], pr[k]) && contains(pr[j], pr[j], pr[k])) rmin[i][j][k] = min(len, 1);
        if (contains(pr[i], pr[k], pr[j]) && contains(pr[j], pr[k], pr[j])) rmax[i][j][k] = min(len, 1);
      }
			
      if (len <= 1) continue;
      for (int x = i; x <= j; x++) {
        if (next_left[i][x] >= i) {
          int y = next_left[i][x];
          if (pr[x] >= pr[i]) lmin[i][j][x] = max(lmin[i][j][x], lmin[i][y][x] + lmax[x][j][i] + 1);
          if (pr[x] <= pr[i]) lmax[i][j][x] = max(lmax[i][j][x], lmax[i][y][x] + lmin[x][j][i] + 1);
        }
        if (next_left[j][x] >= i) {
          int y = next_left[j][x];
          if (pr[x] >= pr[j])
            rmin[i][j][x] = max(rmin[i][j][x], rmin[x][j][x] + rmin[i][y][x] + 1);
          if (pr[x] <= pr[j])
            rmax[i][j][x] = max(rmax[i][j][x], rmax[x][j][x] + rmax[i][y][x] + 1);
        }
        if (next_right[i][x] <= j) {
          int y = next_right[i][x];
          if (pr[x] >= pr[i])
            lmin[i][j][x] = max(lmin[i][j][x], lmin[i][x][x] + lmin[y][j][x] + 1);
          if (pr[x] <= pr[i])
            lmax[i][j][x] = max(lmax[i][j][x], lmax[i][x][x] + lmax[y][j][x] + 1);
        }
        if (next_right[j][x] <= j) {
          int y = next_right[j][x];
          if (pr[x] >= pr[j])
            rmin[i][j][x] = max(rmin[i][j][x], rmin[y][j][x] + rmax[i][x][j] + 1);
          if (pr[x] <= pr[j])
            rmax[i][j][x] = max(rmax[i][j][x], rmax[y][j][x] + rmin[i][x][j] + 1);
        }
      }
			
      int mx_left = -inf;
      int mx_right = -inf;
      for (int k = 0; k <= n; k++) {
        int p = k;
        while (p <= n && b[p].first == b[k].first) {
          mx_left = max(mx_left, lmin[i][j][b[p].second]);
          mx_right = max(mx_right, rmin[i][j][b[p].second]);
          p++;
        }
        for (int l = k; l < p; l++) {
          lmin[i][j][b[l].second] = mx_left;
          rmin[i][j][b[l].second] = mx_right;
        }
        k = p - 1;
      }
      mx_left = -inf;
      mx_right = -inf;
      for (int k = n; k >= 0; k--) {
        int p = k;
        while (p >= 0 && b[p].first == b[k].first) {
          mx_left = max(mx_left, lmax[i][j][b[p].second]);
          mx_right = max(mx_right, rmax[i][j][b[p].second]);
          p--;
        }
        for (int l = k; l > p; l--) {
          lmax[i][j][b[l].second] = mx_left;
          rmax[i][j][b[l].second] = mx_right;
        }
        k = p + 1;
      }
    }
  }
	
  int res = -inf;
  res = max(res, max(lmin[0][n][n], lmax[0][n][n]));
  for (int x = 0; x <= n; x++) {
    for (int y = x + 1; y <= n; y++) {
      res = max(res, rmin[0][x][y] + lmax[y][n][x] + 1);
      res = max(res, rmax[0][x][y] + lmin[y][n][x] + 1);
    }
  }
  cout << res << "\n";
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
}