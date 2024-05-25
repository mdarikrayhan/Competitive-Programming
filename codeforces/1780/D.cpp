#include <bits/stdc++.h>
using namespace std;

void run() {
	int cnt; cin >> cnt;

	int ans = 0;
	for (int i = 0; i < 30 and cnt; i++) {
		cout << "- " << (1 << i) << endl;
		int x; cin >> x; assert(x != -1);

		if (x < cnt) {
			ans |= 1 << i;
			cnt--;
		} else {
			ans |= 1 << (i + x - cnt + 1);
			int orig = i;
			i += x - cnt + 1;

			cout << "- " << (1 << i) - 1 - ((1 << orig) - 1) << endl;
			cin >> x; assert(x != -1); cnt = x;
		}
	}

	cout << "! " << ans << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t; while (t--) run();
}
