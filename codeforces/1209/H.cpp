// LUOGU_RID: 159210352
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
const int maxn = 1e6+5;
const double eps = 1e-10;
map<double,double>f;double ans;
IV ins(double d,double v){
	double rem=d/(v+1);ans+=rem;
	f[v]+=rem+(v>1?d/(v-1):0);
	while(rem>eps){
		double x=f.rbegin()->first,sub=min(f[x],rem);
		f[x]-=sub,rem-=sub,ans+=sub/x;if(f[x]<eps)f.erase(x);
	}
}
i64 n,L;
int main(){
	// freopen("1.in","r",stdin);
	// freopen("1.out","w",stdout);
	n=read();L=read();double x,y,z,lst=0;
	while(n--){
		scanf("%lf%lf%lf",&x,&y,&z);
		ins(x-lst,1),ins(y-x,z+1),lst=y;
	}
	ins(L-lst,1);return printf("%.15lf",ans),0;
}