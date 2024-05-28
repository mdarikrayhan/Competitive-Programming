// LUOGU_RID: 160593113
#include<bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
namespace fastio{
    const int bufl=1<<20;
    const double base1[16]={1,1e-1,1e-2,1e-3,1e-4,1e-5,1e-6,1e-7,1e-8,1e-9,1e-10,1e-11,1e-12,1e-13,1e-14,1e-15};
    const double base2[16]={1,1e1,1e2,1e3,1e4,1e5,1e6,1e7,1e8,1e9,1e10,1e11,1e12,1e13,1e14,1e15};
    struct IN{
        FILE *IT;char ibuf[bufl],*is=ibuf,*it=ibuf;
        IN(){IT=stdin;}IN(char *a){IT=fopen(a,"r");}
        inline char getChar(){if(is==it){it=(is=ibuf)+fread(ibuf,1,bufl,IT);if(is==it)return EOF;}return *is++;}
        template<typename Temp>inline void getInt(Temp &a){a=0;int b=0,c=getChar();while(c<48||c>57)b^=(c==45),c=getChar();while(c>=48&&c<=57)a=(a<<1)+(a<<3)+c-48,c=getChar();if(b)a=-a;}
        template<typename Temp>inline void getDouble(Temp &a){a=0;int b=0,c=getChar(),d=0;__int128 e=0,f=0;while(c<48||c>57)b^=(c==45),c=getChar();while(c>=48&&c<=57)e=(e<<1)+(e<<3)+c-48,c=getChar();if(c==46){c=getChar();while(c>=48&&c<=57)d++,f=(f<<1)+(f<<3)+c-48,c=getChar();}a=e+base1[d]*f;if(b)a=-a;}
        IN& operator>>(char &a){a=getChar();return *this;}
        IN& operator>>(char *a){do{*a=getChar();}while(*a<=32);while(*a>32)*++a=getChar();*a=0;return *this;}
        IN& operator>>(string &a){char b=getChar();while(b<=32)b=getChar();while(b>32)a+=b,b=getChar();return *this;}
        IN& operator>>(int &a){getInt(a);return *this;}
        IN& operator>>(long long &a){getInt(a);return *this;}
        IN& operator>>(__int128 &a){getInt(a);return *this;}
        IN& operator>>(float &a){getDouble(a);return *this;}
        IN& operator>>(double &a){getDouble(a);return *this;}
        IN& operator>>(long double &a){getDouble(a);return *this;}
    };
    struct OUT{
        FILE *IT;char obuf[bufl],*os=obuf,*ot=obuf+bufl;int Eps;long double Acc;
        OUT(){IT=stdout,Eps=6,Acc=1e-6;}OUT(char *a){IT=fopen(a,"w"),Eps=6,Acc=1e-6;}
        inline void ChangEps(int x=6){Eps=x;}
        inline void flush(){fwrite(obuf,1,os-obuf,IT);os=obuf;}
        inline void putChar(int a){*os++=a;if(os==ot)flush();}
        template<typename Temp>inline void putInt(Temp a){if(a<0){putChar(45);a=-a;}if(a<10){putChar(a+48);return;}putInt(a/10);putChar(a%10+48);}
        template<typename Temp>inline void putLeading(Temp a,int b){if(!b)return;putLeading(a/10,b-1);putChar(a%10+48);}
        template<typename Temp>inline void putDouble(Temp a){if(a<0){putChar(45);a=-a;}__int128 b=a;putInt(b);a-=b;a*=base2[Eps];b=a+Acc;putChar(46);putLeading(b,Eps);}
        OUT& operator<<(char a){putChar(a);return *this;}
        OUT& operator<<(char *a){while(*a>32)putChar(*a++);return *this;}
        OUT& operator<<(string a){for(auto c:a)putChar(c);return *this;}
        OUT& operator<<(int a){putInt(a);return *this;}
        OUT& operator<<(long long a){putInt(a);return *this;}
        OUT& operator<<(__int128 a){putInt(a);return *this;}
        OUT& operator<<(float a){putDouble(a);return *this;}
        OUT& operator<<(double a){putDouble(a);return *this;}
        OUT& operator<<(long double a){putDouble(a);return *this;}
        ~OUT(){flush();}
    };
}
using fastio::IN;
using fastio::OUT;
IN fin;
OUT fout;
bool stt;
const int Maxn=2e5+5;
int T;
int n,q,a[Maxn],b[Maxn];
int head[Maxn],to[Maxn<<1],nxt[Maxn<<1],cnt1;
inline void add(int u,int v){
	to[++cnt1]=v;nxt[cnt1]=head[u];
	head[u]=cnt1;
}
struct node{
	int a[31];
	inline void insert(int x){
		for(int i=30;~i;i--){
			if(((x>>i)&1)&&!a[i]){a[i]=x;break;}
			if((x>>i)&1)x^=a[i];
		}
	}
	inline int query(){
		int ans=0;
		for(int i=30;~i;i--)ans=max(ans,ans^a[i]);
		return ans;
	}
	inline void clear(){for(int i=0;i<31;i++)a[i]=0;}
}g[Maxn];
inline node merge(node a,node b){
	node c=a;
	for(int i=0;i<31;i++)if(b.a[i])c.insert(b.a[i]);
	return c;
}
namespace prnx{
	node pre[Maxn],nxt[Maxn];
	inline void init(){
		for(int i=0;i<31;i++)pre[0].a[i]=nxt[n+1].a[i]=0;
		for(int i=1;i<=n;i++)pre[i]=pre[i-1],pre[i].insert(b[i]);
		for(int i=n;i;i--)nxt[i]=nxt[i+1],nxt[i].insert(b[i]);
	}
}
int dfn[Maxn],dfn1[Maxn],cnt,si[Maxn];
int f[Maxn],dep[Maxn],top[Maxn],son[Maxn];
void dfs1(int u,int v){
	dep[u]=dep[v]+1;
	f[u]=v;si[u]=1;g[u].insert(a[u]);
	for(int i=head[u];i;i=nxt[i]){
		int y=to[i];
		if(y==v)continue;
		dfs1(y,u);si[u]+=si[y];
		g[u]=merge(g[u],g[y]);
		if(si[son[u]]<si[y])son[u]=y;
	}
}
void dfs2(int u,int t){
	top[u]=t;dfn[u]=++cnt;b[cnt]=a[u];dfn1[cnt]=u;
	if(!son[u])return;
	dfs2(son[u],t);
	for(int i=head[u];i;i=nxt[i]){
		int y=to[i];
		if(y==f[u]||y==son[u])continue;
		dfs2(y,y);
	}
}
inline int k_son(int u,int v){
	while(dep[top[v]]>dep[u]+1)v=f[top[v]];
	return dfn1[dfn[v]-(dep[v]-dep[u]-1)];
}
inline void solve(){
	fin>>n;
	for(int i=1;i<=n;i++)fin>>a[i];
	cnt1=0;for(int i=0;i<=n;i++)head[i]=son[i]=0,g[i].clear();
	for(int i=1;i<n;i++){
		int u,v;fin>>u;fin>>v;
		add(u,v);add(v,u);
	}
	cnt=0;dfs1(1,0);dfs2(1,1);
	prnx::init();
	fin>>q;
	int ans=g[1].query();
	while(q--){
		int rt,u;fin>>rt;fin>>u;
		if(u==rt){
			fout<<ans<<'\n';
		}
		else{
			if(dfn[u]<dfn[rt]&&dfn[rt]<dfn[u]+si[u]){
//				printf("c:%d:%d %d %d\n",n,rt,u,k_son(u,rt));
				rt=k_son(u,rt);
				fout<<merge(prnx::pre[dfn[rt]-1],prnx::nxt[dfn[rt]+si[rt]]).query()<<'\n';
			}
			else fout<<g[u].query()<<'\n';
		}
	}
}
bool en;
int main(){
	fin>>T;
	while(T--)solve();
	cerr<<(&stt-&en)/1024.0/1024.0<<endl;
	return 0;
}