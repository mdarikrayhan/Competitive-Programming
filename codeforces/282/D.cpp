// LUOGU_RID: 160486077
#include <bits/stdc++.h>
using namespace std;
const long double gold = (sqrtl(5.0) + 1.0) / 2.0;
int n;
int a[4];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	if (n == 1) {
		if (a[1]) {
			cout << "BitLGM" << endl;
		} else {
			cout << "BitAryo" << endl;
		}
	} else if (n == 2) {
		if (a[1] > a[2]) {
			swap(a[1], a[2]);
		}
		if (int(gold * double(a[2] - a[1])) == a[1]) {
			cout << "BitAryo" << endl;
		} else {
			cout << "BitLGM" << endl;
		}
	} else {
		if ((a[1] ^ a[2] ^ a[3]) == 0) {
			cout << "BitAryo" << endl;
		} else {
			cout << "BitLGM" << endl;
		}
	}
	return 0;
}