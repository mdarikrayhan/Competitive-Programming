#include <bits/stdc++.h>
using namespace std;

const int N = 1000010;
int a[N], l[N], r[N], q[N];
long long b[N]; 

int main() {
	int n, m;
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
	int tt = 0;
	for (int i = 1; i <= n; i ++ ) {
		while (tt && a[q[tt]] >= a[i]) tt -- ;
		l[i] = q[tt] + 1;
		q[++ tt] = i;
	}
	tt = 0;
	q[0] = n + 1;
	for (int i = n; i >= 1; i -- ) {
		while (tt && a[q[tt]] > a[i]) tt -- ;
		r[i] = q[tt] - 1;
		q[++ tt] = i;
	}
	for (int i = 1; i <= n; i ++ ) {
		int L = i - l[i] + 1, R = r[i] - i + 1;
		b[1] += a[i];
		b[min(L, R) + 1] -= a[i];
		b[max(L, R) + 1] -= a[i];
		b[L + R + 1] += a[i];
	}
	for (int i = 1; i <= n; i ++ ) b[i] += b[i - 1];
	for (int i = 1; i <= n; i ++ ) b[i] += b[i - 1];
	scanf("%d", &m);
	while (m -- ) {
		int k;
		scanf("%d", &k);
		printf("%.12lf\n", b[k] * 1.0 / (n - k + 1));
	}
	return 0;
}

