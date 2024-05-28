// LUOGU_RID: 160476805
#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 510,mod = 1e9 + 7;
int a[maxn],dp[maxn][maxn];
int f(int l,int r){
	if(l == r)return 1;
	if(dp[l][r])return dp[l][r];
	const int t = a[l+1];
	for(int i = l + 1;i <= r;i++){
		if(i != r && a[i+1] < t)continue;
		dp[l][r] = (dp[l][r] + (long long)f(l + 1,i) * f(i,r) % mod) % mod;
	}
	return dp[l][r];
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
		scanf("%d",a+i);
	printf("%d",f(1,n));
}