// LUOGU_RID: 158230910
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
#define mod 1000000007
#define F first
#define S second
#define ll long long
#define N 1000010
using namespace std;
ll n,a[N],cyc[5],ans;
bool vis[N];
ll calc()
{
	ll i,ret=INF;
	for(i=0;i<=cyc[4];i++)
	{
		ll c1=cyc[1]+i,c2=cyc[2]+(cyc[4]-i)*2,cur=cyc[4];
		cur+=min(c1,c2);
		if(c1>c2)
		{
			cur+=(c1-c2)/3*2;
		}
		else if(c2>c1)
		{
			cur+=c2-c1;
		}
		ret=min(ret,cur);
	}
	return ret;
}
void dfs(ll lft,ll pre)
{
	if(lft==0)
	{
		ans=min(ans,calc()+pre);
		return;
	}
	//merge 1,1
	if(cyc[1]>=2)
	{
		cyc[1]-=2;
		dfs(lft-1,pre+1);
		cyc[1]+=2;
	}
	//use 2
	if(cyc[2]>0)
	{
		cyc[2]--;
		dfs(lft-1,pre);
		cyc[2]++;
	}
	//break 3 -> 1,2
	if(cyc[3]>0)
	{
		cyc[3]--,cyc[1]++;
		dfs(lft-1,pre+1);
		cyc[3]++,cyc[1]--;
	}
	//break 4 -> 2,2
	if(cyc[4]>0)
	{
		cyc[4]--,cyc[2]++;
		dfs(lft-1,pre+1);
		cyc[4]++,cyc[2]--;
	}
	//break 4 -> 1,3 , merge 1,1
	if(cyc[4]>0&&cyc[1]>0)
	{
		cyc[4]--,cyc[3]++,cyc[1]--;
		dfs(lft-1,pre+2);
		cyc[4]++,cyc[3]--,cyc[1]++;
	}
	if(lft==2)
	{
		//use 4
		if(cyc[4]>0)
		{
			cyc[4]--;
			dfs(lft-2,pre);
			cyc[4]++;
		}
		//merge 2,2
		if(cyc[2]>1)
		{
			cyc[2]-=2;
			dfs(lft-2,pre+1);
			cyc[2]+=2;
		}
		//merge 1,3
		if(cyc[1]>0&&cyc[3]>0)
		{
			cyc[1]--,cyc[3]--;
			dfs(lft-2,pre+1);
			cyc[1]++,cyc[3]++;
		}
	}
	return;
}
int main(){
	ll T,i,j;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			a[i]--;
			vis[i]=false;
		}
		memset(cyc,0,sizeof(cyc));
		ll pre=0;
		for(i=0;i<n;i++)
		{
			if(vis[i])
			{
				continue;
			}
			ll len=0;
			for(j=i;!vis[j];j=a[j])
			{
				vis[j]=true;
				len++;
			}
			while(len>4)
			{
				pre++;
				len-=3;
			}
			cyc[len]++;
		}
		ans=INF;
		ll res=1,req=0;
		if(n%3==0)
		{
			for(i=0;i<n/3;i++)
			{
				res=(res*3)%mod;
			}
		}
		else if(n%3==1)
		{
			res=4;
			for(i=0;i<n/3-1;i++)
			{
				res=(res*3)%mod;
			}
			req=2;
		}
		else
		{
			res=2;
			for(i=0;i<n/3;i++)
			{
				res=(res*3)%mod;
			}
			req=1;
		}
		dfs(req,pre);
		printf("%lld %lld\n",res,ans);
	}
	return 0;
}