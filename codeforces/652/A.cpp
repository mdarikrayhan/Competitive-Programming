// LUOGU_RID: 159868079
#include <iostream>
using namespace std;
signed main() {
	int start, end, a, b, ans = 1;
	cin >> start >> end >> a >> b;
	if (start + a * 8 < end && a <= b) {
		cout << -1;
		return 0;
	}
	if(start + 8 * a >= end) {	
		cout << 0;
		return 0;
	}
	start += 8 * a;
	start -= 12 * b;
	start += 12 * a;
	for (; start < end; start += 12 * a) {
		start -= 12 * b;
		ans++;
	}
	cout << ans;
}