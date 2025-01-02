// LUOGU_RID: 159529139
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+3;
const int MOD=1e9+7;

int fac[N],invfac[N];

int powM(int a,int b=MOD-2,int mod=MOD){
	int ans=1;
	while(b){
		if(b&1)ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return ans;
}

int p[N],g[N][22],tot,mip[N];
bool isp[N];

void ini(){
	int n=1e6;
	fac[0]=1;
	for(int i=1;i<=n;++i)fac[i]=1ll*fac[i-1]*i%MOD;
	invfac[n]=powM(fac[n]);
 	for(int i=n-1;i>=0;--i)invfac[i]=1ll*invfac[i+1]*(i+1)%MOD;

 	for(int i=2;i<N;++i){
 		if(!isp[i])p[++tot]=i,mip[i]=i;
 		for(int j=1;j<=tot&&p[j]*i<N;++j){
 			isp[p[j]*i]=true;
 			if(i%p[j]==0){
 				mip[i*p[j]]=mip[i];
 				break;
 			}
 			mip[i*p[j]]=p[j];
 		}
 	}

 	for(int j=1;j<=20;++j)g[0][j]=2;
 	for(int i=0;i<=n;++i)g[i][0]=1;
 	for(int i=1;i<=n;++i){
 		for(int j=1;j<=20;++j)g[i][j]=(g[i][j-1]+g[i-1][j])%MOD;
 	}
}	

int C(int n,int m,int mod=MOD){
	if(n<0||m<0||n<m)return 0;
	return 1ll*fac[n]*invfac[n-m]%mod*invfac[m]%mod;
}

void llz(){
	int r,n;
	cin>>r>>n;
	int ans=1;
	while(n>1){
		int t=mip[n];
		int cnt=0;
		while(n%t==0)n/=t,cnt++;
		ans=1ll*ans*g[r][cnt]%MOD;
	}
	cout<<ans<<"\n";
}

signed main(){
	iostream::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T=1;
	ini();
	cin>>T;
	while(T--)llz();
	return 0;
}