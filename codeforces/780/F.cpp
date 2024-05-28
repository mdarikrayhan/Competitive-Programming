#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e2+5;
const int inf=5e16L;
struct node
{
	int to,next,v;
}e[2*N];
struct did
{
	int x,op,val;
	bool operator<(const did &b)const{return val<b.val;}
}lzj[2*N];
int n,m,h[N],cnt,ans,d[N][N][2];
int g[N][2],kong[N],rez[N],zeq;
bitset<505>f[N][64][2];
void add(int x,int y,int z)
{
	e[++cnt].to=y;
	e[cnt].next=h[x];
	e[cnt].v=z;
	h[x]=cnt;
}
void prepare()
{
	for(int i=1;i<=n;i++)kong[i]=rez[i]=-1;
	for(int x=1;x<=n;x++)
	{
		for(int y=1;y<=n;y++)
		{
			if(d[x][y][0])f[x][0][0][y]=1;
			if(d[x][y][1])f[x][0][1][y]=1;
		}
		if(f[x][0][0].count())kong[x]=0;
		if(f[x][0][1].count())rez[x]=0;
	}
	for(int j=1;j<=60;j++)
	{
		for(int x=1;x<=n;x++)
		{
			for(int y=1;y<=n;y++)
			{
				if(!f[x][j-1][0][y])continue;
				// cout<<"aminos: "<<x<<' '<<y<<' '<<j<<' '<<0<<'\n';
				f[x][j][0]|=f[y][j-1][1];
			}
			for(int y=1;y<=n;y++)
			{
				if(!f[x][j-1][1][y])continue;
				// cout<<"aminos: "<<x<<' '<<y<<' '<<j<<' '<<1<<'\n';
				f[x][j][1]|=f[y][j-1][0];
			}
			if(f[x][j][0].count())kong[x]=j;
			if(f[x][j][1].count())rez[x]=j;
			// cout<<"dyjwcnm: "<<j<<' '<<f[x][j][0].count()<<' '<<f[x][j][1].count()<<'\n';
		}
	}
	for(int i=1;i<=n;i++)
	{
		lzj[++zeq]=(did){i,0,kong[i]};
		lzj[++zeq]=(did){i,1,rez[i]};
	}
	sort(lzj+1,lzj+1+zeq);
}
void solve()
{
	for(int x=1;x<=n;x++)
	{
		if(f[x][60][0].count())
		{
			ans=-1;
			return ;
		}
	}
	for(int i=1;i<=zeq;i++)
	{
		int x=lzj[i].x,op=lzj[i].op;
		int tmp=0;
		for(int y=1;y<=n;y++)
		{
			if(!f[x][lzj[i].val][op][y])continue;
			tmp=max(tmp,g[y][op^1]);
		}
		g[x][op]=(1ll<<lzj[i].val)+tmp;
	}
	for(int x=1;x<=n;x++)ans=max(ans,g[x][0]);
	if(ans>1e18)ans=-1;
}
signed main()
{
#ifdef LOCAL
	freopen("test.in", "r",stdin);
	freopen("test.out", "w",stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		d[x][y][z]=1;
	}
	prepare();
	solve();
	// cerr<<clock()<<'\n';
	cout<<ans<<'\n';
	return 0;
}
/*
aminos: 1 2 1 0
aminos: 2 2 1 1
aminos: 1 2 2 0
4


*/