// LUOGU_RID: 160061985
#include<bits/stdc++.h>
#define ll long long
#define int ll
#define L x<<1
#define R L|1
#define mid (l+r>>1)
#define lc L,l,mid
#define rc R,mid+1,r
#define OK Ll<=l&&r<=Rr
#define Root 1,1,n
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define repn(x) rep(x,1,n)
#define repm(x) rep(x,0,m-1)
#define pb push_back
#define e(x) for(int i=h[x],y=to[i];i;i=nxt[i],y=to[i])
#define E(x) for(auto y:p[x])
#define Pi pair<int,int>
#define ui unsigned ll
inline int read(){int s=0,w=1;char c=getchar();while(c<48||c>57) {if(c=='-') w=-1;c=getchar();}while(c>=48&&c<=57)s=(s<<1)+(s<<3)+c-48,c=getchar();return s*w;}
inline void pf(ll x){if(x<0) putchar('-'),x=-x;if(x>9)pf(x/10);putchar(x%10+48);}
using namespace std;
const int N =1e5+5,M=2e6+5,inf=(1LL<<30)-1,mod=998244853;
const ll llf=1e18;
inline void add(int &a,int b){((a+=b)>=mod) and (a-=mod);}
inline int Add(int a,int b){return add(a,b),a;}
inline int mul(int a,int b){return 1LL*a*b%mod;}
inline void Mul(int &a,int b){a=mul(a,b);}
inline void red(int &a,int b){add(a,mod-b);}
inline int Red(int a,int b){return red(a,b),a;}
inline int qp(int a,int b){if(!b)return 1;int c=qp(a,b>>1);Mul(c,c);if(b&1)Mul(c,a);return c;}
inline int INV(int x){return qp(x,mod-2);}
vector<int>a[N],lsh[N],b[N];
int n,m,h[N*3],to[M],nxt[M],cnt,tot,rd[N*3];
inline void add_(int a,int b){
	to[++cnt]=b,nxt[cnt]=h[a],h[a]=cnt,rd[b]++;
}
int t[N*10],p[N];

inline bool cmp(int a,int b){
	return t[a]>t[b];
}
int ln[N];
inline int id(int x,int y){//第x 
	return n*m+(x-1)*m+y;
}
inline int Id(int x,int y){
	return y+1;
}
int Time;
inline void bfs(){
	queue<int>q;
	rep(i,1,n*m*2)if(!rd[i])q.push(i);
	while(!q.empty()){
		int x=q.front();q.pop();
		t[x]=++Time;
		e(x)if(!--rd[y])q.push(y);
	}
}
map<int,int>P[N];
inline void Main(){
	n=read(),m=read();
	repn(i)a[i].resize(m),lsh[i].resize(m),b[i].resize(m);
	repn(i)repm(j)lsh[i][j]=a[i][j]=read();
	repm(i)p[i+1]=i+1;
	repn(i)sort(lsh[i].begin(),lsh[i].end()),ln[i]=-1;
	repn(i)lsh[i].resize(m+1);
	repn(i)repm(j)if(lsh[i][j]^lsh[i][j+1]&&lsh[i][j]!=-1)b[i][++ln[i]]=lsh[i][j];
	repn(i)rep(j,0,ln[i]){
		P[i][b[i][j]]=j+1;
	}
	repn(i){
		repm(j){
		if(a[i][j]!=-1){
			a[i][j]=P[i][a[i][j]];
			if(a[i][j]>1)add_(j+1,id(i,a[i][j]-1));
			add_(id(i,a[i][j]),j+1);
		}
	}
	}
	
	bfs();
	sort(p+1,p+m+1,cmp);
	if(!t[p[m]])return puts("-1"),void();
	repm(i)cout <<p[i+1]<<' ';
} 
signed main(){
	int T=1;
	while(T--)Main();
	return 0;
}