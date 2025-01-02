// LUOGU_RID: 158287318
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
#define N 1000010
using namespace std;
ll n,b,p,q,m,val[40],tplc[40],tva[40],coef[40],ans=0,cnt=0,tottms=1,precoef[40];
bool vis[N];
vector<ll> ad[40],sum[40],plcs[40];
map<ll,ll> tid;
ll calc(ll x)
{
	ll i,ret=0;
	for(i=0;i<=m;i++)
	{
		if(x==0)
		{
			ret+=ad[i].size();
			continue;
		}
		if(coef[i])
		{
			ll pos=lower_bound(ad[i].begin(),ad[i].end(),(x+coef[i]-1)/coef[i])-ad[i].begin();
			ret+=ad[i].size()-pos;
		}
	}
	return ret;
}
ll recalc(ll lft)
{
	ll l=0,r=LINF,i,curtms=1,preret=0;
	for(i=m;i>=0;i--)
	{
		if(vis[tplc[i]])
		{
			curtms*=val[i];
		}
	}
	for(i=m;i>=0;i--)
	{
		if(ad[i].size())
		{
			preret+=(curtms-precoef[i])*sum[i][ad[i].size()-1];
		}
		coef[i]=tottms-curtms;
		if(!vis[tplc[i]])
		{
			curtms*=val[i];
		}
	}
	while(l<r)
	{
		ll mid=(l+r)>>1;
		if(calc(mid)*p<=lft)
		{
			r=mid;
		}
		else
		{
			l=mid+1;
		}
	}
	ll canlft=lft/p-calc(l),ret=0;
	for(i=0;i<=m;i++)
	{
		if(coef[i]&&ad[i].size())
		{
			ll hi=lower_bound(ad[i].begin(),ad[i].end(),(l+coef[i]-1)/coef[i])-ad[i].begin();
			ll lo=lower_bound(ad[i].begin(),ad[i].end(),(l-1+coef[i]-1)/coef[i])-ad[i].begin();
			ll pos=max(lo,hi-canlft);
			canlft-=(hi-pos);
			ret+=(sum[i][ad[i].size()-1]-(pos==0?0:sum[i][pos-1]))*coef[i];
		}
	}
	return ret+preret;
}
void dfs(ll x,ll pre)
{
	if(pre*q>b)
	{
		return;
	}
	if(x==cnt)
	{
		ans=max(ans,recalc(b-pre*q));
		return;
	}
	ll i;
	dfs(x+1,pre);
	for(i=0;i<plcs[x].size();i++)
	{
		vis[plcs[x][i]]=true;
		dfs(x+1,pre+i+1);
	}
	for(i=0;i<plcs[x].size();i++)
	{
		vis[plcs[x][i]]=false;
	}
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	ll i,j,x,preans=1;
	cin>>n>>b>>p>>q;
	val[0]=1;
	for(i=0,j=0;i<n;i++)
	{
		char c;
		cin>>c>>x;
		if(c=='+')
		{
			preans+=x;
			ad[j].push_back(x);
		}
		else if(x>1)
		{
			tottms*=x;
			preans*=x;
			val[++j]=x;
			tplc[j]=i;
			if(!tid.count(x))
			{
				tva[cnt]=x;
				tid[x]=cnt++;
			}
			plcs[tid[x]].push_back(i);
		}
	}
	m=j;
	precoef[m]=1;
	for(i=m-1;i>=0;i--)
	{
		precoef[i]=precoef[i+1]*val[i+1];
	}
	for(i=0;i<=m;i++)
	{
		sort(ad[i].begin(),ad[i].end());
		for(j=0;j<ad[i].size();j++)
		{
			sum[i].push_back(sum[i].empty()?ad[i][j]:sum[i][sum[i].size()-1]+ad[i][j]);
		}
	}
	dfs(0,0);
	cout<<preans+ans<<endl;
	return 0;
}