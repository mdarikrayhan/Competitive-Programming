#include<bits/stdc++.h>

using namespace std;

#define int long long
const int N = 2e3 + 10;
const int INF = 0x3f3f3f3f3f3f3f3fLL;
typedef __int128 ll;

int n, k;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> k;
	if (k >= (n * (n - 1)) / 2) {
		cout << "no solution" << "\n";
		return 0;
	}
	for (register int i = 1; i <= n; ++i) {
		cout << 0 << " " << i << "\n";
	}
	return 0;
}