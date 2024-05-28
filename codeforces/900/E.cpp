// LUOGU_RID: 159086915
#pragma GCC optimize("Ofast,unroll-loops")
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64=long long ;
using ld=long double;
const int N=2e5+10;
const int mod=1e9+7;
int f[N][2];
int dp[N];
int cnt[N];
int a[N];
void solve(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	s="1"+s;
	f[n][0]=f[n][1]=n;
	if(s[n]=='a') f[n][1]=0;
	if(s[n]=='b') f[n][0]=0;
	for(int i=1;i<=n;i++){
		a[i]=a[i-1]+(s[i]=='?');
	}
	for(int i=n-1;i>=1;i-=1){
		f[i][1]=f[i][0]=0;
		if(s[i]=='?'){
			f[i][0]=f[i][1]=i;
			f[i][0]=max(f[i][0],f[i+1][1]);
			f[i][1]=max(f[i][1],f[i+1][0]);
		}else if(s[i]=='a'){
			f[i][0]=max(i,f[i+1][1]);
		}else{
			f[i][1]=max(i,f[i+1][0]);
		}
	}
//	cout<<f[3][0]<<endl;
	int m;
	cin>>m;
	for(int i=m;i<=n;i+=1){
		dp[i]=dp[i-1];
		cnt[i]=cnt[i-1];
		int u=i-m+1;
		if(f[u][0]>=i){
			if(dp[i]<dp[u-1]+1) cnt[i]=cnt[u-1]+a[i]-a[u-1],dp[i]=dp[u-1]+1;
			else if(dp[i]==dp[u-1]+1) cnt[i]=min(cnt[i],a[i]-a[u-1]+cnt[u-1]);
		}
	}
//	cout<<dp[n]<<endl;
	cout<<cnt[n]<<endl;
	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t=1;
//	cin>>t;
	while(t--) solve();
	return 0;
}