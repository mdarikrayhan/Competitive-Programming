// LUOGU_RID: 160148032
#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int M=1e9+7,N=1e6+5;
int n,dp[N];
signed main()
{
//	freopen(" .in","r",stdin);
//	freopen(" .out","w".stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	dp[1]=1;
	for(int i=2;i<=n;i++) dp[i]=(dp[i-1]+dp[i-2]+2)%M;
	cout<<dp[n];
	return 0;
}