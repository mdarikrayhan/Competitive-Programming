// LUOGU_RID: 158712104
#define G 3
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
const int maxn = 2e5+5;
i64 n,k,a[maxn],b[maxn],sum;
i64 jp[maxn][21],ans,pos,ct[maxn];map<i64,i64>mp;
IV pout(i64 l){
	printf("%d ",(l-1)%n);
	F(i,l,l+k-1)printf("%d ",a[(i-1)%n+1]+sum);
	puts("");
}
IV solve(i64 l,i64 r,i64 x){
	if(l==r)return;
	if(r-l+1<=k){
		F(i,l,r)if(i<=r)a[(i-1)%n+1]=(i==l?x:0);
		pout(l);return;
	}
	i64 s=0;F(i,l,l+k-1)s+=a[(i-1)%n+1];
	if(s>=x){
		F(i,l,l+k-1)a[(i-1)%n+1]=(i==l?x:(i==l+k-1?s-x:0));
		pout(l);solve(l+k-1,r,0);
	}
	else{
		solve(l+k-1,r,a[l+k-1]+x-s);
		F(i,l,l+k-1)a[(i-1)%n+1]=(i==l?x:0);pout(l);
	}
}
int main(){
	// freopen("1.in","r",stdin);
	// freopen("1.out","w",stdout);

	n=read();k=read();
	F(i,1,n)a[i]=read(),sum+=a[i];sum/=n;
	F(i,1,n)a[i]=a[i+n]=a[i]-sum;F(i,1,n*2)b[i]=b[i-1]+a[i];
	F(i,1,2*n){
		jp[i][0]=mp[b[i]*k+(i-1)%(k-1)];
		mp[b[i]*k+i%(k-1)]=i;F(j,1,17)jp[i][j]=jp[jp[i][j-1]][j-1];
	}
	ans=(n-1+k-2)/(k-1);pos=-1;
	F(i,n+1,2*n){
		i64 now=i,c=0;D(j,17,0)if(jp[now][j]>=i-n)now=jp[now][j],c+=(1<<j);
		ct[i]=(i-now-c)/(k-1)+(now-(i-n)+k-2)/(k-1);if(ct[i]<ans)ans=ct[i],pos=i;
	}
	printf("%lld\n",ans);
	if(pos==-1)solve(1,n,0);
	else{
		i64 now=pos;
		while(now>pos-n){
			i64 nw=max(jp[now][0],pos-n);
			solve(nw+1,now,0);now=nw;
		}
	}
	return 0;
}