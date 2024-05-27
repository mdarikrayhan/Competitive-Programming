// LUOGU_RID: 160485854
#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long
#define mod 998244353
#define N 500005
using namespace std;

int n,m,k;
int l[N],r[N],x[N],a[N],f[N],pos[N];

signed main(){
	scanf("%lld%lld%lld",&n,&k,&m);
	for(int i=1;i<=m;i++) scanf("%lld%lld%lld",&l[i],&r[i],&x[i]);
	int ans=1;
	for(int d=0;d<k;d++){
		memset(a,0,sizeof(a));
		memset(f,0,sizeof(f));
		memset(pos,0,sizeof(pos));
		for(int i=1;i<=m;i++){
			if((x[i]>>d)&1) a[l[i]]++,a[r[i]+1]--;
			else pos[r[i]+1]=max(pos[r[i]+1],l[i]);
		}
		for(int i=1;i<=n+1;i++) a[i]+=a[i-1],pos[i]=max(pos[i],pos[i-1]);
		f[0]=1;
		int sum=1,p=0;
		for(int i=1;i<=n+1;i++){
			while(p<pos[i]) (sum+=mod-f[p])%=mod,f[p]=0,p++;
			f[i]=a[i]?0:sum;
			(sum+=f[i])%=mod;
		}
		(ans*=f[n+1])%=mod;
	}
	printf("%lld\n",ans);

	return 0;
}