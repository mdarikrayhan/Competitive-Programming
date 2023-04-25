#include<iostream>
#include<algorithm>
using namespace std;
//int a[200005];
bool f[200005];
int main()
{
	int t,n,x,k,d;
	cin>>t;
	while(t--)
	{
		k=0;
		long long sum=0;
		cin>>n;
		int b=n+1,e=0;
		for(int i=1;i<=n;i++)
		{
			cin>>f[i];
			k=f[i]+k;
			if(!f[i]) sum+=k;
			if(b==n+1&&!f[i]) b=i;
			if(f[i]) e=i;
		}
		d=max(e-1+k-n,n-k-b);
		cout<<sum+max(0,d)<<endl;
	}
}