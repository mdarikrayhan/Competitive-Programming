#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,s,p,x;
signed main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		s=p=0;
		for(int i=1;i<=n;i++)
			cin>>x,s+=x,p=max(p,x);
		s?cout<<max(1ll,2*p-s)<<'\n':cout<<"0\n";
	}
}