#include <iostream>
#include <cstring> 
#include <map>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
// #include <map>
// #include <bits/stdc++.h>

// #define int long long
#define For(i,a,b) for(int i=(a);i<=(b);i++)
#define Rof(i,a,b) for(int i=(a);i>=(b);i--)
#define Grf(it,u,to) for(int it=he[u],to;(to=e[it],it);it=nxt[it]) 
#define In __inline 
#define OP operator
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
namespace Mine {
	// mt19937_64 wql(514);
	In ll read() {
		ll x=1,a=0;
		char ch=getchar();
		while(ch>'9' || ch<'0') x=(ch=='-')?-1:x,ch=getchar();
		while(ch>='0' && ch<='9') a=(a<<1)+(a<<3)+(ch-'0'),ch=getchar();
		return a*x;
	} const int N=2005; char L[N],R[N];int n,lenl,lenr,f[N][N*10],sum[N*10][N];
	int son[N*10][10],idx=1,fail[N*10];bool ok[N][N*10];
	void dfs(int p,int d,bool ld,bool lu) { 
		if(!ld&&!lu) return sum[p][lenr-d+1]++,void();
		if(d==lenr+1) return sum[p][0]++,void();
		int ql=ld?L[d]-'0':0,qr=lu?R[d]-'0':9; For(i,ql,qr) {
			if(p==1 && i==0) {dfs(1,d+1,ld&&(i==ql),lu&&(i==qr));continue;}
			int &to=son[p][i]; if(!to) to=++idx;
			dfs(to,d+1,ld&&(i==ql),lu&&(i==qr));
		}
	} signed main() {
		scanf("%s%s",L+1,R+1);n=read(); lenl=strlen(L+1),lenr=strlen(R+1);
		if(lenl<lenr) { Rof(i,lenr,lenr-lenl+1) L[i]=L[i-lenr+lenl];
			For(i,1,lenr-lenl) {L[i]='0';}lenl=lenr;
		} dfs(1,1,1,1);  For(i,0,9) son[0][i]=1;
		fail[1]=0; queue<int> q; q.push(1); while(q.size()) { int u=q.front();q.pop();
			For(i,0,9) if(son[u][i]) {
					fail[son[u][i]]=son[fail[u]][i]; int to=son[u][i];q.push(to);
					For(j,0,n) sum[to][j]+=sum[fail[to]][j];
				} else son[u][i]=son[fail[u]][i];
		} For(i,1,idx) For(j,1,n) sum[i][j]+=sum[i][j-1];
		memset(f,0xcf,sizeof f); f[0][1]=0; For(i,0,n-1) {
			For(j,1,idx) if(f[i][j]>=0) For(c,0,9) {
				int tmp,&to=f[i+1][son[j][c]]; if((tmp=f[i][j]+sum[son[j][c]][n-i-1])>to) to=tmp;
			}
		} int ans=0; For(i,1,idx) ans=max(ans,f[n][i]);
		printf("%d\n",ans); For(i,1,idx) if(ans==f[n][i]) ok[n][i]=1;
		Rof(i,n-1,0) For(j,1,idx) For(c,0,9) {
			if(f[i][j]+sum[son[j][c]][n-i-1]==f[i+1][son[j][c]]) ok[i][j]|=ok[i+1][son[j][c]];
		} int p=1; For(i,1,n) For(c,0,9) if(ok[i][son[p][c]] && f[i][son[p][c]]==f[i-1][p]+sum[son[p][c]][n-i]){
			p=son[p][c]; putchar(c+'0');break;
		}return 0;
	}
}signed main() {
	// freopen("homework.in","r",stdin);
	// freopen("homework.out","w",stdout);
	return Mine::main();
}
 		  	 						 		 		      	  			