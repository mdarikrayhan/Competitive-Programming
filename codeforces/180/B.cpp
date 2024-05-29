// LUOGU_RID: 158343611
#include <bits/stdc++.h>
using namespace std;

int lcm(int a, int b) {
	return a / __gcd(a, b) * b;
}
signed main() {
	int b, d;
	cin >> b >> d;
	int t = d;
	int cnt = 0;
	while (__gcd(b, t) > 1) {
		cnt++;
		t /= __gcd(b, t);
	}
	if (t == 1) {
		cout << "2-type\n";
		cout << cnt;
	}
	else if(((b + 1) / __gcd((b + 1), (b - 1)) * (b - 1)) % t == 0) {
		if (cnt == 0 && (b - 1) % t == 0) {
			cout << "3-type";
		}
		else if (cnt == 0 && (b + 1) % t == 0) {
			cout << "11-type";
		}
		else {
			cout << "6-type";
		}
	}
	else {
		cout << "7-type";
	}
	return 0;
}