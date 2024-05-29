// LUOGU_RID: 159226009
#include<bits/stdc++.h>
using namespace std;
namespace fast_IO{
    #define FASTIO
    #define IOSIZE 1000000
    char ibuf[IOSIZE],obuf[IOSIZE];char*p1=ibuf,*p2=ibuf,*p3=obuf;
    #ifdef ONLINE_JUDGE
    #define getchar()((p1==p2)and(p2=(p1=ibuf)+fread(ibuf,1,IOSIZE,stdin),p1==p2)?(EOF):(*p1++))
    #define putchar(x)((p3==obuf+IOSIZE)&&(fwrite(obuf,p3-obuf,1,stdout),p3=obuf),*p3++=x)
    #endif
    #define isdigit(ch)(ch>47&&ch<58)
    #define isspace(ch)(ch<33)
    template<typename T>inline T read(){T s=0;int w=1;char ch;while(ch=getchar(),!isdigit(ch)and(ch!=EOF))if(ch=='-')w=-1;if(ch==EOF)return false;while(isdigit(ch))s=s*10+ch-48,ch=getchar();return s*w;}template<typename T>inline bool read(T&s){s=0;int w=1;char ch;while(ch=getchar(),!isdigit(ch)and(ch!=EOF))if(ch=='-')w=-1;if(ch==EOF)return false;while(isdigit(ch))s=s*10+ch-48,ch=getchar();return s*=w,true;}inline bool read(char&s){while(s=getchar(),isspace(s));return true;}inline bool read(char*s){char ch;while(ch=getchar(),isspace(ch));if(ch==EOF)return false;while(!isspace(ch))*s++=ch,ch=getchar();*s='\000';return true;}template<typename T>inline void print(T x){if(x<0)putchar('-'),x=-x;if(x>9)print(x/10);putchar(x%10+48);}inline void print(char x){putchar(x);}inline void print(char*x){while(*x)putchar(*x++);}inline void print(const char*x){for(int i=0;x[i];i++)putchar(x[i]);}
    #ifdef _GLIBCXX_STRING
    inline bool read(std::string&s){s="";char ch;while(ch=getchar(),isspace(ch));if(ch==EOF)return false;while(!isspace(ch))s+=ch,ch=getchar();return true;}inline void print(std::string x){for(int i=0,n=x.size();i<n;i++)putchar(x[i]);}
    #endif
    template<typename T,typename...T1>inline int read(T&a,T1&...other){return read(a)+read(other...);}template<typename T,typename...T1>inline void print(T a,T1...other){print(a);print(other...);}struct Fast_IO{~Fast_IO(){fwrite(obuf,p3-obuf,1,stdout);}}io;template<typename T>Fast_IO&operator>>(Fast_IO&io,T&b){return read(b),io;}template<typename T>Fast_IO&operator<<(Fast_IO&io,T b){return print(b),io;}
}using namespace fast_IO;
#define cin io
#define cout io
#define endl '\n'
//
const int maxn=4e5+10;
const int SQ=460+10;
int n,q,N,B;
int l,r;
int a[maxn];
struct Array{
	int val,flg;
}s[maxn*25];
int len,pos[maxn];
struct Edge{
	int v,next;
}edge[maxn<<1];
int head[maxn],tot;
void add_edge(int u,int v){
	edge[++tot].v=v;
	edge[tot].next=head[u];
	head[u]=tot;
}
int fa[maxn],son[maxn],sz[maxn];
int dfn[maxn],in[maxn],out[maxn];
void dfs1(int u,int f){
	fa[u]=f;
	sz[u]=1;
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].v;
		if(v==fa[u])continue ;
		dfs1(v,u);
		if(sz[v]>sz[son[u]])son[u]=v;
		sz[u]+=sz[v];
	}
}
void dfs2(int u){
	dfn[++dfn[0]]=u;
	in[u]=dfn[0];
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].v;
		if(v==fa[u]||v==son[u])continue ;
		dfs2(v);
	}
	if(son[u])dfs2(son[u]);
	out[u]=dfn[0];
}
void dsu(int u,int clear){ //树上重链启发式合并优化莫队 
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].v;
		if(v==fa[u]||v==son[u])continue ;
		dsu(v,1);
	}
	if(son[u])dsu(son[u],0);
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].v;
		if(v==fa[u]||v==son[u])continue ;
		for(int j=in[v];j<=out[v];j++){
			s[++len]={a[dfn[j]],1};
		}
	}
	s[++len]={a[u],1};
	pos[u]=len;
	if(clear)for(int i=in[u];i<=out[u];i++)s[++len]={a[dfn[i]],-1};
}
int st[maxn],ed[maxn],bel[maxn*25],res;
int t[maxn],cnt[SQ][maxn]; //cnt块内出现次数的出现次数 
int modecnt[SQ]; //块内众数出现次数 
int ans[maxn];
struct Query{
	int l,r,id;
	inline bool operator < (const Query &it)const{
		if(bel[l]!=bel[it.l])return l<it.l;
		else return bel[l]&1?r<it.r:r>it.r;
	}
}qry[maxn];
void init(){
	B=4500;
	for(int i=1;i<=len;i++)bel[i]=(i-1)/B+1;
	sort(qry+1,qry+1+q);
	B=450,tot=ceil(1.0*N/B);
	for(int i=1;i<=tot;i++){
		st[i]=(i-1)*B+1;
		ed[i]=min(N,i*B);
		for(int j=st[i];j<=ed[i];j++){
			bel[j]=i;
		}
	}
}
void add(int x){
	int id=bel[x];
	cnt[id][t[x]]--;
	t[x]++;
	cnt[id][t[x]]++;
	modecnt[id]=max(modecnt[id],t[x]);
}
void del(int x){
	int id=bel[x];
	if(t[x]==modecnt[id]&&cnt[id][t[x]]==1)modecnt[id]--;
	cnt[id][t[x]]--;
	t[x]--;
	cnt[id][t[x]]++;
}
int ask(){
	int mx=-1,id=0;
	for(int i=1;i<=tot;i++){
		if(modecnt[i]>mx){
			mx=modecnt[i];
			id=i;
		}
	}
	for(int i=st[id];i<=ed[id];i++){
		if(t[i]==mx)return i;
	}
}
void update(Array x){
	if(x.flg==1)add(x.val);
	else del(x.val);
}
void solve(){
	l=r=0;
	for(int i=1;i<=q;i++){
		while(l<qry[i].l)update(s[++l]);
		while(r<qry[i].r)update(s[++r]);
		while(l>qry[i].l)update({s[l].val,-s[l].flg}),l--;
		while(r>qry[i].r)update({s[r].val,-s[r].flg}),r--;
		ans[qry[i].id]=ask();
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],N=max(N,a[i]);
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		add_edge(u,v);
		add_edge(v,u);
	}
	dfs1(1,0);
	dfs2(1);
	dsu(1,0);
	cin>>q;
	for(int i=1;i<=q;i++){
		int u,v;
		cin>>u>>v;
		if(pos[v]>pos[u])swap(u,v);
		qry[i]={pos[u],pos[v],i};
	}
	init(); 
	solve();
	for(int i=1;i<=q;i++)cout<<ans[i]<<'\n';

	return 0;
}
//饺子皮是圆皮
