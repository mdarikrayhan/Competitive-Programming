#import<bits/stdc++.h>
using namespace std;
int i,n,t,a[105],b[105];
void f(int d,int x,int y)
{
	int m=x;
	if(x>y)return;
	for(i=x;i<=y;i++)
	{
		if(a[i]>a[m])m=i;
		b[m]=d;
	}
	f(d+1,x,m-1);
	f(d+1,m+1,y);
}
main()
{
	for(cin>>t;t--;)
	{
		cin>>n;
		for(i=0;i++<n;)cin>>a[i];
		f(0,1,n);
		for(i=0;i++<n;)cout<<b[i]<<' ';
		cout<<endl;
	}
}