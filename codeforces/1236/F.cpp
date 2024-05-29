// LUOGU_RID: 160140366
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define mod 1000000007
#define F first
#define S second
#define ll long long
#define N 1000010
using namespace std;
ll n,m,dfn[N],lw[N],idx[N],fa[N],cnt=0,cnt2,ipw2[N],val[N],inv2=(mod+1)/2,vv1[N],vv2[N],gg[N];
vector<ll> vt[N],nt[N];
stack<ll> stk;
bool vis[N];
void dfs(ll x,ll lst)
{
	ll i;
	vis[x]=true;
	dfn[x]=lw[x]=++cnt;
	stk.push(x);
	for(i=0;i<vt[x].size();i++)
	{
		if(!vis[vt[x][i]])
		{
			dfs(vt[x][i],x);
			lw[x]=min(lw[x],lw[vt[x][i]]);
			if(lw[vt[x][i]]>=dfn[x])
			{
				while((!stk.empty())&&stk.top()!=vt[x][i])
				{
					nt[cnt2].push_back(stk.top());
					nt[stk.top()].push_back(cnt2);
					stk.pop();
				}
				nt[cnt2].push_back(stk.top());
				nt[stk.top()].push_back(cnt2);
				stk.pop();
				nt[cnt2].push_back(x);
				nt[x].push_back(cnt2++);
			}
		}
		else if(vt[x][i]!=lst)
		{
			lw[x]=min(lw[x],dfn[vt[x][i]]);
		}
	}
	return;
}
bool cmp(ll x,ll y)
{
	return dfn[x]<dfn[y];
}
void dfs1(ll x,ll lst)
{
	ll i;
	if(x>=n)
	{
		sort(nt[x].begin(),nt[x].end(),cmp);
		ll qwq;
		for(i=0;i<nt[x].size();i++)
		{
			if(nt[x][i]==lst)
			{
				qwq=i;
				break;
			}
		}
		vector<ll> nei;
		for(i=0;i<nt[x].size();i++)
		{
			nei.push_back(nt[x][(i+qwq)%nt[x].size()]);
		}
		nt[x]=nei;
		for(i=1;i<nt[x].size();i++)
		{
			idx[nt[x][i]]=i;
		}
	}
	fa[x]=lst;
	for(i=0;i<nt[x].size();i++)
	{
		if(nt[x][i]!=lst)
		{
			dfs1(nt[x][i],x);
		}
	}
	return;
}
int main(){
	ll i,j,x,y;
	ipw2[0]=1;
	for(i=1;i<N;i++)
	{
		ipw2[i]=(ipw2[i-1]*inv2)%mod;
	}
	scanf("%lld%lld",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&x,&y);
		x--,y--;
		vt[x].push_back(y);
		vt[y].push_back(x);
	}
	cnt2=n;
	dfs(0,-1);
	dfs1(0,-1);
	ll ans1=inv2,ans2=0;
	val[0]=inv2;
	for(i=1;i<n;i++)
	{
		ll hvl=idx[i]-1,hvr=nt[fa[i]].size()-idx[i];
		if(hvl==0)
		{
			val[i]=(inv2*inv2)%mod;
		}
		else
		{
			val[i]=(((inv2*inv2)%mod)*(1+mod-ipw2[hvr]))%mod;
		}
		ans1=(ans1+val[i])%mod;
	}
	ans2=(ans1*ans1+ans1)%mod;
	for(i=n;i<cnt2;i++)
	{
		for(j=1;j<nt[i].size();j++)
		{
			gg[fa[i]]=(gg[fa[i]]+val[nt[i][j]])%mod;
			if(j==1)
			{
				vv1[fa[i]]=(vv1[fa[i]]+inv2*inv2)%mod;
			}
			else
			{
				vv1[fa[i]]=(vv1[fa[i]]+((inv2*inv2)%mod)*inv2)%mod;
				vv2[fa[i]]=(vv2[fa[i]]+((inv2*inv2)%mod)*((inv2*(1+mod-ipw2[nt[i].size()-j-1]))%mod))%mod;
			}
		}
	}
	for(i=n;i<cnt2;i++)
	{
		ll sum=0,totg=0,totf=0;
		for(j=1;j<nt[i].size();j++)
		{
			ans2=(ans2+mod-((val[nt[i][j]]*totg)%mod))%mod;
			ans2=(ans2+(((1+mod-ipw2[nt[i].size()-j])*inv2)%mod)*totf)%mod;
			if(j>1)
			{
				ans2=(ans2+(1+mod-ipw2[nt[i].size()-j])*vv1[nt[i][j-1]])%mod;
				totf=(totf+vv1[nt[i][j-1]]+vv2[nt[i][j-1]])%mod;
			}
			totg=(totg+gg[nt[i][j]]*2)%mod;
			ans2=(ans2+mod-((sum*val[nt[i][j]])%mod))%mod;
			if(j>2)
			{
				ll coef=(((inv2*inv2)%mod)*inv2)%mod;
				coef=(coef*(1+mod-ipw2[nt[i].size()-j]))%mod;
				ans2=(ans2+coef*(j-3))%mod;
				ans2=(ans2+((inv2*inv2)%mod)*inv2)%mod;
			}
			sum=(sum+val[nt[i][j]]*2)%mod;
		}
		totg=0;
		ll totf1=0,totf2=0;
		for(j=nt[i].size()-1;j>0;j--)
		{
			ans2=(ans2+mod-((val[nt[i][j]]*totg)%mod))%mod;
			ans2=(ans2+inv2*totf1)%mod;
			if(j==1)
			{
				ans2=(ans2+inv2*totf2)%mod;
			}
			else
			{
				ans2=(ans2+((inv2*(1+mod-ipw2[nt[i].size()-j-1]))%mod)*totf2)%mod;
			}
			totg=(totg+gg[nt[i][j]]*2)%mod;
			totf1=(totf1+vv1[nt[i][j]])%mod;
			totf2=(totf2+vv2[nt[i][j]])%mod;
		}
	}
	for(i=0;i<n;i++)
	{
		ans2=(ans2+mod-((val[i]*val[i])%mod))%mod;
		if(fa[i]>=0)
		{
			ans2=(ans2+mod-((val[i]*val[fa[fa[i]]])%mod))%mod;
			ans2=(ans2+mod-((val[i]*val[fa[fa[i]]])%mod))%mod;
			ll hvl=idx[i]-1,hvr=nt[fa[i]].size()-idx[i]-1;
			if(hvl>0&&hvr>0)
			{
				ans2=(ans2+((val[fa[fa[i]]]*inv2)%mod)*(1+mod-ipw2[hvr]))%mod;
			}
		}
		ll sum=0,sum2=0,sum3=0;
		for(j=0;j<nt[i].size();j++)
		{
			x=nt[i][j];
			if(x==fa[i])
			{
				continue;
			}
			ll cur=0,cur2=0,cur3=0;
			for(y=1;y<nt[x].size();y++)
			{
				if(y>1)
				{
					cur3=(cur3+1+mod-ipw2[nt[x].size()-y-1])%mod;
				}
				cur2=(cur2+(y>1?inv2:1))%mod;
				cur=(cur+val[nt[x][y]])%mod;
			}
			ans2=(ans2+mod-((cur*sum*2)%mod))%mod;
			ans2=(ans2+((cur2*sum2)%mod)*((inv2*inv2)%mod))%mod;
			ans2=(ans2+((cur3*sum3)%mod)*((((inv2*inv2)%mod)*((inv2*inv2)%mod))%mod))%mod;
			sum=(sum+cur)%mod;
			sum2=(sum2+cur2)%mod;
			sum3=(sum3+cur3)%mod;
		}
	}
	ans1=(ans1*ans1)%mod;
	printf("%lld\n",(ans2+mod-ans1)%mod);
	return 0;
}