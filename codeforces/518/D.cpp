// LUOGU_RID: 160497444
#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 2e3 + 10;
double dp[maxn];
int main(){
	int n,t;
	double ok;
	scanf("%d%lf%d",&n,&ok,&t);
	double no = 1 - ok;
	dp[0] = 1;
	for(int i = 1;i <= t;i++){
		dp[n] += dp[n-1] * ok;
		for(int j = n - 1;j;j--)
			dp[j] = dp[j-1] * ok + dp[j] * no;
		dp[0] *= no;
	}
	double ans = 0;
	for(int i = 1;i <= n;i++)
		ans += dp[i] * i;
	printf("%.8lf",ans);
}