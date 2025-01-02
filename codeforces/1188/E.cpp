// LUOGU_RID: 159800657
// LUOGU_RID: 159711809
#include<map>
#include<set>
#include<ctime>
#include<cmath>
#include<queue>
#include<bitset>
#include<cstdio>
#include<vector>
#include<random>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
#define I ll
#define her1 20081214
#define IV void
#define cht 998244353
#define ld long double
#define Aestas16 392699
#define ull unsigned long long
#define cp(x,y)memcpy(x,y,sizeof y)
#define mem(x,val)memset(x,val,sizeof x)
#define D(i,j,n)for(register int i=j;i>=n;i--)
#define E(i,now)for(register int i=first[now];i;i=e[i].nxt)
#define F(i,j,n)for(register int i=j;i<=n;i++)
#define DL(i,j,n)for(register i64 i=j;i>=n;i--)
#define EL(i,now)for(register i64 i=first[now];i;i=e[i].nxt)
#define FL(i,j,n)for(register i64 i=j;i<=n;i++)
//#define D(i,j,n)for(int i=j;i>=n;i--)
//#define E(i,now)for(int i=first[now];i;i=e[i].nxt)
//#define F(i,j,n)for(int i=j;i<=n;i++)
//#define DL(i,j,n)for(register ll i=j;i>=n;i--)
//#define EL(i,now)for(register ll i=first[now];i;i=e[i].nxt)
//#define FL(i,j,n)for(register ll i=j;i<=n;i++)
ll read(){
	ll ans=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')ans=ans*10+c-'0',c=getchar();
	return ans*f;
}
#undef ll
#include "assert.h"
mt19937_64 rnd(her1);
#include "functional"
using i64 = long long;
const int MAX = 1e6;
const int maxn = 1e6+5;
IV cadd(i64&x,i64 val){x=(x+val)%cht;}
i64 n,a[maxn],fac[maxn],ifac[maxn],Sum[maxn];
i64 qpow(i64 n,i64 base=cht-2){
	i64 ans=1;
	while(base){
		if(base&1)ans=ans*n%cht;
		n=n*n%cht;base>>=1;
	}
	return ans;
}
i64 C(i64 n,i64 m){
	if(n<m||n<0||m<0)return 0;
	return fac[n]*ifac[m]%cht*ifac[n-m]%cht;
}
IV init(){
	fac[0]=1;F(i,1,MAX)fac[i]=fac[i-1]*i%cht;
	ifac[MAX]=qpow(fac[MAX]);D(i,MAX-1,0)ifac[i]=ifac[i+1]*(i+1)%cht;
}
i64 cnt[maxn];
int main(){
	// freopen("1.in","r",stdin);
	// freopen("1.out","w",stdout);
	n=read();i64 sum=0,Ans=0,Mn=1e18;init();
	F(i,1,n)a[i]=read();sort(a+1,a+1+n);
	FL(i,1,n)if(a[i]<i-1)Mn=min(Mn,i-2);
	if(Mn!=1e18){
		i64 now=0;
		F(v,0,Mn){
			while(now<n&&a[now+1]<v)
				now++;
			i64 c=v-now;
			cadd(Ans,C(c+n-1,n-1));
		}
		return cout<<Ans,0;
	}
	F(i,1,n)sum+=a[i],a[i]%=n;
	F(i,1,n)cnt[a[i]]++;i64 R=sum;F(i,1,n)R-=a[i];
	D(d,n-1,0){
		R+=(cnt[d]-1)*n;
		if(R<0||d>Mn)continue;
		cadd(Ans,C(R/n+n-1,n-1));
	}
	return cout<<Ans,0;
}