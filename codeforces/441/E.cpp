// LUOGU_RID: 160386248
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;
const ll mod=998244353;
const ll inf=2e9;
const int N=2e5+5;
const int M=2e5+5;
const int V=2e6;
int x,k;
ld dp[255][255],p;
int calc(int w){
	int tmp=0;
	while(!(w&1)) tmp++,w>>=1;
	return tmp;
}
void solve(int Ca){
	cin>>x>>k>>p;p/=100;
	for(int i=0;i<=k;i++) dp[0][i]=calc(x+i);
	for(int i=0;i<=k-1;i++){
		for(int j=0;j<=k;j++){
			if(j*2<=k) dp[i+1][j*2]+=(dp[i][j]+1)*p;
			if(j) dp[i+1][j-1]+=dp[i][j]*(1-p);
		}
	}
	cout<<fixed<<setprecision(15)<<dp[k][0]<<"\n";
}
int main(){
	#ifdef ONLINE_JUDGE
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	#endif
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	#endif
	
	int Ca=1;
//	cin>>Ca;
	for(int i=1;i<=Ca;i++){
		solve(i);
	}
	return 0;
}