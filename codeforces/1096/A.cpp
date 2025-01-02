#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif //! ONLINE_JUDGE
	int t = 1;
	ll N, K, a, b, x, y, L, R;
	cin >> t;
	while (t--)
	{
		cin >> L >> R;
		cout << L << " " << 2 * L << endl;
	}
	return 0;
}