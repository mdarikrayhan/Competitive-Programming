#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define X first
#define Y second
#define umap unordered_map
using ll = long long;
typedef pair<int, int> pii;
const int maxn = 1e6 + 5, mod = 998244353, maxp = 25, inf = 1e9;
const ll INF = 1e18;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(k + 1), fst(n + 1, inf), lst(n + 1, -1);
	for (int i = 1; i <= k; i++) {
		int x;
		cin >> x;
		fst[x] = min(fst[x], i);
		lst[x] = i;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (i > 1 && fst[i] > lst[i - 1]) ans++;
		if (i < n && fst[i] > lst[i + 1]) ans++;
		if (fst[i] == inf) ans++;
 	}
 	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int tt = 1;
	// cin >> tt;
	while (tt--) solve();
	return 0;
}