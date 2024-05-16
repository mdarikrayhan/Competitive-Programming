// LUOGU_RID: 159194318
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
signed main() {
	cin >> n >> m;
	if (n < m) {
		swap(n, m);
	}
	cout << m + 1 << "\n";
	for (int i = 0; i <= m; i++) {
		cout << i << " " << m - i << "\n";
	}
}