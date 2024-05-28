// LUOGU_RID: 158225083
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int a1, b1, a2, b2, a3, b3, a4, b4;

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3 >> a4 >> b4;
	if ((a1 > max(b3, b4) && b2 > max(a3, a4)) || (a2 > max(b3, b4) && b1 > max(a3, a4))) {
		cout << "Team 1\n";
	} else if (((b3 > a1 && a4 > b2) || (b4 > a1 && a3 > b2)) && ((b3 > a2 && a4 > b1) || (b4 > a2 && a3 > b1))) {
		cout << "Team 2\n";
	} else {
		cout << "Draw\n";
	}
	return 0;
}