// LUOGU_RID: 159633653
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
#define cht 1000000007
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
const int maxn = 2e5+5;
i64 n,k,fa[maxn],mu[maxn],val[maxn];
IV cadd(i64&x,i64 val){x=(x+val)%cht;}
i64 find(i64 x){return fa[x]==x?x:fa[x]=find(fa[x]);}
i64 qpow(i64 n,i64 base=cht-2){
	i64 ans=1;
	while(base){
		if(base&1)ans=ans*n%cht;
		n=n*n%cht;base>>=1;
	}
	return ans;
}
int main(){
	// freopen("1.in","r",stdin);
	// freopen("1.out","w",stdout);
	n=read();k=read();mu[1]=1;
	F(i,1,n)F(j,2,n/i)mu[i*j]-=mu[i];
	i64 all=qpow(k,n),ans=0;
	FL(d,1,n)F(p,1,n/d){
		i64 v=d*p,L=(n-1)/v;
		FL(a,2,2*L)cadd(ans,qpow(k,max(d,a*v-n))*min(a-1,2*L-a+1)*mu[p]);
	}
	return cout<<(ans+cht)*qpow(all)%cht,0;
}