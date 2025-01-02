//JAI SIYA RAM
//JAI SHRI RAM
//JAI BAJRANG BALI

#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int a, b, c; cin >> a >> b >> c;
	int diff = (abs(a - b) + 1) / 2; //+1 because we are taking the ceil of the diff
	//ceilVal = (a / b) + ((a % b) != 0)
	//ceilVal = (a + b - 1) / 2
	cout << (diff / c) + ((diff % c) != 0) << "\n";
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}