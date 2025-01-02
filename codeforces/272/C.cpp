#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int next()
{
	int x;
	cin >> x;
	return x;
}

int main()
{
	ios::sync_with_stdio();
	cin.tie(0);

	int n = next();
	int steps[n];

	for (int i = 0; i < n; i++)
		cin >> steps[i];

	int m = next();
	ll boxRecord = 0;

	for (int i = 0; i < m; i++) {
		ll w = next();
		ll h = next();

		int largestStep = steps[w - 1];

		if (boxRecord > largestStep) {
			cout << boxRecord << '\n';
			boxRecord += h;
		} else {
			cout << largestStep << '\n';
			boxRecord = largestStep + h;
		}
	}

	return 0;
}
