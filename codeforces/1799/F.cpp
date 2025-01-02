// LUOGU_RID: 160533600
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5005;
int n, b, k1, k2, a[N], va[N], vb[N], vc[N];

bool cmp(int x, int y){return x > y;}
void work(){
	scanf("%lld %lld %lld %lld", &n, &b, &k1, &k2); int sum = 0, ans = 0;
	for(int i = 1; i <= n; i ++) scanf("%lld", &a[i]), sum += a[i];
	sort(a + 1, a + n + 1, cmp);
	for(int i = 1; i <= n; i ++){
		va[i] = a[i] / 2; vb[i] = min(a[i], b); vc[i] = min(a[i], b + a[i] / 2);
		va[i] += va[i - 1]; vb[i] += vb[i - 1]; vc[i] += vc[i - 1];
	}
	for(int i = 0; i <= min(k1, k2); i ++){
		int res1 = k1 - i, res2 = k2 - i;
		for(int j = 0; j <= min(res1, n - i); j ++){
			int now = 0; now += vc[i]; now += va[i + j] - va[i];
			int res = n - (i + j);
			if(res <= res2) now += vb[n] - vb[i + j];
			else{
				now += vb[i + j + res2] - vb[i + j];
				int rr = k1 - j - i;
				now += va[min(n, i + j + res2 + rr)] - va[i + j + res2];
			}
			ans = max(ans, now);
		}
	}
	printf("%lld\n", sum - ans);
}
signed main(){
	int t; scanf("%lld", &t);
	while(t --) work(); return 0;
}