#include<bits/stdc++.h>
using namespace std;

const int N=50,B=1000000,mod=998244353,inv_B=616898040;
typedef long long ll;
int inv[N],dp[N*N][N],L[N*N],val[N*N],a[N],b[N],n;
inline void reduce(int&x){x+=x>>31&mod;}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;inv[1]=1;
	for(int i=2;i<=n;++i)inv[i]=mod-mod/i*(ll)inv[mod%i]%mod;
	for(int i=1;i<=n;++i){
		double t;cin>>t;
		a[i]=round(t*B);b[i]=a[i]%B;
	}
	sort(b,b+n+1);int m=unique(b,b+n+1)-b;
	val[n*m]=n*B;
	for(int i=n*m-1;i>=0;--i){
		val[i]=(i/m)*B+b[i%m];
		L[i]=(ll)(val[i+1]-val[i])*inv_B%mod;
	}
	for(int i=0;i<=n*m;++i)dp[i][0]=1;
	for(int i=1;i<=n;++i){
		int u=lower_bound(val,val+n*m+1,a[i])-val,sum=0;
		for(int j=0;j<=n*m;++j){
			for(int k=n;k;--k)dp[j][k]=(ll)dp[j][k-1]*inv[k]%mod;dp[j][0]=sum;sum=0;
			for(int k=n;k>=0;--k)sum=((ll)sum*L[j]+dp[j][k])%mod;
		}
		for(int j=n*m;j>=m;--j)for(int k=0;k<=n;++k)reduce(dp[j][k]-=dp[j-m][k]);
		for(int j=u;j<=n*m;++j){
			for(int k=1;k<=n;++k)dp[j][k]=0;
			dp[j][0]=dp[u][0];
		}
	}
	cout<<dp[n*m][0]<<'\n';
	return 0;
}