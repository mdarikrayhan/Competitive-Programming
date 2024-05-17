#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define X first
#define Y second
#define umap unordered_map
using ll = long long;
typedef pair<int, int> pii;
const int maxn = 2e5 + 5, mod = 1e9 + 7, maxp = 26, inf = 1e9;
const ll INF = 1e18;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ct = 0;
	for (int i = 0; i <= n - 11; i++) {
		if (s[i] == '8') ct++;
	}
	if (ct <= (n - 11) / 2) {
		cout << "NO" << endl;
		return;
	}
	cout << "YES" << endl;
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