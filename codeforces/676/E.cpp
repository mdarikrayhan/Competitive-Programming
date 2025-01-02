#include <algorithm>
#include <iostream>

using namespace std;

const int N = 100001;

char cc[7];
int aa[N];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	int n, k; cin >> n >> k, n++;
	int m = 0;
	for (int i = 0; i < n; i++) {
		cin >> cc;
		if (cc[0] != '?')
			aa[i] = atoi(cc);
		else
			aa[i] = 12345, m++;
	}
	if (!k) {
		cout << (!aa[0] || aa[0] == 12345 && (n - m) % 2 ? "Yes" : "No") << '\n';
		return 0;
	}
	if (m) {
		cout << (n % 2 == 0 ? "Yes" : "No") << '\n';
		return 0;
	}
	if (k == 1) {
		int a = 0;
		for (int i = 0; i < n; i++)
			a += aa[i];
		cout << (!a ? "Yes" : "No") << '\n';
		return 0;
	}
	if (k == -1) {
		int a = 0;
		for (int i = 0; i < n; i++)
			a += aa[i] * (i % 2 ? -1 : 1);
		cout << (!a ? "Yes" : "No") << '\n';
		return 0;
	}
	int a = 0;
	for (int i = n - 1; i >= 0; i--)
		if (abs(a = a * k + aa[i]) > 10000) {
			cout << "No\n";
			return 0;
		}
	cout << (!a ? "Yes" : "No") << '\n';
	return 0;
}
