// LUOGU_RID: 160092449
# pragma GCC optimize("Ofast,no-stack-protector")

# pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

# include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef pair <int, int> pii;

const int t = 1000003;

int n, m, x, s[1000005];

int main () {

	ios::sync_with_stdio (0);

	cin.tie (0);

	cout.tie (0);

	cin >> n >> m;

	while (n --) {

		cin >> x;

		if (s[x] < s[m])
			s[x] = -1;
		else
			++ s[x];

	}
//	for (int i = 1; i < 11; ++ i) cerr << s[i] << ' '; cerr << '\n';
	for (int i = 1; i < t; ++ i)
		if (s[i] >= s[m] && i ^ m) {

			cout << i;

			return 0;

		}

	cout << "-1";

	return 0;

}