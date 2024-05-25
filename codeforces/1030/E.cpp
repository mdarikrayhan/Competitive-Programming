// LUOGU_RID: 160011600
#pragma GCC optimize("Ofast,unroll-loops")
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64=long long ;
using ld=long double;
const int N=5e5+10;
const int mod=1e9+7;
int sum[N];
int f[N][2];
int t[N];
void solve(){
	int n;
	cin>>n;
	f[0][0]=1;
	for(int i=1;i<=n;i+=1){
		i64 x;
		cin>>x;
		int cnt=0;
		for(int j=0;j<=61;j+=1){
			cnt+=x>>j&1;
		}
		sum[i]=sum[i-1]+cnt;
		t[i]=cnt;
		f[i][0]=f[i-1][0];
		f[i][1]=f[i-1][1];
		f[i][sum[i]&1]+=1;
	}
	i64 ans=0;
	for(int i=1;i<=n;i+=1){
		int mx=t[i];
		for(int j=i-1;j>=0&&j>=i-62;j-=1){
		
			if(sum[j]%2==sum[i]%2&&sum[i]-sum[j]>=mx*2){
				ans+=1;	
			}
				mx=max(mx,t[j]);
		}
		if((i-63)>=0) ans+=f[i-63][sum[i]&1];
	}
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