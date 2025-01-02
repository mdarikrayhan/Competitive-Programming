//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 400010
using namespace std;
struct BIT{
	ll val[N];
	void upd(ll x,ll v)
	{
		++x;
		while(x<N)
		{
			val[x]+=v;
			x+=x&(-x);
		}
		return;
	}
	ll qry(ll x)
	{
		ll ret=0;
		++x;
		while(x)
		{
			ret+=val[x];
			x-=x&(-x);
		}
		return ret;
	}
}bit;
ll n,q,col[N],fa[N],dep[N],din[N],dout[N],dfn[N],f[18][N],cnt,dinid[N],doutid[N],dcnt;
vector<ll> vt[N];
void dfs(ll x,ll lst)
{
	ll i;
	fa[x]=lst;
	dfn[x]=++cnt;
	f[0][cnt]=lst;
	din[x]=++dcnt;
	dinid[dcnt]=x;
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i]!=lst)
		{
			dep[vt[x][i]]=dep[x]+1;
			dfs(vt[x][i],x);
		}
	}
	dout[x]=++dcnt;
	doutid[dcnt]=x;
	return;
}
bool check(ll x,ll y)
{
	return bit.qry(din[y])-(x==0?0:bit.qry(din[fa[x]]))==dep[y]-dep[x]+1;
}
ll glca(ll x,ll y)
{
	if(x==y)
	{
		return x;
	}
	x=dfn[x],y=dfn[y];
	if(x>y)
	{
		swap(x,y);
	}
	ll lg=31^__builtin_clz((int)(y-x));
	return dfn[f[lg][x+1]]<dfn[f[lg][y-(1<<lg)+1]]?f[lg][x+1]:f[lg][y-(1<<lg)+1];
}
int main(){
	ll T,i,j,x,y;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld%lld",&n,&q);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&col[i]);
			vt[i].clear();
		}
		for(i=1;i<n;i++)
		{
			scanf("%lld%lld",&x,&y);
			x--,y--;
			vt[x].push_back(y);
			vt[y].push_back(x);
		}
		dcnt=cnt=0;
		dep[0]=0;
		dfs(0,-1);
		for(i=1;i<18;i++)
		{
			for(j=2;j+(1<<i)-1<=n;j++)
			{
				f[i][j]=dfn[f[i-1][j]]<dfn[f[i-1][j+(1<<(i-1))]]?f[i-1][j]:f[i-1][j+(1<<(i-1))];
			}
		}
		set<ll> curin,curout;
		for(i=0;i<=n*2;i++)
		{
			bit.val[i]=0;
		}
		for(i=0;i<n;i++)
		{
			if(col[i])
			{
				bit.upd(din[i],1);
				bit.upd(dout[i]+1,-1);
				curin.insert(din[i]);
				curout.insert(dout[i]);
			}
		}
		while(q--)
		{
			scanf("%lld",&x);
			x--;
			if(col[x])
			{
				bit.upd(din[x],-1);
				bit.upd(dout[x]+1,1);
				curin.erase(din[x]);
				curout.erase(dout[x]);
			}
			col[x]^=1;
			if(col[x])
			{
				bit.upd(din[x],1);
				bit.upd(dout[x]+1,-1);
				curin.insert(din[x]);
				curout.insert(dout[x]);
			}
			if(curin.empty())
			{
				puts("No");
				continue;
			}
			ll v1=dinid[*curin.begin()],v2=doutid[*curout.begin()],v3=dinid[*prev(curin.end())];
			if(v2==v3)
			{
				puts(din[v1]<=din[v2]&&dout[v2]<=dout[v1]&&check(v1,v2)&&dep[v2]-dep[v1]+1==curin.size()?"Yes":"No");
				continue;
			}
			if(v1==glca(v2,v3)&&check(v1,v2)&&check(v1,v3)&&dep[v2]+dep[v3]-dep[v1]*2+1==curin.size())
			{
				puts("Yes");
			}
			else
			{
				puts("No");
			}
		}
	}
	return 0;
}