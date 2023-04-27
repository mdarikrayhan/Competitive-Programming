#import<bits/stdc++.h>
using namespace std;
int k,m,n,p,t;
main()
{
	for(cin>>t;t--;m=0)
	{
		for(cin>>n>>p;n--;)
		{
			cin>>k;
			m^=2*k==p;
			cout<<(2*k<p||2*k==p&&m?"1 ":"0 ");
		}
		cout<<endl;
	}
}