#include<bits/stdc++.h>
using namespace std;
#define ll long long int


void solve(int tc)
{
	ll n;
	scanf("%lld",&n);
	vector<ll> v(n);
	ll sum=0;
	map<ll,ll> mp;
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&v[i]);
		sum+=v[i];
		mp[v[i]]++;
	}
	priority_queue<ll> pq;
	pq.push(sum);
	if(n==1)
	{
		printf("YES\n");
		return;
	}
	for(int i=0;i<n-1;i++)
	{
		ll curr=pq.top();
		pq.pop();
		ll a1=curr/2;
		ll a2=a1;
		if(curr%2==1)
			a2++;
		if(mp[a1]==0 && mp[a2]==0)
		{
			pq.push(a1);
			pq.push(a2);
		}
		else if(a1==a2 && mp[a1]>1)
		{
			mp[a1]--;
			mp[a2]--;
		}
		else if(a1!=a2 && mp[a1]>0 && mp[a2]>0)
		{
			mp[a1]--;
			mp[a2]--;
		}
		else if(mp[a2]>0)
		{
			mp[a2]--;
			pq.push(a1);
		}
		else if(mp[a1]>0)
		{
			mp[a1]--;
			pq.push(a2);
		}	
	}
	if(pq.size()==0)
		printf("YES\n");
	else
		printf("NO\n");
	return;
}
/*
16 18 16 22 26 22
*/

int main()
{
	int tc=1;
	scanf("%d",&tc);
	for(int i=1;i<=tc;i++)
	{
		solve(tc);
	}
	return 0;
}
