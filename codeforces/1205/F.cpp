// LUOGU_RID: 159737132
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
const int MAX = 1e2;
const int MAX2 = 1e4;
const int maxn = 1e2+5;
const int maxm = maxn*maxn;
i64 dp[maxn][maxm],cnt,a[maxn];
i64 S(i64 x){return x*(x+1)/2;}
IV dfs(i64 l,i64 r,i64 k,i64 d){
	i64 len=r-l+1;
	if(S(len)==k){
		F(i,l,r)a[i]=++cnt;
		reverse(a+l,a+r+1);return;
	}
	F(i,2,len-1){
		if(k<=S(i)+len-i||!dp[len-i+1][k-S(i)+1])continue;
		F(j,l,l+i-2)a[j]=++cnt;dfs(l+i-1,r,k-S(i)+1,d);reverse(a+l,a+r+1);return;
	}
	F(i,4,len){
		if(!dp[len-i+1][k-i])continue;
		for(int j=r-i+2;j<=r;j+=2)a[j]=++cnt;dfs(l,r-i+1,k-i,0);
		for(int j=r-i+3;j<=r;j+=2)a[j]=++cnt;if(i&1)swap(a[r-2],a[r]);
		return;
	}
}
IV solve(){
	i64 n=read(),k=read();
	if(!dp[n][k])return(void)(puts("NO"));
	puts("YES");cnt=0;dfs(1,n,k,0);
	F(i,1,n)printf("%lld ",a[i]);puts("");
}
int main(){
	// freopen("1.in","r",stdin);
	// freopen("1.out","w",stdout);
	F(i,0,MAX)dp[i][S(i)]=1;
	F(i,4,MAX)dp[i][i+1]=1;
	F(i,2,MAX)F(j,1,MAX2)if(dp[i][j]){
		for(int k=2;i+k-1<=MAX&&j+S(k)-1<=MAX2;k++)dp[i+k-1][j+S(k)-1]=1;
		for(int k=4;i+k-1<=MAX&&j+k<=MAX2;k++)dp[i+k-1][j+k]=1;
	}
	i64 T=read();while(T--)solve();return 0;
}