// LUOGU_RID: 160029053
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10,mod = 1e9 + 7;
int a[maxn],dp[maxn][maxn];
int f(int now,int x) {
	if(dp[now][x])return dp[now][x];
	if(now > x)return 0;
	return dp[now][x] = (f(now,x - 1) + f(a[x],x - 1) + 2) % mod;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
		scanf("%d",a+i);
	printf("%d",f(1,n));
}