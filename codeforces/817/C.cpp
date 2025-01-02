#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

bool ok(ll N, ll S)
{
	ll sum{}, originalN = N;
	while (N)
		sum += N % 10, N /= 10;
	return (originalN - sum >= S);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif //! ONLINE_JUDGE
	int t = 1;
	ll N, S;
	// cin >> t;
	while (t--)
	{
		cin >> N >> S;
		ll L{}, R{1LL << 62}, ans{};
		while (L <= R)
		{
			ll mid = ((L + R) >> 1);
			if (ok(mid, S))
			{
				if (mid <= N)
					ans = mid;
				R = mid - 1;
			}
			else
				L = mid + 1;
		}
		if (ans)
			cout << N - ans + 1;
		else
			cout << 0;
	}
	return 0;
}