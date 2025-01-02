#include<bits/stdc++.h>
#define int long long
using namespace std;
int32_t main()
{
	int t;
	cin >> t;
	while (t--)
	{
		long long n,ans=1;
		string s;
                cin>>n;
		vector<long long>v(n+1),vis(n+1);
		cin>>s;
		for(int i=1;i<=n;i++)cin>>v[i];
		for(int i=1;i<=n;i++)
		{
			if(!vis[i])
			{
				string t;
				for(int j=i;!vis[j];j=v[j])
				{
					vis[j]=1;
					t+=s[j-1];
				}
				int cnt=(t+t).find(t,1);
				ans=(ans*cnt)/__gcd(ans,cnt);
			}
		}
		cout<<ans<<endl;
	}
    return 0;
}

     		    				 	  				  	 	  	