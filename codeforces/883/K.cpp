#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
int n, ans, s[N], g[N], p[N];
signed main(){
	scanf("%lld", &n);
	for(int i = 1; i <= n; i++)	scanf("%lld%lld", &s[i], &g[i]);
	p[1] = s[1] + g[1];
	for(int i = 2; i <= n; i++)	p[i] = min(p[i - 1] + 1, s[i] + g[i]);
	for(int i = n - 1; i >= 1; i--)	p[i] = min(p[i + 1] + 1, p[i]);
	for(int i = 1; i <= n; i++){
		ans += p[i] - s[i];
		if(p[i] < s[i]){
			printf("-1");
			return 0;
		}
	}
	printf("%lld\n", ans);
	for(int i = 1; i <= n; i++)	printf("%lld ", p[i]);
	return 0;
}