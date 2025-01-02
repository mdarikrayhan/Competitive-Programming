// LUOGU_RID: 159711476
#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 4010;
int a[maxn],b[maxn],dp[maxn][maxn];
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
		scanf("%d",a+i),b[i] = a[i];
	sort(b+1,b+n+1);
	int *m = unique(b+1,b+n+1);
	for(int i = 1;i <= n;i++)
		a[i] = lower_bound(b+1,m,a[i]) - b;
//	for(int i = 1;i <= n;i++)
//		cout << a[i] << ' ';
//	puts("");
	int ans = 0;
	for(int i = 1;i <= n;i++)
		for(int j = i + 1;j <= n;j++)
			ans = max(ans,dp[j][a[i]] = dp[i][a[j]] + 1);
	printf("%d",ans + 1);
}