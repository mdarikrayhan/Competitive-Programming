#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

using namespace std;

const vector<int> dx = { 0, -1, 0, 1 };
const vector<int> dy = { -1, 0, 1, 0 };

int n, m;

vector<vector<char>> pv;

bool f(int x, int y) {
	bool c = false;
	for (int i = 0; i < 4; ++i) {
		int x1 = x + dx[i];
		int y1 = y + dy[i];
		if (0 <= x1 && x1 < n && 0 <= y1 && y1 < m && pv[x1][y1] == 'W') {
			pv[x1][y1] = '.';
			return true;
		}
	}
	return false;
}

int main() {
	cin >> n >> m;
	pv.resize(n, vector<char>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> pv[i][j];
		}
	}
	int volk = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (pv[i][j] == 'P' && f(i, j)) {
				pv[i][j] == '.';
				++volk;
			}
		}
	}
	cout << volk;
}

