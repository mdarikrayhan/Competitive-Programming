// LUOGU_RID: 160242888
// LUOGU_RID: 160197236
#include<bits/stdc++.h>
using namespace std;
namespace IO{
	template<typename T> inline void write(T x){
		if(x<0) putchar('-'),x=-x;
		if(x==0){
			putchar('0'); return ;
		}
		if(x>9) write(x/10);
		putchar(x%10+'0');
		return ;
	}
	template<typename T> inline void read(T &x){
		x=0; int w=1; char ch=getchar();
		while(!isdigit(ch)){
			if(ch=='-') w=-1; ch=getchar();
		}
		while(isdigit(ch))
			x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
		x*=w; return ;
	}
}
using namespace IO;
#define writesp(x) write(x),putchar(' ')
#define writeln(x) write(x),putchar('\n')
#define inf 0x3f3f3f3f
#define mod 998244353
#define N 1<<20
#define pb emplace_back
//#define int long long
#define szi sizeof(int)
#define il inline
int n,m,a[20][20],b[20][20],c[20][20],dp[1<<20];
char s[20][20];
il void cmin(int &x,int y){x=(x<y)?x:y;return ;}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	read(n),read(m);
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j) s[i][j]=getchar();
		getchar();
	}
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j) read(a[i][j]);
	memset(dp,0x3f,sizeof(dp)),dp[0]=0;
	for(int i=0;i<m;++i){
		for(int j=0;j<n;++j){
			b[j][i]=-a[j][i];
			for(int k=0;k<n;++k)
				if(s[k][i]==s[j][i]) c[j][i]|=(1<<k),b[j][i]+=a[k][i];
		}
		for(int j=0;j<n;++j)
			for(int k=0;k<n;++k)
				if(s[k][i]==s[j][i]) cmin(b[k][i],b[j][i]);
	}
	for(int S=0;S<(1<<n)-1;++S){
		for(int i=0;i<n;++i)
			if(!(S&(1<<i))){
				for(int j=0;j<m;++j)
					cmin(dp[S|(1<<i)],dp[S]+a[i][j]),cmin(dp[S|c[i][j]],dp[S]+b[i][j]);
				break;
			}
	}
	writeln(dp[(1<<n)-1]);
	return 0;
}
/*
O(nm2^n) 的 dp 很好想，考虑到 2s 巨大时限，这个是可以过的
但是可以优化到 O(n2^n)，考虑到这个 dp 的本质是在 DAG 上求最短路，一个集合可以走向它的某一个超集
由于每个集合连出去的边是一样的，考虑不连所有的边，随便选一个0位，只连可以把这位变为1的边，这样的边是 O(n) 的
这样最终一定能走到全是1的终点，且复杂度只有 O(n2^n)
*/
