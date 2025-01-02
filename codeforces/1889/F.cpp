#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ch() getchar()
#define pc(x) putchar(x)
using namespace std;
template<typename T>void read(T&x){
	static char c;static int f;
	for(f=1,c=ch();c<'0'||c>'9';c=ch())if(c=='-')f=-f;
	for(x=0;c>='0'&&c<='9';c=ch()){x=x*10+(c&15);}x*=f;
}
template<typename T>void write(T x){
	static char q[64];int cnt=0;
	if(x==0)return pc('0'),void();
	if(x<0)pc('-'),x=-x;
	while(x)q[cnt++]=x%10+'0',x/=10;
	while(cnt--)pc(q[cnt]);
}
long long gcd(long long a,long long b){
	if(b==0)return a;
	return gcd(b,a%b);
}
struct Frac{
	long long a;
	int b;// a/b
	Frac(long long a=0,int b=1):
		a(a),b(b){}
	bool operator < (const Frac o)const{
		return a*o.b<o.a*b;
	}
	bool operator > (const Frac o)const{
		return a*o.b>o.a*b;
	}
	bool operator == (const Frac o)const{
		return a*o.b==o.a*b;
	}
	void output(){
		printf("%lld/%d",a,b);
	}
};
const int inf=0x3f3f3f3f;
struct Val{
	int p1,p2;Frac v1,v2;
	Val(int p1=inf,int p2=inf,Frac v1=Frac(),Frac v2=Frac()):
		p1(p1),p2(p2),v1(v1),v2(v2){}
	void output(void){
		printf("%d : ",p1);v1.output();puts("");
		printf("%d : ",p2);v2.output();puts("\n");
	}
};
Val Comb(Val A,Val B){
	if(A.p1>B.p1)swap(A,B);
	if(B.v1==A.v1)
		return Val(A.p1,A.p2<B.p2?A.p2:B.p2,A.v1,A.p2<B.p2?A.v2:B.v2);
	return Val(A.p1,A.p2<B.p1?A.p2:B.p1,A.v1,A.p2<B.p1?A.v2:B.v1);
}
const int maxn=10005,maxk=505;
struct Edge{
	int v,nt;
	Edge(int v=0,int nt=0):
		v(v),nt(nt){}
}e[maxn*2];
int hd[maxn],num;
void qwq(int u,int v){
	e[++num]=Edge(v,hd[u]),hd[u]=num;
}
long long sm[maxn];int sz[maxn];
int dp[maxn][maxk],wp[maxn][maxk],k,n;
Val va[maxn][maxk];
void Merge(int x,int l,int r,int L,int R){
	wp[x][0]=0;
	va[x][0]=Comb(va[l][0],va[r][0]);
	L=min(L,k);R=min(R,k);
	int up=min(L+R,k);
	for(int i=1;i<=up;++i){
		int t=wp[x][i]=min(L,i),cl=inf,cr=inf;
		while(t>0&&i-t<R){
			cl=min(cl,dp[l][t]);--t;
			cr=min(cr,dp[r][i-t]);
			if(cr<cl)wp[x][i]=t,cl=cr=inf;
		}
		t=wp[x][i-1];cl=cr=inf;
		if(wp[x][i-1]<wp[x][i]){
			while(t<wp[x][i])cl=min(cl,dp[l][++t]);
			dp[x][i]=cl;
		}
		else{
			while(i-t-1<i-wp[x][i])cr=min(cr,dp[r][i-(t--)]);
			dp[x][i]=cr;
		}
		va[x][i]=Comb(va[l][wp[x][i]],va[r][i-wp[x][i]]);
	}
}
int MN[maxn],rsz[maxn];
long long val[maxn];
void dfs(int u,int p){
	int l=0,fa=0;sm[u]=val[u];
	sz[u]=0;rsz[u]=1;MN[u]=0;
	for(int i=hd[u];i;i=e[i].nt){
		int v=e[i].v;
		if(v==p){fa=i;continue;}dfs(v,u);
		Merge(i,i^1,l,sz[v],sz[u]);
		sm[u]+=sm[v],sz[u]+=sz[v];
		rsz[u]+=rsz[v];
		l=i;
	}
	if(sz[u]==0){
		++sz[u];MN[u]=1;
		va[fa][0]=va[fa][1]=Val(u,inf,val[u]);
		dp[fa][1]=inf;
	}
	else{
		int up=min(sz[u],k);
		for(int i=0;i<=up;++i)
			va[fa][i]=Comb(va[l][i],Val(u,inf,val[u])),dp[fa][i]=dp[l][i];
		Frac tmp(sm[u],rsz[u]);
		for(int i=1;i<=up;++i)
			if(va[fa][i].v1>tmp||(va[fa][i].v1==tmp&&va[fa][i].v2>tmp))
				va[fa][i]=Val(va[fa][i].p1,inf,tmp),MN[u]=i;
		if(MN[u]){
			if(va[fa][0].v1==va[fa][1].v1)
				dp[fa][1]=va[fa][0].p2;
			else
				dp[fa][1]=va[fa][0].p1;
			for(int i=2;i<=MN[u];++i)
				dp[fa][i]=inf;
			if(MN[u]<up){
				if(va[fa][MN[u]].v1==va[fa][MN[u]+1].v1)
					dp[fa][MN[u]+1]=va[fa][MN[u]+1].p2;
				else
					dp[fa][MN[u]+1]=va[fa][MN[u]+1].p1;
			}
		}
	}/*
	int up=min(sz[u],k);
	printf("%d MN:%d\n",u,MN[u]);
	for(int i=1;i<=up;++i)
		printf("dp %d = %d\n",i,dp[fa][i]);*/
}
int st[maxn],ts;
int que[maxn],cnt;
void solve(int u,int p,int sk){
	if(sk==0)return;sk=min(sk,sz[u]);
	if(sk<=MN[u])return st[++ts]=u,void();
	int tnc=cnt;
	for(int i=hd[u];i;i=e[i].nt){
		int v=e[i].v;
		if(v==p)continue;
		que[cnt++]=i;
	}
	for(int j=cnt-1;j>=tnc;--j){
		int i=que[j];
		solve(e[i].v,u,wp[i][sk]);
		sk-=wp[i][sk];
	}
}
void imple(void){
	int r;
	read(n),read(r),read(k);
	for(int i=1;i<=n;++i)
		read(val[i]);
	qwq(r,0);
	for(int i=1;i<n;++i){
		int u,v;read(u),read(v);
		qwq(u,v);qwq(v,u);
	}
	dfs(r,0);
	solve(r,0,k);
	printf("%d\n",ts);
	for(int i=1;i<=ts;++i)
		printf("%d%c",st[i]," \n"[i==ts]);
	for(int i=0;i<=n;++i)hd[i]=0;
	num=cnt=ts=0;
}
int main(){
	// freopen("test","r",stdin);
	int T;read(T);
	while(T--)imple();
	return 0;
}