// LUOGU_RID: 159026288
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll int
#define N 45
using namespace std;
ll n,k,st[N][N];
vector<ll> vec[12];
void dfs(ll x)
{
	ll i,j,prenum=0;
	if(x==k)
	{
		ll num=0;
		bool hv1=false,hv2=false;
		for(i=0;i<n;i++)
		{
			if(st[x][i]==-1)
			{
				num++;
				if(num>1||hv1)
				{
					puts("REJECTED");
					exit(0);
				}
				hv2=true;
			}
			else if(st[x][i]==0)
			{
				if(hv1||hv2)
				{
					puts("REJECTED");
					exit(0);
				}
			}
			else
			{
				hv1=true;
			}
		}
		return;
	}
	ll num=0;
	for(i=0;i<vec[x].size();i++)
	{
		if(st[x][vec[x][i]]==-1)
		{
			num++;
		}
		else
		{
			prenum+=(st[x][vec[x][i]]==0);
		}
	}
	for(i=0;i<n;i++)
	{
		st[x+1][i]=st[x][i];
	}
	for(i=0;i<vec[x].size();i++)
	{
		st[x+1][vec[x][i]]=(i>=prenum);
	}
	for(i=0;i<=num;i++)
	{
		dfs(x+1);
		if(i<num)
		{
			st[x+1][vec[x][i+prenum]]=0;
		}
	}
	return;
}
int main(){
	ll i,j,x;
	cin>>n>>k;
	for(i=0;i<k;i++)
	{
		cin>>x;
		vec[i].resize(x);
		for(j=0;j<x;j++)
		{
			cin>>vec[i][j];
			vec[i][j]--;
		}
	}
	memset(st,-1,sizeof(st));
	dfs(0);
	puts("ACCEPTED");
	return 0;
}