// LUOGU_RID: 160422985
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
const int N =3e5+5,M=3e6+5,inf=(1LL<<30)-1,mod=998244853;
const ll llf=1e18;
inline void add(int &a,int b){((a+=b)>=mod) and (a-=mod);}
inline int Add(int a,int b){return add(a,b),a;}
inline int mul(int a,int b){return 1LL*a*b%mod;}
inline void Mul(int &a,int b){a=mul(a,b);}
inline void red(int &a,int b){add(a,mod-b);}
inline int Red(int a,int b){return red(a,b),a;}
inline int qp(int a,int b){if(!b)return 1;int c=qp(a,b>>1);Mul(c,c);if(b&1)Mul(c,a);return c;}
inline int INV(int x){return qp(x,mod-2);}
int n,h[N],to[N<<1],nxt[N<<1],cnt,tot,c[N],f[N],sn[N],siz[N];
string s;
inline void add_(int a,int b){
	to[++cnt]=b,nxt[cnt]=h[a],h[a]=cnt;
}
int son[M][26],dep[N];
inline void dfs(int x,int fa){
	f[x]=fa,siz[x]=1;
	e(x)if(y^fa)dfs(y,x),siz[x]+=siz[y],sn[x]=siz[y]>siz[sn[x]]?y:sn[x];
}
inline void clr(int x){
	memset(son[x],0,sizeof(son[x]));
}
inline void insert(int now,int x){
	int k=s[x]-'a';
	if(!son[now][k])son[now][k]=++tot;
	now=son[now][k];
	e(x)if(y^f[x])insert(now,y);
}
int Mx,ct;
inline void clear(){
	while(tot>n)clr(tot),tot--;
}
inline void Dfs(int x){
	if(!sn[x]){
		insert(x,x);
		int W=1+c[x];
		if(W>Mx)Mx=W,ct=1;
		else if(Mx==W)ct++;
		return;
	}
	e(x)if(y^f[x]&&y^sn[x])Dfs(y),clear();
	Dfs(sn[x]);
	son[x][s[x]-'a']=++tot;
	int nw=tot;
	son[nw][s[sn[x]]-'a']=son[sn[x]][s[sn[x]]-'a'];
	e(x)if(y^f[x]&&y^sn[x])insert(nw,y);
	int W=c[x]+tot-n;
	if(W>Mx)Mx=W,ct=1;
	else if(Mx==W)ct++;
}
inline void Main(){
	n=read(),tot=n;	
	repn(i)c[i]=read();
	cin>>s,s='#'+s;
	rep(i,2,n){
		int x=read(),y=read();
		add_(x,y),add_(y,x);
	}
	dfs(1,0),Dfs(1);
	cout <<Mx<<"\n"<<ct;
} 
signed main(){
	int T=1;
	while(T--)Main();
	return 0;
}