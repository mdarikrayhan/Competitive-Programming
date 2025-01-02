// Hydro submission #6640f1f630edecae74384619@1715568785281
#include <bits/stdc++.h>
using namespace std;
#define N 205
#define ll long long
#define pb push_back
const int up=200,INF=1e9;
int n,m,dp0[N],dp[N][N][N];ll ans,mx[N];struct Node {int op,x,y;}a[N];vector<int> e1[N],e2[N];
struct Node1 {int x,y;bool operator < (Node1 t) const {return x==t.x?y<t.y:x<t.x;}}dp1[N][N*N];
void W(auto &x,auto y) {x=max(x,y);}
void slv()
{
	for(int i=1,t;i<=n;++i)
	{
		auto [op,x,y]=a[i];for(int j=0;j<=up;++j) fill(dp[i][j],dp[i][j]+up+1,-INF);
		for(auto j:e2[i])
		{
			if(op==1)
			{
				for(int k=0;k<=up;++k)
				{
					for(int l=0;l<=up;++l) t=dp[j][k][l]+x*y,W(dp[i][max(k,x)][l],t);
					for(int l=0;l<=up-x;++l) t=dp[j][k][0]+(x+l)*y,W(dp[i][max(k,x+l)][l],t);
					W(ans,mx[i]+dp[j][k][0]);
				}for(int k=0;k<=up-x;++k) W(dp[i][x+k][k],dp0[j]+(x+k)*y);W(ans,mx[i]+dp0[j]);
			}
			else if(op==2) for(int k=0;k<=up;++k) for(int l=x;l<=up;++l)
				W(dp[i][k][l-x],dp[j][k][l]);
			else if(op==3) for(int k=0;k<=up;++k) for(int l=0;l<=up;++l)
				W(dp[i][k][l],dp[j][k][l]+x*k);
			else for(int k=0;k<=up;++k) for(int l=0;l<=up;++l) W(dp[i][k][l],dp[j][k][l]+x);
		}
	}
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i)
	{scanf("%d",&a[i].op);if(a[i].op) scanf("%d",&a[i].x);if(a[i].op==1) scanf("%d",&a[i].y);}
	a[n].op=1;for(int i=1,u,v;i<=m;++i) scanf("%d %d",&u,&v),e1[u].pb(v),e2[v].pb(u);
	for(int i=1;i<=n;++i) {auto [op,x,y]=a[i];x*=op==4;for(auto j:e2[i]) W(dp0[i],dp0[j]+x);}
	for(int i=n;i;--i)
	{
		auto [op,x,y]=a[i];fill(dp1[i],dp1[i]+n*up+1,(Node1) {-INF,-INF});
		dp1[n][0]=(Node1) {0,0};
		for(auto j:e1[i])
		{
			if(op==1) for(int k=0;k<=n*up;++k)
			{
				dp1[i][k]=max(dp1[i][k],(Node1) {dp1[j][k].x,dp1[j][k].y+x*y});
				if(dp1[j][k].x>=0) W(mx[i],1ll*INF*(x+k)*(y+dp1[j][k].x)+dp1[j][k].y);
			}else if(op==2) for(int k=x;k<=n*up;++k) dp1[i][k]=max(dp1[i][k],dp1[j][k-x]);
			else if(op==3) for(int k=0;k<=n*up;++k)
				dp1[i][k]=max(dp1[i][k],(Node1) {dp1[j][k].x+x,dp1[j][k].y});
			else for(int k=0;k<=n*up;++k)
				dp1[i][k]=max(dp1[i][k],(Node1) {dp1[j][k].x,dp1[j][k].y+x});
		}
	}slv();
	for(int i=1;i<=n;++i) 
	{if(a[i].op==1) swap(a[i].x,a[i].y);if(a[i].op==2 || a[i].op==3) a[i].op^=1;}
	slv();printf("%lld\n",ans);return 0;
}