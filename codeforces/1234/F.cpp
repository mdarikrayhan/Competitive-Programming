#include <bits/stdc++.h>
using namespace std;
#define dbg(a) cout << #a << " = " << a << endl

typedef long long ll;

const int MAX = (1 << 20);

int hs[MAX];

void solve() {
	int n;
	string s;
	cin >> s;
	n = s.size();
	
	memset(hs, -1, sizeof hs);
	for (int i = 0; i < n; i++) {
		int msk = 0;
		for (int j = i; j < n; j++) {
			int p = s[j] - 'a';
			if (msk & (1 << p)) break;
			msk |= (1 << p);
			hs[msk] = __builtin_popcount(msk);
		}
	}
	hs[0] = 0;

	for (int i = 0; i < 20; ++i) {
		for (int msk = 0; msk < MAX; ++msk) {
			if (msk&(1<<i)) {
				hs[msk] = max(hs[msk^(1<<i)], hs[msk]);
			}
		}
	}
	int ans = 0;
	for (int msk = 0; msk < MAX; msk++) {
		int smsk = (MAX - 1) ^ msk;
		if (min(hs[msk], hs[smsk]) != -1) {
			ans = max(ans, hs[msk] + hs[smsk]);
		}
	}
	cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);

  int tc = 1;
  // cin >> tc;
  while (tc--)
    solve();

  return 0;
}
