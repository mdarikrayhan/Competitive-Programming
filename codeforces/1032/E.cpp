// LUOGU_RID: 158874807
#pragma GCC optimize("Ofast,unroll-loops")
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64=long long ;
using ld=long double;
const int N=1e4+10;
const int mod=1e9+7;
int a[N];
int dp[110][N];
int cnt[N];
void solve(){
	int n;
	cin>>n;
	set<int> s;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		cnt[x]+=1;
		s.insert(x);
	}
	dp[0][0]=1;
	for(int i=1;i<=100;i++){
		for(int j=100;j>=1;j--){
			for(int k=10000;k>=0;k--){
				for(int u=cnt[i];u>=1;u--){
					int w=u*i;
					if(k>=w&&j>=u){
						dp[j][k]+=dp[j-u][k-w];
						dp[j][k]=dp[j][k]>2?2:dp[j][k];
					}
				}
			}
		}
	}
	int ans=0;
	for(int i=1;i<=100;i++){
		for(int u=1;u<=cnt[i];u++){
			int w=i*u;
			if(dp[u][w]==1){
				ans=max(ans,u);	
			}
		}
	}
	if(s.size()==2){
		cout<<n<<endl;
		return;
	}
//	cout<<dp[2][4]<<endl;
	cout<<ans<<endl;
	
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