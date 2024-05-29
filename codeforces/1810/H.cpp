/* https://en.wikipedia.org/wiki/Fibonacci_word */
#include <stdio.h>

#define K	44

int ff[K + 1], xx[K + 1], yy[K + 1];

void init() {
	int k;

	ff[0] = 1, ff[1] = 1, xx[0] = 0, xx[1] = 1, yy[0] = 0, yy[1] = 1;
	for (k = 2; k <= K; k++) {
		ff[k] = ff[k - 1] + ff[k - 2];
		xx[k] = xx[k - 1] + xx[k - 2];
		yy[k] = yy[k - 1] + yy[k - 2] * (ff[k - 1] % 2 == 0 ? 1 : -1);
	}
}

int count(int n) {
	int k, ans;

	if (n <= 0)
		return 0;
	ans = 0;
	for (k = K; k >= 2; k--)
		if (n >= ff[k - 1])
			ans += xx[k - 1], n -= ff[k - 1];
	if (n > 0)
		ans++;
	return ans;
}

int count_(int n) {
	int k, sgn, ans;

	sgn = n % 2 == 0 ? -1 : 1, ans = 0;
	for (k = K; k >= 2; k--)
		if (n >= ff[k - 1])
			ans += (xx[k - 1] + sgn * yy[k - 1]) / 2, n -= ff[k - 1], sgn *= (ff[k - 1] % 2 == 0 ? 1 : -1);
	if (n > 0)
		ans++;
	return ans;
}

int main() {
	int t;

	init();
	scanf("%d", &t);
	while (t--) {
		int n, lower, upper;

		scanf("%d", &n);
		lower = 0, upper = n;
		while (upper - lower > 1) {
			int k = (lower + upper) / 2;

			if (n - count(k - 1) > k * 2 + 1)
				lower = k;
			else
				upper = k;
		}
		if ((n - 1 - lower) % 2 == 0)
			printf("%d\n", upper - (count_(n - 2) - count_(lower - 1)));
		else
			printf("%d\n", (n - count(n - 2)) - (upper - (count_(n - 3) - count_(lower - 1))));
	}
	return 0;
}