// LUOGU_RID: 159902591

#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <set>
#include <math.h>
using namespace std;

typedef long long ll;
const int MOD = 1000000007;



int n;
ll x;


ll X[100005], Y[100005];

int main(void) {
//	TEST_IN;

	ll x0, y0;
	scanf("%d %lld", &n, &x);
	scanf("%lld %lld", &x0, &y0);

	ll x_delta = 0, y_delta = 0;
	for (int i = 1; i <= n; i++) scanf("%lld %lld", &X[i], &Y[i]);
	for (int i = 1; i <= n; i++) {
		ll t = x/n;
		int left = x - t*n;
		if (left >= i) t++;

		if ((x-i) & 1) {
			if (t&1) {
				x_delta -= 2*X[i]; y_delta -= 2*Y[i];
			}
		} else {
			if (t&1) {
				x_delta += 2*X[i]; y_delta += 2*Y[i];
			}
		}
	}

	if (x & 1) {
		x0 = -x0; y0 = -y0;
	}

	x0 += x_delta; y0 += y_delta;
	printf("%lld %lld\n", x0, y0);
	return 0;
}
