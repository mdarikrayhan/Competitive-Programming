#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 505;

ll n,m,mod,a[N];
int dp[2][N][N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>n>>m>>mod;
	for (int i=1; i<=m; i++){
		string s;
		cin>>s;
		int c1=0;
		for (auto u : s){
			c1+=(u=='1');
		}
		if (c1!=2) return cout<<0<<"\n",0;
		for (int j=0; j<n; j++){
			a[j+1]+=(s[j]=='1');
			if (a[j+1]>2){
				return cout<<0<<"\n",0;
			}
		}
	}
	int st1=0,st2=0;
	for (int i=1; i<=n; i++){
		if (a[i]==0) st2++;
		if (a[i]==1) st1++;
	}
	dp[0][st1][st2]=1;
	int c=1;
	for (int i=m; i<n; i++){
		for (ll c1=0; c1<=n; c1++){
			for (ll c2=0; c2<=n; c2++){
				if (dp[c^1][c1][c2]==0){
					continue;
				}
				#define cal(c) ((c*(c-1)/2)%mod)
				if (c1>=2){
					(dp[c][c1-2][c2]+=1ll*dp[c^1][c1][c2]*cal(c1)%mod)%=mod;
				}
				if (c1>=1 && c2>=1){
					(dp[c][c1][c2-1]+=1ll*dp[c^1][c1][c2]*c1%mod*c2%mod)%=mod;
				}
				if (c2>=2){
					(dp[c][c1+2][c2-2]+=1ll*dp[c^1][c1][c2]*cal(c2)%mod)%=mod;
				}
			}
		}
		c^=1;
	}
	cout<<dp[c^1][0][0]<<"\n";
	return 0;
}
