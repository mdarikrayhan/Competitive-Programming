// LUOGU_RID: 158693288
#include <bits/stdc++.h>
using namespace std;
#define int long long

int k;
bool check(int x, int y) {
	if ((x + 1) * (x + 1) + (y + 1) * (y + 1) * 3 > k * k * 4) {
		return 0;
	}
	if ((x + 2) * (x + 2) + y * y * 3 > k * k * 4) {
		return 0;
	}
	return 1;
}
signed main() {
	cin >> k; 
	int a = 0, b = 0;
	while (check(a, b)) {
		b += 2;
	}
	int sum = -b - 3;
	while (b >= 0) {
		a += 3;
		b += 1;
		sum += 2 * b;
		while (b >= 0 && check(a, b) == 0) {
			b -= 2;
		}
	}
	cout << sum;
	return 0;
}