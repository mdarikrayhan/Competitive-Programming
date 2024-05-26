// LUOGU_RID: 159927306
#pragma GCC optimize("Ofast,unroll-loops")
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64=long long ;
using ld=long double;
const int N=100+10;
const int mod=1e9+7;
int dp[N][N*27];
void solve(){

	int ans=0;
	string s;
	cin>>s;
	for(auto y:s){
		ans+=y-'a'+1;
	}
	cout<<(dp[s.size()][ans]+mod-1)%mod<<endl;
}
int main(){
	int n=100;
	dp[0][0]=1;
	for(int i=1;i<=n;i+=1){
		for(int j=1;j<=26;j+=1){
			for(int k=26*(i-1);k>=i-1;k-=1){
				dp[i][k+j]+=dp[i-1][k];
				if(dp[i][k+j]>=mod) dp[i][k+j]-=mod;
			}
		}
	}
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t=1;
	cin>>t;
	while(t--) solve();
	return 0;
}