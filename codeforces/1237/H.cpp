// LUOGU_RID: 158002483
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
const int maxn = 4e3+5;
char a[maxn],b[maxn],oob[maxn];
i64 T,n,x,y,c0,c1,c2,ans[maxn],acnt,ps;
IV rev(i64 l){ans[++acnt]=l;reverse(a+1,a+l+1);}
bool ck(){
	c0=c1=c2=0;
	for(int i=2;i<=n;i+=2){
		(a[i]==a[i-1]?(a[i]=='1'?c1:c0):c2)++;
		(b[i]==b[i-1]?(b[i]=='1'?c1:c0):c2)--;
	}
	return!c0&&!c1&&!c2;
}
IV pre_rev(){
	i64 ca=0,cb=0,cc=0;
	for(int i=2;i<=n;i+=2){
		ca+=a[i-1]!=a[i]?a[i-1]=='0'?1:-1:0;
		cb+=b[i-1]!=b[i]?b[i-1]=='1'?1:-1:0;
	}
	int i;
	if(abs(ca)>abs(cb)){
		for(i=2;ca-cc*2!=cb;i+=2)cc+=a[i-1]!=a[i]?a[i-1]=='0'?1:-1:0;
		ps=-1;if(i>2)rev(i-2);
	}
	else{
		for(i=n-1;cb-cc*2!=ca;i-=2)cc+=b[i+1]!=b[i]?b[i]=='1'?1:-1:0;
		ps=n-i-1;reverse(b+i+2,b+n+1);
	}
}
int main(){
	// freopen("1.in","r",stdin);
	// freopen("1.out","w",stdout);
	i64 T=read();
	while(T--){
		acnt=0;scanf("%s%s",a+1,b+1);n=strlen(a+1);
		memcpy(oob+1,b+1,n+1);if(!ck()){puts("-1");continue;}
		pre_rev();
		for(int i=2;i<=n;i+=2){
			int j;
			for(j=i;a[j]!=b[n-i+1]||a[j-1]!=b[n-i+2];j+=2);
			if(j>2)rev(j-2);rev(j);if(i==ps)rev(i);
		}
		// assert(strcmp(a+1,oob+1)==0);
		printf("%lld\n",acnt);F(i,1,acnt)printf("%lld ",ans[i]);puts("");
	}
	return 0;
}