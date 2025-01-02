#include<bits/stdc++.h>
using namespace std;

#define int long long
#define SZ(a) int32_t(a.size())
#define endl '\n'

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	int n, k = 1;
	cin >> n;
	while (k <= n) {
		if (n - k <= 1)
			return cout << 1, 0;
		k += k + 1 + (k & 1);
	}
	return cout << 0, 0;
}

