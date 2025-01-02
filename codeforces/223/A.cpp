#include <algorithm>
#include <assert.h>
#include <complex>
#include <ctype.h>
#include <functional>
#include <iostream>
#include <limits.h>
#include <locale.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <cmath>
#include <vector>
#include <deque>
//#include <unordered_set>
//#include <unordered_map>

#pragma warning(disable:4996)
using namespace std;

#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <ldb, ldb> pdd;

int IT_MAX = 1<<21;
const int MOD = 1234567891;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
const db ERR = 1E-10;

char in[100050];
int dp[100050];
int sum[100050];
int main() {
	scanf("%s", in + 1);
	int N = strlen(in + 1), i, j;
	for (i = 1; i <= N; i++) {
		sum[i] = sum[i - 1];
		if (in[i] == '[') sum[i]++;
	}
	for (i = N; i >= 1; i--) {
		if (in[i] == ')' || in[i] == ']') {
			dp[i] = -1;
			continue;
		}
		
		char x = ')';
		if (in[i] == '[') x = ']';

		int t = i + 1;
		while (t > 0 && t != N + 1) {
			if (in[t] == x) break;
			t = dp[t] + 1;
		}
		if (t >= N + 1 || t <= 0) t = -1;
		dp[i] = t;
	}

	int ans = 0, a1 = 0, a2 = -1;
	for (i = N; i >= 1; i--) {
		if (dp[i] <= 0) continue;
		while (1) {
			if (dp[dp[i] + 1] <= 0) break;
			dp[i] = dp[dp[i] + 1];
		}
		if (sum[dp[i]] - sum[i - 1] > ans) {
			ans = sum[dp[i]] - sum[i - 1];
			a1 = i;
			a2 = dp[i];
		}
	}
	printf("%d\n", ans);
	for (i = a1; i <= a2; i++) printf("%c", in[i]);
	return 0;
}