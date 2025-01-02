#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
	ll h, w;
	cin >> h >> w;

	cout << (h * w / 2 + h * w % 2) << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
	FILE* stream1, *stream2;
	freopen_s(&stream1, "input.txt", "rt", stdin);
	//freopen_s(&stream2, "output.txt", "w", stdout);
#endif
	cin.tie(0)->sync_with_stdio(0);
	long long q = 1;
	cin >> q;
	while (q--) {
		solve();
	}
	return 0;
}