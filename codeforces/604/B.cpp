#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int INF = 0x3f3f3f3f;
int a[MAXN];
 
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	int maxv = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		maxv = max(a[i], maxv);
	}
	int ans = 0;
	int pos = n - 1;
	k = k > n ? n : k;
	while (1) {
		if (k == 1) {
			if (pos == 0) {
				ans = max(ans, a[0]);
			}
			else {
				ans = max(ans, a[0] + a[pos]);
			}
			printf("%d\n", ans);
			return 0;
		}
		if (2 * k == n) {
			int front = 0;
			while (front < pos) {
				ans = max(ans, a[front] + a[pos]);
				front++;
				pos--;
			}
			printf("%d\n", ans);
			return 0;
		}
		if ((k & 1) && (n & 1)) {
			if (k == n) {
				printf("%d\n", max(ans, maxv));
				return 0;
			}
			ans = max(ans, a[pos]);
			pos--;
			k--;
			n--;
		}
		else if (!(k & 1) && !(n & 1)) {
			if (k == n) {
				printf("%d\n", max(ans, maxv));
				return 0;
			}
			if (k > n / 2) {
				ans = max(ans, a[pos]);
				pos--;
				k--;
				n--;
			}
		}
		else {
			ans = max(ans, a[pos]);
			pos--;
			k--;
			n--;
		}
	}
	return 0;
}
  			   					      		   	     	