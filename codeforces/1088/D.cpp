#include <iostream>
using namespace std;
int limit = 29;
int main() {
	cout << "? 0 0\n";
	int ans; cin >> ans;
	int op = ans;
	int a = 0, b = 0;
	if (op == 0) {
		for (int i = limit; i >= 0; i--) {
			cout << "? " << a << " " << b + (1 << i) << "\n";
			cin >> op;
			if (op > 0) {
				a += 1 << i;
				b += 1 << i;
			}
		}
		cout << "! " << a << " " << b << "\n";
		return 0;
	}
	for (int i = limit; i >= 0; i--) {
		int ans1, ans2;
		cout << "? " << a + (1 << i) << " " << b << "\n";
		cin >> ans1;
		cout << "? " << a << " " << b + (1 << i) << "\n";
		cin >> ans2;
		if (ans1 == 0 || ans2 == 0) {
			if (op == 1) {
				a += 1 << i;
			}
			else {
				b += 1 << i;
			}
			for (int j = i - 1; j >= 0; j--) {
				cout << "? " << a << " " << b + (1 << j) << "\n";
				cin >> op;
				if (op > 0) {
					a += 1 << j;
					b += 1 << j;
				}
			}
			cout << "! " << a << " " << b << "\n";
			return 0;
		}
		if (op == 1) {
			if (ans1 == 1) {
				if (ans2 == 1){
					a += 1 << i;
					op = 1;
				}
				else {
					op = 1;
				}
			}
			else {
				if (ans2 == 1) {
					a += 1 << i;
					b += 1 << i;
					op = 1;
				}
				else {
					a += 1 << i;
					op = -1;
				}
			}
		}
		else {
			if (ans1 == 1) {
				if (ans2 == 1) {
					b += 1 << i;
					op = 1;
				}
				else {
					op = -1;
				}
			}
			else {
				if (ans2 == 1) {
					a += 1 << i;
					b += 1 << i;
					op = -1;
				}
				else {
					b += 1 << i;
					op = -1;
				}
			}
		}
	}
	cout << "! " << a << " " << b << "\n";
}