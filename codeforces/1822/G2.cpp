#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005],n,b[200005];
map<int,int> mp;
int ask(int x)
{
	if(mp.count(x))return mp[x];
	return 0;
} 
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		mp.clear();
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			b[i]=a[i];
			mp[a[i]]++;
		}
		sort(b+1,b+n+1);
		int len=unique(b+1,b+n+1)-b-1,ans=0;
		for(int i=1;i<=len;i++)
		{
			ans+=mp[b[i]]*(mp[b[i]]-1)*(mp[b[i]]-2);
			for(int j=1;j*j<=b[i]&&b[i]*j<=b[len];j++)
			{
				if(b[i]%j==0)
				{
					if(j!=1)
						ans+=ask(b[i])*ask(b[i]/j)*ask(b[i]*j);
					if(j*j!=b[i])
						ans+=ask(b[i])*ask(j)*ask(b[i]*b[i]/j);
				}
			}
		}
		cout<<ans<<endl;
	}
} 