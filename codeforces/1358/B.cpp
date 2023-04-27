#import<bits/stdc++.h>
using namespace std;
int i,n,t,a[100005];
main()
{
	for(cin>>t;t--;)
	{
		cin>>n;
		for(i=0;i++<n;)cin>>a[i];
		sort(a,a+i);
		for(;a[--i]>i;);
		cout<<i+1<<endl;
	}
}