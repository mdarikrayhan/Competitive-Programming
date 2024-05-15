#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	bool f = false;
	vector<vector<int>> a(n, vector<int> (m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
			if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && a[i][j] == 1) {
				f = true;
			}
		}
	}
	if (f) {
		cout << 2;
	}
	else {
		cout << 4;
	}
}

