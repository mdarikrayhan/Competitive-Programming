# include <iostream>
# include <cstdio>
# include <cmath>
# include <algorithm>
# include <cstring>
# include <vector>
# include <map>
# include <climits>
# include <unordered_map>
using namespace std;
const int PR = 998244353;
const int inv2 = (PR + 1) / 2;
long long fast_pow(long long a, long long p, long long m = PR) {
	long long result = 1;
	while (p > 0) {
		if (p & 1)
			result = result * a % m;
		a = a * a % m;
		p >>= 1;
	}
	return result;
}
int N, M;
long long A;
int main() {
	cin >> N >> M >> A;
	int b, prev = 0;
	long long ans = 1;
	for (int i = 0; i < M; i++) {
		cin >> b;
		int diff = b - prev;
		ans = ans * (fast_pow(A, 2 * diff) + fast_pow(A, diff)) % PR * inv2 % PR;
		prev = b;
	}
	ans = ans * fast_pow(A, N - 2 * b) % PR;
	cout << ans << endl ;
	return 0;
}
