#include <cstdio>
#define LL long long
const int MAXN = 55;
int n;
char a[MAXN];
LL res, x = 1; 
int main() {
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++)
		a[i] = getchar();
	for (int i = n - 1; i >= 0; i--) {
		if (a[i] == 'B') {
			x = 1;
			for (int j = 1; j <= i; j++)
				x *= 2;
			res += x;
		}
	}
	printf("%lld\n", res);
	return 0;
}