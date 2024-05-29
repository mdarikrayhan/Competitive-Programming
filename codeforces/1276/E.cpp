// learned from https://www.luogu.com.cn/article/ho0kbswo
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf = 0x3f3f3f3f3f3f3f3f;
int a[5], b[5], g1, g2;
vector<pair<int, int>> res1, res2, res;

void gg(int x = -1) {
  cout << x << '\n';
  exit(0);
}

void solve(int *a, vector<pair<int, int>> &res) {
  while (1) {
    sort(a + 1, a + 5);
    if (a[4] - a[1] == 1) break;
    int p = inf;
    while (1) {
      int l = a[1] * 3 + a[4], r = a[1] + a[4] * 3;
      if (l <= a[2] * 4 && a[2] * 4 <= r) p = a[2];
      if (l <= a[3] * 4 && a[3] * 4 <= r) p = a[3];
      if (p != inf) break;
      int d2 = min(a[2] - a[1], a[4] - a[2]), d3 = min(a[3] - a[1], a[4] - a[3]);
      if (d2 > d3) {
        swap(d2, d3);
				swap(a[2], a[3]);
			}
			
      int id1, id2;
      if (a[4] - a[3] < a[3] - a[1]) {	
        id1 = 3;
				id2 = 4;
			} else {	
        id1 = 1;
				id2 = 3;
			}
      if (a[4] - a[2] < a[2] - a[1]) swap(id1, id2);
      res.emplace_back(a[2], a[id1]);
      a[2] = (a[id1] << 1) - a[2];
      res.emplace_back(a[2], a[id2]);
      a[2] = (a[id2] << 1) - a[2];
    }
    if (a[1] + a[4] >= (p << 1)) {
      for (int i = 1; i <= 4; i++) {
	      if (a[i] < p) {
					res.emplace_back(a[i], p);
	        a[i] = (p << 1) - a[i];
				}
			}
    } else {
			for (int i = 1; i <= 4; i++) {
				if (a[i] > p) {
					res.emplace_back(a[i], p),
					a[i] = (p << 1) - a[i];
				}
			}
    }
  }
  sort(a + 1, a + 5);
  if (a[1] & 1) {
    for (int i = 1; i <= 4; i++) {
			if (a[i] & 1) {
				res.emplace_back(a[i], a[i] + 1);
				a[i] += 2;
			}
		}
  }
  sort(a + 1, a + 5);
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
	for (int i = 1; i <= 4; i++) cin >> a[i];
	for (int i = 1; i <= 4; i++) cin >> b[i];
  sort(a + 1, a + 5);
	sort(b + 1, b + 5);

  for (int i = 2; i <= 4; i++) {
		g1 = __gcd(g1, a[i] - a[1]);
		g2 = __gcd(g2, b[i] - b[1]);
	}
	
  if (g1 ^ g2) gg();
  if (!g1) gg(a[1] == b[1] ? 0 : -1);
  if ((a[1] - b[1]) % g1) gg();

  int d = (a[1] % g1 + g1) % g1;
  for (int i = 1; i <= 4; i++) {
		a[i] = (a[i] - d) / g1;
		b[i] = (b[i] - d) / g1;
	}
	
  solve(a, res1);
	solve(b, res2);

  for (int i = 1; i <= 4; i++) if ((a[i] & 1) != (b[i] & 1)) gg();
  d = (b[1] - a[1]) / 2;
  while (3 * (a[4] - a[1]) <= abs(d)) {
    res1.emplace_back(a[3], a[1]), a[3] = (a[1] << 1) - a[3];
    res1.emplace_back(a[2], a[4]);
    a[2] = (a[4] << 1) - a[2];
    sort(a + 1, a + 5);
  }
	
  while (1) {
    while (abs(d) >= a[4] - a[1]) {
      if (d < 0) {
        d += a[4] - a[1];
        for (int i = 1; i <= 2; i++) {
          for (int j = 2; j <= 4; j++) {
            res1.emplace_back(a[j], a[1]);
            a[j] = (a[1] << 1) - a[j];
          }
          sort(a + 1, a + 5);
        }
      } else {
        d -= a[4] - a[1];
        for (int i = 1; i <= 2; i++) {
          for (int j = 1; j <= 3; j++) {
            res1.emplace_back(a[j], a[4]);
            a[j] = (a[4] << 1) - a[j];
          }
          sort(a + 1, a + 5);
        }
      }
    }
		
    if (a[4] - a[1] <= 1) break;
    res1.emplace_back(a[1], a[2]);
    a[1] = (a[2] << 1) - a[1];
    res1.emplace_back(a[4], a[3]);
    a[4] = (a[3] << 1) - a[4];
    sort(a + 1, a + 5);
  }
	
  reverse(res2.begin(), res2.end());
  for (auto x : res2) res1.emplace_back((x.second << 1) - x.first, x.second);
  for (auto x : res1) {	
    if (x.first != x.second) res.emplace_back(x.first * g1 + d, x.second * g1 + d);
	}
  cout << res.size() << '\n';
  for (auto x : res) cout << x.first << " " << x.second << '\n';
}