// LUOGU_RID: 158013328
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
const int maxn = 2.2e3+5;
const int maxm = 1e5+5;
i64 u[maxm],v[maxm],E[maxn][maxn],mat[maxn][maxn];
i64 find(i64 x){i64 now=1;while(E[x][now])now++;return now;}
IV col(i64 x,i64 y,i64 id){
	// cout<<"add"<<x<<' '<<y<<endl;
	u[id]=x;v[id]=y;
	i64 A=find(x),B=find(y);
	E[x][A]=y;E[y][B]=x;
	mat[x][y]=A;
	if(A!=B)for(int x=y,c=B;x;x=E[x][c],c^=A^B){
		swap(E[x][A],E[x][B]);
		mat[x][E[x][A]]=A;mat[x][E[x][B]]=B;
	}
}

i64 n,m,k,w[maxn],L[maxn],R[maxn],bel[maxn],cL[maxn],cR[maxn];
int main(){
	// freopen("1.in","r",stdin);
	// freopen("1.out","w",stdout);
	n=read();m=read();k=read();
	F(i,1,n)w[i]=read();i64 c1=0,c2=n+m;
	F(i,1,n)bel[L[i]=++c1]=i,bel[R[i]=++c2]=i;
	F(i,1,m){
		i64 u=read(),v=read();
		if(cL[u]==k)cL[u]=0,bel[L[u]=++c1]=u;
		if(cR[v]==k)cR[v]=0,bel[R[v]=++c2]=v;
		cL[u]++;cR[v]++;col(L[u],R[v],i);
	}

	F(i,1,m){
		printf("%lld\n",mat[u[i]][v[i]]);
	}

	return 0;
}