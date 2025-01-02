#include<bits/stdc++.h>
using namespace std;
#define N 200005
#define F(i,l,r) for(int i=(l);i<=(r);++i)
#define D(i,r,l) for(int i=(r);i>=(l);--i)
#define MEM(x,a) memset(x,a,sizeof(x))
int I() {char c=getchar(); int x=0; int f=1; while(c<'0' or c>'9') f=(c=='-')?-1:1,c=getchar(); while(c>='0' and c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar(); return ((f==1)?x:-x);}
#define vi vector<int> 
#define pb push_back 
#define sz(a) (int)(a.size()) 
#define all(a) a.begin(),a.end() 
#define pii pair<int,int> 
#define fi first 
#define se second 
#define lg2 __builtin_ctz
#define pct __builtin_popcount

int n,m,q,a[N]; int sn;
struct qq{int l,r,id;}qu[N];
bool operator<(qq a,qq b){return a.l/sn<b.l/sn or (a.l/sn==b.l/sn and a.r<b.r);}

int pr[N];bool np[N];
vi pfac[N];
int dpos[N],di[N],dtot; int g[1<<13][700];
int rec[N],p1[N],p2[N],rmid,rtot;
void init()
{
	int n=20000,&c=pr[0]=0; np[1]=1;
	F(i,2,n)
	{
		if(!np[i]) pr[++c]=i;
		for(int j=1;j<=c&&i*pr[j]<=n;++j){int u=pr[j];np[i*u]=1;if(i%u==0)break;}
	}
	// F(i,1,20) printf("%d ",pr[i]); puts("");
	F(i,1,c)F(j,1,n/pr[i])pfac[j*pr[i]].pb(i);

	F(i,1,m)dpos[i]=m/(m-i+1);dtot=unique(dpos+1,dpos+m+1)-dpos-1;
	F(i,1,dtot)di[dpos[i]]=i;
	// F(i,1,dtot) printf("%d ",dpos[i]); puts("");
	
	F(_,1,dtot)g[0][_]=dpos[_];
	F(s,1,(1<<13)-1)F(_,1,dtot)
	{
		int i=lg2(s&(-s));
		g[s][_]=-g[s^(1<<i)][_]/pr[i+1];
	}
	F(i,0,12)F(s,0,(1<<13)-1)if((s>>i)&1)F(_,1,dtot)g[s][_]+=g[s^(1<<i)][_];

	rtot=rmid=0;
	F(i,14,c)rec[++rtot]=pr[i],p1[rtot]=i; rmid=rtot;
	F(i,14,c)F(j,i+1,c)if(pr[i]<=m/pr[j])rec[++rtot]=pr[i]*pr[j],p1[rtot]=i,p2[rtot]=j;
}
int ans[N];
int vis[N];
void add(int p){for(auto x:pfac[a[p]])++vis[x];}
void del(int p){for(auto x:pfac[a[p]])--vis[x];}
void flandre()
{
	n=I();I();m=I();q=I();
	F(i,1,n)a[i]=I();
	F(i,1,q)qu[i].l=I(),qu[i].r=I(),qu[i].id=i;
	init();
	sn=sqrt(n)+1; sort(qu+1,qu+q+1);
	
	MEM(vis,0);
	int cl=1,cr=0;
	F(_,1,q)
	{
		int l=qu[_].l,r=qu[_].r;
		while(cr<r)add(++cr);
		while(cr>r)del(cr--);
		while(cl<l)del(cl++);
		while(cl>l)add(--cl);

		// F(i,1,pr[0])if(vis[i]) printf("%d ",pr[i]); puts("");

		int A=0; F(i,1,13)if(vis[i])A|=(1<<(i-1));

		int cur=g[A][di[m]];
		// printf("ans0=%d\n",cur);
		F(i,1,rmid)if(vis[p1[i]])cur-=g[A][di[m/rec[i]]];
		F(i,rmid+1,rtot)if(vis[p1[i]] and vis[p2[i]])cur+=g[A][di[m/rec[i]]];
		ans[qu[_].id]=cur;
	}

	F(i,1,q) printf("%d\n",ans[i]);
}
int main()
{
	int t=1;
	while(t-->0){flandre();}
	return 0;
}