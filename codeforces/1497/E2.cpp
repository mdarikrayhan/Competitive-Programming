// LUOGU_RID: 160407579
#include<bits/stdc++.h>
#define ll long long
#define L x<<1
#define R L|1
#define mid (l+r>>1)
#define lc L,l,mid
#define rc R,mid+1,r
#define OK y^fa&&!vis[y]
#define Root 1,1,n
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define repn(x) rep(x,1,n)
#define repm(x) rep(x,1,m)
#define pb push_back
#define e(x) for(int i=h[x],y=to[i];i;i=nxt[i],y=to[i])
#define E(x) for(auto y:p[x])
#define Pi pair<int,int>
#define ui unsigned ll
inline int read(){int s=0,w=1;char c=getchar();while(c<48||c>57) {if(c=='-') w=-1;c=getchar();}while(c>=48&&c<=57)s=(s<<1)+(s<<3)+c-48,c=getchar();return s*w;}
inline void pf(ll x){if(x<0) putchar('-'),x=-x;if(x>9)pf(x/10);putchar(x%10+48);}
using namespace std;
const int N =2e5+5,M=1e7+5,inf=(1LL<<30)-1,mod=998244853;
const ll llf=1e18;
inline void add(int &a,int b){((a+=b)>=mod) and (a-=mod);}
inline int Add(int a,int b){return add(a,b),a;}
inline int mul(int a,int b){return 1LL*a*b%mod;}
inline void Mul(int &a,int b){a=mul(a,b);}
inline void red(int &a,int b){add(a,mod-b);}
inline int Red(int a,int b){return red(a,b),a;}
inline int qp(int a,int b){if(!b)return 1;int c=qp(a,b>>1);Mul(c,c);if(b&1)Mul(c,a);return c;}
inline int INV(int x){return qp(x,mod-2);}
int n,k,a[N];
bool vis[M];
int p[N],pre[M],cnt;
inline void prep(){
	pre[1]=1;
	rep(i,2,M-5){
		if(!vis[i])pre[i]=i,p[++cnt]=i;
		for(int j=1;j<=cnt&&p[j]*i<=M-5;j++){
			vis[p[j]*i]=1,pre[p[j]*i]=p[j];
			if(i%p[j]==0)break;
		}
	}
}
int c[M],f[N][21],dp[N][21];
inline void Main(){
	n=read(),k=read();
	repn(i){
		int nw=read();
		a[i]=1;
		while(nw>1){
			int k=pre[nw];
			while(nw%(k*k)==0)nw/=k*k;
			if(pre[nw]==k)nw/=k,a[i]*=k;
		}
	}
	int Ll=1,nk=0;
	rep(lim,0,k){
		Ll=1,nk=0;
		repn(i){
			if(c[a[i]])nk++;
			c[a[i]]++;
			while(nk>lim){
				if(c[a[Ll]]>1)nk--;
				c[a[Ll]]--,Ll++;
			}
			f[i][lim]=Ll; 
		}
		repn(i)c[a[i]]=0;
	}
	repn(i)rep(j,0,k)dp[i][j]=inf;
	repn(i){
		rep(j,0,k){
			rep(del,0,j)dp[i][j]=min(dp[i][j],dp[f[i][del]-1][j-del]+1);
		}	
	}
	cout <<dp[n][k]<<'\n';
} 
signed main(){
	prep();
	int T=read();
	while(T--)Main();
	return 0;
}