// LUOGU_RID: 160057449
//#pragma GCC optimize(2)
//#pragma GCC optimize(3, "Ofast", "inline")

#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n;
long long a[N];

void mymain() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	if (n == 1) printf("%lld\n", a[1]);
	else if (n == 2) printf("%lld\n", max(2*abs(a[1]-a[2]), a[1]+a[2]));
	else if (n == 3) printf("%lld\n", max({a[1]+a[2]+a[3], 3*a[1], 3*a[3], 3*abs(a[1]-a[2]), 3*abs(a[2]-a[3])}));
	else {
		sort(a+1, a+n+1);
		printf("%lld\n", n*a[n]);
	}
}

void myclear() {
}

int main() {
//	int _ = 1;
	int _; scanf("%d", &_);
	while (_--) mymain(), myclear();
	
	return 0;
}