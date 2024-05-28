// LUOGU_RID: 159239933
// Problem: Morse Code
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1129C
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// Written by yinhee.

#include<bits/stdc++.h>
using namespace std;
namespace my_std{
#define mems(x,y) memset(x,y,sizeof x)
#define Mp make_pair
#define eb emplace_back
#define gc getchar
#define pc putchar
#define fi first
#define se second
#define il inline
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define drep(i,a,b) for(int i=(a);i>=(b);i--)
#define go(i,u) for(int i=head[u];i;i=e[i].nxt)
	typedef long long ll;
	typedef unsigned long long ull;
	typedef pair<int,int> pii;
	il int read(){
		int x=0,f=1;char c=gc();
		while(c<'0'||c>'9'){if(c=='-')f=-1;c=gc();}
		while(c>='0'&&c<='9')x=x*10+c-48,c=gc();
		return x*f;
	}
	il void write(int x){
		char buf[23];int len=0;
		if(x<0)pc('-'),x=-x;
		do buf[++len]=x%10,x/=10;while(x);
		while(len)pc(buf[len--]+'0');
	}
}
using namespace my_std;
const int N=3e3+7,M=1e7+7,inf=0x3f3f3f3f,mod=1e9+7;
int n,m,a[N],dp[N][N];
ull c[2],f[N],pw[N];
const ull base=19589103893ull;
mt19937 rnd(time(0));
const int d[4][4]={{0,0,1,1},{0,1,0,1},{1,1,1,0},{1,1,1,1}};
struct HashTable{
	const int mod=1e7+7;
	struct node{
		ull k;int nxt;
	}e[N*N];
	int tot,head[M];
	il void add(int u,ull x){
		e[++tot]={x,head[u]},head[u]=tot;
	}
	bool find(ull x){
		int p=x%mod;
		go(i,p){
			if(e[i].k==x){
				return 1;
			}
		}
		add(p,x);
		return 0;
	}
}H;
il int Mod(int x,int y){
	return x+y>=mod?x+y-mod:x+y;
}
il bool check(int l,int r){
	if(r-l<3){
		return 1;
	}
	rep(i,0,3){
		if(a[l]==d[i][0]&&a[l+1]==d[i][1]&&a[r-1]==d[i][2]&&a[r]==d[i][3]){
			// printf("--%d %d\n",l,r);
			return 0;
		}
	}
	return 1;
}
il ull getHash(int l,int r){
	return f[r]-f[l-1]*pw[r-l+1];
}
void Yorushika(){
	scanf("%d",&n);
	rep(i,0,1){
		c[i]=1ull*rnd()*rnd()*rnd()*rnd();
	}
	pw[0]=1;
	int ans=0;
	rep(i,1,n){
		scanf("%d",&a[i]);
		f[i]=f[i-1]*base+c[a[i]];
		pw[i]=pw[i-1]*base;
		dp[i][i-1]=1;
		rep(j,1,i){
			rep(k,0,3){
				if(i-k>=j&&check(i-k,i)){
					// printf("%d %d\n",i-k-1,dp[j][i-k-1]);
					dp[j][i]=Mod(dp[j][i],dp[j][i-k-1]);
				}
			}
			ull tmp=getHash(j,i);
			if(!H.find(tmp)){
				ans=Mod(ans,dp[j][i]);
			}
		}
		printf("%d\n",ans);
	}
}
signed main(){
	int t=1;
	//	scanf("%d",&t);
	while(t--)
		Yorushika();
}