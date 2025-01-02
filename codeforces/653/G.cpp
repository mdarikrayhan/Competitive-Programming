// LUOGU_RID: 158541605
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e5+10;
const int M=25;
const int MOD=1e9+7;

int p[N],tot,mip[N],p2[N];
bool isp[N];

int powM(int a,int b=MOD-2,int mod=MOD){
	int ans=1;
	while(b){
		if(b&1)ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return ans;
}

int fac[N],invfac[N];

void ini(){
	for(int i=2;i<N;++i){
		if(!isp[i])p[++tot]=i,mip[i]=tot;
		for(int j=1;j<=tot&&p[j]*i<N;++j){
			isp[p[j]*i]=true;
			mip[p[j]*i]=j;
			if(i%p[j]==0)break;
		}
	}
	p2[0]=1;
	for(int i=1;i<N;++i)p2[i]=2ll*p2[i-1]%MOD;
	fac[0]=1;
	for(int i=1;i<N;++i)fac[i]=1ll*fac[i-1]*i%MOD;
	invfac[N-1]=powM(fac[N-1]);
	for(int i=N-2;i>=0;--i)invfac[i]=1ll*invfac[i+1]*(i+1)%MOD;
}

int cnt[N][M],sum[M];

int C(int n,int m,int mod=MOD){
	if(n<0||m<0||n<m)return 0;
	return 1ll*fac[n]*invfac[m]%mod*invfac[n-m]%mod;
}

int a[N];

int f[N],sumc[N],sumf[N];

void llz(){
	int n;
	cin>>n;
	int mx=0;
	for(int i=1;i<=n;++i){
		int t;
		cin>>t;
		a[i]=t;
		mx=max(mx,t);
		while(t>1){
			int id=mip[t];
			int now=0;
			while(t%p[id]==0)t/=p[id],now++;
			cnt[id][now]++;
		}
	}

	sumc[0]=1;
	for(int i=1;i<=n;++i)sumc[i]=(sumc[i-1]+C(n-1,i))%MOD;
	for(int i=1;i<=n;++i){
		if(i-2>=0)f[i]=(f[i]+sumc[i-2])%MOD;
		if(i-1>=0)f[i]=(f[i]-sumc[n]+sumc[i-1])%MOD;
		if(f[i]<0)f[i]+=MOD;
		sumf[i]=(sumf[i-1]+f[i])%MOD;
	}
	//for(int i=1;i<=n;++i)cout<<sumf[i]<<"\n";
	int ans=0;
	for(int i=1;i<=tot&&p[i]<=mx;++i){
		int lim=log(mx)/log(p[i])+2;
		int res=0;
		for(int j=1;j<=lim;++j)res+=cnt[i][j];
		if(res==0)continue;
		cnt[i][0]=n-res,sum[0]=cnt[i][0];
		for(int j=1;j<=lim;++j)sum[j]=(sum[j-1]+cnt[i][j]);
		for(int j=1;j<=lim;++j){
			ans=(ans+1ll*j*(sumf[sum[j]]-sumf[sum[j-1]])%MOD)%MOD;
		}
	}
	if(ans<0)ans+=MOD;
	cout<<ans<<"\n";
}

signed main(){
	iostream::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T=1;
	ini();
	while(T--)llz();
	return 0;
}
