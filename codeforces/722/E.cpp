// LUOGU_RID: 160240750
#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long
#define mod 1000000007
using namespace std;

int n,m,k,s;
int inv[200005];
int fac[200005];
int infac[200005];
int f[2005][25];
pair <int,int> a[2005];

inline void in(int &n){
	n=0;
	char c=getchar();
	while(c<'0' || c>'9') c=getchar();
	while(c>='0'&&c<='9') n=n*10+c-'0',c=getchar();
	return ;
}

inline int calc(int x,int k){
	int tmp=1;
	while(k){
		if(k&1) tmp=tmp*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return tmp;
}

inline int C(int a,int b){return a<b||b<0?0:fac[a]*infac[b]%mod*infac[a-b]%mod;}

inline int S(int i,int j){
	if(a[i].first>a[j].first||a[i].second>a[j].second) return 0;
	int x=a[j].first-a[i].first,y=a[j].second-a[i].second;
	return C(x+y,x);
}

signed main(){
	in(n),in(m),in(k),in(s);
	for(int i=1;i<=k;i++) in(a[i].first),in(a[i].second);
	fac[0]=fac[1]=infac[0]=infac[1]=inv[1]=1;
	for(int i=2;i<=n+m;i++){
		inv[i]=(mod-mod/i)*inv[mod%i]%mod;
		fac[i]=fac[i-1]*i%mod;
		infac[i]=infac[i-1]*inv[i]%mod;
	}
	sort(a+1,a+1+k);
	if(a[1].first+a[1].second!=2) a[++k]={1,1},s*=2;
	if(a[k].first+a[k].second!=n+m) a[++k]={n,m};
	else s=(s+1)/2;
	sort(a+1,a+1+k);
	f[1][0]=1;
	for(int i=2;i<=k;i++){
		f[i][1]=S(1,i);
		for(int x=2;x<=22;x++){
			for(int j=1;j<i;j++)
				f[i][x]=(f[i][x]+(f[j][x-1]-f[j][x]+mod)*S(j,i)%mod)%mod;
		}
	}
	int ans=0;
	for(int i=1;i<=22;i++){
		s-=s/2;
		(ans+=(f[k][i]-f[k][i+1]+mod)*s)%=mod;
	}
	printf("%lld\n",ans*calc(C(n+m-2,n-1),mod-2)%mod);

	return 0;
}