// coached by rainboy
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	int n, k; cin >> n >> k;
	if (k == 1 || k > 3) {
		cout << "-1\n";
		return 0;
	}
	if (k == 2) {
		if (n < 5) {
			cout << "-1\n";
			return 0;
		}
		cout << n - 1 << '\n';
		for (int i = 1; i < n; i++)
			cout << i << ' ' << i + 1 << '\n';
	} else {
		if (n < 4) {
			cout << "-1\n";
			return 0;
		}
		if (n == 4) {
			cout << "3\n";
			cout << "1 2\n";
			cout << "2 3\n";
			cout << "3 4\n";
			return 0;
		}
		if (n == 5) {
			cout << "4\n";
			cout << "1 2\n";
			cout << "2 3\n";
			cout << "3 4\n";
			cout << "3 5\n";
			return 0;
		}
		cout << n - 1 + n - 3 << '\n';
		for (int i = 1; i < n; i++)
			cout << i << ' ' << i + 1 << '\n';
		for (int i = 3; i < n; i++)
			cout << "1 " << i + 1 << '\n';
	}
	return 0;
}
