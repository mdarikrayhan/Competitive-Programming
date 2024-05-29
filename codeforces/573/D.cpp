// LUOGU_RID: 160506965
/*
  author: honglan0301
  Sexy_goodier _ xiaoqing
 */
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cctype>
#include <queue>
#include <map>
#include <unordered_map>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cmath>
#include <random>
#include <set>
#include <bitset>
#include <assert.h>
using namespace std;

//namespace Fread{const int SIZE=1<<20;char buf[SIZE],*S,*T;inline char getchar(){if(S==T){T=(S=buf)+fread(buf,1,SIZE,stdin);if(S==T)return'\n';}return*S++;}}using namespace Fread;namespace Fwrite{const int SIZE=1<<20;char buf[SIZE],*S=buf,*T=buf+SIZE;inline void flush(){fwrite(buf,1,S-buf,stdout);S=buf;}inline void putchar(char c){*S++=c;if(S==T)flush();}struct NTR{~NTR(){flush();}}ztr;}using namespace Fwrite;
//#define getchar Fread::getchar
//#define putchar Fwrite::putchar

namespace Fastio{struct Reader{template<typename T>Reader&operator>>(T&x){x=0;short f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();x*=f;return*this;}Reader&operator>>(double&x){x=0;double t=0;short f=1,s=0;char c=getchar();while((c<'0'||c>'9')&&c!='.'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9'&&c!='.')x=x*10+(c^48),c=getchar();if(c=='.')c=getchar();else{x*=f;return*this;}while(c>='0'&&c<='9')t=t*10+(c^48),s++,c=getchar();while(s--)t/=10.0;x=(x+t)*f;return*this;}Reader&operator>>(long double&x){x=0;long double t=0;short f=1,s=0;char c=getchar();while((c<'0'||c>'9')&&c!='.'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9'&&c!='.')x=x*10+(c^48),c=getchar();if(c=='.')c=getchar();else{x*=f;return*this;}while(c>='0'&&c<='9')t=t*10+(c^48),s++,c=getchar();while(s--)t/=10.0;x=(x+t)*f;return*this;}Reader&operator>>(__float128&x){x=0;__float128 t=0;short f=1,s=0;char c=getchar();while((c<'0'||c>'9')&&c!='.'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9'&&c!='.')x=x*10+(c^48),c=getchar();if(c=='.')c=getchar();else{x*=f;return*this;}while(c>='0'&&c<='9')t=t*10+(c^48),s++,c=getchar();while(s--)t/=10.0;x=(x+t)*f;return*this;}Reader&operator>>(char&c){c=getchar();while(c==' '||c=='\n'||c=='\r')c=getchar();return*this;}Reader&operator>>(char*str){int len=0;char c=getchar();while(c==' '||c=='\n'||c=='\r')c=getchar();while(c!=' '&&c!='\n'&&c!='\r')str[len++]=c,c=getchar();str[len]='\0';return*this;}Reader&operator>>(string&str){str.clear();char c=getchar();while(c==' '||c=='\n'||c=='\r')c=getchar();while(c!=' '&&c!='\n'&&c!='\r')str.push_back(c),c=getchar();return*this;}Reader(){}}cin;const char endl='\n';struct Writer{const int Setprecision=6;typedef int mxdouble;template<typename T>Writer&operator<<(T x){if(x==0){putchar('0');return*this;}if(x<0)putchar('-'),x=-x;static short sta[40];short top=0;while(x>0)sta[++top]=x%10,x/=10;while(top>0)putchar(sta[top]+'0'),top--;return*this;}Writer&operator<<(double x){if(x<0)putchar('-'),x=-x;mxdouble _=x;x-=(double)_;static short sta[40];short top=0;while(_>0)sta[++top]=_%10,_/=10;if(top==0)putchar('0');while(top>0)putchar(sta[top]+'0'),top--;putchar('.');for(int i=0;i<Setprecision;i++)x*=10;_=x;while(_>0)sta[++top]=_%10,_/=10;for(int i=0;i<Setprecision-top;i++)putchar('0');while(top>0)putchar(sta[top]+'0'),top--;return*this;}Writer&operator<<(long double x){if(x<0)putchar('-'),x=-x;mxdouble _=x;x-=(long double)_;static short sta[40];short top=0;while(_>0)sta[++top]=_%10,_/=10;if(top==0)putchar('0');while(top>0)putchar(sta[top]+'0'),top--;putchar('.');for(int i=0;i<Setprecision;i++)x*=10;_=x;while(_>0)sta[++top]=_%10,_/=10;for(int i=0;i<Setprecision-top;i++)putchar('0');while(top>0)putchar(sta[top]+'0'),top--;return*this;}Writer&operator<<(__float128 x){if(x<0)putchar('-'),x=-x;mxdouble _=x;x-=(__float128)_;static short sta[40];short top=0;while(_>0)sta[++top]=_%10,_/=10;if(top==0)putchar('0');while(top>0)putchar(sta[top]+'0'),top--;putchar('.');for(int i=0;i<Setprecision;i++)x*=10;_=x;while(_>0)sta[++top]=_%10,_/=10;for(int i=0;i<Setprecision-top;i++)putchar('0');while(top>0)putchar(sta[top]+'0'),top--;return*this;}Writer&operator<<(char c){putchar(c);return*this;}Writer&operator<<(char*str){int cur=0;while(str[cur])putchar(str[cur++]);return*this;}Writer&operator<<(const char*str){int cur=0;while(str[cur])putchar(str[cur++]);return*this;}Writer&operator<<(string str){int st=0,ed=str.size();while(st<ed)putchar(str[st++]);return*this;}Writer(){}}cout;}using namespace Fastio;
#define cin Fastio::cin
#define cout Fastio::cout
#define endl Fastio::endl//;fflush(stdout)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define int long long
#define ll long long
#define ull unsigned long long
#define mod 998244353
#define G 3
#define Gi 332748118
mt19937 rnd(time(0));
mt19937_64 rndl(time(0));

int ksm(int x,int k) {int na=1; for(int i=1;i<=k;i<<=1) {if(i&k) na=na*x%mod; x=x*x%mod;} return na;}
int gcd(int x,int y) {return !y?x:gcd(y,x%y);}
void exgcd(int u,int v,ll &x,ll &y) {if(!v) return x=1,y=0,void(); exgcd(v,u%v,y,x); y-=u/v*x;}
void CRTmerge(ll la,ll lb,ll&na,ll&nb){ll g=gcd(la,na),x,y;exgcd(la,na,x,y);ll dd=(nb-lb)/g;x*=dd;na=la*na/g;nb=((x*la+lb)%na+na)%na;}

struct MF
{
	#define N 1
	#define NN 1
	#define M 1
	struct edge{int son,val,next;}edge[M];
	int cnt=1,head[N],nowb[N],dis[N],ff[NN],pre[NN],s,t;
	void adde(int x,int y,int z)
	{
		edge[++cnt]={y,z,head[x]}; head[x]=cnt;
		edge[++cnt]={x,0,head[y]}; head[y]=cnt;
	}
	void clear(int n)
	{
		for(int i=0;i<=cnt;i++) edge[i]={0,0,0};
		for(int i=0;i<=n;i++) head[i]=nowb[i]=dis[i]=0; cnt=1;
	}
	queue<int>Q;bool bfs(){memset(dis,127,sizeof(dis));dis[s]=0;Q.push(s);while(!Q.empty()){int nr=Q.front();Q.pop();for(int i=head[nr];i>0;i=edge[i].next){if(edge[i].val&&dis[nr]+1<dis[edge[i].son])dis[edge[i].son]=dis[nr]+1,Q.push(edge[i].son);}}return dis[t]<1000000000;}
	int bfs2(){memset(ff,0,sizeof(ff));ff[s]=1000000000;pre[s]=-1;Q.push(s);while(!Q.empty()){int nr=Q.front();Q.pop();for(int i=head[nr];i>0;i=edge[i].next){if(!ff[edge[i].son]&&edge[i].val){ff[edge[i].son]=min(edge[i].val,ff[nr]);pre[edge[i].son]=i;Q.push(edge[i].son);}}if(ff[t])break;}while(!Q.empty())Q.pop();return ff[t];}int EK(){int na=0;while(bfs2()){na+=ff[t];for(int j=pre[t];j>0;j=pre[edge[j^1].son])edge[j].val-=ff[t],edge[j^1].val+=ff[t];}return na;}
	int dfs(int x,int nfl){if(x==t)return nfl;int nuse=0;for(int i=nowb[x];i>0;i=edge[i].next){nowb[x]=i;if(edge[i].val&&dis[x]+1==dis[edge[i].son]){int flw=dfs(edge[i].son,min(edge[i].val,nfl-nuse));edge[i].val-=flw;edge[i^1].val+=flw;nuse+=flw;if(nuse==nfl)break;}}return nuse;}
	int dinic(){int maxflow=0;while(bfs()){memcpy(nowb,head,sizeof(head));maxflow+=dfs(s,1000000000);}return maxflow;}
	#undef N
	#undef NN
	#undef M
}MF;

struct MCMF
{
	#define N 1
	#define M 1
	struct edge
	{
		int son,val,fey,next;
	}edge[M];
	int head[N],cnt=1,nowb[N],dis[N],dep[N],maxflow,mincost,s,t;
	void adde(int x,int y,int z,int w)
	{
		edge[++cnt]={y,z,w,head[x]}; head[x]=cnt;
		edge[++cnt]={x,0,-w,head[y]}; head[y]=cnt;
	}
	void clear(int n)
	{
		for(int i=0;i<=cnt;i++) edge[i]={0,0,0};
		for(int i=0;i<=n;i++) head[i]=nowb[i]=dis[i]=dep[i]=0; cnt=1;
	}
	queue<int>Q;bool spfa(){memset(dis,127,sizeof(dis));dis[s]=dep[s]=0;Q.push(s);while(!Q.empty()){int nr=Q.front();Q.pop();for(int i=head[nr];i>0;i=edge[i].next){if(edge[i].val&&dis[nr]+edge[i].fey<dis[edge[i].son]){dis[edge[i].son]=dis[nr]+edge[i].fey;dep[edge[i].son]=dep[nr]+1;Q.push(edge[i].son);}}}return dis[t]<1000000000000;}int dfs(int x,int nfl){if(x==t)return mincost+=nfl*dis[t],nfl;int nuse=0;for(int i=nowb[x];i>0;i=edge[i].next){nowb[x]=i;if(edge[i].val&&dis[x]+edge[i].fey==dis[edge[i].son]&&dep[x]+1==dep[edge[i].son]){int flw=dfs(edge[i].son,min(edge[i].val,nfl-nuse));edge[i].val-=flw;edge[i^1].val+=flw;nuse+=flw;if(nuse==nfl)break;}}return nuse;}
	pair<int,int>dinic(){maxflow=mincost=0;while(spfa()){memcpy(nowb,head,sizeof(nowb));maxflow+=dfs(s,1000000000);}return mp(maxflow,mincost);}
	#undef N
	#undef M
}MCMF;

struct SA
{
	#define N 1
	#define M 135
	int s[N],rk[N],sa[N],lrk[N],buc[N],id[N],ht[N];
	void clear(int n) {memset(buc,0,sizeof(buc[0])*(n+3));}
	void build(int n){int m=M,p=0;for(int i=1;i<=n;i++)buc[rk[i]=s[i]]++;for(int i=1;i<=M;i++)buc[i]+=buc[i-1];for(int i=1;i<=n;i++)sa[buc[rk[i]]--]=i;for(int w=1;w<=n;w<<=1){for(int i=n-w+1;i<=n;i++)id[++p]=i;for(int i=1;i<=n;i++)if(sa[i]>w)id[++p]=sa[i]-w;memcpy(lrk,rk,sizeof(rk[0])*(n+3));memset(buc,0,sizeof(buc[0])*(m+3));p=0;for(int i=1;i<=n;i++)buc[lrk[i]]++;for(int i=1;i<=m;i++)buc[i]+=buc[i-1];for(int i=n;i>=1;i--)sa[buc[lrk[id[i]]]--]=id[i];for(int i=1;i<=n;i++)rk[sa[i]]=(lrk[sa[i]]==lrk[sa[i-1]]&&lrk[sa[i]+w]==lrk[sa[i-1]+w])?p:++p;m=p;p=0;if(m==n)break;}for(int i=1,k=0;i<=n;i++){k--;if(k<0)k++;while(s[i+k]==s[sa[rk[i]-1]+k])k++;ht[rk[i]]=k;}}
	#undef N
	#undef M
}SA;

struct LC
{
	#define N 1
	int n,x[N],y[N],F[N],lf[N],nf[N];
	void init(){lf[0]=1;for(int i=1;i<=n;i++){for(int j=n;j>=0;j--)lf[j]=(lf[j]*(mod-x[i])+((j>0)?lf[j-1]:0))%mod;}for(int i=1;i<=n;i++){int prd=1;for(int j=1;j<=n;j++)if(i!=j)prd=prd*(x[i]-x[j]+mod)%mod;prd=ksm(prd,mod-2);for(int j=n;j>=0;j--)nf[j]=(lf[j+1]+x[i]*nf[j+1])%mod;for(int j=0;j<=n;j++)F[j]=(F[j]+y[i]*nf[j]%mod*prd)%mod;}}
	int solve(int k){int na=0;for(int i=n;i>=0;i--)na=(na*k+F[i])%mod;return na;}
	#undef N
}LC;

struct LO
{
	struct node
	{
		int cntu,cntr,sums;
		friend node operator+(node x,node y)
		{
			node z; 
			z.cntu=(x.cntu+y.cntu)%mod; z.cntr=(x.cntr+y.cntr)%mod;
			z.sums=(x.sums+y.sums+x.cntu*y.cntr)%mod; return z;
		}
	};
	node getk() {node x; x.cntu=x.cntr=x.sums=0; return x;}
	node getr() {node x; x.cntu=x.sums=0; x.cntr=1; return x;}
	node getu() {node x; x.cntu=1; x.cntr=x.sums=0; return x;}
	node ksm(node x,int k){node na=getk();for(int i=1;i<=k;i<<=1){if(i&k)na=na+x;x=x+x;}return na;}node solve(int p,int r,int q,int x,node nu,node nr){if(!x)return getk();if(p*x+r<q)return ksm(nr,x);if(p>=q||r>=q)return ksm(nu,r/q)+solve(p%q,r%q,q,x,nu,ksm(nu,p/q)+nr);int m=(p*x+r)/q;return ksm(nr,(q-r-1)/p)+nu+solve(q,(q-r-1)%p,p,m-1,nr,nu)+ksm(nr,x-(q*m-r-1)/p);}
}LO;

struct NTT
{
	#define N 1
	int rv[N],lim,L;
	void init(int n) {lim=1,L=0; while(lim<=n) lim<<=1,L++; for(int i=0;i<lim;i++) rv[i]=(rv[i>>1]>>1)|((i&1)<<L-1);}
	void work(int x[],int flag){for(int i=0;i<lim;i++)if(i<rv[i])swap(x[i],x[rv[i]]);for(int len=1;len<lim;len<<=1){int w=ksm((flag==1)?G:Gi,(mod-1)/(len<<1));for(int j=0;j<lim;j+=(len<<1)){int nw=1;for(int k=0;k<len;k++){int xx=x[j|k],yy=nw*x[j|k|len]%mod;x[j|k]=(xx+yy)%mod;x[j|k|len]=(xx-yy+mod)%mod;nw=nw*w%mod;}}}if(flag==-1){int iv=ksm(lim,mod-2);for(int i=0;i<lim;i++)x[i]=x[i]*iv%mod;}}
	#undef N
}NTT;

struct FWT
{
	void AND(int x[],int n,int flag){for(int len=1;len<(1<<n);len<<=1){for(int j=0;j<(1<<n);j+=(len<<1)){for(int k=0;k<len;k++){if(flag==1)x[j|k]=(x[j|k]+x[j|k|len])%mod;else x[j|k]=(x[j|k]-x[j|k|len]+mod)%mod;}}}}
	void OR(int x[],int n,int flag){for(int len=1;len<(1<<n);len<<=1){for(int j=0;j<(1<<n);j+=(len<<1)){for(int k=0;k<len;k++){if(flag==1)x[j|k|len]=(x[j|k|len]+x[j|k])%mod;else x[j|k|len]=(x[j|k|len]-x[j|k]+mod)%mod;}}}}
	void XOR(int x[],int n,int flag){for(int len=1;len<(1<<n);len<<=1){for(int j=0;j<(1<<n);j+=(len<<1)){for(int k=0;k<len;k++){int xx=x[j|k],yy=x[j|k|len];x[j|k]=(xx+yy)%mod;x[j|k|len]=(xx-yy+mod)%mod;}}}if(flag==-1){int iv=ksm((1<<n),mod-2);for(int i=0;i<(1<<n);i++)x[i]=x[i]*iv%mod;}}
}FWT;

/*struct PT
{
	int x,y;
	bool operator<(const PT &rs) {return x!=rs.x?x<rs.x:y<rs.y;}
	bool operator>(const PT &rs) {return x!=rs.x?x>rs.x:y>rs.y;}
	bool operator==(const PT &rs) {return x==rs.x&&y==rs.y;}
	PT operator+(const PT &rs) {return {x+rs.x,y+rs.y};}
	PT operator-(const PT &rs) {return {x-rs.x,y-rs.y};}
}nl,stk[1];
int arg(PT xx) {return (int)xx.x*xx.x+(int)xx.y*xx.y;}
int cross(PT xx,PT yy) {return (int)xx.x*yy.y-(int)xx.y*yy.x;}
int dot(PT xx,PT yy) {return (int)xx.x*yy.x+(int)xx.y*yy.y;}*/

struct PT
{
	double x,y;
	bool operator<(const PT &rs) {return x!=rs.x?x<rs.x:y<rs.y;}
	bool operator>(const PT &rs) {return x!=rs.x?x>rs.x:y>rs.y;}
	bool operator==(const PT &rs) {return x==rs.x&&y==rs.y;}
	PT operator+(const PT &rs) {return {x+rs.x,y+rs.y};}
	PT operator-(const PT &rs) {return {x-rs.x,y-rs.y};}
	PT operator*(const double rs) {return {x*rs,y*rs};}
	PT operator/(const double rs) {return {x/rs,y/rs};}
}nl,STK[1];
double arg(PT xx) {return xx.x*xx.x+xx.y*xx.y;}
double len(PT xx) {return sqrt(arg(xx));}
double cross(PT xx,PT yy) {return xx.x*yy.y-xx.y*yy.x;}
double dot(PT xx,PT yy) {return xx.x*yy.x+xx.y*yy.y;}
double cdis(PT xx,PT yy) {return sqrt(arg(xx-yy));}
PT rotate(PT xx,double rad) {return {xx.x*cos(rad)+xx.y*sin(rad),-xx.x*sin(rad)+xx.y*cos(rad)};}

bool cmpPT(PT xx,PT yy) {return cross(xx-nl,yy-nl)!=0?cross(xx-nl,yy-nl)<0:arg(xx-nl)<arg(yy-nl);}
void init(vector<PT> &xx)
{
	sort(xx.begin(),xx.end()); 
	xx.erase(unique(xx.begin(),xx.end()),xx.end());
	int top;
	nl=xx[top=0]; sort(xx.begin()+1,xx.end(),cmpPT);
	for(auto i:xx)
	{
		while(top>=2&&cross(i-STK[top],STK[top]-STK[top-1])<=0) top--;
		STK[++top]=i;
	}
	xx.clear(); for(int i=1;i<=top;i++) xx.pb(STK[i]);
}
void init2(vector<PT> &xx)
{
	int top; nl=xx[top=0];
	for(auto i:xx)
	{
		while(top>=2&&cross(i-STK[top],STK[top]-STK[top-1])<=0) top--;
		STK[++top]=i;
	}
	xx.clear(); for(int i=1;i<=top;i++) xx.pb(STK[i]);
}
vector<PT> merge(vector<PT> xx,vector<PT> yy)
{
	vector<PT> na,nx,ny; na.pb(xx[0]+yy[0]); int L=xx.size(),R=yy.size(),cntl=0,cntr=0;
	for(int i=0;i<L;i++) nx.pb(xx[(i+1)%L]-xx[i]); for(int i=0;i<R;i++) ny.pb(yy[(i+1)%R]-yy[i]);
	while(cntl<L&&cntr<R) {int cc=cross(nx[cntl],ny[cntr]); na.pb(na.back()+((cc<0||!cc&&nx[cntl]>ny[cntr])?nx[cntl++]:ny[cntr++]));}
	while(cntl+1<L) na.pb(na.back()+nx[cntl++]);
	while(cntr+1<R) na.pb(na.back()+ny[cntr++]); return na;
}

int n,q,w[30005],h[30005],bhw[30005],bhh[30005],rkw[30005],rkh[30005],jy[30005],u,v;

bool cmpw(int x,int y) {return w[x]<w[y];}
bool cmph(int x,int y) {return h[x]<h[y];}

//int dp[30005];

struct mat
{
	int a[3][3];
	void init() {memset(a,192,sizeof(a));}
	void init2() {init(); for(int i=0;i<3;i++) a[i][i]=0;}
	friend mat operator*(mat x,mat y)
	{
		mat z; z.init();
		for(int i=0;i<3;i++) for(int j=0;j<3;j++) for(int p=0;p<3;p++) z.a[i][p]=max(z.a[i][p],x.a[i][j]+y.a[j][p]); return z;
	}
}F[30005],tree[120005];

void init(int x)
{
	F[x].init();
	F[x].a[1][0]=F[x].a[2][1]=0;
	if(x>=1&&jy[x]!=x) F[x].a[2][2]=w[x]*h[x];
	if(x>=2&&jy[x]!=x-1&&jy[x-1]!=x) F[x].a[1][2]=w[x]*h[x-1]+w[x-1]*h[x];
	if(x>=3&&jy[x]!=x-1&&jy[x-1]!=x-2&&jy[x-2]!=x) F[x].a[0][2]=max(F[x].a[0][2],w[x]*h[x-1]+w[x-1]*h[x-2]+w[x-2]*h[x]);
	if(x>=3&&jy[x]!=x-2&&jy[x-1]!=x&&jy[x-2]!=x-1) F[x].a[0][2]=max(F[x].a[0][2],w[x]*h[x-2]+w[x-1]*h[x]+w[x-2]*h[x-1]);
	if(x>=3&&jy[x]!=x-2&&jy[x-1]!=x-1&&jy[x-2]!=x) F[x].a[0][2]=max(F[x].a[0][2],w[x]*h[x-2]+w[x-1]*h[x-1]+w[x-2]*h[x]);
}

#define ls(x) (x<<1)
#define rs(x) ((x<<1)|1)
#define md(x,y) ((x+y)>>1)
#define push_up(x) tree[x]=tree[ls(x)]*tree[rs(x)]

void build(int l,int r,int p)
{
	if(l==r) return tree[p]=F[l],void(); int mid=md(l,r);
	build(l,mid,ls(p)); build(mid+1,r,rs(p)); push_up(p);
}
void cz(int l,int r,int x,int p)
{
	if(l==r) return tree[p]=F[l],void(); int mid=md(l,r);
	if(mid>=x) cz(l,mid,x,ls(p)); else cz(mid+1,r,x,rs(p)); push_up(p);
}

/*void solve()
{
	memset(dp,128,sizeof(dp)); dp[0]=0;
	for(int i=1;i<=n;i++)
	{
		if(jy[i]!=i) dp[i]=max(dp[i],dp[i-1]+w[i]*h[i]);
		if(i>=2&&jy[i]!=i-1&&jy[i-1]!=i) dp[i]=max(dp[i],dp[i-2]+w[i]*h[i-1]+w[i-1]*h[i]);
		if(i>=3&&jy[i]!=i-1&&jy[i-1]!=i-2&&jy[i-2]!=i) dp[i]=max(dp[i],dp[i-3]+w[i]*h[i-1]+w[i-1]*h[i-2]+w[i-2]*h[i]);
		if(i>=3&&jy[i-1]!=i&&jy[i-2]!=i-1&&jy[i]!=i-2) dp[i]=max(dp[i],dp[i-3]+w[i]*h[i-2]+w[i-1]*h[i]+w[i-2]*h[i-1]);
		if(i>=3&&jy[i]!=i-2&&jy[i-2]!=i&&jy[i-1]!=i-1) dp[i]=max(dp[i],dp[i-3]+w[i]*h[i-2]+w[i-1]*h[i-1]+w[i-2]*h[i]);
	}
}*/

signed main()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>w[i],bhw[i]=i;
	for(int i=1;i<=n;i++) cin>>h[i],bhh[i]=i;
	sort(bhw+1,bhw+n+1,cmpw); sort(w+1,w+n+1);
	sort(bhh+1,bhh+n+1,cmph); sort(h+1,h+n+1);
	for(int i=1;i<=n;i++) rkw[bhw[i]]=i,rkh[bhh[i]]=i;
	for(int i=1;i<=n;i++) jy[rkw[i]]=rkh[i];
	for(int i=1;i<=n;i++) init(i); build(1,n,1);
	while(q--)
	{
		cin>>u>>v;
		swap(rkh[u],rkh[v]);
		jy[rkw[u]]=rkh[u]; jy[rkw[v]]=rkh[v];
		for(int i=rkw[u];i<=min(n,rkw[u]+2);i++) init(i),cz(1,n,i,1);
		for(int i=rkw[v];i<=min(n,rkw[v]+2);i++) init(i),cz(1,n,i,1);
		//solve();
		///cout<<dp[n]<<endl;
		mat na; na.init(); na.a[0][2]=0;
		na=na*tree[1];
		cout<<na.a[0][2]<<endl;
	}
}