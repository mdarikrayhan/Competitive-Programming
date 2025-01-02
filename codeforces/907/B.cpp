#define DEBUG false
#define DEBUG2 true

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <functional>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
using ll = long long;
using ld = long double;

int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}

int main() {
	std::vector<string> v;
	for (int i = 1; i <= 9; i++) {
		string res = "";
		for (int j = 0; j < 3; j++) {
			string s; cin >> s;
			res += s;
			if (j != 3) res += ' ';
		}
		v.push_back(res);
		if (i == 3 || i == 6) v.push_back("");
	}
	int x, y; cin >> x >> y;

	#if DEBUG
		for (string t: v) cout << t << '\n';
		cout << "DONE PRINTING\n";
	#endif

	int pos_x = x % 3, pos_y = y % 3;
	int offset_x, offset_y;
	bool found = false;
	if (pos_x == 1) offset_x = 0;
	else if (pos_x == 2) offset_x = 4;
	else offset_x = 8;
	if (pos_y == 1) offset_y = 0;
	else if (pos_y == 2) offset_y = 4;
	else offset_y = 8;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (v[offset_x + i][offset_y + j] == '.') {
				found = true;
				v[offset_x + i][offset_y + j] ='!';
			}
		}
	}
	if (!found) {
		for (int i = 0; i < v.size(); i++) {
			for (int j = 0; j < v[i].size(); j++) {
				if (v[i][j] == '.') v[i][j] = '!';
			}
		}
	}
	for (string t: v) cout << t << '\n';
}