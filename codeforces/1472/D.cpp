#import<bits/stdc++.h>
using namespace std;
long long i,n,t,x,y,a[200040];
main()
{
	for(cin>>t;t--;)
	{
		cin>>n;
		for(i=0;i<n;i++)cin>>a[i];
		sort(a,a+n);
		for(i=x=y=0;i++<n;)
		{
			if(i&1&&~a[n-i]&1)x+=a[n-i];
			if(~i&1&&a[n-i]&1)y+=a[n-i];
		}
		if(x>y)cout<<"Alice"<<endl;
		else if(x<y)cout<<"Bob"<<endl;
		else cout<<"Tie"<<endl;
	}
}