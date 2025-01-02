// LUOGU_RID: 158673966
#include <bits/stdc++.h>
using namespace std;

int query(int i, int j) {
	cout << "? " << i << " " << j << endl;
	int dist;
	cin >> dist;
	if (dist == -1)
		exit(0);
	return dist;
}

int main() {
	const int n = 1e9;
	int dist1 = query(1, 1);
	int dist2 = query(n, 1);
	int x = (dist1 - dist2 + n + 1) / 2;
	int dist3 = query(x, 1);
	int y = dist3 + 1;
	int x_res = dist1 - y + 1 + 1;
	int dist4 = query(x, n);
	int y_high = n - dist4;
	int dist5 = query(n, n);
	int x_high = n - y_high + n - dist5;
	cout << "! " << x_res << " " << y << " " << x_high << " " << y_high << endl;
	return 0;
}
