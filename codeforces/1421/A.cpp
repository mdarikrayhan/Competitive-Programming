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
	ll N, a, b;
	cin >> t;
	while (t--)
	{
		cin >> a >> b;
		ll XOR{};
		for (int i{}; i < 31; i++)
		{
			if ((a & (1LL << i)) && (b & (1LL << i)))
				XOR |= (1LL << i);
		}
		cout << (a ^ XOR) + (b ^ XOR) << endl;
	}
	return 0;
}