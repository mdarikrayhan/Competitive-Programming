#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll s[200005]; 
void solve()
{
	cin>>n;
	vector<ll> v;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		if(s[i]==0) v.push_back(i);
		s[i]+=s[i-1];
	}
	v.push_back(n+1);
	ll ans=0,i=1;
	for(auto r=v.begin();r!=v.end();r++)
	{
		map<ll,ll> mp;
		ll sum=0;
		for(;i<*r;i++)
		{
			if(r==v.begin())
			{
				if(s[i]==0) sum++;
			}
			else
			{
				mp[s[i]]++;
				sum=max(sum,mp[s[i]]);
			}
		}
		ans+=sum;
	}
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t=1; cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}