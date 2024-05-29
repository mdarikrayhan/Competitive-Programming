// LUOGU_RID: 160508664
//饺子皮是圆皮
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
}
#define cin fast_IO::io
#define cout fast_IO::io
#define endl '\n'
//
const int maxn=1e5+10;
const int SQ=500+10;
int n,q,ans;
int t[maxn];
struct Edge{
	int v,next;
}edge[maxn];
int head[maxn],etot;
void add_edge(int u,int v){
	edge[++etot].v=v;
	edge[etot].next=head[u];
	head[u]=etot;
}
int fa[maxn],son[maxn],dep[maxn],sz[maxn];
int top[maxn],dfn[maxn],pos[maxn];
void dfs1(int u){
	sz[u]=1;
	dep[u]=dep[fa[u]]+1;
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].v;
		dfs1(v);
		if(sz[v]>sz[son[u]])son[u]=v;
		sz[u]+=sz[v];
	}
}
void dfs2(int u,int topf){
	top[u]=topf;
	dfn[u]=++dfn[0];
	pos[dfn[0]]=u;
	if(son[u])dfs2(son[u],topf);
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].v;
		if(v==son[u])continue ;
		dfs2(v,v);
	}
}
//
int B,tot;
int st[maxn],ed[maxn],bel[maxn],cnt[SQ][maxn],s[maxn],tag[maxn],col[maxn];
void init(){
	B=450,tot=ceil(1.0*n/B);
	for(int i=1;i<=tot;i++){
		st[i]=(i-1)*B+1;
		ed[i]=min(n,i*B);
		for(int j=st[i];j<=ed[i];j++){
			bel[j]=i;
		}
	}
}
void update(int id,int l,int r,int k){ //散块暴力改
	for(int i=l;i<=r;i++){
		if(!col[i]&&s[i]>=n+1-tag[id])ans--;
		if(!col[i])cnt[id][s[i]]--;
		s[i]+=k;
		if(!col[i]&&s[i]>=n+1-tag[id])ans++;
		if(!col[i])cnt[id][s[i]]++;
	}
}
void update(int l,int r,int k){
	int idl=bel[l],idr=bel[r];
	if(idl==idr){
		update(idl,l,r,k);
		return ;
	}
	update(idl,l,ed[idl],k);
	update(idr,st[idr],r,k);
	for(int i=idl+1;i<=idr-1;i++){
		if(k==1)tag[i]++,ans+=cnt[i][n+1-tag[i]];
		else ans-=cnt[i][n+1-tag[i]],tag[i]--;
	}
}
void change(int x,int k){
	col[x]^=1;
	if(s[x]>=n+1-tag[bel[x]])ans+=k;
	cnt[bel[x]][s[x]]+=k;
}
//
void update(int x,int k){
	while(top[x]){
		update(dfn[top[x]],dfn[x],k);
		x=fa[top[x]];
	}
}
int main(){
	cin>>n>>q;
	for(int i=2;i<=n;i++){
		cin>>fa[i];
		add_edge(fa[i],i);
	}
	dfs1(1);
	dfs2(1,1);
	init();
	for(int i=1;i<=n;i++){
		cin>>t[i];
		s[dfn[i]]=n-t[i];
		
	}
	for(int i=1;i<=n;i++){
		cnt[bel[i]][s[i]]++;
	}
	for(int i=1;i<=q;i++){
		int k;
		cin>>k;
		change(dfn[abs(k)],-k/abs(k));
		if(k>0){
			update(k,1);
		}else{
			update(-k,-1);
		}
		cout<<ans<<' ';
	}
	
	return 0;
}