// Hydro submission #6641fe0430edecae7438f56b@1716360948342
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MP make_pair
mt19937 rnd(time(0));
const int MAXN=2e5+5;
const int sqN=1005;
int n,m,B=500;
namespace IO{
#define getchar()(p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1<<21],*p1=buf,*p2=buf;
inline int read(){
	int re=0;char ch=getchar();
	while(ch>'9'||ch<'0') ch=getchar();
	while(ch>='0'&&ch<='9') re=10*re+ch-'0',ch=getchar();
	return re; 
}
inline void write(ll x,char div='\n'){
	if(x==0){putchar('0');putchar(div);return;} 
	static int st[60],top;top=0;
	while(x) st[++top]=x%10,x/=10;
	for(int i=top;i>=1;i--) putchar('0'+st[i]);
	putchar(div);
}
}using namespace IO;
int a[MAXN],b[MAXN],c[MAXN],oa[MAXN];bool sp[MAXN],imp[MAXN];
int op[MAXN>>2],ox[MAXN>>2],oy[MAXN>>2];ll ans[MAXN>>2];
int le[sqN],ri[sqN],bel[MAXN],tot=0;
vector<int> occ[MAXN];
vector<ll> bef[MAXN];
struct node{ll a,b,c,ab,bc,abc;};
inline node operator *(const node &x,const node &y){
	node z;
	z.a=x.a+y.a;z.b=x.b+y.b;z.c=x.c+y.c;
	z.ab=x.ab+y.ab+x.a*y.b;
	z.bc=x.bc+y.bc+x.b*y.c;
	z.abc=x.abc+y.abc+x.a*y.bc+x.ab*y.c;
	return z;
}
struct sqrt_modify_1_query{
ll a[MAXN],s[sqN];
inline void init(){memset(a,0,sizeof(a));memset(s,0,sizeof(s));}
inline void modify(const int x,const ll v){
	if(v==0) return;
	for(int i=x;i<=ri[bel[x]];i++) a[i]+=v;
	for(int i=bel[x];i<=tot;i++) s[i]+=v;
}
inline ll query(const int x){return s[bel[x]-1]+a[x];}
}B1;
struct sqrt_query_1_modify{
ll a[MAXN],s[sqN];
inline void init(){memset(a,0,sizeof(a));memset(s,0,sizeof(s));}
inline void modify(const int x,const ll v){
	a[x]+=v;s[bel[x]]+=v;
}
inline ll query(const int x){
	ll ans=0;
	for(int i=1;i<bel[x];i++) ans+=s[i];
	for(int i=le[bel[x]];i<=x;i++) ans+=a[i];
	return ans;
}
}B2;
struct one_chain{
node a[MAXN],s[sqN];
node b[MAXN],t[sqN];
inline void init(){
	memset(a,0,sizeof(a));memset(s,0,sizeof(s));
	memset(b,0,sizeof(b));memset(t,0,sizeof(t));
}
inline void upd(const int x,const node v){
	b[x]=v;
	a[x]=(x==le[bel[x]]?v:a[x-1]*v);
	for(int i=x+1;i<=ri[bel[x]];i++) a[i]=a[i-1]*b[i];
	s[bel[x]]=a[ri[bel[x]]];
	for(int i=bel[x];i<=tot;i++) t[i]=t[i-1]*s[i];
}
inline ll ask(const int x){
	return (t[bel[x]-1]*a[x]).abc;
}
}C;
inline node get(const int id,const int col){
	return (node){b[a[id]]==col,a[id]==col,c[a[id]]==col,0,0,0};
}
inline void solve_sp(){
	for(int col=1;col<=n;col++) if(sp[col]){
		memcpy(a,oa,sizeof(oa));memset(imp,0,sizeof(imp));C.init();
		for(int i:occ[col]) imp[i]=true;
		for(int i=1;i<=n;i++)if(imp[i]){
			C.upd(i,get(i,col));
		}
		for(int i=1;i<=m;i++){
			if(op[i]==1&&imp[ox[i]]){
				a[ox[i]]=oy[i];
				C.upd(ox[i],get(ox[i],col));
			}else if(op[i]==2) ans[i]+=C.ask(ox[i]);
		}
	}
}
inline void rebuild(const int col){
	if(sp[col]) return;
	node cur=(node){0,0,0,0,0,0};
	vector<ll> now(occ[col].size());
	ll lst=0;
	for(int i=0;i<(int)occ[col].size();i++){
		cur=cur*get(occ[col][i],col);
		B2.modify(occ[col][i],-bef[col][i]);
		now[i]=cur.abc-lst;lst=cur.abc;
		B2.modify(occ[col][i],now[i]);
	}
	bef[col]=now;
}
inline void solve_usp(){
	memcpy(a,oa,sizeof(oa));
	for(int i=1;i<=n;i++) rebuild(i);
	for(int i=1;i<=m;i++){
		if(op[i]==1){
			int oa=a[ox[i]];a[ox[i]]=oy[i];
			rebuild(oa);rebuild(b[oa]);rebuild(c[oa]);
			rebuild(a[ox[i]]);rebuild(b[a[ox[i]]]);rebuild(c[a[ox[i]]]);
		}else{
			ans[i]+=B2.query(ox[i]);
		}
	}
}
int main(){
	// freopen("Otomachi_Una.in","r",stdin);
	// freopen("Otomachi_Una.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read(),oa[i]=a[i];
	for(int i=1;i<=n;i++) b[i]=read();
	for(int i=1;i<=n;i++) c[i]=read();
	for(int i=1;i<=n;i++){
		occ[a[i]].push_back(i);
		occ[b[a[i]]].push_back(i);
		occ[c[a[i]]].push_back(i);
	}
	for(int i=1;i<=m;i++){
		op[i]=read();
		if(op[i]==1){
			ox[i]=read(),oy[i]=read();
			occ[oy[i]].push_back(ox[i]);
			occ[b[oy[i]]].push_back(ox[i]);
			occ[c[oy[i]]].push_back(ox[i]);
		}else ox[i]=read();
	}
	while(ri[tot]!=n){
		++tot;
		le[tot]=ri[tot-1]+1;
		ri[tot]=min(n,le[tot]+B-1);
	}
	for(int i=1;i<=tot;i++) for(int j=le[i];j<=ri[i];j++) bel[j]=i;
	for(int i=1;i<=n;i++){
		sort(occ[i].begin(),occ[i].end());
		occ[i].erase(unique(occ[i].begin(),occ[i].end()),occ[i].end());
		sp[i]=((int)occ[i].size()>=B);
		bef[i].resize(occ[i].size(),0);
	}
	solve_sp();
	solve_usp();
	for(int i=1;i<=m;i++) if(op[i]==2) write(ans[i]);
	return 0;
}